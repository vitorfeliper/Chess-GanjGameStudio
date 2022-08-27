/** @param Documentation to GanjGameEngine basic edition v1.0
*   @authr VDEV GanjGameStudio Entertainment Productions

    piece name improvment --> to v1.1 current version v1.0

*/
#include <iostream>
#include "TextAnimation.h"
#include "../Games/Chess/Board.h"

void Game()
{
    system("color 7");
    InitializeGraphics();
    LoadImages();
    std::cout << "GanjGameEngine Welcome" << std::endl;

    while(true)
    {
        RenderScreen();
        CaptureEvents();
        SDL_Delay(69);
    }
}

int main(int argc, char** argv)
{
    keybd_event ( VK_MENU, 0x36, 0, 0 );
    keybd_event ( VK_RETURN, 0x1C, 0, 0 );
    keybd_event ( VK_RETURN, 0x1C, KEYEVENTF_KEYUP, 0 );
    keybd_event ( VK_MENU, 0x38, KEYEVENTF_KEYUP, 0 );

    RunAnimation();
    Game();

    system("Pause");
    return 0;
}
