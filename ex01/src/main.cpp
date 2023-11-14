/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:40:18 by blefebvr          #+#    #+#             */
/*   Updated: 2023/11/14 17:46:25 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << RED "Usage: <value>" DEFAULT << '\n';
		return(1);
	}
	std::string		input = av[1];
	if (input.empty() || input.size() < 3)
	{
		std::cerr << RED "Bad Input: argument empty or incomplete."  DEFAULT << '\n';
		return(2);
	}
	RPN		*R = new RPN();
	try
	{
		R->checkInput(input);
		R->operate(input);
		std::cout << *R << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete R;
	return (0);
}
