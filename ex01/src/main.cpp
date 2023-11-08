/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:40:18 by blefebvr          #+#    #+#             */
/*   Updated: 2023/11/08 14:43:15 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: <value>" << '\n';
		return(1);
	}
	std::string		input = av[1];
	if (input.empty() || input.size() < 5)
	{
		std::cerr << "Bad Input: argument empty or too short to operate." << '\n';
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
