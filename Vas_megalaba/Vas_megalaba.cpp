﻿#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Pipe
{
public:
	string pipename = "";
	int pipelength = 0;
	int pipediameter = 0;
	int piperepair = 0;
	int repair = 0;

};


template <typename T>
void InputCorrectNumber(T& var)
{
	cin >> var;
	while (cin.fail() || cin.peek() != '\n' || var < 1)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Error! Please enter correct data: ";
		cin >> var;
	}
}

void AddPipe(Pipe& pipe) {
	cout << "Enter the name of the pipe: ";
	cin.ignore();
	getline(cin, pipe.pipename);
	cout << "Enter the pipe length (in kilometers): ";
	InputCorrectNumber(pipe.pipelength);

	cout << "Enter the pipe diameter (in millimeters): ";
	InputCorrectNumber(pipe.pipediameter);
	cout << "Is the pipe being repaired? (1 - Yes, 2 - No) ";
	cin >> pipe.repair;
	while (!(pipe.repair == 2 || pipe.repair == 1))
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Error! Please enter correct data: ";
		pipe.piperepair = pipe.repair;
	}

}


void show_Pipe(const Pipe& p)
{
	if (p.pipename != "")
	{
		cout << "------PIPELINE------" <<
			"\nName: " << p.pipename <<
			"\nLength: " << p.pipelength <<
			"\nDiameter: " << p.pipediameter <<
			"\nUnder repair? " << p.piperepair <<
			"\n--------------------" << endl;
	}
	else
	{
		cout << "Create pipeline first" << endl;
	}
}

int main()
{

	setlocale(LC_ALL, "Russian");
	Pipe pipeline;

	int chose;

	do
	{
		cout << "1. Показать информацию о трубе\n";
		cout << "2. Добавить трубу\n";

		switch (chose)
		{
		case 1:
			AddPipe(pipeline);
			break;

		case 2:
			AddPipe(pipeline);
			break;


		default:
			break;
		}

	} while (chose != 0);
	return 0;
}