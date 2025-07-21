/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers <ctravers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:31:41 by ctravers          #+#    #+#             */
/*   Updated: 2025/07/21 10:10:50 by ctravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av){
	Harl harl;
	
	if (ac == 2)
		harl.complain(av[1]);
	else
		std::cout << "Invalid input, please insert one arg (level)" << std::endl;
}