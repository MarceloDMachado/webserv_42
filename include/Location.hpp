/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Location.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 12:43:39 by madias-m          #+#    #+#             */
/*   Updated: 2025/08/04 13:28:20 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOCATION__HPP
# define LOCATION__HPP

#include <string>
#include <stdlib.h>
#include "Harl.hpp"

class Location
{
	private:
		std::string		_path;
		bool			_autoindex;
		unsigned int	_client_max_size_body;
	public:
		Location(void);
		Location(const Location& other);
		Location&	operator=(const Location& other);
		void		setAutoIndex(std::string value);
		void		setAutoIndex(bool value);
		void		setClientMaxSizeBody(std::string value);
		void		setClientMaxSizeBody(unsigned int value);
};

#endif
