/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WebServer.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:45:02 by madias-m          #+#    #+#             */
/*   Updated: 2025/08/13 15:52:59 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WebServer.hpp"

WebServer::WebServer(void)
{

}

WebServer::WebServer(std::vector<Server> servers)
{
	this->_servers = servers;
}

WebServer::WebServer(const WebServer& other)
{
	*this = other;
}

WebServer&	WebServer::operator=(const WebServer& other)
{
	if (this != &other)
	{
		this->_servers = other._servers;
	}
	return (*this);
}

void		WebServer::setServers(std::vector<Server> servers)
{
	this->_servers = servers;
}

void		WebServer::initServers(void)
{
	std::vector<Server>::iterator it;
	for (it = this->_servers.begin(); it != this->_servers.end(); ++it)
		it->init();
}

void		WebServer::stopServers(void)
{
	std::vector<Server>::iterator it;
	for (it = this->_servers.begin(); it != this->_servers.end(); ++it)
		it->stop();
}

void		WebServer::init(void)
{
	Harl("Server is running!!!", INFO).complain();
	initServers();
}

std::vector<int>	getPorts(std::vector<Server>& servers)
{
	std::vector<int> allPorts;
	
	std::vector<Server>::const_iterator it;
	for (it = servers.begin(); it != servers.end(); ++it)
	{
		std::vector<int> itPorts = it->getListen();
		std::vector<int>::const_iterator port;
		for (port = itPorts.begin(); port != itPorts.end(); ++port)
			allPorts.push_back(*port);
	}
	return (allPorts);
}

std::vector<int>	getServerSockets(std::vector<Server>& servers)
{
	std::vector<int> allFds;
	
	std::vector<Server>::const_iterator it;
	for (it = servers.begin(); it != servers.end(); ++it)
	{
		std::vector<int> itFds = getMapKeysGeneric(it->_address_by_fd);
		std::vector<int>::const_iterator fd;
		for (fd = itFds.begin(); fd != itFds.end(); ++fd)
			allFds.push_back(*fd);
	}
	return (allFds);
}


/**TIRAR DAQUI EM ALGUM MOMENTO */
#include <csignal>

volatile bool	running = true;

void	signal_handle(int sig)
{
	(void) sig;
	running = false;
}

//// ENDD


void		WebServer::execute(void)
{
	fd_set				read_fds;
	fd_set				write_fds;
	std::vector<int>	client_sockets;
	std::vector<int>	ports = getPorts(this->_servers);
	std::vector<int>	server_sockets = getServerSockets(this->_servers);
	
	
	signal(SIGINT, signal_handle);
	while (running)
	{
		FD_ZERO(&read_fds);
		FD_ZERO(&write_fds);

		std::vector<int>::const_iterator serverFD;
		for (serverFD = server_sockets.begin(); serverFD != server_sockets.end(); ++serverFD)
			FD_SET(*serverFD, &read_fds);
		
		std::vector<int>::const_iterator client_socket;
		for (client_socket = client_sockets.begin(); client_socket != client_sockets.end(); ++client_socket)
		{
			FD_SET(*client_socket, &read_fds);
			FD_SET(*client_socket, &write_fds);
		}
		
		int max_fd = 0;
		for (size_t i = 0; i < server_sockets.size(); i++)
			max_fd = std::max(max_fd, server_sockets[i]);
		for (size_t i = 0; i < client_sockets.size(); i++)
			max_fd = std::max(max_fd, client_sockets[i]);

		struct timeval timeout;
		timeout.tv_sec = 1;
		timeout.tv_usec = 0;

		int ready = select(max_fd + 1, &read_fds, &write_fds, NULL, &timeout);
		if (ready < 0)
		{
			std::cout << "deu ruim no select\n";
			continue ; 
		}
		if (ready == 0)
		{
			std::cout << "timeout: no activities" << std::endl;
			continue ;
		}

		for (size_t i = 0; i < server_sockets.size(); i++)
		{
			if (FD_ISSET(server_sockets[i], &read_fds))
			{
				struct sockaddr_in	client_address;
				socklen_t			socket_len = sizeof(client_address);

				int client_socket = accept(server_sockets[i], (struct sockaddr*) &client_address, &socket_len);
				
				std::cout << "New client connected on: " << ports[i] << std::endl;
				client_sockets.push_back(client_socket);
			}
		}

		for (size_t i = 0; i < client_sockets.size();)
		{
			if (FD_ISSET(client_sockets[i], &read_fds))
			{
				
				char buffer[1024]; // alterar para max_body_size
				size_t bytes = read(client_sockets[i], buffer, sizeof(buffer));
				
				if (bytes <= 0)
				{
					std::cout << "Client disconnected\n";
					close(client_sockets[i]);
					client_sockets.erase(client_sockets.begin() + i);
					continue ;
				}
				else
				{
					// redirecionar buffer para tratamento de REQUESTS
					std::cout << "Data received from client: " << std::string(buffer, bytes) << std::endl;
					
					// elaborar RESPONSE e devolver para o client
					const char *response = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nHello from server!";
					write(client_sockets[i], response, strlen(response));
					if (1) // Verificar se deve manter a conexao
					{
						std::cout << "Closing client connection\n"; // elaborar mensagem utilizando o client_address
						close(client_sockets[i]);
						client_sockets.erase(client_sockets.begin() + i);
					}
				}
			}
			i++;
		}
	}
	for (size_t i = 0; i < client_sockets.size(); i++)
		close(client_sockets[i]);
}

void		WebServer::clientTCP(void)
{
	struct sockaddr_in	client_address;
	socklen_t			client_len = sizeof(client_address);
	
	int client_socket = accept((this->_servers[0]._address_by_fd.begin())->first, (struct sockaddr*)&client_address, &client_len);
	if (client_socket < 0)
		return ;
	
	char	buffer[1024];
	read(client_socket, buffer, sizeof(buffer));
	
	std::cout << "Client message:\n" << buffer << std::endl;
	const char *response = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nHello from server!";
	write(client_socket, response, strlen(response));
	close(client_socket);
}

void		WebServer::run(void)
{
	//clientTCP();
	execute();
}