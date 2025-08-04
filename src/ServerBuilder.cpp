/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerBuilder.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:57:21 by madias-m          #+#    #+#             */
/*   Updated: 2025/08/04 14:43:49 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ServerBuilder.hpp"


ServerBuilder::ServerBuilder(void){}

ServerBuilder::ServerBuilder(std::map<int, std::string>& confContent, std::vector<int>& serverDeclarationLines)
{
	int next;
	
	std::vector<int>::const_iterator it;
	for (it = serverDeclarationLines.begin(); it != serverDeclarationLines.end(); ++it)
	{
		if (it + 1 != serverDeclarationLines.end()) 
			next = *(it + 1);
		else
			next = (--(confContent.end()))->first;
		buildServer(confContent, *it + 1, next);
	}
	// std::cout << this->_servers[0] << std::endl;
	// std::cout << this->_servers[1] << std::endl;
	// std::cout << this->_servers[2] << std::endl;
}

void	ServerBuilder::buildServer(std::map<int, std::string>& confContent, int currentLine, int finalLine)
{
	Server server;
	Location genericLocation;
	
	while (currentLine < finalLine)
	{
		std::istringstream iss(confContent[currentLine++]);
		server.setDynamicAttribute(iss);
	}
	genericLocation.setAutoIndex("on");
	genericLocation.setClientMaxSizeBody("1g");
	server.setLocation(genericLocation);
	this->_servers.push_back(server);
}

std::vector<Server>	ServerBuilder::getServers(void) const
{
	return (this->_servers);
}
