/*insert 42 header*/

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string> //std:string,

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

#endif

