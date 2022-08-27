#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

#define WIDTH 640
#define HEIGHT 480
#define null NULL

SDL_Window *window;
SDL_Renderer *render;
SDL_Event event;

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

SDL_Texture *images[12];
char nameImages[][50] =
{
  "BW.png",
  "BB.png",
  "HW.png",
  "HB.png",
  "KW.png",
  "KB.png",
  "QW.png",
  "QB.png",
  "PW.png",
  "PB.png",
  "TW.png",
  "TB.png"
};

char pieces[] = { 'b', 'B', 'c', 'C', 'k', 'K', 'q', 'Q', 'p', 'P', 't', 'T' };

int lineOfOrigin = -1, colOfOrigin = -1;

void LoadImages()
{
    if(IMG_Init(IMG_INIT_PNG) == IMG_INIT_PNG)
    {
        printf("[ENGINE]: Loading images ...\n");
        int i;
        for(i = 0; i < 12; i++)
        {
            char nameIMG[50] = "Assets/";
            strcat(nameIMG, nameImages[i]);
            printf("[ENGINE]: Image : %s\n", nameIMG);
            SDL_Surface *surImage = IMG_Load(nameIMG);
            images[i]  = SDL_CreateTextureFromSurface(render, surImage);

        }
    }
    else
    {
        printf("[SYSTEM]Images not loaded!!!");
    }
}

void InitializeGraphics()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) >= 0)
    {
        printf("\nSDL has been initialized...");
        window = SDL_CreateWindow("GGE C H E S S", 50, 50, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
        if(window != null)
        {
            printf("\nWindow has been initialized with success\n");
            render = SDL_CreateRenderer(window, -1, 0);
            if(render != null)
            {

            }
            else
            {
                printf("\nSYSTEM:[0xAB03] Not initialized renderer...\n\n");
            }
        }
        else
        {
            printf("\nSYSTEM:[0xAB04] Not created window...\n\n");
        }
    }
    else
    {
        printf("\nSYSTEM:[0xAB05] Not initialized SDL...\n\n");
    }
}

SDL_Texture *ImageFromPiece(char piece)
{
    int i;

    for(i = 0; i < 12; i++)
    {
        if (pieces[i] == piece)
        {
            return images[i];
        }
    }

    return 0;
}

void RenderScreen()
{
    int line,
        col,
        w = WIDTH / 8,
        h = HEIGHT / 8;

    SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
    SDL_RenderClear(render);

    for(line = 0; line < 8; line++)
    {
        for(col = 0; col < 8; col++)
        {
            if((col + line) % 2 == 0)
            {
                SDL_SetRenderDrawColor(render, 0, 191, 255, 255); ///White Color
            }
            else
            {
                SDL_SetRenderDrawColor(render, 255, 255, 255, 255); ///Cian Color
            }

            int x = (col * w), y = (line * h);

            SDL_Rect rectangle = {x, y, w, h};

            SDL_RenderFillRect(render, &rectangle);

            char p = chess[line][col];

            if (p != ' ')
            {
                int wOrigin, hOrigin;

                SDL_Texture *img = ImageFromPiece(p);

                SDL_QueryTexture(img, null, null, &wOrigin, &hOrigin);

                SDL_Rect rectangleOrigin = {0, 0, wOrigin, hOrigin};

                SDL_RenderCopy(render, img, &rectangleOrigin, &rectangle);
            }

            if(lineOfOrigin == line && colOfOrigin == col)
            {
                SDL_SetRenderDrawColor(render, 0, 128, 0, 255); ///Green Color
                SDL_RenderDrawRect(render, &rectangle);
            }
        }
    }

    SDL_RenderPresent(render);
}

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
        (lineDestiny >= 0 && lineDestiny < 8 && colDestiny >= 0 && colDestiny < 8) &&
        (verticalDisplacement + horizontalDisplacement > 0)
    )
    {
        piece = chess[lineOrigin][colOrigin];

        ///Pieces limitations
        if((piece == 'T' || piece == 't') && (verticalDisplacement == 0 || horizontalDisplacement == 0)) moove = 1;
        if((piece == 'B' || piece == 'b') && (verticalDisplacement == horizontalDisplacement)) moove = 1;
        if((piece == 'C' || piece == 'c') && ((verticalDisplacement == 1 && horizontalDisplacement == 2) || (verticalDisplacement == 2 && horizontalDisplacement == 1))) moove = 1;
        if((piece == 'Q' || piece == 'q') && ((verticalDisplacement == horizontalDisplacement) || (verticalDisplacement == 0 || horizontalDisplacement == 0) ) ){ moove = 1; }
        if((piece == 'K' || piece == 'k') && ((verticalDisplacement >= 0 && verticalDisplacement <= 1) && (horizontalDisplacement >= 0 && horizontalDisplacement <= 1) ) ){ moove = 1; }
        if((piece == 'P') && ((lineDestiny - lineOrigin) == 1 && (horizontalDisplacement == 0))) moove = 1;
        if((piece == 'p') && ((lineOrigin - lineDestiny) == 1 && (horizontalDisplacement == 0))) moove = 1;

        ///Pieces movement
        if(moove == 1)
        {
            chess[lineDestiny][colDestiny] = chess[lineOrigin][colOrigin];
            chess[lineOrigin][colOrigin] = ' ';
            return 1;
        }
        else
        {
            return 9;
        }
    }
    else
    {
        return 0;
    }

}

void CaptureEvents()
{
    int e = SDL_PollEvent(&event);

    if(event.type == SDL_QUIT)
    {
        exit(0);
    }
    else if(event.type == SDL_MOUSEMOTION)
    {
        //printf("X : %d, Y : %d \n", event.motion.x, event.motion.y);
    }
    else if(event.type == SDL_MOUSEBUTTONDOWN)
    {
        int w = WIDTH / 8;
        int h = HEIGHT / 8;

        ///printf("X : %d, Y : %d \n", event.motion.x, event.motion.y);

        int col = event.motion.x / w;
        int line = event.motion.y / h;

        if(lineOfOrigin == -1)
        {
            lineOfOrigin = line;
            colOfOrigin = col;
        }
        else
        {
            MovePiece(lineOfOrigin, colOfOrigin, line, col);
            lineOfOrigin = -1;
            colOfOrigin = -1;
        }

        //printf("Line : %d  Col : %d\n", line, col);
    }
}


#endif // BOARD_H_INCLUDED
