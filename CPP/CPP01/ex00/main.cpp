/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers <ctravers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:03:26 by ctravers          #+#    #+#             */
/*   Updated: 2025/06/26 16:21:19 by ctravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(){
	Zombie* Alice = newZombie("Alice");
	
	Alice->announce();
	randomChump("Michel");
	delete (Alice);
	return (0);
}