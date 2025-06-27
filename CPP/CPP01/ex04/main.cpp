/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers <ctravers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:59:35 by ctravers          #+#    #+#             */
/*   Updated: 2025/06/27 14:31:49 by ctravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int ac, char **av){
	if (ac != 4)
	{
		std::cout << "Please, enter: filename wordtoreplace word." << std::endl;
		return (0);
	}
	std::string fileName = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	std::ifstream file(fileName.c_str());
	std::string newFileName = fileName + ".replace";
	if (!file)
	{
		std::cout << "Please, enter a valid file to read from." << std::endl;
		return (0);
	}
	std::ofstream fileReplace(newFileName.c_str());
	std::string line;
	while (std::getline(file, line))
	{
		size_t pos = line.find(s1);
		if (pos != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
		}
		fileReplace << line << "\n";
	}
	file.close();
	return (0);
}