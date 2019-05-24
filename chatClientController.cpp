#include "chatClientController.h"

void ChatClientController::Run() {
    _view = new ChatClientView();
    _model = new ChatClientModel();

    _model->Init(new ChatClientController());
    _view->Init(this);
    _model->SetAuth(_view->Authenticate());

    boost::thread_group threads;
    threads.create_thread(std::bind(&ChatClientView::Run, _view));
    threads.create_thread(std::bind(&ChatClientModel::Run, _model));
    //_view->Run();
    threads.join_all();
}

void ChatClientController::SendMsg(string msg) {
    _model->SendMsg(msg);
}

void ChatClientController::ShowMsg(string msg) {
    _view->DrawMsg(msg);
}
