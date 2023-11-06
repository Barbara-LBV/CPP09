/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:40:57 by blefebvr          #+#    #+#             */
/*   Updated: 2023/11/06 18:22:23 by blefebvr         ###   ########.fr       */
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
        std::stack<int>	*_stack;
		int				_res;

    public :
        RPN();
        RPN(RPN const &s);
        RPN &operator=(RPN const &s);
        ~RPN();

        void	checkInput(std::string content);
		void	fillStack(std::string input);
		int 	findNumber(std::string input);
		void 	operate(void);
		int		getRes(void)const;
		void	setRes(int nb);

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
std::ofstream &operator<<(std::ofstream &o, RPN &s);

#endif
