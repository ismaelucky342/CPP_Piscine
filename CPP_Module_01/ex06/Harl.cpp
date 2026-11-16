/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:46:36 by ismherna          #+#    #+#             */
/*   Updated: 2024/09/14 22:38:33 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{}

Harl::~Harl()
{}

void	Harl::debug()
{
	std::cout	<< "[ DEBUG ]" << std::endl
				<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!"
				<<	std::endl << std::endl;
}

void	Harl::info()
{
	std::cout	<< "[ INFO ]" << std::endl
				<< "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"
				<<	std::endl << std::endl;
}

void	Harl::warning()
{
	std::cout	<< "[ WARNING ]" << std::endl
				<< "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month."
				<<	std::endl << std::endl;
}

void	Harl::error()
{
	std::cout	<< "[ ERROR ]" << std::endl
				<< "This is unacceptable! I want to speak to the manager now."
				<<	std::endl << std::endl;
}

static void	insignificant_error()
{
	std::cout	<< "[ Probably complaining about insignificant problems ]"
				<<	std::endl;
}

void	Harl::complain(std::string level)
{
	t_harl	commands[4] = {
		{"DEBUG", &Harl::debug},
		{"INFO", &Harl::info},
		{"WARNING", &Harl::warning},
		{"ERROR", &Harl::error}
	};
	
	for (size_t i = 0; i < 4; i++)
	{
		if (level == commands[i].text)
		{
			for (size_t j = i; j < 4; j++)
				(this->*commands[j].func)();
			return;
		}
	}
	insignificant_error();
}