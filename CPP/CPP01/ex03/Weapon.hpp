/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers <ctravers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:18:17 by ctravers          #+#    #+#             */
/*   Updated: 2025/06/27 12:07:36 by ctravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Weapon
{
	private:
		std::string type;

	public:
		Weapon(const std::string& type);
		~Weapon();
		const std::string& getType();
		void setType(const std::string& type);
};
