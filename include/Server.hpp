/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:47:41 by madias-m          #+#    #+#             */
/*   Updated: 2025/07/10 15:03:44 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER__HPP
# define SERVER__HPP

#include <string>
#include <vector>

class Server 
{
	private:
		std::vector<std::string>	_server_name;
		std::vector<std::string>	_listen;
		std::vector<std::string>	_root;
		std::vector<std::string>	_index;
		std::vector<std::string>	_error_page;
		//std::vector<Location>		_locations;
	public:
		Server(void);
		Server(const Server& other);
		Server&	operator=(const Server& other);
		~Server(void);
};

#endif
