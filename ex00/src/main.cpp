/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:25:26 by blefebvr          #+#    #+#             */
/*   Updated: 2023/11/01 18:55:58 by blefebvr         ###   ########.fr       */
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
	std::ifstream file;
  	file.exceptions ( std::ifstream::failbit | std::ifstream::badbit );
	try 
	{
		file.open("data.cvs");
		while ()
			b->fillMap(file);
		file.close();
	}
	catch (std::ifstream::failure e) {
		std::cerr << "Error with opening/reading/closing file\n";
	}
	try
	{
		std::ifstream input(av[1]);
		input.exceptions ( std::ifstream::failbit | std::ifstream::badbit );
		std::string s;
		
	}
	catch(const std::exception &e)
	{
		std::cerr << "Error with opening/reading/closing file\n";
	}
	delete b;
	return (0);
}

