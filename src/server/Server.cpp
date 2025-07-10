/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:36:09 by madias-m          #+#    #+#             */
/*   Updated: 2025/07/10 15:41:26 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/server/Server.hpp"

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
