/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:09:59 by madias-m          #+#    #+#             */
/*   Updated: 2025/07/21 17:01:19 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
# define PARSER_HPP

#include <string>
#include <map>
#include "Harl.hpp"
#include "define.h"
#include "SyntaxChecker.hpp"
#include "FileHandler.hpp"

class Parser
{
	private:
		std::string					_confPath;
		FileHandler					_fileHandler;
		std::map<int, std::string>	_fileContent;
		bool						_checkResult;
		void			openFile(void);
		Parser(void);
		void	checkFileContent(void);
	public:
		Parser(int argc, char **argv);
		Parser(const Parser& other);
		Parser&			operator=(const Parser& other);
		~Parser(void);
		void	doParsing(void);
};

#endif