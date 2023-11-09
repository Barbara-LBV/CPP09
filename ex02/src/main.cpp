/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:43:40 by blefebvr          #+#    #+#             */
/*   Updated: 2023/11/09 18:11:31 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*use the Ford-Johnson algorithm.*/

#include "../lib/PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Usage: <value>" << '\n';
		return(1);
	}
	if (ac == 2)
	{
		std::cerr << "Bad Input: not enough numbers to sort." << '\n';
		return(2);
	}
	//if (ac > 3001)
	//{
	//	std::cerr << "Bad Input: not enough numbers to sort." << '\n';
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
		//std::cout << *P << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete P;
	return (0);
}
