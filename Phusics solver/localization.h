#pragma once

#ifndef LOCALIZATION_CLS

#define LOCALIZATION_CLS
#include <string>
#include <windows.h>

class localization
{
public:
    std::string message = "Write amount of rows and columns separated by comma";
    std::string delta = "Delta";
    std::string averageDelata = "Average delta";
    std::string error = "Error";
    std::string currentTable = "Current table";
    std::string row = "Row";
    std::string average = "Average";
    std::string lng = "Choose language";

    int setLoc(std::string language_specifier);
private:
    int setLCC(int ID_of_language);
};

#endif // !LOCALIZATION_CLS



