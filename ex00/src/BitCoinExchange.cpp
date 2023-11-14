/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitCoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:42:29 by blefebvr          #+#    #+#             */
/*   Updated: 2023/11/14 16:24:22 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/BitCoinExchange.hpp"

BitCoinExchange::BitCoinExchange()
{
	std::cout << BLUE "Default constructor -> called" DEFAULT << std::endl;
	_date = "";
	_rate = "";
	_d = 0;
	_m = 0;
	_y = 0;
}

BitCoinExchange::BitCoinExchange(BitCoinExchange const &b)
{
	std::cout << BLUE "Copy constructor -> called" DEFAULT << std::endl;
	*this = b;
}

BitCoinExchange &BitCoinExchange::operator=(BitCoinExchange const &b)
{
	std::cout << BLUE "Assignement opertor -> called" DEFAULT << std::endl;
	if (this != &b)
	{
		_map = b._map;
		_date = b._date;
		_rate = b._rate;
		_d = b._d;
		_m = b._m;
		_y = b._y;
	}
	return (*this);
}

BitCoinExchange::~BitCoinExchange()
{
	std::cout << BLUE "Destructor -> called" DEFAULT << std::endl;
}

void 	BitCoinExchange::setDate(std::string date)
{
	_date = date;
}

void    BitCoinExchange::setRate(std::string rate)
{
	_rate = rate;		
}

std::string const	&BitCoinExchange::getDate(void)const
{
	return _date;
}

void	BitCoinExchange::checkDate(void)
{
	std::stringstream	s(_date);
	std::string			year, month, day;
	
	std::size_t found = _date.find_first_not_of("0123456789-");
	if (found != std::string::npos || _date.size() != 10)
		throw BadDate();
	if (getline(s, year, '-') && checkYear(year) == false)
		throw BadDate();
	if (getline(s, month, '-') && checkMonth(month) == false)
		throw BadDate();
	if (getline(s, day) && checkDay(day) == false)
		throw BadDate();
}

bool 	BitCoinExchange::checkYear(std::string y)
{
	_y = atoi(y.c_str());
	if (_y < 1900 || _y > 2023)
		return (false);
	return (true);
}

bool 	BitCoinExchange::checkMonth(std::string m)
{
	_m = atoi(m.c_str());
	if (_m < 1 || _m > 12)
		return (false);
	return (true);
}

bool 	BitCoinExchange::checkDay(std::string d)
{
	_d = atoi(d.c_str());
	if (_d < 1 || _d > 31)
		return (false);
	return (true);
}

void	BitCoinExchange::fillMap(std::string date, std::string r)
{
	float ex_rate = strtof(r.c_str(), NULL);
	_map.insert(std::pair<std::string, float>(date, ex_rate));
}

void    BitCoinExchange::findInfo(std::string s)
{
	size_t 	i(0);
	
	while (s[i] && s[i] == 32)
		i++;
	if (s.size() > i + 10)
		_date = s.substr(i, 10);
	else 
	{
		_date = s.substr(i);
		return ;
	}	
	i += 11;
	while (s[i] && !isdigit(s[i]) && s[i] != '-')
		i++;
	if (i < s.size())
		_rate = s.substr(i);
}

void	BitCoinExchange::printRate(void)
{
	float	r;
	try
	{
		checkDate();
		r = strtof(_rate.c_str(), NULL);
		if (r > 1000)
			throw RateTooLarge();
		if (r <= 0)
			throw NoPositiveNb();
		findDate(_date, r);
	}
	catch(const std::exception& e)
	{
		if (dynamic_cast<const NoPositiveNb*>(&e) != NULL || dynamic_cast<const RateTooLarge*>(&e) != NULL)
            std::cerr << YELLOW "Error: " << e.what() << DEFAULT << std::endl;
		else
			std::cerr << RED "Error: " << this->getDate() << " => " << e.what() << DEFAULT << std::endl;
	}
}

void 	BitCoinExchange::findDate(std::string date, float val)
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


std::string BitCoinExchange::decreaseDate(void)
{
	std::string			newDate = "";
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
	else if (_y < 2009)
		return ("2009-01-02");
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
