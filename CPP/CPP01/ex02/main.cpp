/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers <ctravers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:44:40 by ctravers          #+#    #+#             */
/*   Updated: 2025/06/27 11:14:48 by ctravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(){
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string& stringREF = string;

	std::cout << "Adress of the string:           " << &string << std::endl;
	std::cout << "Adress of the string pointer:   " << stringPTR << std::endl;
	std::cout << "Adress of the string reference: " << &stringREF << std::endl;
	std::cout << "The string value:               " << string << std::endl;
	std::cout << "The stringPTR value:            " << *stringPTR << std::endl;
	std::cout << "The stringREF value:            " << stringREF << std::endl;
}