//
//  LoginServer.hpp
//  ENSF480Lab6_ExC
//
//  Created by Nathan Godard on 2018-10-25.
//  Copyright © 2018 Nathan Godard. All rights reserved.
//

#ifndef LoginServer_hpp
#define LoginServer_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

#include "User.h"

class LoginServer{
public:
    static LoginServer* getInstance();
    void add(std::string username, std::string password);
    User* validate(std::string username, std::string password);
private:
    LoginServer();
    LoginServer(const LoginServer& src);
    LoginServer& operator=(const LoginServer& rhs);
protected:
    std::vector<User> users;
    static LoginServer* instance;
};
#endif /* LoginServer_hpp */
