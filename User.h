#pragma once
#include <fstream>
#include <iostream>


class User
{
private:
    std::string _name;
    std::string _login;
    std::string _pass;
public:
    User() {}
    User(std::string name, std::string login, std::string pass) : _name(name), _login(login), _pass(pass) {}

    friend std::fstream& operator >>(std::fstream& is, User& obj);
    friend std::ostream& operator <<(std::ostream& os, const User& obj);
    
    void write(const std::string& filename);
    void read(const std::string& filename);
    void getData();
};
