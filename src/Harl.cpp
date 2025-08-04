/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:46:38 by madias-m          #+#    #+#             */
/*   Updated: 2025/08/04 14:43:25 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

Harl::Harl(std::string msg)
{
	setMsg(msg);
	setLevel(DEBUG);
}

Harl::Harl(std::string msg, levels level)
{
	setMsg(msg);
	setLevel(level);
}

Harl::Harl(std::ostringstream& msg)
{
	setMsg(msg.str());
	setLevel(DEBUG);
}

Harl::Harl(std::ostringstream& msg, levels level)
{
	setMsg(msg.str());
	setLevel(level);
}

void	Harl::setMsg(std::string msg)
{
	this->_msg = msg;
}

void	Harl::setLevel(levels level)
{
	this->_level = level;
}

void    Harl::debug(void)
{
    std::cout << WHITE << "[DEBUG] " << RESET << this->_msg << std::endl;
}

void    Harl::info(void)
{
    std::cout << CYAN << "[INFO] " << RESET << this->_msg << std::endl;
}

void    Harl::warning(void)
{
    std::cout << YELLOW << "[WARNING] " << RESET << this->_msg << std::endl;
}

void    Harl::error(void)
{
    std::cout << RED << "[ERROR] " << RESET << this->_msg << std::endl;
}

void    Harl::complain(void)
{
	void		(Harl::*funcArray[4])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
    };
	(this->*funcArray[this->_level])();
}
