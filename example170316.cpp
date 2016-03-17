// example170316.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


int main()
{
	FILE *map;
	char symbol;
	map = fopen("map.txt", "r");
	while (!feof(map))
	{
		symbol = fgetc(map);
		switch (symbol)
		{
		case '0':
			printf(" ");
			break;
		case '1':
			printf("%c",219);
			break;
		case '2':
			printf("%c",178);
			break;
		case '3':
			printf("%c",176);
			break;
		case ' ':
			break;
		default:
			printf("%c", symbol);
			break;
		}
	}
	fclose(map);
    return 0;
}

