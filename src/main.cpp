/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:30:00 by madias-m          #+#    #+#             */
/*   Updated: 2025/08/05 11:42:33 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/WebServer.hpp"
#include "../include/Parser.hpp"

int	main(int argc, char **argv)
{
	WebServer	webserver;
	{
		Parser parser(argc, argv);
		parser.doParsing();
		webserver.setServers(parser.getServers());
	}
	webserver.init();
	webserver.run();
	return (0);
}
