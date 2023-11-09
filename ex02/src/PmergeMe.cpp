/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:44:24 by blefebvr          #+#    #+#             */
/*   Updated: 2023/11/09 19:07:07 by blefebvr         ###   ########.fr       */
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

//std::ostream &operator<<(std::ostream &o, PmergeMe &p)
//{
//	o << " Time to process a range of " << p.getTimeL()
//	  << " elements with std::list :" << p.getTimeL() 
//	  << "us" << std::endl;
//	return (o);
//}

//float const &PmergeMe::getTimeV(void)const
//{
	
//}

//float const &PmergeMe::getTimeL(void)const
//{
	
//}

//int	const   &PmergeMe::getElement(void)const
//{
	
//}

//int const   &PmergeMe::getListValue(std::list<int> l, int idx)const
//{
	
//}

//void	PmergeMe::setValueOfList(int idx, int value)
//{
			
//}

void	PmergeMe::checkInput(int ac, char **av)
{
	std::string	s;
	
	for (int i = 1; i < ac; i++)
	{
		s = av[i];
		std::size_t found = s.find_first_not_of("0123456789");
		if (found != std::string::npos)
			throw BadInput();
	}
	for (int i = 1; i < ac; i++)
		_unsortedVect.push_back(static_cast<unsigned int>(strtod(av[i], NULL)));
	_nElement = ac - 1;
}

void	PmergeMe::printSortedNb(void)const
{
	std::vector<int>::const_iterator	it = _vect.begin();
	
	std::cout << "Vector : " << std::endl;
	while (it != _vect.end())
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout <<std::endl;
	it = _vect.begin();
	
	std::cout << "List : " << std::endl;
	while (it != _vect.end())
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout <<std::endl;
}

void	PmergeMe::printUnsortedNb(void)const
{
	std::vector<int>::const_iterator	it = _unsortedVect.begin();
	
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
	std::cout << "After: ";
	printSortedNb();
}

void	PmergeMe::vectorMerge(int left, int middle, int right) //a adapter en vector
{
	//l, m et r sont des indices qui delimitent les 2 sous-tab
	//m = middle(idx de coupe du 1e tab), l = left(debut), r = right(fin)
    int s1 = middle - left + 1; // n1 & n2 -> taille des sous-tab
    int s2 = right - middle;
    std::vector<int> 	leftTab(s1), rightTab(s2);
	
	for (int i = 0; i < s1; i++)
		leftTab[i] = _unsortedVect[left + i];
	for (int j = 0 ; j < s2; j++)
		rightTab[j] = _unsortedVect[middle + 1 + j];
		
	std::vector<int>::const_iterator	it1 = leftTab.begin();
	std::vector<int>::const_iterator	it2 = rightTab.begin();
    while (it1 != leftTab.end() && it2 != rightTab.end()) 
	{
        if (*it1 <= *it2) 
		{
            _vect.push_back(*it1);
            ++it1;
        } 
		else 
		{
            _vect.push_back(*it2);
            ++it2;
        }
    }
    while (it1 != leftTab.end()) 
	{
        _vect.push_back(*it1);
        ++it1;
    }
    while (it2 != rightTab.end()) 
	{
        _vect.push_back(*it2);
        ++it2;
    }
}
 
void	PmergeMe::vectorMergeSort(int left, int right) 
{
    if (left < right) 
	{
        int middle = left +(right - left)/2;
        vectorMergeSort(left, middle);
        vectorMergeSort(middle + 1, right);
        vectorMerge(left, middle, right );
    }
}

void	PmergeMe::listMerge(int left, int middle, int right) //a adapter en list
{
    int s1 = right - middle;

	std::list<int> leftTab(_unsortedVect.begin() + left, _unsortedVect.begin() + middle + 1);
    std::list<int> rightTab(_unsortedVect.begin() + middle + 1, _unsortedVect.begin() + middle + 1 + s1);

	//std::vector<int>::const_iterator	it = _unsortedVect.begin() + left;
	std::list<int>::const_iterator		it1 = leftTab.begin();
	std::list<int>::const_iterator		it2 = rightTab.begin();
	
    while (it1 != leftTab.end() && it2 != rightTab.end()) 
	{
        if (*it1 <= *it2) 
		{
            _lst.push_back(*it1);
            ++it1;
        } 
		else 
		{
            _lst.push_back(*it2);
            ++it2;
        }
    }
    while (it1 != leftTab.end()) 
	{
        _lst.push_back(*it1);
        ++it1;
    }
    while (it2 != rightTab.end()) 
	{
        _lst.push_back(*it2);
        ++it2;
    }
}
 
void	PmergeMe::listMergeSort(int left, int right) 
{
    if (left < right) 
	{
        int middle = left +(right - left)/2;
        listMergeSort(left, middle);
        listMergeSort(middle + 1, right);
        listMerge(left, middle, right );
    }
}

void	PmergeMe::merge(void)
{
	int	l, r;
	
	l = 0;
	r = _nElement;
	vectorMergeSort(l, r);
	listMergeSort(l, r);
}