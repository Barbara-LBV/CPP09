/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:44:24 by blefebvr          #+#    #+#             */
/*   Updated: 2023/11/08 18:07:57 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	std::cout << BLUE "Default constructor -> called" DEFAULT << std::endl;
	_vTime = 0;
	_lTime = 0;
	_nElement = 0;
}

PmergeMe::PmergeMe(PmergeMe const &p)
{
	std::cout << BLUE "Copy constructor -> called" DEFAULT << std::endl;
	*this = p;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &p)
{
	std::cout << BLUE "Assignment operator -> called" DEFAULT << std::endl;
	if (this != &p)
	{
		_vect = p._vect;
		_lst = p._lst;
		_vTime = p._vTime;
		_lTime = p._lTime;
		_nElement = p._nElement;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
	std::cout << BLUE "Destructor -> called" DEFAULT << std::endl;
}

std::ostream &operator<<(std::ostream &o, PmergeMe &p)
{
	o << " Time to process a range of " << p.getTimeV()
	  << " elements with std::vector :" << p.getTimeV() 
	  << "us \n"
	  << " Time to process a range of " << p.getTimeL()
	  << " elements with std::list :" << p.getTimeL() 
	  << "us" << std::endl;
	return (o);
}

