/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:41:37 by blefebvr          #+#    #+#             */
/*   Updated: 2023/11/06 18:21:39 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/RPN.hpp"

RPN::RPN()
{
	std::cout << BLUE "Default constructor -> called" DEFAULT << std::endl;
	_stack = NULL;
	_res = 0;
}

RPN::RPN(RPN const &s)
{
	std::cout << BLUE "Copy constructor -> called" DEFAULT << std::endl;
	*this = s;
}

RPN &RPN::operator=(RPN const &s)
{
	std::cout << BLUE "Assignment operator -> called" DEFAULT << std::endl;
	if (this != &s)
		_stack = s._stack;
	return (*this);
}

RPN::~RPN()
{
	std::cout << BLUE "Destructor -> called" DEFAULT << std::endl;
}

std::ostream &operator<<( std::ostream &o, RPN &s)
{
	o << s.getRes();
	return (o);
}

int		RPN::getRes(void)const
{
	return(_res);
}

void	RPN::setRes(int nb)
{
	_res = nb;
}

bool	isSpecChar(char c)
{
	if (c != '*' && c != '/' && c != ' ' && c != '+' && c != '-')
		return false;
	return true;
}

void	RPN::checkInput(std::string str)
{
	std::string::iterator it = str.begin();
	while (it != str.end())
	{
		if (!isdigit(*it) && isSpecChar(*it) == false)
			throw BadInput();
		it++;
	}
}

int 	RPN::findNumber(std::string input)
{
	int 	nb(0);
	/**/
	return (nb);
}

void	RPN::fillStack(std::string input)
{
	findNumber();
	/**/
}

void 	RPN::operate(std::string input)
{
	fillStack(input);
	/**/
	
}

