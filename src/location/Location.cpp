/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Location.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 12:43:28 by madias-m          #+#    #+#             */
/*   Updated: 2025/08/04 13:33:31 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Location.hpp"

Location::Location(void)
{
	
}

Location::Location(const Location& other)
{
	*this = other;
}

Location& Location::operator=(const Location& other)
{
	if (this != &other)
	{
		this->_path = other._path;
		this->_autoindex = other._autoindex;
		this->_client_max_size_body = other._client_max_size_body;
	}
	return (*this);
}

void	Location::setAutoIndex(std::string value)
{
	setAutoIndex(!value.compare("on"));
}

void	Location::setAutoIndex(bool value)
{
	this->_autoindex = value;
}

unsigned int	getMultiplier(std::string value)
{
	if (value.find('k') != std::string::npos || value.find('K') != std::string::npos)
		return (1024);
	else if (value.find('m') != std::string::npos || value.find('M') != std::string::npos)
		return (1024 * 1024);
	else if (value.find('g') != std::string::npos || value.find('G') != std::string::npos)
		return (1024 * 1024 * 1024);
	else
		return (1);
}

void	Location::setClientMaxSizeBody(std::string value)
{
	setClientMaxSizeBody(atoi(value.c_str()) * getMultiplier(value));
}

void	Location::setClientMaxSizeBody(unsigned int value)
{
	std::ostringstream	msg;
	
	this->_client_max_size_body = value;
	
	msg.str("");
	msg << "value: ";
	msg << value;
	Harl(msg, INFO).complain();
}