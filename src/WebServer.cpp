/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WebServer.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:45:02 by madias-m          #+#    #+#             */
/*   Updated: 2025/08/11 17:28:25 by madias-m         ###   ########.fr       */
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

std::vector<int>	getServerFds(std::vector<Server>& servers)
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

void		WebServer::execute(void)
{
	fd_set				read_fds;
	fd_set				write_fds;
	std::vector<int>	client_sockets;
	std::vector<int>	ports = getPorts(this->_servers);
	std::vector<int>	serverFds = getServerFds(this->_servers);
	
	while (1)
	{
		FD_ZERO(&read_fds);
		FD_ZERO(&write_fds);

		std::vector<int>::const_iterator serverFD;
		for (serverFD = serverFds.begin(); serverFD != serverFds.end(); ++serverFD)
			FD_SET(*serverFD, &read_fds);
		
		std::vector<int>::const_iterator client_socket;
		for (client_socket = client_sockets.begin(); client_socket != client_sockets.end(); ++client_socket)
		{
			FD_SET(*client_socket, &read_fds);
			FD_SET(*client_socket, &write_fds);
		}
		
		
	}
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
	// clientTCP();
	execute();
}