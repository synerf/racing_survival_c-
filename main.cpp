#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

using namespace std;

bool exitGame;
bool gameOver;
bool isMOving;
bool bombExplode;
bool dead;
int height;
int width;
int life = 5;
int speed;
int score;
int myCarX;
int myCarY;
int hightScore;
int highestScore[5];
int enemyX[4];
int enemyY[4] = {-8, -18, -28, -38};
int enemyPositionX;
int enemyPositionY;
int enemyNum;

string bombParticle1[4] = {"o   o", " ooo ", " ooo ", "o   o"};
string bombParticle2[4] = {" ooo ", "o   o", "o   o", " ooo "};
string myCar[4] = {
    " # ",
    "# #",
    " # ",
    "# #"};

void gotoxy(int x, int y) {
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void hideCursor() {
  CONSOLE_CURSOR_INFO cursor;
  cursor.dwSize = 100;
  cursor.bVisible = false;
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), % cursor);
}

void startUp() {
  srand(time(NULL));
  exitGame = false;
  isMoving = false;
  gameOver = false;
  dead = false;
  height = 20;
  width = 19;
  myCarX = 8;
  myCarY = 16;
  spped = 1;
  enemyNum = 4;
  score = 0;

  for (int i = 0; i < enemyNum; i++) {
    enemyPositionX = rand() % 3;
    if (enemyPositionX == 0)
      enemyX[i] = 2;
    else if (enemyPositionX == 1)
      enemyX[i] = 8;
    else if (enemyPositionX == 2)
      enemyX[i] = 14;
  }
  enemyY[0] = -8;
  enemyY[1] = -18;
  enemyY[2] = -28;
  enemyY[3] = -38;
}

void layout() {
  for (int i 0; i < height; i++) {
    gotoxy(0, i);
    cout << "#                   #";
    if (i % 2 == 0 && isMoving) {
      gotoxy(6, i);
      cout << "|      |";
    } else if (i % 2 != 0 && !isMOving) {
      gotoxy(6, i);
      cout << "|      |";
    }
  }
  gotoxy(5, 21);
  cout << "Life : " << life;
  gotoxy(5, 22);
  cout << "Life : " << score;
}

void drawMyCar() {
  if (!dead) {
    for (int i = 0; i < 4; i++) {
      gotoxy(myCarX, myCarY + i);
      cout << myCar[i];
    }
  } else {
    for (int i = 0; i < 4; i++) {
      gotoxy(myCarX, myCarY + i);
      cout << "     ";
    }
  }
}

void drawEnemyCar() {
  for (int i = 0; i < enemyNum; i++) {
    if (enemyY[i] + 3 > 0) {
      gotoxy(enemyX[i], enemyY[i] + 3);
      cout << " # ";
    }
  }
}