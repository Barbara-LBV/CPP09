/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitCoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:28:59 by blefebvr          #+#    #+#             */
/*   Updated: 2023/10/27 17:24:20 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>

class BitCoin
{
	
};

#endif

/*
utiliser containers map
map est un container associatif, car il associe des paires clef-valeur
dont on doit determiner les types (int, string, class etc)

-utilise un fichier .csv dans le prog
-utilise un 2e fichier database en argument du main
  -parser pour gerer les erreurs de fichiers (ouverture, existence etc)
  -creer ce fichier dont chaq ligne doit avoir un formatage " date | value"
  -parser pour gerer les erreurs de fichier vide, de formatage de date, value
   -date = years-month-day
   -value = entier ou float positif entre 0 et 1000
- le resultat doit afficher la value multipliee par le taux d'echange du jour indique 
dans mon fichier database.
ex --> 2011-01-03 => 3 = 0.9
  -si la date n'existe pas, on prend la plus proche avt ou apres. Si deux sont a 
  equidistance, prendre la date la plus basse.
  -s'il y a un prob de nombre (neg, out of range etc) cela devra etre affiche.


*/