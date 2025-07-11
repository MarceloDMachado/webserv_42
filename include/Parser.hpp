/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:09:59 by madias-m          #+#    #+#             */
/*   Updated: 2025/07/11 19:15:44 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
# define PARSER_HPP

#include <string>
#include <iostream>
#include <fstream>
#include "Harl.hpp"
#include "define.h"

class Parser
{
	private:
		std::string	_confPath;
		std::fstream	_confFile;
		void			openFile(void);
		Parser(void);
	public:
		Parser(int argc, char **argv);
		Parser(const Parser& other);
		Parser&			operator=(const Parser& other);
		~Parser(void);
		void	doParsing(void);
};

#endif