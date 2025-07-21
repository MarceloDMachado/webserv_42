/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:18:00 by madias-m          #+#    #+#             */
/*   Updated: 2025/07/21 17:08:43 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Parser.hpp"

Parser::Parser(void):_confPath(DEFAULT_CONFIG){}

Parser::Parser(int argc, char **argv):_confPath(DEFAULT_CONFIG)
{
	if (argc == 1)
		Harl("No config file passed by args. Using default config", INFO).complain();
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

Parser::~Parser(void) {}

void	Parser::openFile(void)
{
	this->_fileHandler.setPath(this->_confPath);
	this->_fileHandler.openFile();
	this->_fileContent = this->_fileHandler.getContent();
}

void	Parser::checkFileContent(void)
{
	bool	(*checkFunctions[])(std::string) = {
		hasDuplicatedSpecialTokens,
		isMissingTokens
	};
	int		index;

	this->_checkResult = true;
	index = 0;
	while (index < 2)
		if (!check(this->_fileContent, checkFunctions[index++]))
			this->_checkResult = false;
}

void	Parser::doParsing(void)
{
	openFile();
	checkFileContent();
	if (this->_checkResult == false)
		return ;
}
