/** @param Documentation to GanjGameEngine basic edition v1.0
*   @authr VDEV GanjGameStudio Entertainment Productions

    piece name improvment --> to v1.1 current version v1.0

*/
#include <iostream>
#include "../Games/Chess/Board.h"

int main(int argc, char** argv)
{
    InitializeGraphics();
    LoadImages();
    ///getch();
    system("Pause");
    std::cout << "GanjGameEngine Welcome" << std::endl;
    int lineOrigin = 0, lineDestiny = 0, colOrigin = 0, colDestiny = 0;

    while(true)
    {
        RenderScreen();
        CaptureEvents();
        SDL_Delay(10);
        //printScreenText();
        ///printf("\nUpercase = Black\nLowercase = White pieces\n");

        ///printf("Line and col origin(Piece coordinates): ");
        ///scanf("%d %d", &lineOrigin, &colOrigin);
        ///printf("\nPiece:%c\n", chess[lineOrigin][colOrigin]);

        ///printf("Line and col destiny: ");
        ///scanf("%d %d", &lineDestiny, &colDestiny);

        ///int result = MovePiece(lineOrigin, colOrigin, lineDestiny, colDestiny);
    /*
        if(result != 1)
        {
            system("cls");
            switch(result)
            {
                case 9 : printf("\n\n\nSYSTEM:[0xAB00] Invalid(PIECE) entrances!!\nPress any key to continue...\n"); getch(); break;
                case 0 : printf("\n\n\nSYSTEM:[0xAB01] Invalid entrances!!\nPress any key to continue...\n"); getch(); break;
                case 1 : break;
            }
            printf("\n\n\nSYSTEM:[0xAB01] Invalid entrances!!\nPress any key to continue...\n");
            getch();
        }
        */
    }
    return 0;
}
