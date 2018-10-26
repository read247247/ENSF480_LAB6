//
//  Client_A.hpp
//  ENSF480Lab6_ExC
//
//  Created by Nathan Godard on 2018-10-25.
//  Copyright © 2018 Nathan Godard. All rights reserved.
//

#ifndef Client_A_hpp
#define Client_A_hpp

#include <stdio.h>
#include <string.h>
#include "LoginServer.hpp"

class Client_A {
public:
    void add(std::string username, std::string password);
    User* validate(std::string username, std::string password);
private:
    LoginServer* instance;
};
#endif /* Client_A_hpp */
