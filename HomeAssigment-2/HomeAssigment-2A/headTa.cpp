/* Kirill Sagorin st128530@student.spbu.ru
Home Assignment 2a */

#include "headTa.h"
#include <iostream>
#include <filesystem>
#include <string>

int GetFileSize(std::string filename)
{
	return (int)std::filesystem::file_size((std::filesystem::path)filename) - 1;
}

char* ReadFileInArray(std::string filename)
{
	std::filesystem::path mypath = filename;
	int size = (int)std::filesystem::file_size(mypath) - 1;
	char* text = new char(size);

	std::ifstream file;
	file.open(mypath, std::ios::in | std::ios::binary);
	file.read(text, size);
	
	file.close();

	return text;
}

void ChangeDirrection(char* array, int size)
{
	char a;
	for(int i = 0; i < size / 2; i++)
	{
		a = array[i];
		array[i] = array[size - 1 - i];
		array[size - 1 - i] = a;
	}
}
