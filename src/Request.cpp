/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:23:29 by madias-m          #+#    #+#             */
/*   Updated: 2025/08/13 16:37:29 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Request.hpp"


Request::Request(void)
{
	
}

Request::Request(std::string message)
{
	this->_message = message;
}

Request& Request::operator=(const Request& other)
{
	if (this != &other)
	{
		this->_message = other._message;
	}
	return (*this);
}

Request::Request(const Request& other)
{
	*this = other;
}


