/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:41:37 by blefebvr          #+#    #+#             */
/*   Updated: 2023/11/09 10:44:41 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/RPN.hpp"

RPN::RPN()
{
	std::cout << BLUE "Default constructor -> called" DEFAULT << std::endl;
	_res = 0;
	_op = "";
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
	{
		_res =s._res;
		_op = s._op;
		_stack = s._stack;
	}
	return (*this);
}

RPN::~RPN()
{
	std::cout << BLUE "Destructor -> called" DEFAULT << std::endl;
}

std::ostream &operator<<(std::ostream &o, RPN &s)
{
	o << s.getRes();
	return (o);
}

int	const	&RPN::getRes(void)const
{
	return(_res);
}

void	RPN::setRes(int nb)
{
	_res = nb;
}

bool	isSpecChar(char c)
{
	if (c != '*' && c != '/' && c != '+' && c != '-')
		return false;
	return true;
}

void	RPN::checkInput(std::string str)
{
	std::string::iterator	it = str.begin();
	std::string::iterator	ite = str.end();
	int						flag1(0);
	if (*it == 32 || isSpecChar(*it))
		throw BadInput();
	while (it != ite)
	{
		if (!isdigit(*it) && *it != 32 && isSpecChar(*it) == false)
			throw BadInput();
		if (flag1 == 0 && (isdigit(*it) || isSpecChar(*it)))
			flag1 = 1;
		else if (flag1 == 1 && (isdigit(*it) || isSpecChar(*it)))
			flag1 = 2;
		else if (flag1 == 1 && *it == 32)
			flag1 = 0;
		else if (flag1 == 0 && *it == 32)
			flag1 = 1;
		if (it+1 != ite && isdigit(*it) && isdigit(*(it+1)))
			throw BadInput();
		++it;
	}
	if (flag1 != 1)
		throw BadInput();
}

std::string	RPN::fillStack(std::string input)
{
	int			nb;
	size_t		i(0);
	std::string tmp;
	
	for (; i < input.size(); i++)
	{
		if (isdigit(input[i]))
		{
			tmp.push_back(input[i]);
			nb = atoi(tmp.c_str());
			_stack.push(nb);
			tmp.erase(0);
		}
		else if (isSpecChar(input[i]))
		{
			_op = input[i];
			input.erase(0, ++i);
			break ;
		}
	}
	if (_op.size() == 0)
		throw CantOperate();
	return (input);
}

void 	RPN::operate(std::string input)
{
	size_t i(0);
	
	for (; i < input.size(); i++)
	{
		if (input.size() == 0)
			break ;
		input = fillStack(input);
		operateRes();
		i = 0;
		_op = "";
	}
}

int	RPN::findRes(int n1, int n2)
{
	int		res;
	size_t	i;
	std::string tab[] = {"+", "-", "*", "/"};

	for(i = 0; i < 4; i++)
	{
		if (tab[i] == _op)
			break ;
	}
	switch (i)
	{
		case 0:
			res = n2 + n1;
			break;
		case 1:
			res = n2 - n1;
			break;
		case 2:
			res = n2 * n1;
			break;
		case 3:
			res = n2 / n1;
			break;
	}
	setRes(res);
	return(res);
}

void	RPN::operateRes(void)
{
	int	res, n1, n2;
	
	n1 = _stack.top();
	_stack.pop();
	n2 = _stack.top();
	_stack.pop();
	res = findRes(n1, n2);
	_stack.push(res);
}