#include "tictactoe.h"
#include "tictactoebot.h"
#include <iostream>
#include <memory>
#include <taictactoetcpserver.h>
using namespace std;

int main()
{
    // create the window
    TicTacToeTcpServer srv;
    srv.loop();

    return 0;
}
