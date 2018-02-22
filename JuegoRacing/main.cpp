#include <windows.h>  
#include <iostream>
#include <thread>
#include <stdio.h>
#include "funciones.h"
#include <conio.h>
#include <time.h>
#include <string>
using namespace std;

int main(){
	int i = 0, nivel = 1, nivel2 = 1, nivel3 = 1, nivel4 = 1, velocidad = 1,acelera =110; 
	int x1 = 0, xx1 = 0, xx2 = 0, xx3 = 1;
	long int h1 = 0, h2 = 0, h3 = 0, h4 = 0, h5 = 0,h6 = 0, h7 = 0, h9 = 0, h10 = 0;
	long int mult2 = 2, mult3 = 3, mult4 = 4, mult5 = 5, mult6 = 6.5, mult7 = 8.5, mult9 = 11, mult10 = 14;
	clock_t comienzo;
	bool n1 = true, n2 = true, n3 = true, n4 = true, n5 = true, n6 = true, n7 = true, n8 = true, n9 = true, n10 = true;
	bool p1 = true, p2 = true, p3 = true, p4 = true, p5 = true, p6 = true, p7 = true, p8 = true, p9 = true, p10 = true;
	bool m1 = true, m2 = true, m3 = true, m4 = true, m5 = true, m6 = true, m7 = true, m8 = true, m9 = true, m10 = true;
	bool k1 = true, k2 = true, k3 = true, k4 = true, k5 = true, k6 = true, k7 = true, k8 = true, k9 = true, k10 = true;
	bool v1 = true, v2 = true, v3 = true, v4 = true, v5 = true, v6 = true, v7 = true, v8 = true, v9 = true, v10 = true;
	bool c1 = true, c2 = true, c3 = true, c4 = true, c5 = true, c6 = true, c7 = true, c8 = true, c9 = true, c10 = true;
	bool z1 = true, z2 = true, z3 = true, z4 = true, z5 = true, z6 = true, z7 = true, z8 = true, z9 = true, z10 = true;
	bool s1 = true, s2 = true, s3 = true, s4 = true, s5 = true, s6 = true, s7 = true, s8 = true, s9 = true, s10 = true;
	bool d1 = true, d2 = true, d3 = true, d4 = true, d5 = true, d6 = true, d7 = true, d8 = true, d9 = true, d10 = true;
	comienzo = clock();
	int opcion;
	int tex = 9;
	do {
		cout << "*****     RACING     *****" << "\n       1.Jugar" << "\n       2.Ver Estadisticas" << "\n       3.Controles" << "\n       4.Salir" << endl;
		cin >> opcion;
		switch (opcion) {
		case 1: {
			system("cls");
			auto start = std::chrono::high_resolution_clock::now();
			Carro bueno = Carro();
			Enemigos malo = Enemigos();
			thread Accion(Controles, &bueno);
			bool running = true;
			while (running) {
				if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
					system("pause>nul");
				}
				if (GetKeyState(VK_UP) & 0x8000)
				{
					acelera = acelera - 3;
				}
				reset();
				malo.Entra();
				malo.crea();
				malo.move();
				malo.paso();
				bueno.crea();
				bueno.Choque(&malo, &running);
				gotoXY(21, 7);
				//EN EL DOCUMENTO QUE SUBIO ING. FALTA LA CANT. DE PUNTOS EN LA VELOCIDAD 8
				if (velocidad == 1) {
					h1 = malo.getPuntos();
				}
				if (velocidad == 2) {
					h2 = mult2 * (malo.getPuntos() - h1);
				}
				if (velocidad == 3) {
					h3 = mult3 * (malo.getPuntos() - h2);
				}
				if (velocidad == 4) {
					h4 = mult4 * (malo.getPuntos() - h3);
				}
				if (velocidad == 5) {
					h5 = mult5 * (malo.getPuntos() - h4);
				}
				if (velocidad == 6) {
					h6 = mult6 * (malo.getPuntos() - h5);
				}
				if (velocidad == 7) {
					h7 = mult7 * (malo.getPuntos() - h6);
				}
				if (velocidad == 9) {
					h9 = mult9 * (malo.getPuntos() - h7);
				}
				if (velocidad == 10) {
					h10 = mult10 * (malo.getPuntos() - h9);
				}
				cout << "Puntos: " << h1 + h2 + h3 + h4 + h5 + h6 + h7 + h9 + h10;
				gotoXY(21, 9);
				cout << "Vidas: " << bueno.vidas;
				for (int j = 0; j<20; j++) {
					for (int i = 0; i<21; i++) {
						if (i == 0 || i == 20) {
							gotoXY(i, j);
							cout << "|";
						}
						else if (pista[i][j] == 1) {
							gotoXY(i, j);
							cout << "X";
						}
						else {
							gotoXY(i, j);
							cout << " ";
						}
					}
				}
				auto finish = std::chrono::high_resolution_clock::now();
				std::chrono::duration<float> elapsed = finish - start;
			    /*gotoXY(21, 11);
				cout << "Tiempo: " << elapsed.count();*/
				gotoXY(21, 13);
				//81-90
				if (elapsed.count() > 1780 && d10 == true) {
					d9 = false;
					while (x1 < 89) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 1760 && d9 == true) {
					d8 = false;
					while (x1 < 88) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 1740 && d8 == true) {
					d7 = false;
					while (x1 < 87) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 1720 && d7 == true) {
					d6 = false;
					while (x1 < 86) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 1700 && d6 == true) {
					d5 = false;
					while (x1 < 85) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 1680 && d5 == true) {
					d4 = false;
					while (x1 < 84) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 1660 && d4 == true) {
					d3 = false;
					while (x1 < 83) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 1640 && d3 == true) {
					d2 = false;
					while (x1 < 82) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 1620 && d2 == true) {
					d1 = false;
					while (x1 < 81) {
						nivel++;
						x1++;
						xx3++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 1600 && d1 == true) {
					s10 = false;
					while (x1 < 80) {
						nivel++;
						x1++;

					}
					cout << "Nivel " << nivel;
				}
				//71-80
				if (elapsed.count() > 1580 && s10 == true) {
					s9 = false;
					while (x1 < 79) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 1560 && s9 == true) {
					s8 = false;
					while (x1 < 78) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 1540 && s8 == true) {
					s7 = false;
					while (x1 < 77) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 1520 && s7 == true) {
					s6 = false;
					while (x1 < 76) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 1500 && s6 == true) {
					s5 = false;
					while (x1 < 75) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 1480 && s5 == true) {
					s4 = false;
					while (x1 < 74) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 1460 && s4 == true) {
					s3 = false;
					while (x1 < 73) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 1440 && s3 == true) {
					s2 = false;
					while (x1 < 72) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 1420 && s2 == true) {
					s1 = false;
					while (x1 < 71) {
						nivel++;
						x1++;
						xx3++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 1400 && s1 == true) {
					z10 = false;
					while (x1 < 70) {
						nivel++;
						x1++;

					}
					cout << "Nivel " << nivel;
				}
				//61-70
				if (elapsed.count() > 1380 && z10 == true) {
					z9 = false;
					while (x1 < 69) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 1360 && z9 == true) {
					z8 = false;
					while (x1 < 68) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 1340 && z8 == true) {
					z7 = false;
					while (x1 < 67) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 1320 && z7 == true) {
					z6 = false;
					while (x1 < 66) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 1300 && z6 == true) {
					z5 = false;
					while (x1 < 65) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 1280 && z5 == true) {
					z4 = false;
					while (x1 < 64) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 1260 && z4 == true) {
					z3 = false;
					while (x1 < 63) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 1240 && z3 == true) {
					z2 = false;
					while (x1 < 62) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 1220 && z2 == true) {
					z1 = false;
					while (x1 < 61) {
						nivel++;
						x1++;
						xx3++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 1200 && z1 == true) {
					c10 = false;
					while (x1 < 60) {
						nivel++;
						x1++;

					}
					cout << "Nivel " << nivel;
				}
				//51-60
				if (elapsed.count() > 1180 && c10 == true) {
					c9 = false;
					while (x1 < 59) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 1160 && c9 == true) {
					c8 = false;
					while (x1 < 58) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 1140 && c8 == true) {
					c7 = false;
					while (x1 < 57) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 1120 && c7 == true) {
					c6 = false;
					while (x1 < 56) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 1100 && c6 == true) {
					c5 = false;
					while (x1 < 55) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 1080 && c5 == true) {
					c4 = false;
					while (x1 < 54) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 1060 && c4 == true) {
					c3 = false;
					while (x1 < 53) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 1040 && c3 == true) {
					c2 = false;
					while (x1 < 52) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 1020 && c2 == true) {
					c1 = false;
					while (x1 < 51) {
						nivel++;
						x1++;
						xx3++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 1000 && c1 == true) {
					v10 = false;
					while (x1 < 50) {
						nivel++;
						x1++;

					}
					cout << "Nivel " << nivel;
				}
				//41-50
				if (elapsed.count() > 980 && v10 == true) {
					v9 = false;
					while (x1 < 49) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 960 && v9 == true) {
					v8 = false;
					while (x1 < 48) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 940 && v8 == true) {
					v7 = false;
					while (x1 < 47) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 920 && v7 == true) {
					v6 = false;
					while (x1 < 46) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 900 && v6 == true) {
					v5 = false;
					while (x1 < 45) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 880 && v5 == true) {
					v4 = false;
					while (x1 < 44) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 860 && v4 == true) {
					v3 = false;
					while (x1 < 43) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 840 && v3 == true) {
					v2 = false;
					while (x1 < 42) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 820 && v2 == true) {
					v1 = false;
					while (x1 < 41) {
						nivel++;
						x1++;
						xx3++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 800 && v1 == true) {
					k10 = false;
					while (x1 < 40) {
						nivel++;
						x1++;

					}
					cout << "Nivel " << nivel;
				}
				//31-40
				if (elapsed.count() > 780 && k10 == true) {
					k9 = false;
					while (x1 < 39) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 760 && k9 == true) {
					k8 = false;
					while (x1 < 38) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 740 && k8 == true) {
					k7 = false;
					while (x1 < 37) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 720 && k7 == true) {
					k6 = false;
					while (x1 < 36) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 700 && k6 == true) {
					k5 = false;
					while (x1 < 35) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 680 && k5 == true) {
					k4 = false;
					while (x1 < 34) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 660 && k4 == true) {
					k3 = false;
					while (x1 < 33) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 640 && k3 == true) {
					k2 = false;
					while (x1 < 32) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 620 && k2 == true) {
					k1 = false;
					while (x1 < 31) {
						nivel++;
						x1++;
						xx3++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 600 && k1 == true) {
					m10 = false;
					while (x1 < 30) {
						nivel++;
						x1++;

					}
					cout << "Nivel " << nivel;
				}
				//21-30
				if (elapsed.count() > 580 && m10 == true) {
					m9 = false;
					while (x1 < 29) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 560 && m9 == true) {
					m8 = false;
					while (x1 < 28) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 540 && m8 == true) {
					m7 = false;
					while (x1 < 27) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 520 && m7 == true) {
					m6 = false;
					while (x1 < 26) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 500 && m6 == true) {
					m5 = false;
					while (x1 < 25) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 480 && m5 == true) {
					m4 = false;
					while (x1 < 24) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 460 && m4 == true) {
					m3 = false;
					while (x1 < 23) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 440 && m3 == true) {
					m2 = false;
					while (x1 < 22) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 420 && m2 == true) {
					m1 = false;
					while (x1 < 21) {
						nivel++;
						x1++;
						xx3++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 400 && m1 == true) {
					p10 = false;
					while (x1 < 20) {
						nivel++;
						x1++;
						
					}
					cout << "Nivel " << nivel;
				}
				//11-20
				if (elapsed.count() > 380 && p10 == true) {
					p9 = false;
					while (x1 < 19) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 360 && p9 == true) {
					p8 = false;
					while (x1 < 18) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 340 && p8 == true) {
					p7 = false;
					while (x1 < 17) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 320 && p7 == true) {
					p6 = false;
					while (x1 < 16) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 300 && p6 == true) {
					p5 = false;
					while (x1 < 15) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 280 && p5 == true) {
					p4 = false;
					while (x1 < 14) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 260 && p4 == true) {
					p3 = false;
					while (x1 < 13) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 240 && p3 == true) {
					p2 = false;
					while (x1 < 12) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 220 && p2 == true) {
					p1 = false;
					while (x1 < 11) {
						nivel++;
						x1++;
						xx3++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 200 && p1 == true) {
					n10 = false;
					while(x1 < 10) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				//1-10
				if (elapsed.count() > 180 && n10 == true) {
					n9 = false;
					while (x1 < 9) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 160 && n9 == true) {
					n8 = false;
					while (x1 < 8) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 140 && n8 == true) {
					n7 = false;
					while (x1 < 7) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 120 && n7 == true) {
					n6 = false;
					while (x1 < 6) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 100 && n6 == true) {
					n5 = false;
					while (x1 < 5) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 80 && n5 == true) {
					n4 = false;
					while (x1 < 4) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 60 && n4 == true) {
					n3 = false;
					while (x1 < 3) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 40 && n3 == true) {
					n2 = false;
					while (x1 < 2) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() > 20 && n2 == true) {
					n1 = false;
					while (x1 < 1) {
						nivel++;
						x1++;
					}
					cout << "Nivel " << nivel;
				}
				if (elapsed.count() < 20 && n1 == true) {
					cout << "Nivel " << nivel;
				}
				
				gotoXY(21, 15);
				if (nivel == 11 || nivel == 21 || nivel == 31 || nivel == 41 || nivel == 51 || nivel == 61 || nivel == 71 || nivel == 81) {
					while (xx2 < xx3) {
						velocidad++;
						acelera = acelera - 5;
						xx2++;
					}
				}
				cout << "Velocidad " << velocidad;

				Sleep(acelera);
			}
			int r = h1 + h2 + h3 + h4 + h5 + h6 + h7 + h9 + h10;
			puntuaciones[tex] = r;
			if (tex >= 0) {
				tex--;
			}
			Sleep(500);
			system("cls");
			gotoXY(5, 4);
			cout << "PERDISTE !!!";
			Sleep(1000);
			system("cls");
			Accion.detach();
			break;
		}
		case 2: {
			system("cls");
			cout << "*****     Estadisticas     *****" << endl;
			for (int i = 0; i != 10; i++) {
				cout << i + 1 << ". " <<"Puntos: " << puntuaciones[i] << endl;
			}
			system("pause>nul");
			system("cls");
			break;
		}
		case 3: {
			system("cls");
			cout << "*****     Controles     *****" ;
			cout << "\n     1.Para mover a la derecha ->" << "\n     2.Para mover a la izquierda <-" << "\n     3.Para pausar el juego ESC" << "\n     4.Para acelerar ^";
			system("pause>nul");
			system("cls");
			break;
		}
		}
	} while (opcion != 4);

	return 0;
}