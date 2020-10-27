#include <stdio.h>
#include <cmath>
#include <windows.h>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>

void init_2dVector(std::vector<std::vector<float>>* vector, int x, int y) {

	for (int i = 0; i < x; i++) {

		(*vector).push_back(std::vector<float>());

		for (int j = 0; j < y; j++) 
			(*vector)[i].push_back(0.0);
	}
}

void print_2dVector(std::vector<std::vector<float>>* vector, int x, int y) {

	printf("\n");

	for (int i = 0; i < x; i++) {

		for (int j = 0; j < y; j++) 
			printf("\t %8.3f", (*vector)[i][j]);
		
		printf("\n ");
	}
}

void print_vector(std::vector<float>* vector) {

	for (int i = 0; i < (*vector).size(); i++)
		printf(" %8.3f  \t", (*vector)[i]);

}

std::vector<float> averageColumn(std::vector<std::vector<float>>* vectorFrom, int rows/*x*/, int columns/*y*/) {

	std::vector<float> average;

	for (int j = 0; j < columns; j++) {

		float sum = 0.0;

		for (int i = 0; i < rows; i++)
			sum += abs((*vectorFrom)[i][j]);

		average.push_back(sum / rows);
	}
	return average;
}

void printTemplate(int x, int y, int h, int w) {

	printf("\n    ");

	for (int i = 0; i < y; i++) 
		printf(" %2i", i);

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

	init_2dVector(&table, x, y);
	init_2dVector(&deltaTable, x, y);

	for (int i = 0; i < x; i++) {
		printf("Row %i \n", i + 1);
		for (int j = 0; j < y; j++) {
			printTemplate(x, y, i, j);
			scanf_s("%fl", &(table[i][j]));
		}
	}

	system("CLS");

	printf("Current table: \n");
	print_2dVector(&table, x, y);

	average = averageColumn(&table, x, y);

	printf("\n Average:");
	print_vector(&average);

	for (int j = 0; j < y; j++) {
		for (int i = 0; i < x; i++) {
			deltaTable[i][j] = table[i][j] - average[j];
		}
	}

	printf("\n ");

	printf("\n Delta:\n");
	print_2dVector(&deltaTable, x, y);

	averageDelta = averageColumn(&deltaTable, x, y);

	printf("\n Average delta:");
	print_vector(&averageDelta);
	printf("\n ");

	printf("\n Error:");
	for (int i = 0; i < averageDelta.size(); i++)
		printf(" %8.3f  \t", averageDelta[i] / average[i]);

	printf("\n ");

	system("pause");
	system("pause");
}
