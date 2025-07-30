/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:09:59 by madias-m          #+#    #+#             */
/*   Updated: 2025/07/30 15:16:53 by madias-m         ###   ########.fr       */
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
#include "ServerBuilder.hpp"

class Parser
{
	private:
		std::string					_confPath;
		FileHandler					_fileHandler;
		std::map<int, std::string>	_fileContent;
		bool						_checkResult;
		std::vector<int>			_serverDeclarationLines;
		void						openFile(void);
		Parser(void);
		void						checkFileContent(void);
		void						setServerDeclarationLines(void);
		bool						isServerDeclarationLine(std::string line);

	public:
		Parser(int argc, char **argv);
		Parser(const Parser& other);
		~Parser(void);
		Parser&						operator=(const Parser& other);
		void						doParsing(void);
};

#endif