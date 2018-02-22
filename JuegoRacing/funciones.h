#pragma once
#include <iostream>
#include "windows.h"
#include <thread>
#include <string>
#include <chrono>
using namespace std;
void gotoXY(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int pista[21][20];
int puntuaciones[10];
void forma(int x, int y) {
	if (y<20 && y >= -0) {
		pista[x][y] = 1;
	}
}
void reset() {
	for (int j = 0; j<20; j++) {
		for (int i = 1; i<20; i++) {
			pista[i][j] = 0;
		}
	}
}

class Enemigos {
public:
	Enemigos() {
		xPos = 1;
		yPos = -3;
	}
	int xPos;
	int yPos;
	int puntos = 0;
	void Entra() {
		if (yPos == 20) {
			int ran = rand() % 5;
			if (ran == 0) {
				xPos = 1;
			}
			else if (ran == 1) {
				xPos = 5;
			}
			else if (ran == 2) {
				xPos = 9;
			}
			else if (ran == 3) {
				xPos = 13;
			}
			else if (ran == 4) {
				xPos = 17;
			}
			yPos = -3;
		}
	}
	void crea() {
		forma(xPos, yPos);
		forma(xPos + 2, yPos);
		forma(xPos + 1, yPos + 1);
		forma(xPos, yPos + 2);
		forma(xPos + 2, yPos + 2);

	}
	void move() {
		yPos++;
	}
	void paso() {
		if (yPos >= 20) {
			puntos = puntos + 20;
		}
	}
	int getPuntos() {
		return puntos;
	}
};
class Carro {
public:
	int xPos;
	int yPos;
	int vidas = 3;
	Carro() {
		xPos = 1;
		yPos = 17;
	}
	void crea() {
		forma(xPos, yPos);
		forma(xPos + 2, yPos);
		forma(xPos + 1, yPos + 1);
		forma(xPos, yPos + 2);
		forma(xPos + 2, yPos + 2);	
	}
	void moveLeft() {
		if (xPos == 5) {
			xPos = 1;
		}
		else if(xPos == 9){
			xPos = 5;
		}
		else if (xPos == 13) {
			xPos = 9;
		}
		else if (xPos == 17) {
			xPos = 13;
		}
	}
	void moveRight() {
		if (xPos == 1) {
			xPos = 5;
		}
		else if(xPos == 5){
			xPos = 9;
		}
		else if (xPos == 9) {
			xPos = 13;
		}
		else if (xPos == 13) {
			xPos = 17;
		}
	}
	void Choque(Enemigos *E, bool *running) {
		if (E->xPos == xPos && E->yPos>=16) {
			vidas = vidas - 1;
			reset();
			E->yPos = -3;
			system("pause>nul");
			if (vidas == -1) {
				*running = false;
			}
			
		}
	}
};
void Controles(Carro *c)	 {
	while (1) {
		if (GetAsyncKeyState(VK_LEFT) & (0x8000 != 0)) {
			c->moveLeft();
		}
		else if (GetAsyncKeyState(VK_RIGHT) & (0x8000 != 0)) {
			c->moveRight();
		}
	}
}