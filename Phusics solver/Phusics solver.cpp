#include <stdio.h>
#include <cmath>
#include <windows.h>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <functional>

#define findMax(a, b) (a > b) ? a : b
#define findMin(a, b) (a < b) ? a : b

#define subtrack(a, b) (a < 0)&&(b < 0) ? ((abs(a) > abs(b)) ? (-1)*(abs(a) - abs(b)) : abs(b) - abs(a)) : (((a < 0)||(b < 0))&&((a == 0)||(b == 0)) ? findMax(abs(a) ,abs(b)) : (((a < 0)&&(b > 0)||((a > 0)&&(b < 0))) ? findMax(a, b) + abs(findMin(a, b)) : ((a > 0)&&(b > 0)) ? findMax(a, b) - findMin(a, b) : 0))

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

	printf("Write amount of rows and columns separated by comma (\",\")\n");
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

	system("CLS");

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

	for (int j = 0; j < y; j++) {
		for (int i = 0; i < x; i++) {
			deltaTable[i][j] = table[i][j] - average[j];
		}
	}
	printf("\n ");

	printf("\n");
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			printf("\t %8.3f", deltaTable[i][j]);
		}
		printf("\n ");
	}

	for (int j = 0; j < y; j++) {
		float sum = 0.0;
		for (int i = 0; i < x; i++) {
			sum = sum + abs(deltaTable[i][j]);
		}
		averageDelta.push_back(sum / x);
	}

	printf("\n Average delta:");
	for (int i = 0; i < averageDelta.size(); i++)
		printf(" %8.3f  \t", averageDelta[i]);
	printf("\n ");

	printf("\n Error:");
	for (int i = 0; i < averageDelta.size(); i++)
		printf(" %8.3f  \t", averageDelta[i] / average[i]);

	printf("\n ");

	system("pause");
	system("pause");
}
