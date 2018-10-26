//
//  LoginServer.cpp
//  ENSF480Lab6_ExC
//
//  Created by Nathan Godard on 2018-10-25.
//  Copyright © 2018 Nathan Godard. All rights reserved.
//

#include "LoginServer.hpp"
LoginServer* LoginServer::instance = nullptr;

LoginServer* LoginServer::getInstance(){
    if(instance == nullptr){
        instance = new LoginServer();
    }
    return instance;
}

void LoginServer::add(std::string username, std::string password){
    LoginServer* ls = getInstance();
    for(User u: ls -> users){
        if(u.username.compare(username) == 0){
            std::cout << "A user with the specified name already exists\n";
            return;
    }   }
    User* u = new User();
    u -> username = username;
    u -> password = password;
    ls -> users.push_back(*u);
}

User* LoginServer::validate(std::string username, std::string password){
    User* toReturn;
    LoginServer* ls = getInstance();
    for(int i = 0; i < ls -> users.size(); i++){
        toReturn = &(ls -> users.at(i));
        if(toReturn -> username.compare(username) == 0 && toReturn -> password.compare(password) == 0){
            return toReturn;
    }    }
    
    //std::cout << "Username or Password not found\n";          <- Implemented in main
    return nullptr;
}

LoginServer::LoginServer(){
    users = std::vector<User>();
    if(instance == NULL){
        instance = this;
    }
}

LoginServer::LoginServer(const LoginServer& src){
    if(&src == this){
        return;
    }
    users = std::vector<User>();
    for(User u: src.users){
        this -> add(u.username, u.password);
    }
    instance = src.getInstance();
}

LoginServer& LoginServer::operator=(const LoginServer& rhs){
    if(&rhs == this){
        return *this;
    }
    users = std::vector<User>();
    for(User u: rhs.users){
        users.push_back(u);
    }
    instance = rhs.getInstance();
    return *this;
}
