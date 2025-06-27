/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers <ctravers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:37:04 by ctravers          #+#    #+#             */
/*   Updated: 2025/06/27 15:13:47 by ctravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Harl {
	private:
		void debug ( void );
		void info ( void );
		void warning ( void );
		void error ( void );
	public:
		Harl();
		~Harl();
		void complain( std::string level );
};