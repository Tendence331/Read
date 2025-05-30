#include <iostream>
#include "User.h"
#include "Message.h"
#include <string>
#include <fstream>
#include <filesystem>
namespace fs = std::filesystem;
using namespace std;

void demo_perms(fs::perms p)
{
    std::cout << ((p & fs::perms::owner_read) != fs::perms::none ? "r" : "-")
        << ((p & fs::perms::owner_write) != fs::perms::none ? "w" : "-")
        << ((p & fs::perms::owner_exec) != fs::perms::none ? "x" : "-")
        << ((p & fs::perms::group_read) != fs::perms::none ? "r" : "-")
        << ((p & fs::perms::group_write) != fs::perms::none ? "w" : "-")
        << ((p & fs::perms::group_exec) != fs::perms::none ? "x" : "-")
        << ((p & fs::perms::others_read) != fs::perms::none ? "r" : "-")
        << ((p & fs::perms::others_write) != fs::perms::none ? "w" : "-")
        << ((p & fs::perms::others_exec) != fs::perms::none ? "x" : "-")
        << '\n';
}

int main()
{
    char ch, act;
    while (true)
    {
        User person;
        Message msg;
        cout << " 'u' - записать/прочитать данные о ПОЛЬЗОВАТЕЛЕ в файл \n"
                " 's' - записать/прочитать данные о СООБЩЕНИИ в файл \n"
                " 'x' - выход \n";
        cin >> ch;
        
        if (ch == 'x')
        {
            cout << "Выход...";
            break;
        }
        switch (ch)
        {
        case 'u':
            cout << "Выберите чтение/запись: 'r - чтение' 'w - запись''\n'";
            cin >> act;
            if ('w' == act)
            {
                person.getData();
                person.write("USERS.txt");
                fs::permissions("USERS.txt", fs::perms::group_all | fs::perms::others_all, fs::perm_options::remove);
                demo_perms(fs::status("USERS.txt").permissions());
            }
            else if ('r' == act)
            {
                person.read("USERS.txt");
            }
            else
            {
                cout << "Ошибка: неверный выбор действия! (только 'r' или 'w')\n";
            }
            
            break;
        case 's':
            cout << "Выберите чтение/запись: 'r - чтение' 'w - запись''\n'";
            cin >> act;
            if ('w' == act)
            {
                msg.getData();
                msg.write("MESSAGE.txt");
                fs::permissions("USERS.txt", fs::perms::group_all | fs::perms::others_all, fs::perm_options::remove);
                demo_perms(fs::status("USERS.txt").permissions());
            }
            else if ('r' == act)
            {
                msg.read("MESSAGE.txt");
            }
            else
            {
                cout << "Ошибка: неверный выбор действия! (только 'r' или 'w')\n";
            }
            
            break;
        default:
            cout << "Неизвестная команда!" << endl;
            break;
        }
    }

}
