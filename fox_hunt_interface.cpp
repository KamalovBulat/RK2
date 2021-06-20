#include <iostream>
#include <iostream>
#include <windows.h>
#include <locale>
#include <conio.h>
#include <limits>
#include "source.h"
/* Класс координаты на поле */
class Coord {
public:
	int x_;
	int y_;
	int fox_count;
	Coord() {
		//std::cout << "h";
		x_ = 0;
		y_ = 0;
		fox_count = 0;
	}
	/* Получить координату */
	void get_coord() {
		std::cout << x_ << ' ' << y_;
	}
	/* Получить количество лис в этой координате */
	void get_fox() {
		std::cout << fox_count;
	}
};
/* Класс игрового поля, который состоит из матрицы-объектов координат */
class Board {
public:
	/* Создание матрицы - поля */
	Coord** board = new Coord * [10];
	Board() {
		char fox = 253, user = 1;
		std::cout << fox << "- Fox  " << user << "- User's position" << std::endl;
		for (int j = 0; j < 10; j++) {
			board[j] = new Coord[10];
		}
		/* Вводим координаты */
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				board[i][j].x_ = i;
				board[i][j].y_ = j;
			}
		}
	}
};
/* Отрисовка игрового поля */
class DrawBoard {
public:
	int x_new = 0;
	int y_new = 0;
	int delta = 1;
	char fox = 253;
	char empty_cell = 254;
	int x_user = 0;
	int y_user = 14;
	char user_face = 1;
	DrawBoard() {
		x_new = 6; y_new = 12;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				DrawCell(x_new, y_new);
				x_new = x_new + 2;
			}
			x_new = 6;
			y_new--;
		}
		std::cout << std::endl;
		console_gotoxy(x_user, y_user);
		x_user = 0;
		y_user = y_user + 1;
	}
	void DrawCell(int x_, int y_) {
		console_gotoxy(x_, y_);
		std::cout << empty_cell;
	}
	void DrawFox(int x, int y) {
		int x_ = 6 + 2 * x;
		int y_ = 12 - y;
		console_gotoxy(x_, y_);
		std::cout << fox;
	}
	void DrawUser(int x, int y) {
		int x_ = 6 + 2 * x;
		int y_ = 12 - y;
		console_gotoxy(x_, y_);
		std::cout << user_face;
		y_user = y_user + 3;
		x_user = 0;
		console_gotoxy(x_user, y_user);
	}
	
};

/* Реализация игры */
class Game {
public:
public:								// Старые координаты используются для удаления предыдущей позиции игрока 
	int x_old = 6, y_old = 12;		// Установим начальные значения координат, чтобы не выдавались ошибки
	Board* brd = nullptr;
	Board* brd = nullptr;		
	DrawBoard* dr_brd = nullptr;
	Game(Board* ptr, DrawBoard *d_ptr) {
		brd = ptr;
@@ -229,7 +229,7 @@ class Game {
		}

		dr_brd->DrawUser(x, y);			// Если наступил на позицию, где есть лис, то не высвечивает лиса
		x_old = 6 + 2*x; y_old = 12-y;
		x_old = 6 + 2*x; y_old = 12-y;		// Теперь "новые" координаты будут "старыми"

		return fox;
	}
};
int main() {
	Board* board = new Board;		// Создание поля
	DrawBoard *draw = new DrawBoard;
	std::cout << std::endl;
	Game gm(board, draw);			// Начало игры
	return 0;
}
