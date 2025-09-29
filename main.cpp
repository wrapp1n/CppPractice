#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

bool bIsRunning = true;

int KeyCode;
int PlayerX = 1;
int PlayerY = 1;
int MonsterX = 1;
int MonsterY = 1;
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

	COORD Mpos = { 5, 3 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Mpos);
	cout << MonsterShape << endl;
}


int main()
{
	
	while (bIsRunning)
	{
		Input();
		Process();
		Render(PlayerX, PlayerY, MonsterX, MonsterY);
	}

	return 0;
}