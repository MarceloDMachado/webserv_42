/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:36:09 by madias-m          #+#    #+#             */
/*   Updated: 2025/08/11 16:16:58 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Server.hpp"

Server::Server(void){};

Server::Server(const Server& other)
{
	*this = other;
}

Server&	Server::operator=(const Server& other)
{
	if (this != &other)
	{
		this->_server_name = other._server_name;
		this->_listen = other._listen;
		this->_root = other._root;
		this->_index = other._index;
		this->_error_page = other._error_page;
	}
	return (*this);
}

Server::~Server(void)
{
	
}

void	Server::setDynamicAttribute(std::istringstream &iss)
{
	std::string	attribute_key;

	iss >> attribute_key;
	if (!attribute_key.compare("server_name"))
		setServerName(iss);
	else if (!attribute_key.compare("listen"))
		setListen(iss);
	else if (!attribute_key.compare("root"))
		setRoot(iss);
	else if (!attribute_key.compare("index"))
		setIndex(iss);
	else if (!attribute_key.compare("error_page"))
		setErrorPage(iss);
	else
		handleUnknowKey(attribute_key);
}

void	Server::handleUnknowKey(std::string key)
{
	if (!key.compare("") || !key.compare("}"))
		return ;
	Harl("Could not find the key: [" + key + "]", WARNING).complain();
}

std::string	Server::removeExtraChar(std::string value, char c)
{
	if (value.find(c) == std::string::npos)
		return (value);
	value.at(value.find(c)) = 0;
	return (value);
}

void	Server::setServerName(std::istringstream& iss)
{
	std::string	value;
	
	while (iss >> value)
		this->_server_name.push_back(removeExtraChar(value, ';'));
}

void	Server::setListen(std::istringstream& iss)
{
	std::string	value;
	
	while (iss >> value)
		this->_listen.push_back(atoi(value.c_str()));
}

void	Server::setRoot(std::istringstream& iss)
{
	std::string	value;

	while (iss >> value)
		this->_root.push_back(removeExtraChar(value, ';'));
}

void	Server::setIndex(std::istringstream& iss)
{
	std::string	value;

	while (iss >> value)
		this->_index.push_back(removeExtraChar(value, ';'));
}

void	Server::setErrorPage(std::istringstream& iss)
{
	std::string	value;

	while (iss >> value)
		this->_error_page.push_back(removeExtraChar(value, ';'));
}

std::vector<std::string>	Server::getServerName(void) const
{
	return (this->_server_name);
}

std::vector<int>	Server::getListen(void) const
{
	return (this->_listen);
}

std::vector<std::string>	Server::getRoot(void) const
{
	return (this->_root);
}

std::vector<std::string>	Server::getIndex(void) const
{
	return (this->_index);
}

std::vector<std::string>	Server::getErrorPage(void) const
{
	return (this->_error_page);
}

void						Server::setLocation(Location location)
{
	this->_locations.push_back(location);
}

void						Server::init(void)
{
	int server_fd;
	
	std::vector<int>::const_iterator it;
	for (it = this->_listen.begin(); it != this->_listen.end(); ++it)
	{
		struct sockaddr_in address;
		
		address.sin_family = AF_INET;
		address.sin_addr.s_addr = inet_addr("127.0.0.1");
		address.sin_port = htons(*it);

		server_fd = socket(AF_INET, SOCK_STREAM, 0);
		bind(server_fd, (struct sockaddr *) &address, sizeof(address));
		listen(server_fd, 10);
		
		this->_address_by_fd.insert(std::make_pair(server_fd, address));
	}
}

void						Server::stop(void)
{
	std::map<int, sockaddr_in>::const_iterator it;
	for (it = this->_address_by_fd.begin(); it != this->_address_by_fd.end(); ++it)
		close(it->first);
}


std::ostream&	operator<<(std::ostream& o, Server const& rhs)
{
	o << "Server Description" << std::endl;
	o << "server_name: " << rhs.getServerName()[0] << std::endl;
	o << "listen: " << rhs.getListen()[0] << std::endl;
	o << "root: " << rhs.getRoot()[0] << std::endl;
	o << "index: " << rhs.getIndex()[0] << std::endl;
	o << "error_page: " << rhs.getErrorPage()[0] << std::endl;

	return (o);
}
