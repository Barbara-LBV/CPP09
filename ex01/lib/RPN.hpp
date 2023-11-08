/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:40:57 by blefebvr          #+#    #+#             */
/*   Updated: 2023/11/08 14:00:10 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RNP_HPP
# define RNP_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <cstdlib>
#include <stack>

# define DEFAULT "\001\033[0;39m\002"
# define RED "\001\033[1;91m\002"
# define BLUE "\001\033[1;36m\002"

class iterator;

template <typename T>
class RPN : public std::stack<T>
{
	private :
        typedef typename std::stack<T>::container_type::iterator iterator;
		    iterator	begin(void);
		    iterator	end(void); 

		    int				      _res;
        std::string     _op;

    public :
        RPN();
        RPN(RPN const &s);
        RPN &operator=(RPN const &s);
        ~RPN();

        void	      checkInput(std::string content);
        std::string	fillStack(std::string input, RPN<T> &r);
        void 	      operate(std::string input, RPN<T> &r);
        void        operateRes(RPN<T> &r);
        int	        findRes(int n1, int n2);
        int		      const &getRes(void)const;
        void	      setRes(int nb);

    class BadInput : public std::exception
    {
      public:
        virtual const char* what() const throw()
          {
            return (RED "Error: Bad input" DEFAULT);
          }
    };
};

bool isSpecChar(char c);

template <typename T>
std::ofstream &operator<<(std::ofstream &o, RPN<T> &s);

#endif
