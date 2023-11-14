/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:45:07 by blefebvr          #+#    #+#             */
/*   Updated: 2023/11/14 17:55:05 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <vector>
#include <deque>
#include <list>
#include <ctime>
#include <limits.h>

# define DEFAULT "\001\033[0;39m\002"
# define BOLD "\001\033[1;89m\002"
# define RED "\001\033[1;91m\002"
# define BLUE "\001\033[1;36m\002"
# define YELLOW "\001\033[1;93m\002"

class PmergeMe
{
	private :
        std::vector<unsigned int> _unsortedVect;
        std::vector<unsigned int> _vect;
        std::deque<unsigned int> 	_deque;
        float				              _vTime;
        float				              _dTime;
        size_t				            _nElement;

    public :
        PmergeMe();
        PmergeMe(PmergeMe const &p);
        PmergeMe &operator=(PmergeMe const &p);
        ~PmergeMe();

        float	const     &getTimeV(void)const;
        float	const     &getTimeD(void)const;
        size_t	const   &getElement(void)const;
        void	          checkArguments(int ac, char **av);
        void	          checkInput(int ac, char **av);
        void            vectorMerge(int l, int m, int r);
        void            vectorMergeSort(int l, int r);
        void            dequeMerge(int l, int m, int r);
        void            dequeMergeSort(int l, int r);
        void            merge(void);
        void            printSortedNb(void)const;
        void            printUnsortedNb(void)const;
        void	          printAll(void);
  
    class BadUsage : public std::exception
    {
      public:
        virtual const char* what() const throw()
          {
            return (RED "Usage: <value>" DEFAULT);
          }
    };
    class NotEnoughNb : public std::exception
    {
      public:
        virtual const char* what() const throw()
          {
            return (RED "Error: not enough arguments." DEFAULT);
          }
    };
    class EmptyArgments : public std::exception
    {
      public:
        virtual const char* what() const throw()
          {
            return (RED "Error: argument empty or too short to operate." DEFAULT);
          }
    };
    class BadInput : public std::exception
    {
      public:
        virtual const char* what() const throw()
          {
            return (RED "Bad input" DEFAULT);
          }
    };
};

std::ostream &operator<<(std::ostream &o, PmergeMe &p);

#endif
