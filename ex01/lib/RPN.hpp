/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:40:57 by blefebvr          #+#    #+#             */
/*   Updated: 2023/11/09 10:47:30 by blefebvr         ###   ########.fr       */
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

class RPN
{
	private :
		    int				      _res;
        std::string     _op;
        std::stack<int> _stack;

    public :
        RPN();
        RPN(RPN const &s);
        RPN &operator=(RPN const &s);
        ~RPN();

        void	      checkInput(std::string content);
        std::string	fillStack(std::string input);
        void 	      operate(std::string input);
        void        operateRes(void);
        int	        findRes(int n1, int n2);
        int const   &getRes(void)const;
        void	      setRes(int nb);

    class BadInput : public std::exception
    {
      public:
        virtual const char* what() const throw()
          {
            return (RED "Error: Bad input" DEFAULT);
          }
    };
    class CantOperate : public std::exception
    {
      public:
        virtual const char* what() const throw()
          {
            return (RED "Error: not enough operand to finish operation" DEFAULT);
          }
    };
};

bool isSpecChar(char c);

std::ostream &operator<<(std::ostream &o, RPN &s);

#endif
