/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:43:40 by blefebvr          #+#    #+#             */
/*   Updated: 2023/11/14 11:42:43 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/PmergeMe.hpp"

int main(int ac, char **av)
{
	PmergeMe	*P = NULL;
	try
	{
		P = new PmergeMe();
		P->checkInput(ac, av);
		P->checkArguments(ac, av);
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
