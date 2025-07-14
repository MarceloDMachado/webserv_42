/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileHandler.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:11:02 by madias-m          #+#    #+#             */
/*   Updated: 2025/07/14 16:03:31 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEHANDLER__HPP
# define FILEHANDLER__HPP

#include <fstream>
#include <cstring>
#include <map>
#include "Harl.hpp"

class FileHandler
{
	private:
		std::string					_path;
		std::fstream				_file;
		std::map<int, std::string>	_lineByNumberMap;
		void						readFile(void);
	public:
		FileHandler(void);
		FileHandler(std::string path);
		FileHandler(const FileHandler& other);
		FileHandler&	operator=(const FileHandler& other);
		~FileHandler(void);
		std::map<int, std::string>	getContent(void) const;
		void						openFile(void);
		void						setPath(std::string path);
};

#endif
