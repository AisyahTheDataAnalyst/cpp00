/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 16:50:01 by aimokhta          #+#    #+#             */
/*   Updated: 2025/08/24 21:34:55 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

// std::cout uses << named insertion operator (insert data into the stream)
// std::cin uses >> named extraction operator (take data out of stream(keyboard))
void PhoneBook::add_command()
{
    std::string fn, ln, nn, pn, secret;

    std::cout << "FirstName: ";
    std::cin.ignore(1000, '\n');  // This means: ignore up to 1000 characters, or stop when a newline \n is found.  
    std::getline(std::cin, fn);   // getline include spaces
    std::cout << "LastName: ";
    std::getline(std::cin, ln);
    std::cout << "Nickname: ";
    std::getline(std::cin, nn);
    std::cout << "PhoneNumber (without spaces and digits only): ";
    std::cin >> pn;
    if (is_it_digit_only(pn) == false)
    {
        std::cerr << RED << "Phone number is not in digits\n" << RESET << std::endl;
        return ;
    }
    std::cout << "DarkestSecret: ";
    std::cin.ignore(1000, '\n');    // discard leftover \n from previous >> 
    std::getline(std::cin, secret); 

    if (fn.empty() || ln.empty() || nn.empty() || pn.empty() || secret.empty()) //.empty() returns true if string length is 0, can also use .length() or .size()
    {
        std::cerr << RED << "Contact's detail must not be empty\n" << RESET << std::endl;
        return ;
    }
    else
    {
        int i = contact_count % MAX_CONTACTS;
        contacts[i].setIndex(i + 1);
        contacts[i].setFirstName(fn);
        contacts[i].setLastName(ln);
        contacts[i].setNickname(nn);
        contacts[i].setPhoneNumber(pn);
        contacts[i].setDarkestSecret(secret);
        contact_count++;
        std::cout << CYAN << "Contact's details saved!\n" << RESET << std::endl;
        return ;
    }
}
bool PhoneBook::is_it_digit_only(std::string pn)
{
    for(int i = 0; pn[i] != '\0'; i++)
    {
        if (!isdigit(pn[i]))
            return (false);
    }
    return (true);
}

void PhoneBook::search_command()
{
    int index;

    std::cout   << std::setw(10) << "Index" << "|"
                << std::setw(10) << "FirstName" << "|"
                << std::setw(10) << "LastName" << "|"
                << std::setw(10) << "Nickname" << "\n";
    for (int i = 0; i < MAX_CONTACTS && i < contact_count; i++)
    {
        std::cout   << std::setw(10) << contacts[i].getIndex() << "|"
                    << formatting(contacts[i].getFirstName()) << "|"
                    << formatting(contacts[i].getLastName()) << "|"
                    << formatting(contacts[i].getNickname()) << std::endl;
    }

    std::cout	<< BLUE << "\nIndex of the contact you are searching for: " << RESET;
    std::cin	>> index;
    
    if (index > 0 && index <= MAX_CONTACTS && index <= contact_count)
    {
        std::cout   << "FirstName: " << contacts[index - 1].getFirstName() << "\n"
                    << "LastName: " << contacts[index - 1].getLastName() << "\n"
                    << "Nickname: " << contacts[index - 1].getNickname() << "\n" 
                    << "PhoneNumber: " << contacts[index - 1].getPhoneNumber() << "\n" 
                    << "DarkestSecret: " << contacts[index - 1].getDarkestSecret() << "\n" << std::endl;
    }
    else
        std::cerr << RED << "Invalid index" << RESET << "\n" << std::endl;
}

std::string PhoneBook::formatting(std::string str) // already declare static at header, no need 
{
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    else
        return (std::string(10 - str.length(), ' ') + str);
}