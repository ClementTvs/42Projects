/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers <ctravers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:24:57 by ctravers          #+#    #+#             */
/*   Updated: 2025/06/26 16:33:43 by ctravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


Zombie::Zombie( std::string zomName ){
	name = zomName;
}

Zombie::~Zombie(){
	std::cout << name << " has been destroyed" << std::endl;
}

void Zombie::announce( void ){
	std::string zombieName;

	zombieName = getZombieName();
	std::cout << zombieName << ":"
			  << " BraiiiiiiinnnzzzZ..." << std::endl;
}


const std::string& Zombie::getZombieName() const {
	return (name);
}