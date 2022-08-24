#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED



#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


///Primary function to map v1.0
char chess[8][8] =
{
	{ 'T', 'C', 'B', 'Q', 'K', 'B', 'C', 'T' },
	{ 'P', 'P', 'P','P' ,'P' ,'P' , 'P', 'P' },
	{ ' ', ' ', ' ',' ' ,' ' ,' ' , ' ', ' ' },
	{ ' ', ' ', ' ',' ' ,' ' ,' ' , ' ', ' ' },
	{ ' ', ' ', ' ',' ' ,' ' ,' ' , ' ', ' ' },
	{ ' ', ' ', ' ',' ' ,' ' ,' ' , ' ', ' ' },
	{ 'p', 'p', 'p', 'p' , 'p', 'p', 'p', 'p'},
	{ 't', 'c', 'b', 'k', 'q', 'b', 'c', 't', }

};

///Primary function to draw board size v1.0
void DrawBoard(int line, int col, int r, char letter, char piece)
{
    ///If line + col % 2 == 0 then this instruction is a par then the caracter is 'xB2', else ' '
    letter = (r == 1 && piece != ' ') ? piece : letter;
    if((line + col ) % 2 == 0)
    {
        printf("\xB2\xB2%c\xB2\xB2", letter);
    }
    else
    {
        printf("  %c  ", letter);
    }
}

void BoardObjectTransform(int x, int y)
{
    for(int i = 0; i < x; i++)
    {
        printf("\t");
    }

    for(int j = 0; j < y; j++)
    {
        printf("\n");
    }
}


///Draw map second function son's of board map v1.0
int printScreenText()
{
	system("cls");
	BoardObjectTransform(0, 5);
	int line, col, r;
		for (line = 0; line < 8; line++)
		{
		    for(r = 0; r < 3; r++)
            {
                BoardObjectTransform(5, 0);
                for (col = 0; col < 8; col++)
                {
                    char piece = chess[line][col];
                    char letter = ((line + col ) % 2 == 0) ? '\xB2' : ' ';
                    DrawBoard(line, col, r, letter, piece);
                }
                printf("\n");
		    }
		}
    return 0;
}

int MovePiece(int lineOrigin, int colOrigin, int lineDestiny, int colDestiny)
{
    int moove,
        verticalDisplacement = abs(lineDestiny - lineOrigin),
        horizontalDisplacement = abs(colDestiny - colOrigin);
    char piece;
    if
    (
        (lineOrigin >= 0 && lineOrigin < 8 && colOrigin >= 0 && colOrigin < 8) &&
        (lineDestiny >= 0 && lineDestiny < 8 && colDestiny >= 0 && colDestiny < 8)
    )
    {
        piece = chess[lineOrigin][colOrigin];

        ///Pieces limitations
        if((piece == 'T' || piece == 't') && (verticalDisplacement == 0 || horizontalDisplacement == 0)) moove = 1;
        if((piece == 'B' || piece == 'b') && (verticalDisplacement == horizontalDisplacement)) moove = 1;
        if((piece == 'C' || piece == 'c') && ((verticalDisplacement == 1 && horizontalDisplacement == 2) || (verticalDisplacement == 2 && horizontalDisplacement == 1))) moove = 1;
        if((piece == 'Q' || piece == 'q') && ((verticalDisplacement == horizontalDisplacement) || (verticalDisplacement == 0 || horizontalDisplacement == 0) ) ){ moove = 1; }


        ///Pieces movement
        if(moove == 1)
        {
            chess[lineDestiny][colDestiny] = chess[lineOrigin][colOrigin];
            chess[lineOrigin][colOrigin] = ' ';
        }
        return 1;
    }
    else
    {
        return 0;
    }

}


#endif // BOARD_H_INCLUDED
