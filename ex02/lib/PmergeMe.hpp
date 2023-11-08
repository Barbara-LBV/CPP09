/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:45:07 by blefebvr          #+#    #+#             */
/*   Updated: 2023/11/08 18:08:25 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <list>

# define DEFAULT "\001\033[0;39m\002"
# define BOLD "\001\033[1;89m\002"
# define RED "\001\033[1;91m\002"
# define BLUE "\001\033[1;36m\002"
# define YELLOW "\001\033[1;93m\002"

class PmergeMe
{
	private :
        std::vector<int>  	_vect;
		std::list<int>		_lst;
		float				_vTime;
		float				_lTime;
		size_t				_nElement;

    public :
        PmergeMe();
        PmergeMe(PmergeMe const &p);
        PmergeMe &operator=(PmergeMe const &p);
        ~PmergeMe();

		float	const &getTimeV(void)const;
		float	const &getTimeL(void)const;
		float	const &getElement(void)const;
		
    class BadInput : public std::exception
    {
      public:
        virtual const char* what() const throw()
          {
            return ("Bad input");
          }
    };
};

std::ostream &operator<<(std::ostream &o, PmergeMe &p);

#endif
