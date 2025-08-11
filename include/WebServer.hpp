/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WebServer.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:45:12 by madias-m          #+#    #+#             */
/*   Updated: 2025/08/11 16:56:40 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERVER__HPP
# define WEBSERVER__HPP

#include <string>
#include <vector>
#include <unistd.h> //remover;
#include <cstring> // remover;
#include "SyntaxChecker.hpp";
#include "Harl.hpp"
#include "Server.hpp"

class WebServer
{
	private:
		std::vector<Server>	_servers;
		void				clientTCP(void);
	public:
		WebServer(void);
		WebServer(std::vector<Server> servers);
		WebServer(const WebServer& other);
		WebServer&	operator=(const WebServer& other);
		void		setServers(std::vector<Server> servers);
		void		init(void);
		void		initServers(void);
		void		run(void);
		void		stopServers(void);
		void		execute(void);
};

#endif
