/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitCoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:42:29 by blefebvr          #+#    #+#             */
/*   Updated: 2023/11/02 16:39:46 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/BitCoinExchange.hpp"

BitCoin::BitCoin()
{
	std::cout << BLUE "Default constructor -> called" DEFAULT << std::endl;
}

BitCoin::BitCoin(BitCoin const &b)
{
	std::cout << BLUE "Copy constructor -> called" DEFAULT << std::endl;
	*this = b;
}

BitCoin &BitCoin::operator=(BitCoin const &b)
{
	std::cout << BLUE "Assignement opertor -> called" DEFAULT << std::endl;
	if (this != &b)
		_map = b._map;
	return (*this);
}

BitCoin::~BitCoin()
{
	std::cout << BLUE "Destructor -> called" DEFAULT << std::endl;
}

// std::ostream &operator<<( std::ostream &o, BitCoin &b)
// {
// 	o << b.getDate() << " | "   // a ne suffira sans doute pas a recuperer la valeur "date" au bon node de map
// 	  << b.getRate() << " => " // idem => utiliser les iterateurs !
// 	  << b.getRes() << std::endl;
// 	return (o);
// }

// char*	BitCoin::findRate(std::string line)
// {
// 	char	*nb = NULL;
// 	size_t	size;

// 	for(size_t i = 10; i < line.size(); i++)
// 	{
// 		size = line.size() - 10;
// 		if (line[i] >= '0' && line[i] <= '9')
// 		{
// 			line.copy(nb, size, i);
// 			break ;
// 		}
// 	}
// 	return (nb);
// }

float	BitCoin::checkRate(std::string r)
{
	int i(0);
	int flag(0);
	
	std::cout << r[0] << std::endl;
	while (r[i] != '\0' && (r[i] == 32 || r[i] == '|')) 
		i++;
	while (r[i] != '\0')
	{
		if (r[i] == '.')
			flag += 1;
		if (r[i] == '-')
			throw NoPositiveNb();
		if (r[i] != '.' && (r[i] < 0 && r[i] > 9))
			throw BadInput();
	}
	if (flag > 1)
		throw BadInput();
	float	n = strtod(r.c_str(), NULL);
	if (n > 1000)
		throw RateTooLarge();
	return (n);
}

void	BitCoin::checkDate(std::string date)
{
	if (date[0] != '2' || date[1] != '0')
		throw BadInput();
	if (date[2] < '0' && date[2] > '2')
		throw BadInput();
	if (date[3] < '0' && date[3] > '9')
		throw BadInput();
	if (date[4] != '-' || date[7] != '-')
		throw BadInput();
	if (date[5] < '0' && date[5] > '2')
		throw BadInput();
	if (date[6] < '0' && date[6] > '9')
		throw BadInput();
	if (date[8] < '0' && date[9] > '3')
		throw BadInput();
	if (date[9] < '0' && date[9] > '9')
		throw BadInput();
}

void	BitCoin::fillMap(std::string date, std::string r)
{
	float ex_rate = strtod(r.c_str(), NULL);
	_map.insert(std::pair<std::string, float>(date,ex_rate));
}

void        BitCoin::printRate(std::string date, std::string rate)
{
	try
	{
		float	r = checkRate(rate);
		checkDate(date);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

// float	BitCoin::getRes(void) const // or int/float return.
// {
// 	return (_res);
// }

//bool	BitCoin::checkLine(std::string line)
//{
//	try
//	{
//		fillMap(line);
//	}
//	catch(const std::exception& e)
//	{
//		std::cerr << e.what() << '\n';
//	}
	
//}
//std::string	BitCoin::getDate(void)const
//{
//	return ();
//}

//float	BitCoin::getRate(void) const // or int/float return.
//{
//	return ();
//}

