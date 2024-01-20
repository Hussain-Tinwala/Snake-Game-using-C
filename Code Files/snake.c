/*
		  Snake Game
A simple sanke game using C programming
Control the snake using 'W','A','S','D' keys.

Project By- Tinwala Hussain S.

*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

int height = 80, width = 20;
int x, y, fruitX, fruitY, score, gameover, flag;
int tailX[100], tailY[100], countail = 0, life = 3;

void welcomescreen();
void informationscreen();
void setposition();
void boundary();
void keyinput();
void logic();
void exitscreen();
void changeTextColor(int textcolor);

int main()
{
	char restart;
	welcomescreen();
	informationscreen();
restartagain:
	countail = 0;
	setposition();
	while (!gameover)
	{
		boundary();
		keyinput();
		logic();
	}
	if (gameover)
	{
		changeTextColor(1);
		printf("\n\t\t\t\t\t\t\t!!!!!Game Over!!!!!");
		changeTextColor(2);
		printf("\n\t\t\t\t\t\t\t   Your Score :%d", score);
		changeTextColor(4);
		printf("\n\n\t\t\t\t\t\t\tYou have %d Life Left ", --life);
		getch();
		if (life != 0)
		{
			goto restartagain;
		}
		else
		{
			exitscreen();
			system("cls");
		}
	}

	return 0;
}

void welcomescreen()
{

	system("cls");
	changeTextColor(2);
	printf("\n\n\n\n\n");
	printf("\n\t\t\t    _________              __              ________                        ");
	printf("\n\t\t\t   /   _____/ ____ _____  |  | __ ____    /  _____/_____    _____   ____   ");
	printf("\n\t\t\t   \\_____  \\ /    \\__  \\ |  |/ // __ \\  /   \\  ___\\__  \\  /     \\_/ __ \\  ");
	printf("\n\t\t\t   /        \\   |  \\/ __ \\|    <\\  ___/  \\    \\_\\  \\/ __ \\|  Y Y  \\  ___/  ");
	printf("\n\t\t\t  /_______  /___|  (____  /__|_ \\___  >  \\______  (____  /__|_|  /\\___  > ");
	printf("\n\t\t\t          \\/     \\/     \\/     \\/    \\/          \\/     \\/      \\/     \\/  ");
	printf("\n\n\t\t\t\t\t\t  ");
	changeTextColor(7);
	for (int i = 0; i < 10; i++)
	{
		printf("%c ", 220);
		Sleep(200);
	}
	system("cls");
}

void informationscreen()
{
	changeTextColor(7);
	printf("\n\n\n\n\t\t\t\t------------------------------------------------------------");
	changeTextColor(2);
	printf("\n\t\t\t\t\t\t     How to Play the Game ? ");
	changeTextColor(7);
	printf("\n\t\t\t\t------------------------------------------------------------");
	changeTextColor(6);
	printf("\n\n\n\t\t\t\tUse keys 'W','A','S','D'");
	printf("\n\n\t\t\t\tW -> To Move Snake Up");
	printf("\n\t\t\t\tA -> To Move Snake Left");
	printf("\n\t\t\t\tS -> To Move Snake Down");
	printf("\n\t\t\t\tD -> To Move Snake Down");
	changeTextColor(2);
	printf("\n\n\t\t\t\tFor each fruit eaten by snake, Score will increase by 5 points");
	changeTextColor(7);
	printf("\n\n\n\n\n\n\n\n\n\n\t\t\tPress any key to continue....");
	getch();
}

void exitscreen()
{
	system("cls");
	// printf("\n\n\n\n\n\n\t\t\t\t\t-------------------------------------------");
	changeTextColor(4);
	printf("\n\n\n\t\t\t\t\t    Thanks For Playing the Snake Game");
	changeTextColor(7);
	printf("\n\n\t\t\t\t\t-------------------------------------------");
	changeTextColor(2);
	printf("\n\n\t\t\t\t\t\tDeveloped By : Hussain Tinwala");
	changeTextColor(4);
	printf("\n\n\t\t\t\t\tFollow for more on -");
	changeTextColor(7);
	printf("\n\t\t\t\t\t-------------------------------------------");
	printf("\n\n\t\t\t\t\tLinkedin: https://www.linkedin.com/in/hussaintin");
	printf("\n\t\t\t\t\tGithub: https://github.com/Hussain-Tinwala");
	printf("\n\t\t\t\t\t-------------------------------------------");
	printf("\n\n\t\t\t\t\tPlease wait a second....");
	printf("\n\n\t\t\t\t\t\t\t");
	for (int i = 0; i < 5; i++)
	{
		printf("%c ", 248);
		Sleep(500);
	}
}

void setposition()
{
	gameover = 0;
	x = width / 2;
	y = height / 2;

fr_X:
	fruitX = rand() % 20;
	if (fruitX == 0 || fruitX == width)
	{
		goto fr_X;
	}

fr_Y:
	fruitY = rand() % 80;
	if (fruitY == 0 || fruitY == width)
	{
		goto fr_Y;
	}
	score = 0;
}

void keyinput()
{
	if (kbhit())
	{
		switch (getch())
		{
		case 'a':
			flag = 1;
			break;
		case 's':
			flag = 2;
			break;
		case 'w':
			flag = 3;
			break;
		case 'd':
			flag = 4;
			break;
		case 'x':
			gameover = 1;
			break;
		}
	}
}

void logic()
{
	int i;
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2x, prev2y;
	tailX[0] = x;
	tailY[0] = y;

	for (i = 1; i < countail; i++)
	{
		prev2x = tailX[i];
		prev2y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2x;
		prevY = prev2y;
	}

	switch (flag)
	{
	case 1:
		y--;
		break;
	case 2:
		x++;
		break;
	case 3:
		x--;
		break;
	case 4:
		y++;
		break;
	default:
		break;
	}
	if (x < 0 || x >= width || y < 0 || y >= height)
	{
		gameover = 1;
	}
	for (i = 0; i < countail; i++)
	{
		if (x == tailX[i] && y == tailY[i])
		{
			gameover = 1;
		}
	}
	if (fruitX == x && fruitY == y)
	{
	fr_X1:
		fruitX = rand() % 20;
		if (fruitX == 0 || fruitX == width)
		{
			goto fr_X1;
		}

	fr_Y1:
		fruitY = rand() % 80;
		if (fruitY == 0 || fruitY == width)
		{
			goto fr_Y1;
		}
		score += 5;
		countail++;
	}
}

void boundary()
{
	system("cls");
	changeTextColor(2);
	printf("\n\n\t\t\t\t\t\t\t      SCORE : %d", score, life);
	changeTextColor(4);
	printf("\t\t\t\tLife : %d", life);
	printf("\n\t\t\t  ");
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			if (i == 0 || j == 0 || i == width - 1 || j == height - 1)
			{
				changeTextColor(7);
				printf("#");
			}
			else
			{
				if (i == x && j == y)
				{
					changeTextColor(4);
					printf("%c", 220);
				}
				else if (i == fruitX && j == fruitY)
				{
					changeTextColor(3);
					printf("O");
				}
				else
				{
					int printblank = 1;
					for (int k = 0; k < countail; k++)
					{
						if (i == tailX[k] && j == tailY[k])
						{
							changeTextColor(4);
							printf("%c", 220);
							printblank = 0;
						}
					}
					if (printblank)
					{
						printf(" ");
					}
				}
			}
		}
		printf("\n\t\t\t  ");
	}
}

void changeTextColor(int textColor)
{
	printf("\x1b[38;5;%dm", textColor);
}
