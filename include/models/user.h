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
    std::string m_name;
    Direction m_direction;
public:
    user(const std::string& name)
        : m_name{name}
    {

    }
};

#endif //USER_H
