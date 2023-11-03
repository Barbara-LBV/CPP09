/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitCoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:42:29 by blefebvr          #+#    #+#             */
/*   Updated: 2023/11/03 18:31:31 by blefebvr         ###   ########.fr       */
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

std::string	BitCoin::checkDate(std::string date)
{
	std::stringstream s(date);
	std::string	year, month, day;
	
	if (getline(s, year, '-') && checkYear(year) == false)
		throw BadInput();
	if (getline(s, month, '-') && checkMonth(month) == false)
		throw BadInput();
	if (getline(s, day) && checkDay(day) == false)
		throw BadInput();
	//std::string d = "";
	//d.replace(0, 10, date, 0, 10);
	//if (d[0] != '2')
	//	throw BadInput();
	//if (d[1] != '0')
	//	throw BadInput();
	//if (!(d[2] >= '0' && d[2] <= '2'))
	//	throw BadInput();
	//if (!(d[3] >= '0' && d[3] <= '9'))
	//	throw BadInput();
	//if (d[4] != '-' || d[7] != '-')
	//	throw BadInput();
	//if (!(d[5] >= '0' && d[5] < '2'))
	//	throw BadInput();
	//if (!(d[6] >= '0' && d[6] <= '9'))
	//	throw BadInput();
	//if (!(d[8] >= '0' && d[8] <= '3'))
	//	throw BadInput();
	//if (!(d[9] >= '0' && d[9] <= '9'))
	//	throw BadInput();
	return(date);
}

bool 	BitCoin::checkYear(std::string y)
{
	return (true);
}

bool 	BitCoin::checkMonth(std::string m)
{
	return (true);
}

bool 	BitCoin::checkDay(std::string d)
{
	return (true);
}

void	BitCoin::fillMap(std::string date, std::string r)
{
	float ex_rate = strtof(r.c_str(), NULL);
	_map.insert(std::pair<std::string, float>(date,ex_rate));
}

void        BitCoin::printRate(std::string date, std::string rate)
{
	float	r;
	try
	{
		checkDate(date);
		r = strtof(rate.c_str(), NULL);
		if (r > 1000)
			throw RateTooLarge();
		if (r <= 0)
			throw NoPositiveNb();
		// fonction qui verifie que la date de l'input existe bien dans la Database
		r *= _map[date];
		std::cout << date << " | " << rate << " = " << r << std::endl;
	}
	catch(const std::exception& e)
	{
		if (dynamic_cast<const NoPositiveNb*>(&e) != NULL || dynamic_cast<const RateTooLarge*>(&e) != NULL)
            std::cerr << rate << " => " << e.what() << '\n';
		else
			std::cerr << date << " => " << e.what() << '\n';
	}
}
/*
void BitcoinExchange::findDate(std::string date, float val)
{
	if (ratesMap.find(date) != ratesMap.end())
	{
		float result = val * ratesMap[date];
		std::cout << date << " => " << std::fixed << std::setprecision(2) << val << " = " << result << std::endl;
		return ;
	}
	else
	{
		date = decreaseDate(date);
		findDate(date, val);
	}
}

++++ fonctions en sus +++++

checkDate ( qui verifie le format et la validite de year, month et day)
 ->checkDay
 ->checkYear
 ->checkMonth
 
+ fonction decreaseDate;

revoir aussi le parsing en utilisant davantage les fonctions de std::string

*/


// std::ostream &operator<<( std::ostream &o, BitCoin &b)
// {
// 	o << b.getDate() << " | "   // a ne suffira sans doute pas a recuperer la valeur "date" au bon node de map
// 	  << b.getRate() << " => " // idem => utiliser les iterateurs !
// 	  << b.getRes() << std::endl;
// 	return (o);
// }
