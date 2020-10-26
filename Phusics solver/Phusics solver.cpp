#include <iostream>
#include <stdio.h>
#include <cmath>
#include <windows.h>

#define log(x) (std::cout << x << ' ')
#define func(x) (pow(x, 2))

// Printing a row that show which element is being edited now

void printRow(int size, int pos) {
	printf("\n");
	for (int i = 0; i < size; i++) {
		if (i == pos)
			printf("[@]");
		else 
			printf("[ ]");
	}
	printf("\n");
}

// sd

void fillArray(float* table[], int x, int y) {
	if (y != 0){
		for (int i = 0; i < y; i++) {
			printf("Fill row %i", i);
			for (int j = 0; j < x; j++) {
				printRow(x, j);
				scanf_s("%f", &table[i][j]);
			}
		}
	}
	else {
		for (int i = 0; i < x; i++) {
			printRow(x, i);
			scanf_s("%f.3", table[i]);
		}
	}
}

//

void printArray(float* table[], int x, int y) {
	if (y != 0) {
		for (int i = 0; i < y; i++) {
			for (int j = 0; j < x; j++) {
				printf("\t %f.3", table[i][j]);
			}
			printf("\n");
		}
	}
	else {
		for (int i = 0; i < x; i++) {
			printf("\t %f.3", *table[i]);
		}
		printf("\n");
	}
}

int main()
{
	// ============================= Setting localization =====================================
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ru");

	// ============================== Initialising variables ==================================
	int x, y;

	printf("Уведіть розміри таблиці (стовпці та ряди через кому)\n");
	scanf_s("%i, %i", &x, &y);

	float **table = new float* [x];
	for (int i = 0; i < x; i++)
		table[i] = new float[y];

	char* heading = new char[x];
	float* average = new float[x];

	float** delta = new float*[x];
	for (int i = 0; i < x; i++)
		delta[i] = new float[y];
	


	printf("Fill headings\n");
	for (int i = 0; i < x; i++) {
		printRow(x, i);
		scanf_s("%c", &heading[x], 1);
	}

	for (int i = 0; i < x; i++) {
		printf("\t %c", heading[i]);
	}
	printf("\n");

	fillArray(table, x, y);

	printArray(table, x, y);

	log('\n');
	
	delete [] table;

	system("pause");
}
