/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:40:18 by blefebvr          #+#    #+#             */
/*   Updated: 2023/10/25 17:40:44 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/RPN.hpp"

int main(int ac, char **av) // un doc sera lance en 2e arg
{
	if (ac != 2)
	{
		std::err << "Usage: <value>" << '\n';
		return(1);
	}
	

	return (0);
}