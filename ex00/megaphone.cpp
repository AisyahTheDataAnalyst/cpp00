/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 18:57:56 by aimokhta          #+#    #+#             */
/*   Updated: 2025/08/23 23:05:30 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream> // std::cout, std::endl
# include <string>//std::string
# include <cctype> //std::toupper

// c: char *text | c++: std::string text 
// c: printf("%s\n", av[i]) | c++: std:count << av[i] << std::endl
// std::cout = C++ stream object for output
// << = "insertion operator" (chaining data into the output stream)
// std::endl = "\n" + flushes the stream

int main(int ac, char **av)
{
    // without arguments
    std::string text = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    if (ac < 2)
    {
        std::cout << text << std::endl;
        // std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    

    // with arguments
    for (int i = 1; i < ac; i++)
    {
        for (int j = 0; av[i][j] != '\0'; j++)
            av[i][j] = std::toupper(av[i][j]);
        std::cout << av[i];
    }
    std::cout << std::endl;
    return (0);
}




/*
📝 Simplified Notes on Buffering & Flushing

🔹 Flushing
- Output first goes into a buffer (temporary memory).
- Flushed (sent to terminal/file) when:
    -Buffer is full
    -Program ends
    -You explicitly flush (std::endl, std::flush).
- Purpose: speed (batch writes instead of immediate writes).

🔹 \n vs std::endl
- "\n" → newline only (may flush if line-buffered).
- std::endl → newline + always flush.
- Prefer "\n" for normal printing.
- Use std::endl when you need immediate output (e.g., progress, debugging).

🔹 Buffering types
Fully buffered → flush only when full or on manual flush (typical for files).
Line-buffered → flush on every newline (typical for stdout in terminals).
Unbuffered → writes instantly (typical for stderr).

🔹 Example timeline
std::cout << "Hello";   // hidden in buffer
sleep(2);
std::cout << "\n";      // newline flushes → "Hello\n" appears
sleep(2);
std::cerr << "Error!\n"; // unbuffered → appears instantly

🔹 What happens when you run it (terminal vs file)

In a terminal (line-buffered)
"text\n" → shows immediately (newline triggers flush).
std::endl → also shows immediately (forced flush).
👉 They look the same.

Redirected to a file (fully buffered)
"text\n" → stays in buffer, may not appear until program ends.
std::endl → flushed immediately, so appears in file right away.
👉 Difference is visible here.

So this:
    std::cout << "Hello" << std::endl;
is equivalent to:
    std::cout << "Hello\n";
    std::cout.flush();

✅ Summary:
- Buffer = waiting area for output.
- \n = newline (may flush if line-buffered).
- std::endl = newline + guaranteed flush.
- stdout = line-buffered, stderr = unbuffered, files = fully buffered.
*/