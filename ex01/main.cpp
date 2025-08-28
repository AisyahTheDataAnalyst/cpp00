/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 07:23:05 by aimokhta          #+#    #+#             */
/*   Updated: 2025/08/24 21:09:16 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
{
    PhoneBook pb;
    std::string cmd;

    while (1)
    {
        std::cout << GREEN_BG << "Enter command (ADD, SEARCH, EXIT):" << RESET << " ";
        std::cin >> cmd;

        if (cmd == "ADD")
            pb.add_command();
        else if (cmd == "SEARCH")
            pb.search_command();
        else if (cmd == "EXIT")
            break ;
        else
            std::cerr << RED << "Invalid command\n" << RESET << std::endl;
    }
    return (0);
}
