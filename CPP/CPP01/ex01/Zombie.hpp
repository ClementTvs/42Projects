/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers <ctravers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:26:18 by ctravers          #+#    #+#             */
/*   Updated: 2025/06/26 17:22:44 by ctravers         ###   ########.fr       */
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
	Zombie(); ///<  default Constructor
	~Zombie(); ///< Destructor
	/**
	 * @brief Make the zombie announce itself.
	 * 
	 */
	void announce( void );
	/**
	 * @brief Set the name of the zombie.
	 * 
	 * @param zomName The name of thje zombie.
	 */
	void setName(const std::string& zomName);
	/**
	 * @brief Get the name of the zombie.
	 * @return const reference to the zombie's name.
	 */
	const std::string& getZombieName(void) const;
	
private:
	std::string name;///< Name of the zombie
};

/**
 * @brief Create a horde of Zombies with the given name.
 * 
 * This function allocates an array of Zombies on the heap. Each Zombie in the array
 * is initialized with the given name using the setName() method.
 * 
 * @param N The number of zombies to create. If N <= 0, the function returns null.
 * @param name The name to assign to each zombie in the horde.
 * @return Zombie* A pointer to the first Zombie in the heap-allocated array, or nullptr if N <= 0.
 */
Zombie* zombieHorde( int N, std::string name );