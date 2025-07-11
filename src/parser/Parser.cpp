/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:18:00 by madias-m          #+#    #+#             */
/*   Updated: 2025/07/11 19:17:34 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Parser.hpp"

Parser::Parser(void):_confPath(DEFAULT_CONFIG){}

Parser::Parser(int argc, char **argv):_confPath(DEFAULT_CONFIG)
{
	if (argc == 1)
		std::cout << "No config file passed by args. Using default config\n";
	else
		this->_confPath = argv[1];
}

Parser::Parser(const Parser& other)
{
	*this = other;
}

Parser&			Parser::operator=(const Parser& other)
{
	if (this != &other)
		this->_confPath = other._confPath;
	return (*this);
}

Parser::~Parser(void)
{
	this->_confFile.close();
}

void	Parser::openFile(void)
{
	this->_confFile.open(this->_confPath.c_str());
	if (this->_confFile.is_open())
		Harl("File is open", INFO).complain();
	else
		Harl("Could not open the file", ERROR).complain();
}

void	Parser::doParsing(void)
{
	openFile();
}
