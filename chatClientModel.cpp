#include "chatClientController.h"
#include "chatClientModel.h"

ChatClientModel::ChatClientModel()
    : _ep{ip::tcp::endpoint(ip::address::from_string(LOCALHOST), PORT)},
      _socket{ip::tcp::socket(_service)}
{}

void ChatClientModel::SendMsg(std::string msg) {
    _socket.write_some(buffer(msg));
}

void ChatClientModel::Init(ChatClientController* controller) {
    _controller = controller;
}

void ChatClientModel::showMsg() {
    _controller->ShowMsg(std::string(_buff, _alreadyRead));
}

bool ChatClientModel::Run() {
    try {
        _socket.connect(_ep);
        login();
        getMsg();

        return true;
    }
    catch(boost::system::system_error &) {
        std::cout << "server skipped" << std::endl;
    }

    return false;
}

void ChatClientModel::login() {
    SendMsg(_auth->login + " " + _auth->password);
}

void ChatClientModel::SetAuth(AuthData auth) {
    _auth = new AuthData(auth);
}

void ChatClientModel::getMsg() {
    _alreadyRead = 0;
    read(_socket,
         buffer(_buff),
         std::bind(&ChatClientModel::readComplete, this, std::placeholders::_1, std::placeholders::_2));
    showMsg();
}

size_t ChatClientModel::readComplete(const boost::system::error_code &err, size_t bytes) {
    if (err) return 0;

    _alreadyRead = bytes;
    bool found = std::find(_buff, _buff + bytes, '\n') < _buff + bytes;
    return found ? 0 : 1;
}
