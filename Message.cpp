#include "Message.h"

std::fstream &operator >>(std::fstream& is, Message &obj)         // from message
{
    is >> obj._sender;
    is >> obj._receiver;
    is >> obj._text;
    return is;
}

std::ostream &operator <<(std::ostream& os, const Message &obj)       // from message
{
    os << obj._sender;
    os << ' ';
    os << obj._receiver;
    os << ' ';
    os << obj._text;
    return os;
}

void Message::write(const std::string& filename)
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
        file << "Текст: " << _text << '\n';
        file << "Отправитель : " << _sender << '\n'; 
        file << "Получатель : " << _receiver << '\n';
        file << "---------------------------" << '\n';
        file.close();
    }
}

void Message::read(const std::string &filename)
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
        while (getline(file, str))          // читаем весь файл
        {
            std::cout << str << '\n';       // выводим содержимое
        }
        file.close();
    }
}

void Message::getData()
{
    std::cout << "Идет запись: " << '\n';
    std::cin.ignore();
    std::cout << "Введите текст: ";
    std::getline(std::cin, _text);
    std::cout << "Введите откправителя: ";
    std::getline(std::cin, _sender);
    std::cout << "Введите получателя : ";
    std::getline(std::cin, _receiver);
}