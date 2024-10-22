//
// Created by aziz on 10/22/24.
//

#ifndef USER_H
#define USER_H
#include <string>
#include <iostream>
#include "utils.h"
class user {
private:
    std::string name;
    Direction direction;
public:
    friend std::istream& operator>>(std::istream& in, user& user) {
        in >> user.name;
        return in;
    }
};

#endif //USER_H
