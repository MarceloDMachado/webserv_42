/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:47:41 by madias-m          #+#    #+#             */
/*   Updated: 2025/08/01 10:07:44 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER__HPP
# define SERVER__HPP

#include <string>
#include <sstream>
#include <vector>
#include "Harl.hpp"

class Server 
{
	private:
		std::vector<std::string>	_server_name;
		std::vector<std::string>	_listen;
		std::vector<std::string>	_root;
		std::vector<std::string>	_index;
		std::vector<std::string>	_error_page;
		//std::vector<Location>		_locations;
		void						setServerName(std::istringstream& iss);
		void						setListen(std::istringstream& iss);
		void						setRoot(std::istringstream& iss);
		void						setIndex(std::istringstream& iss);
		void						setErrorPage(std::istringstream& iss);
		void						handleUnknowKey(std::string key);

	public:
		Server(void);
		Server(const Server& other);
		Server&	operator=(const Server& other);
		~Server(void);
		void						setDynamicAttribute(std::istringstream& iss);
		std::vector<std::string>	getServerName(void) const;
		std::vector<std::string>	getListen(void) const;
		std::vector<std::string>	getRoot(void) const;
		std::vector<std::string>	getIndex(void) const;
		std::vector<std::string>	getErrorPage(void) const;
};

std::ostream&	operator<<(std::ostream& o, Server const& rhs);

#endif
