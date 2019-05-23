#include <iostream>
#include "chatClientController.h"

using namespace std;

int main()
{
    auto controller = new ChatClientController();
    controller->Run();

    return 0;
}
