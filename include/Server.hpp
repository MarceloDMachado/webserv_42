/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:47:41 by madias-m          #+#    #+#             */
/*   Updated: 2025/08/11 16:16:25 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER__HPP
# define SERVER__HPP

#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "Harl.hpp"
#include "Location.hpp"

class Server 
{
	private:
		std::vector<std::string>	_server_name;
		std::vector<int>			_listen;
		std::vector<std::string>	_root;
		std::vector<std::string>	_index;
		std::vector<std::string>	_error_page;
		std::vector<Location>		_locations;
		void						setServerName(std::istringstream& iss);
		void						setListen(std::istringstream& iss);
		void						setRoot(std::istringstream& iss);
		void						setIndex(std::istringstream& iss);
		void						setErrorPage(std::istringstream& iss);
		void						handleUnknowKey(std::string key);
		std::string					removeExtraChar(std::string value, char c);
		
	public:
		std::map<int, sockaddr_in>	_address_by_fd;
		Server(void);
		Server(const Server& other);
		Server&	operator=(const Server& other);
		~Server(void);
		void						setDynamicAttribute(std::istringstream& iss);
		std::vector<std::string>	getServerName(void) const;
		std::vector<int>			getListen(void) const;
		std::vector<std::string>	getRoot(void) const;
		std::vector<std::string>	getIndex(void) const;
		std::vector<std::string>	getErrorPage(void) const;
		void						setLocation(Location Location);
		void						init(void);
		void						stop(void);
};

std::ostream&	operator<<(std::ostream& o, Server const& rhs);

#endif
