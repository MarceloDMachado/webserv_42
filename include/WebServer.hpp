/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WebServer.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:45:12 by madias-m          #+#    #+#             */
/*   Updated: 2025/08/04 14:56:08 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERVER__HPP
# define WEBSERVER__HPP

#include <string>
#include <vector>
#include "Harl.hpp"
#include "Server.hpp"

class WebServer
{
	private:
		std::vector<Server>	_servers;
		WebServer(void);
	public:
		WebServer(std::vector<Server> servers);
		WebServer(const WebServer& other);
		WebServer&	operator=(const WebServer& other);
};

#endif
