/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:25:26 by blefebvr          #+#    #+#             */
/*   Updated: 2023/11/06 15:29:09 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*You must use at least one container in your code to validate this
exercise. You should handle possible errors with an appropriate
error message.*/

#include "../lib/BitCoinExchange.hpp"
#include <stdexcept>
#include <cstring>  

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << RED "Usage: <value>" DEFAULT << '\n';
		return(1);
	}
	BitCoin 		*b = new BitCoin();
	std::ifstream 	file, input;
	std::string 	date, rate, s, content;
  	file.exceptions(std::ifstream::badbit);
	try 
	{
		file.open("data.csv");
		while (getline(file, date, ',') && getline(file, rate))
			b->fillMap(date, rate);
		file.close();
	}
	catch (std::ifstream::failure &e)
	{
		std::cerr << RED "Error with opening,reading or closing file" << std::endl;;
	}
	input.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try
	{
		input.open(av[1]);
		getline(input, s);
		if (s.compare("date | value") != 0)
			throw BitCoin::BadInput();
		while (getline(input, s))
		{
			size_t i(0);
			while (s[i] && s[i] == 32)
				i++;
			date = s.substr(i, 10);
			i += 11;
			while (s[i] && !(s[i] >= 0 && s[i] <= '9') && s[i] != '-')
				i++;
			if (i < s.size())
				rate = s.substr(i);
			b->printRate(date, rate);
			date.clear();
			rate.clear();
			if (input.eof())
				break ;
		}
	}
	catch(const std::exception &e)
	{
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}
	delete b;
	return (0);
}

