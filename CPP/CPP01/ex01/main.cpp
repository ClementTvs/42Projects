/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers <ctravers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:03:26 by ctravers          #+#    #+#             */
/*   Updated: 2025/06/26 17:24:24 by ctravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(){
	int	hordeSize = 10;
	
	Zombie* horde = zombieHorde(hordeSize, "Alice");
	
	for (int i = 0; i < hordeSize; i++)
	{
		horde[i].announce();
	}

	delete[] horde;
	return (0);
}