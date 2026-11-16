/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 22:56:39 by ismherna          #+#    #+#             */
/*   Updated: 2025/05/02 00:39:18 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

/*=================================INCLUDES==================================*/

#include <iomanip>
#include <iostream>

/*=================================COLORS===================================*/

#define RESET "\033[0m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

/*=================================CLASS====================================*/

class Fixed
{
	private:
		int					_value;
		static const int	_fract_bits = 8;
	public:
		Fixed();
		Fixed(const Fixed &ref);
		Fixed &operator=(const Fixed &ref);
		~Fixed();
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif