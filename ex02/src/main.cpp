/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:43:40 by blefebvr          #+#    #+#             */
/*   Updated: 2023/11/13 18:20:47 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*use the Ford-Johnson algorithm.*/

#include "../lib/PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << RED "Usage: <value>" DEFAULT << '\n';
		return(1);
	}
	if (ac == 2)
	{
		std::cerr << RED "Bad Input: not enough numbers to sort." DEFAULT << '\n';
		return(2);
	}
	//if (ac > 3000)
	//{
	//	std::cerr << "Bad Input: too much numbers." << '\n';
	//	return(3);
	//}
	std::string		input = av[1];
	if (input.empty() || input.size() < 1)
	{
		std::cerr << "Bad Input: argument empty or too short to operate." << '\n';
		return(2);
	}
	PmergeMe		*P = new PmergeMe();
	try
	{
		P->checkInput(ac, av);
		P->merge();
		P->printAll();
		std::cout << *P;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete P;
	return (0);
}
