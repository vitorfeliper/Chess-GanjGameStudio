/** @param Documentation to GanjGameEngine basic edition v1.0
*   @authr VDEV GanjGameStudio Entertainment Productions

    piece name improvment --> to v1.1 current version v1.0

*/
#include "../Game/Board.h"

int main(int argc, char** argv)
{
    int lineOrigin = 0, lineDestiny = 0, colOrigin = 0, colDestiny = 0;

    while(true)
    {
        printScreenText();
        printf("\nUpercase = Black\nLowercase = White pieces\n");

        printf("Line and col origin(Piece coordinates): ");
        scanf("%d %d", &lineOrigin, &colOrigin);
        printf("\nPiece:%c\n", chess[lineOrigin][colOrigin]);

        printf("Line and col destiny: ");
        scanf("%d %d", &lineDestiny, &colDestiny);

        int result = MovePiece(lineOrigin, colOrigin, lineDestiny, colDestiny);
        if(result != 1)
        {
            switch(result)
            {
            case 9 : printf("\n\n\nSYSTEM:[0xAB00] Piece dont can move this form");  getch(); break;
            case 0 : printf("\n\n\nSYSTEM:[0xAB01] Invalid entrances!!\nPress any key to continue...\n"); getch(); break;
            case 1 : break;
            }
            getch();
        }
    }
	getch();
    return 0;
}
