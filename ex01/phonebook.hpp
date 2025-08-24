/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 22:40:43 by aimokhta          #+#    #+#             */
/*   Updated: 2025/08/24 16:04:53 by aimokhta         ###   ########.fr       */
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
# include <string> //std:string
# include <iomanip> //std::setw

class Contact
{
    public:
		int			Index;
        std::string FirstName;
        std::string LastName;
        std::string Nickname;
        std::string PhoneNumber;
        std::string DarkestSecret;
};

class PhoneBook 
{
    public: 
        Contact contacts[MAX_CONTACTS];
		int 	contact_count;

		PhoneBook() 
		{
			contact_count = 0;
		}
		//equivalent to:
		// PhoneBook() : contact_count(0) {} 
		// meaning = constructor (PhoneBook()) | with an initializer list (: contact_count(0)) | {} = empty body, done nothing else than the initialization

        void add_command()
        {
			std::string fn, ln, nn, pn, secret;

			std::cout << "FirstName: ";
            std::cin >> fn;
            std::cout << "LastName: ";
            std::cin >> ln;
            std::cout << "Nickname: ";
            std::cin >> nn;
            std::cout << "PhoneNumber: ";
            std::cin >> pn;
            std::cout << "DarkestSecret: ";
			std::cin.ignore();
            std::getline(std::cin, secret); // to include spaces

            if (fn.empty() || ln.empty() || nn.empty() || pn.empty() || secret.empty()) //.empty() returns true if string length is 0, can also use .length() or .size()
			{
				std::cout << "Contact's detail must not be empty" << std::endl;
				return ;
			}
			else
			{
				int i = contact_count % MAX_CONTACTS;
				contacts[i].Index = i + 1;
				contacts[i].FirstName = fn;
				contacts[i].LastName = ln;
				contacts[i].Nickname = nn;
				contacts[i].PhoneNumber = pn;
				contacts[i].DarkestSecret = secret;
				contact_count++;
				std::cout << CYAN << "Contact's details saved!\n" << RESET << std::endl;
				return ;
			}
        }

        std::string formatting(std::string str)
        {
            if (str.length() > 10)
                return (str.substr(0, 9) + ".");
            else
				return (std::string(10 - str.length(), ' ') + str);
        }

        void search_command()
        {
			int index;

            std::cout   << std::setw(10) << "Index" << "|"
                        << std::setw(10) << "FirstName" << "|"
                        << std::setw(10) << "LastName" << "|"
                        << std::setw(10) << "Nickname" << "\n";
            for (int i = 0; i < MAX_CONTACTS && i < contact_count; i++)
            {
                std::cout   << std::setw(10) << contacts[i].Index << "|"
                            << formatting(contacts[i].FirstName) << "|"
                            << formatting(contacts[i].LastName) << "|"
                            << formatting(contacts[i].Nickname) << std::endl;
            }

            std::cout	<< BLUE << "\nIndex of the contact you are searching for: " << RESET;
			std::cin	>> index;
			
            if (index > 0 && index <= MAX_CONTACTS && index <= contact_count)
            {
                std::cout   << "FirstName: " << contacts[index - 1].FirstName << "\n"
                            << "LastName: " << contacts[index - 1].LastName << "\n"
                            << "Nickname: " << contacts[index - 1].Nickname << "\n" 
							<< "PhoneNumber: " << contacts[index - 1].PhoneNumber << "\n" << std::endl;
            }
            else
                std::cout << RED << "Invalid index\n" << RESET << std::endl;
        }
};

#endif