/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SyntaxChecker.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:18:41 by madias-m          #+#    #+#             */
/*   Updated: 2025/07/21 16:48:41 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYNTAXCHECKER__HPP
# define SYNTAXCHECKER__HPP

# include <cstring>
# include <sstream>
# include <algorithm>
# include <map>
# include <vector>
# include "Harl.hpp"

template <typename KeyType, typename ValueType>
static std::vector<KeyType> getMapKeysGeneric(const std::map<KeyType, ValueType>& myMap) {
    std::vector<KeyType> keys;
    typename std::map<KeyType, ValueType>::const_iterator it;
    for (it = myMap.begin(); it != myMap.end(); ++it) {
        keys.push_back(it->first);
    }
    return (keys);
}

template <typename KeyType>
static bool	check(std::map<KeyType, std::string> &target, bool (*checker)(std::string))
{
	bool					result;
	std::vector<KeyType>	keys;
	std::ostringstream		msg;
	
	result = true;
	keys = getMapKeysGeneric(target);
	typename std::vector<KeyType>::const_iterator it;
	for (it = keys.begin(); it != keys.end(); ++it)
	{
		if (checker(target[*it]))
		{
			result = false;
			msg.str("");
			msg << "Invalid syntax on line: [" << *it << "] " << " ["<< target[*it] << "]";
			Harl(msg, ERROR).complain();
		}
	}
	return (result);
}

static bool	hasDuplicatedSpecialTokens(std::string str)
{
	int	semicolon;
	int	openCurly;
	int closeCurly;

	semicolon = std::count(str.begin(), str.end(), ';');
	openCurly = std::count(str.begin(), str.end(), '{');
	closeCurly = std::count(str.begin(), str.end(), '}');
	
	if (semicolon + openCurly + closeCurly > 1)
		return (true);
	return (false);
}

static const char*	runOverSpaces(const char *str)
{
	while (*str && strchr(" \t\r\v\f", *str))
		str++;
	return (str);
}

static bool	isMissingTokens(std::string str)
{
	int semicolon;
	int	openCurly;
	int closeCurly;

	semicolon = std::count(str.begin(), str.end(), ';');
	openCurly = std::count(str.begin(), str.end(), '{');
	closeCurly = std::count(str.begin(), str.end(), '}');

	if (semicolon + openCurly + closeCurly == 0)
	{
		if (*runOverSpaces(str.c_str()) == 0)
			return (false);
		return (true);
	}
	return (false);
}

#endif