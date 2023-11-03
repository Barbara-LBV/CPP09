/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:25:26 by blefebvr          #+#    #+#             */
/*   Updated: 2023/11/03 18:29:09 by blefebvr         ###   ########.fr       */
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
	std::ifstream 	file;
	std::string 	date, rate;
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
	std::ifstream input;
	input.exceptions(std::ifstream::badbit);
	std::string s;
	size_t i(0);
	try
	{
		input.open(av[1]);
		while (getline(input, s))
		{
			while (s[i] && !(s[i] >= 0 && s[i] <= '9'))
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
			i = 0;
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

