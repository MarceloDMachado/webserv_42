/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SyntaxChecker.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:18:41 by madias-m          #+#    #+#             */
/*   Updated: 2025/07/21 12:22:18 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYNTAXCHECKER__HPP
# define SYNTAXCHECKER__HPP

# include <string>
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
static void	check(std::map<KeyType, std::string> &target, bool (*checker)(std::string))
{
	std::vector<KeyType>	keys = getMapKeysGeneric(target);
	
	typename std::vector<KeyType>::const_iterator it;
	for (it = keys.begin(); it != keys.end(); ++it)
	{
		if (checker(target[*it]))
			Harl("Invalid Syntax on", ERROR).complain();
	}
}

static bool	checkDuplicatedSpecialTokens(std::string str)
{
	int	semicolon;
	int	openCurly;
	int closeCurly;

	semicolon = std::count(str.begin(), str.end(), ';');
	openCurly = std::count(str.begin(), str.end(), '{');
	closeCurly = std::count(str.begin(), str.end(), '}');

	if (semicolon + openCurly + closeCurly > 1)
	{
		return (true);
	}
	return (false);
}

#endif