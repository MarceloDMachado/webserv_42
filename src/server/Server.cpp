/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:36:09 by madias-m          #+#    #+#             */
/*   Updated: 2025/07/30 14:44:33 by madias-m         ###   ########.fr       */
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

void	Server::setServerName(std::istringstream& iss)
{
	std::string	value;
	
	while (iss >> value)
		this->_server_name.push_back(value);
}

// void	Server::setListen(std::istringstream iss)
// {
	// std::string	value;
	// 
	// while (iss >> value)
		// this->_listen.push_back(value);
// }
// 
// void	Server::setRoot(std::istringstream iss)
// {
	// std::string	value;
// 
	// while (iss >> value)
		// this->_root.push_back(value);
// }
// 
// void	Server::setIndex(std::istringstream iss)
// {
	// std::string	value;
// 
	// while (iss >> value)
		// this->_index.push_back(value);
// }
// 
// void	Server::setErrorPage(std::istringstream iss)
// {
	// std::string	value;
// 
	// while (iss >> value)
		// this->_error_page.push_back(value);
// }

