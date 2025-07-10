/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:09:59 by madias-m          #+#    #+#             */
/*   Updated: 2025/07/10 14:01:14 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
# define PARSER_HPP

#include <cstring>
#include <iostream>
#include <fstream>

class Parser
{
	private:
		std::string	_confPath;
		std::fstream	_confFile;
		void			openFile(void);
	public:
		Parser(void);
		Parser(std::string confPath);
		Parser(const Parser& other);
		Parser&			operator=(const Parser& other);
		~Parser(void);
		void	doParsing(void);
};

#endif