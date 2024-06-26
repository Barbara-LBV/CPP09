/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitCoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:28:59 by blefebvr          #+#    #+#             */
/*   Updated: 2023/11/14 15:55:08 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <cstdlib>
#include <stdexcept>
#include <cstring>  
#include <map>

# define DEFAULT "\001\033[0;39m\002"
# define BOLD "\001\033[1;89m\002"
# define RED "\001\033[1;91m\002"
# define BLUE "\001\033[1;36m\002"
# define YELLOW "\001\033[1;93m\002"

class BitCoinExchange
{
    private :
        std::map<std::string, float>  _map;
        std::string                   _date;
        std::string                   _rate;
        int                           _d;
        int                           _m;
        int                           _y;
  
    public :
        BitCoinExchange();
        BitCoinExchange(BitCoinExchange const &b);
        BitCoinExchange &operator=(BitCoinExchange const &b);
        ~BitCoinExchange();

        void	            fillMap(std::string date, std::string r);
        void      	      checkDate(void);
        void              findInfo(std::string s);
        void              printRate(void);
        bool 	            checkYear(std::string y);
        bool 	            checkMonth(std::string m);
        bool 	            checkDay(std::string d);
        void	            findDate(std::string date, float val);
        std::string       decreaseDate(void);
        void              convert(std::string input);
        std::string const &getDate(void)const;
        void              setDate(std::string date);
			  void              setRate(std::string rate);

    class BadDate : public std::exception
    {
      public:
        virtual const char* what() const throw()
          {
            return ("bad Input");
          }
    };
    class NoPositiveNb : public std::exception
    {
      public:
        virtual const char* what() const throw()
        {
          return ("not a positive integer");
        }
    };
    class RateTooLarge : public std::exception
    {
      public:
        virtual const char* what() const throw()
        {
          return ("too large a number");
        }
    };  
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