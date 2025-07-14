/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:30:00 by madias-m          #+#    #+#             */
/*   Updated: 2025/07/14 12:15:43 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/define.h"
#include "../include/Parser.hpp"
#include "../include/Server.hpp"

int	main(int argc, char **argv)
{
	Parser(argc, argv).doParsing();
	return (0);
}
