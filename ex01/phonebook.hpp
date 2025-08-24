/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 22:40:43 by aimokhta          #+#    #+#             */
/*   Updated: 2025/08/24 21:27:32 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define MAX_CONTACTS 3
# define RESET   	"\033[0m"
# define WHITE  	"\033[1;37m"
# define RED		"\033[1;31m"
# define BLUE 		"\033[1;34m"
# define CYAN		"\033[1;36m"
# define GREEN_BG	"\033[42m"

# include <iostream> //std::cin, std::cout , std::endl
# include <string> //std:string, std::getline
# include <iomanip> //std::setw
# include <cctype> //isdigit

class Contact
{
private:
    int			Index;
    std::string FirstName;
    std::string LastName;
    std::string Nickname;
    std::string PhoneNumber;
    std::string DarkestSecret;
    
public:
    //setters or recorders into the class
    void setIndex(int i) { Index = i; }
    void setFirstName(const std::string &fn) { FirstName = fn; } // & take the original string instead of the copy of it, useful if its a long string
    void setLastName(const std::string &ln) { LastName = ln; }   // const here refers to the parameter
    void setNickname(const std::string &nn) { Nickname = nn; }
    void setPhoneNumber(const std::string &pn) {PhoneNumber = pn; }
    void setDarkestSecret(const std::string &secret) {DarkestSecret = secret; }

    //getters or readers only from the class
    int         getIndex() const { return Index; } // const refers to the members/object of the class
    std::string getFirstName() const { return FirstName; }
    std::string getLastName() const { return LastName; }
    std::string getNickname() const { return Nickname; }
    std::string getPhoneNumber() const { return PhoneNumber; }
    std::string getDarkestSecret() const { return DarkestSecret; }
};

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
        static std::string formatting(std::string str); // static nly mention ONCE in class declaration only
        static bool is_it_digit_only(std::string pn);
};

#endif