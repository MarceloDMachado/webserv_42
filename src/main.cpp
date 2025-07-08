/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:30:00 by madias-m          #+#    #+#             */
/*   Updated: 2025/07/08 14:27:46 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstring>
#include "../include/define.h"

using std::cout;
using std::fstream;
using std::string;

int	main(int argc, char **argv)
{
	string pathFile;
	
	if (argc == 1)
	{
		cout << "No config file passed by args. Using default config\n";
		pathFile = DEFAULT_CONFIG;
	}
	else
		pathFile = argv[1];
	fstream configFile(pathFile.c_str());
	configFile.close();
	return (0);
}
