/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers <ctravers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:43:57 by ctravers          #+#    #+#             */
/*   Updated: 2025/07/21 10:10:08 by ctravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){}

Harl::~Harl(){}

void Harl::complain( std::string level ){
	if ( level != "DEBUG" && level != "INFO" && level != "WARNING" && level != "ERROR")
	{
		std::cout << "Invalid level." << std::endl;
		return ;
	}
	switch (level[0])
	{
		case 'D':
			debug();
		case 'I':
			info();
		case 'W':
			warning();
		case 'E':
			error();
			break ;
		default:
			std::cout << "Invalid level." << std::endl;
	}
}

void Harl::debug( void ){
	std::cout << "[DEBUG]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
			  << std::endl;
}

void Harl::info( void ){
	std::cout << "[INFO]\nI cannot believe adding extra bacon costs more money. You didn’t putenough bacon in my burger! If you did, I wouldn’t be asking for more!"
			  << std::endl;
}

void Harl::warning( void ){
	std::cout << "[WARNING]\nI think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month."
			  << std::endl;
}

void Harl::error( void ){
	std::cout << "[ERROR]\nThis is unacceptable! I want to speak to the manager now."
			  << std::endl;
}