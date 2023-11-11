/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:44:24 by blefebvr          #+#    #+#             */
/*   Updated: 2023/11/11 18:20:15 by root             ###   ########.fr       */
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

int const   &PmergeMe::getListValue(int idx)const
{
	std::list<int> tmpList;

	tmpList.assign(_lst.begin(), _lst.end());
	std::list<int>::iterator iter = tmpList.begin();
	while (idx--) 
		++iter;
	return *iter;
}

void	PmergeMe::setValueOfList(int idx, int value)
{
	std::list<int>::iterator iter = this->listData.begin();
  	while (idx--) 
  		++iter;
  	*iter = value;	
}

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
    // int s1 = middle - left + 1;
	// int s2 = right - middle;
	std::list<int> leftTab, rightTab;

	std::cout << "left= " << left << ", middle= " << middle << ", right= " << right << '\n';
	std::list<int>::iterator	it = _lst.begin();
	std::list<int>::iterator	ite1 = _lst.begin();
	std::list<int>::iterator	ite2 = _lst.begin();
	std::advance(ite1, middle + 1);
	while (it != _lst.end())
	{
		std::cout << *it << " ";
		++it;
	}
	it = _lst.begin();
	while (it != ite1)
	{
		leftTab.push_back(*it);
		//std::cout << "in leftTab, it = " << *it << '\n';
		++it;
	}
	std::advance(ite2, right + 1);
	std::cout << "value of it after filling of leftTab= " << *it << '\n';
    while (it != ite2)
	{
		rightTab.push_back(*it);
		//std::cout << "in rightTab, it = " << *it << '\n';
		++it;
	}
	std::list<int>::iterator	it1 = leftTab.begin();
	std::list<int>::iterator	it2 = rightTab.begin();
	it = leftTab.begin();
	std::advance(it, left);
    while (it1 != leftTab.end() && it2 != rightTab.end()) 
	{
		std::cout << "it1= " << *it1 << ", it2= " << *it2 << ", it= " << *it << '\n';
        if (*it1 <= *it2) 
		{
			*it = *it1;
            ++it1;
        } 
		else if (*it1 > *it2) 
		{
			*it = *it2;
            ++it2;
        }
		++it;
    }
    while (it1 != leftTab.end()) 
	{
        *it = *it1;
        ++it1;
		++it;
    }
    while (it2 != rightTab.end()) 
	{
        *it = *it2;
        ++it2;
		++it;
    }
}
 
void	PmergeMe::listMergeSort(int left, int right) 
{
    if (left < right) 
	{
        int middle = left +(right - left) / 2;
		std::cout << "middle = " << middle << '\n';
		listMerge(left, middle, right);
        listMergeSort(left, middle);
        listMergeSort(middle + 1, right);
		//listMerge(left, middle, right);
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
	std::cout << "before vectorMerge r= " << r << '\n';
	vectorMergeSort(0, r - 1);
	std::cout << "after vectorMerge r= " << r << '\n';
	listMergeSort(0, r - 1);
}