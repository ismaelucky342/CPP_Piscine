/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:06:58 by ismherna          #+#    #+#             */
/*   Updated: 2026/11/03 18:53:33 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

/*===============================INCLUDES===================================*/

#include <vector>
#include <list>
#include <deque>
#include <iostream>
#include <stddef.h>
#include <string>
#include <algorithm>
#include <exception>
#include <cassert>

/*=================================COLORS=======================================*/

# define RESET "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"

/*=================================FUNCTIONS=====================================*/

template <typename T>
int easyfind(T &conteiner, int target);
void test_find_should_return_target();
void test_find_should_return_exception();
void test_find_then_src_null_should_return_exception();

#include "easyfind.tpp"

#endif