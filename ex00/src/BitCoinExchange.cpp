/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitCoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:42:29 by blefebvr          #+#    #+#             */
/*   Updated: 2023/11/06 14:56:53 by blefebvr         ###   ########.fr       */
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
	return(date);
}

bool 	BitCoin::checkYear(std::string y)
{
	_y = atoi(y.c_str());
	if (_y < 2009 || _y > 2022)
		return (false);
	return (true);
}

bool 	BitCoin::checkMonth(std::string m)
{
	_m = atoi(m.c_str());
	if (_m < 1 || _m > 12)
		return (false);
	return (true);
}

bool 	BitCoin::checkDay(std::string d)
{
	_d = atoi(d.c_str());
	if (_d < 1 || _d > 31)
		return (false);
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
		findDate(date, r);
	}
	catch(const std::exception& e)
	{
		if (dynamic_cast<const NoPositiveNb*>(&e) != NULL || dynamic_cast<const RateTooLarge*>(&e) != NULL)
            std::cerr << YELLOW "Error: " << e.what() << DEFAULT << std::endl;
		else
			std::cerr << RED << date << " => " << e.what() << DEFAULT << std::endl;
	}
}

void 	BitCoin::findDate(std::string date, float val)
{
	std::stringstream s(date);
	
	if (_map.find(date) != _map.end())
	{
		float result = val * _map[date];
		std::cout << date << " => " << val << " = " << result << std::endl;
		return ;
	}
	else
	{
		date = decreaseDate();
		findDate(date, val);
	}
}

std::string BitCoin::decreaseDate(void)
{
	std::string			newDate;
	std::stringstream 	conc;
	
	if (_d > 1)
		_d--;
	else if (_m > 1)
	{
		_m--;
		if (_m <= 7 && _m % 2 != 0)
			_d = 31;
		else if ((_m >= 8 && _m <= 12) && _m % 2 == 0)
			_d = 31;
		else
			_d = 30;
	}
	else
	{
		_y--;
		_m = 12;
		_d = 31;
	}
	conc << _y << '-' << std::setw(2) << std::setfill('0') << _m << '-' << std::setw(2) << std::setfill('0') << _d;
	newDate = conc.str();
	return (newDate);
}

//void        BitCoin::convert(std::ifstream input)
//{
//	std::string::iterator 	it;
//	std::string				content;
	
//	for (it != input.end())
//	{
//		getline(input, s);
//		{
//			while (!(*it >= 0 && *it <= '9'))
//				i++;
//			date = s.substr(i, 10);
//			i += 11;
//			while (s[i] && !(s[i] >= 0 && s[i] <= '9') && s[i] != '-')
//				i++;
//			if (i < s.size())
//				rate = s.substr(i);
//			b->printRate(date, rate);
//			date.clear();
//			rate.clear();
//			i = 0;
//		}
//	}
//}