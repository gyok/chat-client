#include "chatClientView.h"
#include "chatClientController.h"

void ChatClientView::DrawMsg(string msg) {
    cout << msg << endl;
}

void ChatClientView::Init(ChatClientController* controller) {
    _controller = controller;
}

bool ChatClientView::Run() {
    string msg;
    while (true) {
        boost::this_thread::sleep_for(boost::chrono::milliseconds(100));
        getline(cin, msg);
        if (msg != "") {
            sendMsg(msg);
        }
    }
    return true;
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


