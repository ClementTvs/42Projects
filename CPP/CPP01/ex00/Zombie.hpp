/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers <ctravers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:26:18 by ctravers          #+#    #+#             */
/*   Updated: 2025/06/26 16:35:00 by ctravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

/**
 * @class Zombie
 * @brief Represent a Zombie that can announce itself
 * 
 * This class defines a simple Zombie with a name and the ability to announce itself.
 */
class Zombie {
public:
	Zombie( std::string zomName); ///< Constructor
	~Zombie(); ///< Destructor
	/**
	 * @brief Make the zombie announce itself.
	 * 
	 */
	void announce( void );
	
	/**
	 * @brief Get the name of the zombie.
	 * @return const reference to the zombie's name.
	 */
	const std::string& getZombieName(void) const;
	
private:
	std::string name;///< Name of the zombie
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );