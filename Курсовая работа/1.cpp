#include <iostream>
#include <conio.h>
#include <clocale>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <set>

#define ME board[inputrow][inputcol]
#define UP board[inputrow - 1][inputcol]
#define DOWN board[inputrow + 1][inputcol]
#define LEFT board[inputrow][inputcol - 1]
#define RIGHT board[inputrow][inputcol + 1]
#define UPLEFT board[inputrow - 1][inputcol - 1]
#define UPRIGHT board[inputrow - 1][inputcol + 1]
#define DOWNLEFT board[inputrow + 1][inputcol - 1]
#define DOWNRIGHT board[inputrow + 1][inputcol + 1]

using namespace std;
int inputrow;
int inputcol;
char O;
char X;
char col;
char row;
char board[9][9];
bool temp;

int sOFFSET_MOVE_ROW[] = { -1, -1, -1,  0,  0,  1,  1,  1 };

int sOFFSET_MOVE_COL[] = { -1,  0,  1, -1,  1, -1,  0,  1 };

int Enter_the_numb(int* Nom)
{
	char buff[100];
	int good;
	do
	{
		std::cin >> buff;
		for (int g = 0; g < strlen(buff); g++)	// проверяем число это или буква
		{
			if (buff[g]<'0' || buff[g]>'9')
			{
				good = 0;
				break;
			}
		}
		if (good == 0)
		{
			printf("Введена буква, попробуйте еще раз");
			system("pause");
		}
		else
		{
			int a = atoi(buff);
			*Nom = a;
		}
	} while (good == 0);
	return *Nom;
}

void player(char arg_me, char arg_ather)
{
	bool temp = false;
	int inputrow_temp = inputrow, inputcol_temp = inputcol;

	if (ME == ' ')
	{
		if (UP != arg_me || DOWN != arg_me || LEFT != arg_me || RIGHT != arg_me || UPLEFT != arg_me || UPRIGHT != arg_me || DOWNLEFT != arg_me || DOWNRIGHT != arg_me)
		{
			ME = arg_me;
			for (int k = 0; k < 8; k++)
			{
				if (k == 0)
					if (UP == arg_ather)
					{
						for (int i = (inputrow - 1); i > 0; i--)
							if (board[i][inputcol] == arg_me)
							{
								temp = true;
								break;
							}
							else
							{
								temp = false;
							}
						if (temp)
						{
							do
							{
								UP = arg_me;
								inputrow--;
							} while (UP == arg_ather);
							inputcol = inputcol_temp;
							inputrow = inputrow_temp;
						}
					}
				if (k == 1)
					if (DOWN == arg_ather)
					{
						for (int i = (inputrow + 1); i < 9; i++)
						{
							if (board[i][inputcol] == arg_me)
							{
								temp = true;
								break;
							}
							else
							{
								temp = false;
							}
						}
						if (temp)
						{
							do
							{
								DOWN = arg_me;
								inputrow++;
							} while (DOWN == arg_ather);
							inputcol = inputcol_temp;
							inputrow = inputrow_temp;
						}
					}
				if (k == 2)
					if (LEFT == arg_ather)
					{
						for (int j = (inputcol - 1); j > 0; j--)
							if (board[inputrow][j] == arg_me)
							{
								temp = true;
								break;
							}
							else
							{
								temp = false;
							}
						if (temp)
						{
							do
							{
								LEFT = arg_me;
								inputcol--;
							} while (LEFT == arg_ather);
							inputcol = inputcol_temp;
							inputrow = inputrow_temp;
						}
					}
				if (k == 3)
					if (RIGHT == arg_ather)
					{
						for (int j = (inputcol + 1); j < 9; j++)
							if (board[inputrow][j] == arg_me)
							{
								temp = true;
								break;
							}
							else
							{
								temp = false;
							}
						if (temp)
						{
							do
							{
								RIGHT = arg_me;
								inputcol++;
							} while (RIGHT == arg_ather);
							inputcol = inputcol_temp;
							inputrow = inputrow_temp;
						}
					}
				if (k == 4)
					if (UPLEFT == arg_ather)
					{
						int i = inputrow;
						int j = inputcol;
						do
						{
							i--;
							j--;
							if (board[i][j] == arg_me)
							{
								temp = true;
								break;
							}
							else
							{
								temp = false;
							}
						} while ((i > 0) && (j < 9));
						if (temp)
						{
							do
							{
								UPLEFT = arg_me;
								inputrow--;
								inputcol--;
							} while (UPLEFT == arg_ather);
							inputcol = inputcol_temp;
							inputrow = inputrow_temp;
						}
					}
				if (k == 5)
					if (UPRIGHT == arg_ather)
					{
						int i = inputrow;
						int j = inputcol;
						do
						{
							i--;
							j++;
							if (board[i][j] == arg_me)
							{
								temp = true;
								break;
							}
							else
							{
								temp = false;
							}
						} while ((i > 0) && (j < 9));
						if (temp)
						{
							do
							{
								UPRIGHT = arg_me;
								inputrow--;
								inputcol++;
							} while (UPRIGHT == arg_ather);
							inputcol = inputcol_temp;
							inputrow = inputrow_temp;
						}
					}
				if (k == 6)
					if (DOWNLEFT == arg_ather)
					{
						int i = inputrow;
						int j = inputcol;
						do
						{
							i++;
							j--;
							if (board[i][j] == arg_me)
							{
								temp = true;
								break;
							}
							else
							{
								temp = false;
							}
						} while ((j > 0) && (i < 9));
						if (temp)
						{
							do
							{
								DOWNLEFT = arg_me;
								inputrow++;
								inputcol--;
							} while (DOWNLEFT == arg_ather);
							inputcol = inputcol_temp;
							inputrow = inputrow_temp;
						}
					}
				if (k == 7)
					if (DOWNRIGHT == arg_ather)
					{
						int i = inputrow;
						int j = inputcol;
						do
						{
							i++;
							j++;
							if (board[i][j] == arg_me)
							{
								temp = true;
								break;
							}
							else
							{
								temp = false;
							}
						} while ((i > 0) && (j < 9));
						if (temp)
						{
							do
							{
								DOWNRIGHT = arg_me;
								inputrow++;
								inputcol++;
							} while (DOWNRIGHT == arg_ather);
							inputcol = inputcol_temp;
							inputrow = inputrow_temp;
						}
					}
			}
		}
	}
};

void win()
{
	cout << "Game over!!!";
	cin.get();
}

void playerone()
{
	int *Nom = new int;
	cin.clear();
	temp = false;
	cout << "Enter row(1-8):";
//	cin >> inputrow;
	Enter_the_numb(Nom);
	inputrow = *Nom;
	cout << "Enter column(1-8):";
//	cin >> inputcol;
	Enter_the_numb(Nom);
	inputcol = *Nom;
	player('X', 'O');
}

bool CanMove(int x, int y){
	// check whether this square is empty
	if (board[x][y] != ' ')
		return false;

	boolean isValid = false;
	// check 8 directions
	for (int i = 0; i < 8; ++i) {
		int curRow = x + sOFFSET_MOVE_ROW[i];
		int curCol = y + sOFFSET_MOVE_COL[i];
		boolean hasOppPieceBetween = false;
		while (curRow >= 1 && curRow < 9 && curCol >= 1 && curCol < 9) {

			if (board[curRow][curCol] == 'X')
				hasOppPieceBetween = true;
			else if ((board[curRow][curCol] == 'O') && hasOppPieceBetween)
			{
				isValid = true;
				break;
			}
			else
				break;

			curRow += sOFFSET_MOVE_ROW[i];
			curCol += sOFFSET_MOVE_COL[i];
		}
		if (isValid)
			break;
	}

	return isValid;
}

int GetPlacesToSet(int *xs, int *ys)
{
	int num = 0;
	for (int i = 1; i<9; i++)
		for (int j = 1; j<9; j++)
			if (CanMove(i, j))
			{
				xs[num] = i;
				ys[num++] = j;
			}
	return num;
}

int tactic(int *n, char arg_ather, char arg_me, int *xs, int *ys)
{
	int n_new = 0;
	int summ_direction = 0;
	int max_summ = 0;
	for (int i = 0; i < *n; i++)
	{
		summ_direction = 0;
		inputrow = xs[i];
		inputcol = ys[i];
		for (int k = 0; k < 8; k++)
		{
			if (k == 0)
				if (UP == arg_ather)
				{
					int temp_temp = 0;
					for (int i = (inputrow - 1); i > 0; i--)
						if (board[i][inputcol] == arg_me)
						{
							temp = true;
							break;
						}
						else
						{
							temp = false;
							temp_temp++;
						}
					if (temp == true)
					{
						summ_direction += summ_direction + temp_temp;
					}
				}
			if (k == 1)
				if (DOWN == arg_ather)
				{
					int temp_temp = 0;
					for (int i = (inputrow + 1); i < 9; i++)
						if (board[i][inputcol] == arg_me)
						{
							temp = true;
							break;
						}
						else
						{
							temp = false;
							temp_temp++;
						}
					if (temp == true)
					{
						summ_direction += summ_direction + temp_temp;
					}
				}
			if (k == 2)
				if (LEFT == arg_ather)
				{
					int temp_temp = 0;
					for (int j = (inputcol - 1); j > 0; j--)
						if (board[inputrow][j] == arg_me)
						{
							temp = true;
							break;
						}
						else
						{
							temp = false;
							temp_temp++;
						}
					if (temp == true)
					{
						summ_direction += summ_direction + temp_temp;
					}
				}
			if (k == 3)
				if (RIGHT == arg_ather)
				{
					int temp_temp = 0;
					for (int j = (inputcol + 1); j < 9; j++)
						if (board[inputrow][j] == arg_me)
						{
							temp = true;
							break;
						}
						else
						{
							temp = false;
							temp_temp++;
						}
					if (temp == true)
					{
						summ_direction += summ_direction + temp_temp;
					}
				}
			if (k == 4)
				if (UPLEFT == arg_ather)
				{
					int temp_temp = 0;
					int i = inputrow;
					int j = inputcol;
					do
					{
						i--;
						j--;
						if (board[i][j] == arg_me)
						{
							temp = true;
							break;
						}
						else
						{
							temp = false;
							temp_temp++;
						}
					} while ((i > 0) && (j < 9));
					if (temp == true)
					{
						summ_direction += summ_direction + temp_temp;
					}
				}
			if (k == 5)
				if (UPRIGHT == arg_ather)
				{
					int temp_temp = 0;
					int i = inputrow;
					int j = inputcol;
					do
					{
						i--;
						j++;
						if (board[i][j] == arg_me)
						{
							temp = true;
							break;
						}
						else
						{
							temp = false;
							temp_temp++;
						}
					} while ((i > 0) && (j < 9));
					if (temp == true)
					{
						summ_direction += summ_direction + temp_temp;
					}
				}
			if (k == 6)
				if (DOWNLEFT == arg_ather)
				{
					int temp_temp = 0;
					int i = inputrow;
					int j = inputcol;
					do
					{
						i++;
						j--;
						if (board[i][j] == arg_me)
						{
							temp = true;
							break;
						}
						else
						{
							temp = false;
							temp_temp++;
						}
					} while ((j > 0) && (i < 9));
					if (temp == true)
					{
						summ_direction += summ_direction + temp_temp;
					}
				}
			if (k == 7)
				if (DOWNRIGHT == arg_ather)
				{
					int temp_temp = 0;
					int i = inputrow;
					int j = inputcol;
					do
					{
						i++;
						j++;
						if (board[i][j] == arg_me)
						{
							temp = true;
							break;
						}
						else
						{
							temp = false;
							temp_temp++;
						}
					} while ((i > 0) && (j < 9));
					if (temp == true)
					{
						summ_direction += summ_direction + temp_temp;
					}
				}
			if (max_summ < summ_direction)
				{
					max_summ = summ_direction;
					n_new = i;
				}
		}
	}
	*n = n_new;
	return *n;
}

