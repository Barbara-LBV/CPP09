/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:40:18 by blefebvr          #+#    #+#             */
/*   Updated: 2023/11/06 18:03:43 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/RPN.hpp"

int main(int ac, char **av) // un doc sera lance en 2e arg
{
	if (ac != 2)
	{
		std::cerr << "Usage: <value>" << '\n';
		return(1);
	}
	std::string		input = av[1];
	RPN				*R = new RPN();
	
	try
	{
		R->checkInput(input);
		R->operate();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	delete R;
	return (0);
}