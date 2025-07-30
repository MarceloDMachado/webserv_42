/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerBuilder.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:57:21 by madias-m          #+#    #+#             */
/*   Updated: 2025/07/30 14:54:36 by madias-m         ###   ########.fr       */
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
		buildServer(confContent, *it, next);
	}
}

void	ServerBuilder::buildServer(std::map<int, std::string>& confContent, int initalLine, int finalLine)
{
	Server server;
	std::istringstream iss(confContent[initalLine]);
	server.setServerName(iss);
}

std::map<std::string, Server>	ServerBuilder::getServers(void) const
{
	return (this->_servers);
}
