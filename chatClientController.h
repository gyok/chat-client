#ifndef CHATCLIENTCONTROLLER_H
#define CHATCLIENTCONTROLLER_H

#include <string>
#include "chatClientModel.h"
#include "chatClientView.h"
using namespace std;

struct AuthData {
    string login;
    string password;
};

class ChatClientController {
public:
    void Run();
    void SendMsg(string msg);
    void ShowMsg(string msg);
private:
    ChatClientView* _view;
    ChatClientModel* _model;

};

#endif // CHATCLIENTCONTROLLER_H
