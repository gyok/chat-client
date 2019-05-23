#ifndef CHATCLIENTMODEL_H
#define CHATCLIENTMODEL_H

#define MAX_BUFF_SIZE 1024
#define PORT 2001
#define LOCALHOST "127.0.0.1"

#include <list>
#include <string>
#include <iostream>
#include <boost/asio.hpp>
using namespace boost::asio;

struct AuthData;
class ChatClientController;

class ChatClientModel {
public:
    void SendMsg(std::string);
    void Init(ChatClientController*);
    bool Run();
    void SetAuth(AuthData);

    ChatClientModel();

private:
    ChatClientController* _controller;
    io_service _service;
    ip::tcp::endpoint _ep;
    ip::tcp::socket _socket;
    char _buff[MAX_BUFF_SIZE];
    size_t _alreadyRead;
    AuthData *_auth;

    void showMsg();
    void login();
    void getMsg();
    size_t readComplete(const boost::system::error_code &, size_t);
};

#endif //CHATCLIENTMODEL_H
