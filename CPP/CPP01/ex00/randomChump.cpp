/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers <ctravers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:01:59 by ctravers          #+#    #+#             */
/*   Updated: 2025/06/26 16:28:06 by ctravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief Create a zombie on the stack and have it announce itself.
 * 
 * @param name The name of the zombie.
 */
void randomChump( std::string name ){
	 Zombie zombie(name);
	 zombie.announce();
}