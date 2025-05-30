#pragma once
#include <fstream>
#include <iostream>

class Message
{
private:
    std::string _text;
    std::string _sender;
    std::string _receiver;
public:
    Message() {}
    Message(std::string text, std::string sender, std::string receiver) : _text(text), _sender(sender), _receiver(receiver) {}

    friend std::fstream& operator >>(std::fstream& is, Message& obj);
    friend std::ostream& operator <<(std::ostream& os, const Message& obj);

    void write(const std::string& filename);
    void read(const std::string &filename);
    void getData();
};