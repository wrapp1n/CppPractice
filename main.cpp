#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
	int Ball[53] = {};
	srand((unsigned)time(NULL));

	for (int i = 1; i <= 52; i++)
	{
		Ball[i] = i;
	}
	
	for (int i = 1; i <= 52; i++)
	{	
		
		while (true)
		{
			int ran = rand() % 52 + 1;
			if (Ball[ran] != 0)
			{
				cout << Ball[ran] << endl;
				Ball[ran] = 0;
				break;
			}
			else if (Ball[ran] = 0)
			{
				continue;
			}
		}
	}

	return 0;
}