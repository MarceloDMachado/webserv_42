/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:23:37 by madias-m          #+#    #+#             */
/*   Updated: 2025/08/13 16:34:30 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef REQUEST__HPP
# define REQUEST__HPP

#include <string>
#include "Harl.hpp"

class Request
{
	private:
		std::string	_message;
	public:
		Request(void);
		Request(std::string message);
		Request(const Request& other);
		Request&	operator=(const Request& other);
		
};

#endif