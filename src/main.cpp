/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:30:00 by madias-m          #+#    #+#             */
/*   Updated: 2025/08/05 16:35:41 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <csignal>
#include "../include/WebServer.hpp"
#include "../include/Parser.hpp"

volatile bool	running = true;

void	signal_handle(int sig)
{
	(void) sig;
	running = false;
}

int	main(int argc, char **argv)
{
	WebServer	webserver;
	// signal(SIGINT, signal_handle);
	{
		Parser parser(argc, argv);
		parser.doParsing();
		webserver.setServers(parser.getServers());
	}
	webserver.init();
	webserver.run();
	webserver.stopServers();
	return (0);
}
