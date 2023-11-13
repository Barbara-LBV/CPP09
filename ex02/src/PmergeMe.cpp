/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:44:24 by blefebvr          #+#    #+#             */
/*   Updated: 2023/11/13 18:36:27 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	std::cout << BLUE "Default constructor -> called" DEFAULT << std::endl;
	_vTime = 0;
	_dTime = 0;
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
		_deque = p._deque;
		_vTime = p._vTime;
		_dTime = p._dTime;
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
	o << "Time to process a range of " << p.getElement()
	  << " elements with std::vector: " << p.getTimeV() 
	  << " us" << std::endl
	  << "Time to process a range of " << p.getElement()
	  << " elements with std::deque: " << p.getTimeD() 
	  << " us" << std::endl;
	return (o);
}

float const &PmergeMe::getTimeV(void)const
{
	return (_vTime);
}

float const &PmergeMe::getTimeD(void)const
{
	return (_dTime);
}

size_t const &PmergeMe::getElement(void)const
{
	return (_nElement);
}

void	PmergeMe::checkInput(int ac, char **av)
{
	std::string		s;
	unsigned int	nb;
	
	for (int i = 1; i < ac; i++)
	{
		s = av[i];
		std::size_t found = s.find_first_not_of("0123456789");
		if (found != std::string::npos || s.size() > 10)
			throw BadInput();
		if ((s.size() >= 10 && s[0] > '4') || (s.size() == 10 && s[0] == '4' && s[1] >= '2'))
			throw BadInput();
	}
	for (int i = 1; i < ac; i++)
	{
		nb = static_cast<unsigned int>(strtod(av[i], NULL));
		if (nb > INT_MAX)
			throw BadInput();
		_unsortedVect.push_back(nb);
	}
	_nElement = ac - 1;
}

void	PmergeMe::printSortedNb(void)const
{
	std::cout << "****** Vector ******" << std::endl;
	std::vector<unsigned int>::const_iterator	it = _vect.begin();
	while (it != _vect.end())
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout <<std::endl;
	
	std::cout << "****** Deque ******" << std::endl;
	for (size_t i = 0; i < _deque.size(); i++)
	{
		std::cout << _deque[i] << " ";
	}
	std::cout <<std::endl;
}

void	PmergeMe::printUnsortedNb(void)const
{
	std::vector<unsigned int>::const_iterator	it = _unsortedVect.begin();
	
	while (it != _unsortedVect.end())
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout <<std::endl;
}

void	PmergeMe::printAll(void)
{
	std::cout << "Before: ";
	printUnsortedNb();
	std::cout << "After: " << '\n';
	printSortedNb();
}

void	PmergeMe::vectorMerge(int left, int middle, int right)
{
	int s1 = middle - left + 1;
    int s2 = right - middle;
	int i , j, k;
    std::vector<int> leftTab, rightTab;

    for (i = 0; i < s1; ++i)
		leftTab.push_back(_vect[left + i]);
    for (j = 0; j < s2; ++j)
		rightTab.push_back(_vect[middle + 1 + j]);
    i = 0, j = 0, k = left;
    while (i < s1 && j < s2)
    {
        if (leftTab[i] <= rightTab[j])
            _vect[k++] = leftTab[i++];
        else if (leftTab[i] > rightTab[j])
            _vect[k++] = rightTab[j++];
    }
    while (i < s1)
        _vect[k++] = leftTab[i++];
    while (j < s2)
        _vect[k++] = rightTab[j++];
}
 
void	PmergeMe::vectorMergeSort(int left, int right) 
{
    if (left < right) 
	{
        int middle = left +(right - left) / 2;
	    vectorMergeSort(left, middle);
        vectorMergeSort(middle + 1, right);
		vectorMerge(left, middle, right );
    }
}

void	PmergeMe::dequeMerge(int left, int middle, int right)
{
	int s1 = middle - left + 1;
    int s2 = right - middle;
	int i , j, k;
    std::deque<int> leftTab, rightTab;

    for (i = 0; i < s1; ++i)
		leftTab.push_back(_deque[left + i]);
    for (j = 0; j < s2; ++j)
		rightTab.push_back(_deque[middle + 1 + j]);
    i = 0, j = 0, k = left;
    while (i < s1 && j < s2)
    {
        if (leftTab[i] <= rightTab[j])
            _deque[k++] = leftTab[i++];
        else if (leftTab[i] > rightTab[j])
            _deque[k++] = rightTab[j++];
    }
    while (i < s1)
        _deque[k++] = leftTab[i++];
    while (j < s2)
        _deque[k++] = rightTab[j++];
}
 
void	PmergeMe::dequeMergeSort(int left, int right) 
{
    if (left < right) 
	{
        int middle = left +(right - left) / 2;
	    dequeMergeSort(left, middle);
        dequeMergeSort(middle + 1, right);
		dequeMerge(left, middle, right );
    }
}

void	PmergeMe::merge(void)
{
	int r = _nElement;
	std::vector<unsigned int>	tmp = _unsortedVect;
	for (size_t i = 0; i < _unsortedVect.size(); i++)
	{
		_vect.push_back(_unsortedVect[i]);
		_deque.push_back(_unsortedVect[i]);
	}
	const std::clock_t c_start1 = std::clock();
	vectorMergeSort(0, r - 1);
	const std::clock_t c_end1 = std::clock();
	_vTime = 1000.0 * (c_end1 - c_start1) / CLOCKS_PER_SEC;
	const std::clock_t c_start2 = std::clock();
	dequeMergeSort(0, r - 1);
	const std::clock_t c_end2 = std::clock();
	_dTime = 1000.0 * (c_end2 - c_start2) / CLOCKS_PER_SEC;
}
