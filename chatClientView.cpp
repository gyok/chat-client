#include "chatClientView.h"
#include "chatClientController.h"

void ChatClientView::DrawMsg(string msg) {
    cout << msg << endl;
}

void ChatClientView::Init(ChatClientController* controller) {
    _controller = controller;
}

void ChatClientView::Run() {
    string msg;
    while (msg != "/quit") {
        getline(cin, msg);
        sendMsg(msg);
    }
}

AuthData ChatClientView::Authenticate() {
    AuthData auth;
    cout << "Enter your login: ";
    cin >> auth.login;
    cout << "Enter yout password: ";
    cin >> auth.password;

    return auth;
}

void ChatClientView::sendMsg(string msg) {
    _controller->SendMsg(msg);
}


