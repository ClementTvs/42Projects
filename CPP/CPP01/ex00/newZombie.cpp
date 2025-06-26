/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers <ctravers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:59:58 by ctravers          #+#    #+#             */
/*   Updated: 2025/06/26 16:26:32 by ctravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief Create a zombie on the heap.
 * 
 * @param name The name of the zombie.
 * @return Zombie* The newly created zombie.
 */
Zombie* newZombie( std::string name ){
	Zombie* zombie = new Zombie(name);
	return (zombie);
}