void ComputerMove(int *x, int *y)
{
	//CopyMemory(board, pboard, sizeof(board));                //Копирую доску для её использования
	int *xs = new int[64], *ys = new int[64], *pls = new int[64], *n = new int;
	*n = GetPlacesToSet(xs, ys);                       //Получаю места, куда можно поставить фишку (n - количество мест)
	if (n == 0)                               //Если мест нет, то
	{
		delete[] xs;                             //Удаляем переменные
		delete[] ys;
		delete[] pls;
		*x = -1;                                 //Устанавливаем значения позиции, куда поставить в -1
		*y = -1;
		return;                               //Завершаем работу.
	}                                  //Иначе
	if (*n == 1)
	{
		*x = -1;
		*y = -1;
		return;
	}
	else
		tactic(n, 'X', 'O', xs, ys);
//	*n = rand() % (*n-1) + 1;                               
	int a = xs[*n];                               //Получаем координату x
	int b = ys[*n];
	*x = a;
	*y = b;								//Получаем координату y
	delete[] xs;                              //Удаляем переменные
	delete[] ys;
	delete[] pls;
}

bool playertwo(bool *rez)
{
	ComputerMove(&inputrow, &inputcol);
	if (inputcol < 0 && inputrow < 0)
	{
		win();
		*rez = true;
		return rez;
	}
	temp = false;
	player('O', 'X');
}

int main()
{
	bool *rez = new bool;
	*rez = false;
	int newgame;
	bool newgame1 = false;
	srand(time(NULL));
	do
	{
		{
			cout << "Hello, this is a Reversi Game for Two players." << endl << "Player 1 is X. Player 2 is O." << endl;
			for (row = 0; row < 9; row++) //rows
			{
				for (col = 0; col < 9; col++) //columns
					board[row][col] = ' ';
			}
			board[4][4] = 'O';
			board[5][5] = 'O';
			board[5][4] = 'X';
			board[4][5] = 'X';
			board[0][0] = '0';
			board[0][1] = '1';
			board[0][2] = '2';
			board[0][3] = '3';
			board[0][4] = '4';
			board[0][5] = '5';
			board[0][6] = '6';
			board[0][7] = '7';
			board[0][8] = '8';
			board[1][0] = '1';
			board[2][0] = '2';
			board[3][0] = '3';
			board[4][0] = '4';
			board[5][0] = '5';
			board[6][0] = '6';
			board[7][0] = '7';
			board[8][0] = '8';
		}

		int playermovecounter = 0, player = 0, score1 = 0, score2 = 0;

		for (;;)
		{
			if (player != 0)
				system("cls");
			for (row = 0; row<9; row++)
			{
				cout << "------------------" << endl;
				for (col = 0; col<9; col++)
				{
					cout << "|" << board[row][col];
				}
				{
					cout << "|";
				}
				cout << endl;
			}
			cout << "------------------" << endl;
			*rez = false;
			if (player % 2 == 0)
			{
				playerone();
			}
			else
			{
				playertwo(rez);
				if (*rez)
				{
					break;
				}
			}
			player++;
		}
		score1 = 0;
		score2 = 0;
		for (row = 1; row < 9; row++)
		{
			for (col = 1; col < 9; col++)
			{
				if (board[row][col] == 'X')
					score1++;
				else
					if (board[row][col] == 'O')
						score2++;
			}
		}
		if (score1 > score2)
			cout << "Player1 is win" << endl;
		else
			if (score1 < score2)
				cout << "Player2 is win" << endl;;
		if (score1 == score2)
			cout << "It's a draw." << endl;
		cout << "Score:" << endl << "Player 1: " << score1 << endl << "Player 2: " << score2 << endl;
		cout << "Do you want to play again? For new game, press 1. For exit, press E" << endl;
		do
		{
			cin.clear();
			cin >> newgame;
		} while (newgame != 1);
		if (newgame == 1)
			newgame1 = true;
		system("cls");
	} while (newgame == 1);
	if (newgame1 = false)
		system("exit");
	return EXIT_SUCCESS;
}