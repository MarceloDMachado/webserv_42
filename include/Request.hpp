/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:23:37 by madias-m          #+#    #+#             */
/*   Updated: 2025/08/13 17:14:35 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef REQUEST__HPP
# define REQUEST__HPP

#include <string>
#include <vector>
#include "Harl.hpp"

class Request
{
	private:
		std::string					_message;
		std::string 				_requestLine;
		std::vector<std::string>	_headers;
		std::string					_body;
		std::string					extractRequestLine(char *msg);
		std::vector<std::string>	extractHeaders(char *msg);
		std::string					extractBody(char *msg);
	public:
		Request(void);
		Request(std::string message);
		Request(const Request& other);
		Request&	operator=(const Request& other);
		
};

#endif