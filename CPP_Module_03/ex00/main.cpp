/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:14:02 by ismherna          #+#    #+#             */
/*   Updated: 2024/09/14 23:14:03 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap joe("Joe");
	ClapTrap foe("Foe");
	ClapTrap toe;

	toe = ClapTrap("Toe");

	joe.attack("Foe");
	foe.takeDamage(2);

	foe.beRepaired(10);

	toe.attack("Joe");
	joe.takeDamage(4);

	
	joe.attack("Toe");
	toe.takeDamage(2);

	foe.attack("Joe");
	joe.takeDamage(3);
}