#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

bool bIsRunning = true;

int KeyCode;
int PlayerX = 1;
int PlayerY = 1;
int MonsterX = 5;
int MonsterY = 3;
char PlayerShape = 'P';
char MonsterShape = 'M';

void Input()
{
	KeyCode = _getch();
}

void Process()
{
	if (KeyCode == 'w')
	{
		PlayerY--;
	}

	else if (KeyCode == 's')
	{
		PlayerY++;
	}

	else if (KeyCode == 'a')
	{
		PlayerX--;
	}

	else if (KeyCode == 'd')
	{
		PlayerX++;
	}

	else if (KeyCode == 'q')
	{
		bIsRunning = false;
	}
	
}

void Render(int PlayerX, int PlayerY, int MonsterX, int MonsterY)
{
	system("cls");
	COORD Ppos = { PlayerX, PlayerY };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Ppos);
	cout << PlayerShape ;

	int Mmove = rand() % 5;

	if (Mmove == 1)
	{
		--MonsterY;
	}
	else if (Mmove == 2)
	{
		++MonsterY;
	}
	else if (Mmove == 3)
	{
		--MonsterX;
	}
	else if (Mmove == 4)
	{
		++MonsterX;
	}
	
	COORD Mpos = { MonsterX, MonsterY };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Mpos);
	cout << MonsterShape << endl;
	
}


int main()
{
	srand((unsigned int)time(NULL));
	while (bIsRunning)
	{
		Input();
		Process();
		Render(PlayerX, PlayerY, MonsterX, MonsterY);
	}

	return 0;
}