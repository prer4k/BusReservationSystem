#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    int userID;
    std::string name;

public:
    User(int id, const std::string& n);

    int getUserID() const;
    std::string getName() const;

    void displayUser() const;
};

#endif
