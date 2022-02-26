#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define DINO_X 0
#define DINO_Y 15
#define TREE_X 94
#define TREE_Y 25

void setting();
void gotoxy(int x, int y);
void start()
int game(int);
void score(int);
int crashing();
void end(int);
void draw_dino(int);
void earase_dino();
void earase_foot();
void tree();
void draw_tree();
void erase_tree();

int treeX = TREE_X;
int dinoX = DINO_X;
int dinoY = DINO_Y;

int key = 0;

int main()
{
    int tic = 0;
    int crash = 0;

    setting();
    start();

    while (1) {

        tic = game(tic);


        if (_kbhit()) {
            key = _getch();
            if (key == 32 && dinoY - 15 == 0) {

                int h = 0;

                while (h < 8) {
                    earase_dino();
                    dinoY--;
                    tic = game(tic);
                    crash = crashing();
                    if (crash == -1)
                        break;
                    h++;
                }

                while (h > 0) {
                    tic = game(tic);
                    crash = crashing();
                    if (crash == -1)
                        break;
                    dinoY++;
                    earase_dino();
                    h--;
                }
            }
        }
        crash = crashing();
        if (crash == -1)
            break;

    }

    end(tic);

    system("pause>>null");
    return 0;
}
int game(int tic) {
    score(tic);
    tree();
    draw_dino(tic);

    Sleep(10);
    tic++;

    return tic;
}

int crashing() {
    if ((dinoX + 6 <= treeX + 2 && dinoX + 9 >= treeX + 2) && dinoY + 10 >= TREE_Y + 2)
        return -1;
    else
        return 0;
}

void draw_dino(int tic) {

    int toc = tic % 8;

    //몸통
    gotoxy(dinoX, dinoY);         printf("              @@@@@@@@\n");
    gotoxy(dinoX, dinoY + 1);      printf("             @@@@@@@@@@@\n");
    gotoxy(dinoX, dinoY + 2);      printf("             @@@ @@@@@@@\n");
    gotoxy(dinoX, dinoY + 3);      printf("             @@@@@@@@@@@\n");
    gotoxy(dinoX, dinoY + 4);      printf("             @@@@@@\n");
    gotoxy(dinoX, dinoY + 5);      printf("     *      @@@@@@@@@@\n");
    gotoxy(dinoX, dinoY + 6);      printf("     @     @@@@@@\n");
    gotoxy(dinoX, dinoY + 7);      printf("     @@  @@@@@@@@@@@@\n");
    gotoxy(dinoX, dinoY + 8);      printf("     @@@@@@@@@@@@   @\n");
    gotoxy(dinoX, dinoY + 9);      printf("     @@@@@@@@@@@@\n");
    gotoxy(dinoX, dinoY + 10);      printf("      @@@@@@@@@@\n");
    gotoxy(dinoX, dinoY + 11);      printf("       @@@@@@@@\n");
    gotoxy(dinoX, dinoY + 12);      printf("         @@@@@@\n");



    if (toc >= 0 && toc <= 3)
    {
        earase_foot();
        gotoxy(dinoX, dinoY + 13);
        printf("         @    @@@\n");
        printf("         @@");
    }
    else
    {
        earase_foot();
        gotoxy(dinoX, dinoY + 13);
        printf("         @@@  @\n");
        printf("              @@");
    }
}

void earase_foot() { //발 지우기
    gotoxy(dinoX, dinoY + 13);
    printf("                 \n");
    printf("                 ");
}

void earase_dino() {
    for (int i = 0; i < 24; i++) {
        gotoxy(dinoX, 6 + i);
        printf("                              ");
    }
    earase_foot();
}


void draw_tree() {
    gotoxy(treeX + 2, TREE_Y);         printf("##\n");
    gotoxy(treeX, TREE_Y + 1);        printf("# ## #\n");
    gotoxy(treeX, TREE_Y + 2);        printf("######\n");
    gotoxy(treeX + 2, TREE_Y + 3);      printf("##\n");
    gotoxy(treeX + 2, TREE_Y + 4);      printf("##");
}

void erase_tree() {
    gotoxy(treeX + 3, TREE_Y);        printf("  \n");
    gotoxy(treeX + 1, TREE_Y + 1);   printf("      \n");
    gotoxy(treeX + 1, TREE_Y + 2);   printf("      \n");
    gotoxy(treeX + 3, TREE_Y + 3);     printf("  \n");
    gotoxy(treeX + 3, TREE_Y + 4);      printf("  ");
}

void tree() {
    treeX--;
    erase_tree();
    draw_tree();

    if (treeX == 0)
        treeX = TREE_X;
}

void gotoxy(int x, int y)
{
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void setting() {
    system("title Jumping Dino by.woo");
    system("mode con:cols=100 lines=30");

    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ConsoleCursor;
    ConsoleCursor.dwSize = 1;
    ConsoleCursor.bVisible = 0;
    SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

void start() {
    while (1) {
        gotoxy(30, 10);
        printf("Press 'Space bar' to start the game");
        draw_dino(0);

        if (_kbhit()) {
            key = _getch();
            if (key == 32) {
                system("cls");
                break;
            }
        }
    }
}

void score(int tic) {
    gotoxy(45, 1);
    printf("score : %4d", tic / 5 * 10);
}

void end(int tic) {
    system("cls");
    int a = 10;
    gotoxy(a, a);      printf(" #####      ##    ##   ##  #######            #####    ##  ##  #######   ######  \n");
    gotoxy(a, a + 1);   printf("##   ##    ####   ### ###   ##  ##           ##   ##   ##  ##   ##  ##   ##  ##  \n");
    gotoxy(a, a + 2);   printf("##        ##  ##  #######   ##               ##   ##   ##  ##   ##       ##  ##  \n");
    gotoxy(a, a + 3);   printf("##        ######  ## # ##   ####             ##   ##   ##  ##   ####     #####   \n");
    gotoxy(a, a + 4);   printf("##  ###   ##  ##  ##   ##   ##               ##   ##   ##  ##   ##       ####    \n");
    gotoxy(a, a + 5);   printf("##   ##   ##  ##  ##   ##   ##  ##           ##   ##    ####    ##  ##   ## ##   \n");
    gotoxy(a, a + 6);   printf(" #####    ##  ##  ##   ##  #######            #####      ##    #######   ###  ## \n");

    gotoxy(40, 20);
    printf("final score : %4d", tic / 5 * 10);
}