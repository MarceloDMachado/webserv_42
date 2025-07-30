/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerBuilder.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:57:07 by madias-m          #+#    #+#             */
/*   Updated: 2025/07/30 14:54:16 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVERBUILDER__HPP
# define SERVERBUILDER__HPP

#include <string>
#include <map>
#include <vector>
#include <sstream>
#include "Server.hpp"
// #include "Location.hpp"

class ServerBuilder 
{
	private:
		std::map<std::string, Server>	_servers;
		ServerBuilder(void);
		void							buildServer(std::map<int, std::string>& confContent, int initalLine, int finalLine);
	public:
		ServerBuilder(std::map<int, std::string>& confContent, std::vector<int>& serverDeclarationLines);
		std::map<std::string, Server>	getServers(void) const;
		
};

#endif
