/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 07:23:05 by aimokhta          #+#    #+#             */
/*   Updated: 2025/08/24 16:00:14 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

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
            std::cout << RED << "Invalid command\n" << RESET << std::endl;
    }
    return (0);
}
