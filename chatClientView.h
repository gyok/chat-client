#ifndef CHATCLIENTVIEW_H
#define CHATCLIENTVIEW_H

#include <string>
#include <iostream>
#include <unistd.h>
using namespace std;

struct AuthData;
class ChatClientController;

class ChatClientView {
public:
    void DrawMsg(string);
    void Init(ChatClientController*);
    bool Run();
    AuthData Authenticate();

private:
    ChatClientController* _controller;

    void sendMsg(string);
};

#endif // CHATCLIENTVIEW_H
