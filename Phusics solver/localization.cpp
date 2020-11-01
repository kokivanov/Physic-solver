#include "localization.h"
int localization::setLCC(int ID) {
	switch(ID){
	case 1:
		message = "Write amount of rows and columns separated by comma";
		delta = "Delta";
		averageDelata = "Average delta";
		error = "Error";
		currentTable = "Current table";
		row = "Row";
		average = "Average";
		lng = "Choose language";
		return 1;
		break;

	case 2:
		message = "Введите кол-во строчек и столбцов через запятую";
		delta = "Дельта";
		averageDelata = "Среднее значение дельта";
		error = "Погрешность";
		currentTable = "Текущая таблица";
		row = "Ряд";
		average = "Среднее";
		lng = "Выберите язык";
		return 1;
		break;

	default:
		return -1;
		break;
	}
}

int localization::setLoc(std::string name) {
	if ((name.compare("RU") == 0) || (name.compare("ru") == 0))
		return setLCC(2);
	else if ((name.compare("EN") == 0) || (name.compare("en") == 0))
		return setLCC(1);
	else
		return -1;
}


