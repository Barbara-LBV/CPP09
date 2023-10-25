/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:25:26 by blefebvr          #+#    #+#             */
/*   Updated: 2023/10/25 17:28:30 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*You must use at least one container in your code to validate this
exercise. You should handle possible errors with an appropriate
error message.*/

int main(int ac, char **av) // un doc sera lance en 2e arg
{
	if (ac != 2)
	{
		std::err << "Usage: <value>" << '\n';
		return(1);
	}
	

	return (0);
}