/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:30:00 by madias-m          #+#    #+#             */
/*   Updated: 2025/07/10 15:42:08 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/define.h"
#include "../include/parser/Parser.hpp"
#include "../include/server/Server.hpp"

using std::cout;
using std::string;

int	main(int argc, char **argv)
{
	Parser	parser;
	
	if (argc == 1)
		cout << "No config file passed by args. Using default config\n";
	else
		parser = Parser(argv[1]);
	parser.doParsing();
	return (0);
}
