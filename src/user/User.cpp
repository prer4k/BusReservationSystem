#include "User.h"
#include <iostream>

User::User(int id, const std::string& n) {
    userID = id;
    name = n;
}

int User::getUserID() const {
    return userID;
}

std::string User::getName() const {
    return name;
}

void User::displayUser() const {
    std::cout << "User ID: " << userID << std::endl;
    std::cout << "Name: " << name << std::endl;
}
