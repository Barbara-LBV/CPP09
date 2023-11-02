/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:25:26 by blefebvr          #+#    #+#             */
/*   Updated: 2023/11/02 16:52:45 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*You must use at least one container in your code to validate this
exercise. You should handle possible errors with an appropriate
error message.*/

#include "../lib/BitCoinExchange.hpp"
#include <stdexcept>
#include <cstring>  

int main(int ac, char **av) // un doc sera lance en 2e arg
{
	if (ac != 2)
	{
		std::cerr << RED "Usage: <value>" DEFAULT << '\n';
		return(1);
	}
	BitCoin 	*b = new BitCoin();
	std::ifstream 	file;
	std::string 	date;
	std::string 	rate;
  	file.exceptions(std::ifstream::badbit);
	
	try 
	{
		file.open("data.csv");
		while (getline(file, date, ',') && getline(file, rate))
			b->fillMap(date, rate);
		file.close();
	}
	catch (std::ifstream::failure &e) {
		std::cerr << "Error with opening/reading/closing file\n";
	}
	std::cout <<"is out 1st catch" << std::endl;
	std::ifstream input;
	input.exceptions(std::ifstream::badbit);
	date = "";
	rate = "";
	try
	{
		input.open(av[1]);
		while (getline(input, date, '|') && getline(input, rate))
		{
			std::cout << date << std::endl;
			std::cout << rate << std::endl;
			b->printRate(date, rate);
		}
		input.close();
	}
	catch(const std::exception &e)
	{
		std::cerr << "Error with opening/reading/closing file\n";
	}
	delete b;
	return (0);
}

