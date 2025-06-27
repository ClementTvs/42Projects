/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers <ctravers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:33:49 by ctravers          #+#    #+#             */
/*   Updated: 2025/06/27 12:06:18 by ctravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon): name(name),weapon(weapon){}

HumanA::~HumanA(){}

void HumanA::attack(){
	std::cout << name
			  << " attacks with their "
			  << weapon.getType() << std::endl;
}