/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:44:24 by blefebvr          #+#    #+#             */
/*   Updated: 2023/11/10 17:52:53 by blefebvr         ###   ########.fr       */
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
	//std::cout << "****** Vector ******" << std::endl;
	//std::vector<int>::const_iterator	it = _vect.begin();
	//while (it != _vect.end())
	//{
	//	std::cout << *it << " ";
	//	++it;
	//}
	//std::cout <<std::endl;
	
	std::cout << "****** List ******" << std::endl;
	std::list<int>::const_iterator it1 = _lst.begin();
	while (it1 != _lst.end())
	{
		std::cout << *it1 << " ";
		++it1;
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
       	vectorMerge(left, middle, right );
	    vectorMergeSort(left, middle);
        vectorMergeSort(middle + 1, right);
		vectorMerge(left, middle, right );
    }
}

void	PmergeMe::listMerge(int left, int middle, int right) //a adapter en list
{
    int s1 = middle - left + 1;
	int s2 = right - middle;
	std::list<int> leftTab, rightTab;

	for (int i = 0; i < s1; i++)
		leftTab.push_back(_unsortedVect[left + i]);
    for (int j = 0; j < s2; j++)
		rightTab.push_back(_unsortedVect[middle + 1 + j]);
	std::list<int>::const_iterator	it = _lst.begin() + left;
	std::list<int>::const_iterator	it1 = leftTab.begin();
	std::list<int>::const_iterator	it2 = rightTab.begin();
	
    while (it1 != leftTab.end() && it2 != rightTab.end()) 
	{
        if (*it1 <= *it2) 
		{
            _lst.insert(it, *it1);
            ++it1;
        } 
		else 
		{
            _lst.push_back(*it2);
            ++it2;
        }
		++it;
    }
    while (it1 != leftTab.end()) 
	{
        _lst.push_back(*it1);
        ++it1;
		left++;
    }
    while (it2 != rightTab.end()) 
	{
        _lst.push_back(*it2);
        ++it2;
		left++;
    }
}
 
void	PmergeMe::listMergeSort(int left, int right) 
{
    if (left < right) 
	{
        int middle = left +(right - left) / 2;
		listMerge(left, middle, right);
        listMergeSort(left, middle);
        listMergeSort(middle + 1, right);
		listMerge(left, middle, right);
    }
}

void	PmergeMe::merge(void)
{
	int r = _nElement;
	std::vector<int>	tmp = _unsortedVect;
	for (size_t i = 0; i < _unsortedVect.size(); i++)
	{
		_vect.push_back(_unsortedVect[i]);
		_lst.push_back(_unsortedVect[i]);
	}
	vectorMergeSort(0, r - 1);
	listMergeSort(0, r - 1);
}