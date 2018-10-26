//
//  Client_A.cpp
//  ENSF480Lab6_ExC
//
//  Created by Nathan Godard on 2018-10-25.
//  Copyright © 2018 Nathan Godard. All rights reserved.
//

#include "Client_A.hpp"

void Client_A::add(std::string username, std::string password){
    instance -> add(username, password);
}

User* Client_A::validate(std::string username, std::string password){
    return instance -> validate(username, password);
}
