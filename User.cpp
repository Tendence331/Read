#include "User.h"

std::fstream &operator>>(std::fstream &is, User &obj)   // from user
{
    is >> obj._name;
    is >> obj._login;
    is >> obj._pass;
    return is;
}

std::ostream &operator<<(std::ostream &os, const User &obj) // from user
{
    os << obj._name;
    os << ' ';
    os << obj._login;
    os << ' ';
    os << obj._pass;
    return os;
}

void User::write(const std::string& filename)
{

    std::fstream file; 

    file.open(filename, std::ios::app | std::ios::out | std::ios::binary);     // открываем файл с аргументами на запись, запись конец файла без удаления, биннарый ввод
    if (!file.is_open())                                        // проверка существует ли файл    
    {
        std::cout << "Невозможно открыть файл!" << '\n';
        return;
    }
    if (file)
    {
        file << "Имя: " << _name << '\n';
        file << "Логин: " << _login << '\n'; 
        file << "Пароль: " << _pass << '\n';
        file << "---------------------------"<< '\n';
        file.close();
    }
}

void User::read(const std::string &filename)
{
    std::cout << "Идет чтение: " << '\n';
    
    std::fstream file;

    file.open(filename, std::ios::in);   // открытие файла для чтения
    if (!file.is_open())
    {
        std::cout << "Невозможно открыть файл!" << '\n';
        return;
    }
    if (file)
    {
        std::string str;
        while (getline(file, str))
        {
            std::cout << str << '\n';
        }
        file.close();
    }
}

void User::getData()
{
    std::cout << "Идет запись: " << '\n';
    std::cin.ignore();
    std::cout << "Введите имя: ";
    std::getline(std::cin, _name);
    std::cout << "Введите логин: ";
    std::getline(std::cin, _login);
    std::cout << "Введите пароль: ";
    std::getline(std::cin, _pass);
}