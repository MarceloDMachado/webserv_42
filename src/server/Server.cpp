/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:36:09 by madias-m          #+#    #+#             */
/*   Updated: 2025/08/01 10:08:23 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Server.hpp"

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


void	Server::setServerName(std::istringstream& iss)
{
	std::string	value;
	
	while (iss >> value)
		this->_server_name.push_back(value);
}

void	Server::setListen(std::istringstream& iss)
{
	std::string	value;
	
	while (iss >> value)
		this->_listen.push_back(value);
}

void	Server::setRoot(std::istringstream& iss)
{
	std::string	value;

	while (iss >> value)
		this->_root.push_back(value);
}

void	Server::setIndex(std::istringstream& iss)
{
	std::string	value;

	while (iss >> value)
		this->_index.push_back(value);
}

void	Server::setErrorPage(std::istringstream& iss)
{
	std::string	value;

	while (iss >> value)
		this->_error_page.push_back(value);
}

std::vector<std::string>	Server::getServerName(void) const
{
	return (this->_server_name);
}

std::vector<std::string>	Server::getListen(void) const
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
