#include <stdio.h>
#include <cmath>
#include <windows.h>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>

#define log(x) (std::cout << x << ' ')
#define func(x) (pow(x, 2))

void printTemplate(int x, int y, int h, int w) {

	printf("\n    ");

	for (int i = 0; i < y; i++) {
		
		printf(" %2i", i);

	}

	printf("\n");

	for (int i = 0; i < x; i++) {

		printf("%2i\. ", i+1);

		for (int j = 0; j < y; j++) {
			
			if ((i == h) && (j == w))
				printf("[#]");
			else
				printf("[ ]");

		}

		printf("\n");

	}

}

int main() {

	int x, y;
	scanf_s("%d, %d", &x, &y);

	std::vector<std::vector<float>> table;
	std::vector<std::vector<float>> deltaTable;
	std::vector<std::string> heading;
	std::vector<float> average;
	std::vector<float> averageDelta;


	for (int i = 0; i < x; i++) {
		table.push_back(std::vector<float>());
		for (int j = 0; j < y; j++) {
			table[i].push_back(0.0);
		}
	}

	for (int i = 0; i < x; i++) {
		deltaTable.push_back(std::vector<float>());
		for (int j = 0; j < y; j++) {
			deltaTable[i].push_back(0.0);
		}
	}



	for (int i = 0; i < x; i++) {
		printf("Row %i \n", i + 1);
		for (int j = 0; j < y; j++) {
			printTemplate(x, y, i, j);
			scanf_s("%fl", &(table[i][j]));
		}
	}

	printf("\n");
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			printf("\t %8.3f", table[i][j]);
		}
		printf("\n ");
	}

	for (int j = 0; j < y; j++) {
		float sum = 0.0;
		for (int i = 0; i < x; i++) {
			sum += table[i][j];
		}
		average.push_back(sum / x);
	}

	printf("\n Average:");
	for (int i = 0; i < average.size(); i++)
		printf(" %8.3f  \t", average[i]);

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			deltaTable[i][j] = abs(table[i][j]-average[i]);
		}
	}

	for (int j = 0; j < y; j++) {
		float sum = 0.0;
		for (int i = 0; i < x; i++) {
			sum += deltaTable[i][j];
		}
		averageDelta.push_back(sum / x);
	}

	printf("\n Average delta:");
	for (int i = 0; i < average.size(); i++)
		printf(" %8.3f  \t", averageDelta[i]);

}
