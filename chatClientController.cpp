#include "chatClientController.h"

void ChatClientController::Run() {
    _view = new ChatClientView();
    _model = new ChatClientModel();

    _model->Init(new ChatClientController());
    _view->Init(this);
    _model->SetAuth(_view->Authenticate());

    if (_model->Run()) {
        _view->Run();
    }
}

void ChatClientController::SendMsg(string msg) {
    _model->SendMsg(msg);
}

void ChatClientController::ShowMsg(string msg) {
    _view->DrawMsg(msg);
}
