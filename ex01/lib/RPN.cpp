/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:41:37 by blefebvr          #+#    #+#             */
/*   Updated: 2023/11/07 18:02:09 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

template<typename T>
RPN<T>::RPN()
{
	std::cout << BLUE "Default constructor -> called" DEFAULT << std::endl;
	_res = 0;
	_op = '\0';
}

template<typename T>
RPN<T>::RPN(RPN const &s)
{
	std::cout << BLUE "Copy constructor -> called" DEFAULT << std::endl;
	*this = s;
}

template<typename T>
RPN<T> &RPN<T>::operator=(RPN<T> const &s)
{
	std::cout << BLUE "Assignment operator -> called" DEFAULT << std::endl;
	if (this != &s)
	{
		_res =s._res;
		_op = s._op;
	}
	return (*this);
}

template<typename T>
RPN<T>::~RPN()
{
	std::cout << BLUE "Destructor -> called" DEFAULT << std::endl;
}

template<typename T>
std::ostream &operator<<(std::ostream &o, RPN<T> &s)
{
	o << s.getRes();
	return (o);
}

template<typename T>
int	const	&RPN<T>::getRes(void)const
{
	return(_res);
}

template<typename T>
void	RPN<T>::setRes(int nb)
{
	_res = nb;
}

bool	isSpecChar(char c)
{
	if (c != '*' && c != '/' && c != '+' && c != '-')
		return false;
	return true;
}

template<typename T>
void	RPN<T>::checkInput(std::string str)
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
		if (isdigit(*(it-1)) && isdigit(*it))
			throw BadInput();
		++it;
	}
	if (flag1 != 1)
		throw BadInput();
}

template<typename T>
std::string	RPN<T>::fillStack(std::string input, RPN<T> &r)
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
			r.push(nb);
			tmp.erase(0);
			std::cout << r.top() << std::endl; //a enlever
		}
		else if (isSpecChar(input[i]))
		{
			_op = input[i];
			std::cout << "op= "<< _op << std::endl; //a enlever
			input.erase(0, ++i);
			break ;
		}
	}
	std::cout << "new input= "<< input << std::endl; // a enlever
	return (input);
}

template<typename T>
void 	RPN<T>::operate(std::string input, RPN<T> &r)
{
	size_t i(0);
	
	for (; i < input.size(); i++)
	{
		if (input.size() == 0)
			break ;
		input = fillStack(input, r);
		_res = operateNb(r);
		i = 0;
	}
}

template<typename T>
int	RPN<T>::operateNb(RPN<T> &r) // a completer
{
	int	nb(0);
	(void)r;
	return(nb);
}