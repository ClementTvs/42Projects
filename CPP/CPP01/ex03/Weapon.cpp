/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers <ctravers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:35:26 by ctravers          #+#    #+#             */
/*   Updated: 2025/06/27 13:43:15 by ctravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& type): type(type){}

Weapon::~Weapon(){}

const std::string& Weapon::getType(){
	return (type);
}

void Weapon::setType(const std::string& type){
	this->type = type;
}