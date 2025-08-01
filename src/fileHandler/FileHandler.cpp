/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileHandler.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:18:09 by madias-m          #+#    #+#             */
/*   Updated: 2025/08/01 10:29:13 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/FileHandler.hpp"

FileHandler::FileHandler(void){}

FileHandler::FileHandler(std::string path)
{
	setPath(path);
}

FileHandler::FileHandler(const FileHandler& other)
{
	*this = other;
}

FileHandler&	FileHandler::operator=(const FileHandler& other)
{
	if (this != &other)
		setPath(other._path);
	return (*this);
}

FileHandler::~FileHandler(void)
{
	
}

void	FileHandler::openFile(void)
{
	this->_file.open(this->_path.c_str());
	if (!this->_file.is_open())
		Harl("Could not open the file [_path]", ERROR).complain();
	else
		readFile();
}

static const char*	runOverSpaces(const char *str)
{
	while (*str && strchr(" \t\r\v\f", *str))
		str++;
	return (str);
}

void	FileHandler::readFile(void)
{
	std::string	line;
	int			line_num;
	
	if (!this->_file.is_open())
		Harl("Could not read from file [_path]", ERROR).complain();
	line_num = 1;
	while (std::getline(this->_file, line))
	{
		this->_lineByNumberMap.insert(std::make_pair(line_num++, runOverSpaces(line.c_str())));
		// Harl(line, DEBUG).complain(); // Remover
	}
	this->_file.close();
}

std::map<int, std::string>	FileHandler::getContent(void) const
{
	return (this->_lineByNumberMap);
}

void	FileHandler::setPath(std::string path)
{
	this->_path = path;
}
