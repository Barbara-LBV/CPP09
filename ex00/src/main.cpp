/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:25:26 by blefebvr          #+#    #+#             */
/*   Updated: 2023/11/14 15:57:10 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/BitCoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << RED "Usage <value>" DEFAULT << '\n';
		return(1);
	}
	BitCoinExchange *b = new BitCoinExchange();
	std::ifstream 	file, input;
	std::string 	date, rate, s;
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
		std::cerr << RED "Error with opening, reading or closing database file" DEFAULT << std::endl;
	}
	input.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try
	{
		input.open(av[1]);
		getline(input, s);
		if (s.compare("date | value") != 0)
		{
			std::cerr << RED "Error: wrong header" DEFAULT << std::endl;
			input.close();
			input.open(av[1]);
		}
		while (getline(input, s))
		{
			b->findInfo(s);
			b->printRate();
			b->setDate("");
			b->setRate("");
			if (input.eof())
				break ;
		}
		input.close();
	}
	catch(const std::exception &e)
	{
		std::cerr << RED "Error with opening, reading or closing input file" DEFAULT << std::endl;
	}
	delete b;
	return (0);
}

