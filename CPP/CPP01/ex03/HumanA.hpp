/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers <ctravers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:24:09 by ctravers          #+#    #+#             */
/*   Updated: 2025/06/27 12:09:40 by ctravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Weapon.hpp"

class HumanA{
	private:
		std::string name;
		Weapon &weapon;
	public:
		HumanA(const std::string& name, Weapon& type);
		~HumanA();
		void attack( void );
};