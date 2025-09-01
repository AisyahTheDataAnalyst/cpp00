/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 08:57:18 by aimokhta          #+#    #+#             */
/*   Updated: 2025/09/01 10:14:29 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define MAX_CONTACTS 8
# define RESET   	"\033[0m"
# define WHITE  	"\033[1;37m"
# define RED		"\033[1;31m"
# define BLUE 		"\033[1;34m"
# define CYAN		"\033[1;36m"
# define GREEN_BG	"\033[42m"

# include <iostream> //std::cin, std::cout , std::endl
# include <string> //std:string, std::getline
# include <iomanip> //std::setw
# include <cctype> //syd::isdigit
# include "Contact.hpp"

class PhoneBook 
{
    private: 
        Contact contacts[MAX_CONTACTS];
		int 	contact_count;

    public:
		PhoneBook() 
		{
			contact_count = 0;
		}
		//equivalent to:
		// PhoneBook() : contact_count(0) {} 
		// meaning = constructor (PhoneBook()) | with an initializer list (: contact_count(0)) | {} = empty body, done nothing else than the initialization

        void add_command();
        void search_command();
        std::string formatting(std::string str); // static nly mention ONCE in class declaration only
        bool is_it_digit_only(std::string pn);
};

#endif