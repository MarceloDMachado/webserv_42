/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:46:59 by madias-m          #+#    #+#             */
/*   Updated: 2025/07/11 19:08:50 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>
#include "define.h"

enum		levels {DEBUG, INFO, WARNING, ERROR};

class Harl
{
    private:
        std::string _msg;
        levels		_level;
        void		debug(void);
        void		info(void);
        void		warning(void);
        void		error(void);
	public:
        Harl(std::string msg);
		Harl(std::string msg, levels level);
        void    complain();
		void	setMsg(std::string msg);
		void	setLevel(levels level);
};

#endif
