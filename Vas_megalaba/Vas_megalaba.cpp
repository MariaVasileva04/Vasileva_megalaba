#include <iostream>
#include <string>
#include <fstream>

using namespace std;

template <typename T>
void InputCorrectNumber(T& var)
{
	cin >> var;
	while (cin.fail() || cin.peek() != '\n' || var < 1)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Ошибка! Пожалуйста введите корректное значение: ";
		cin >> var;
	}
};

struct Pipe
{
	string pipename = "";
	int pipelength = 0;
	int pipediameter = 0;
	int piperepair = 0;
	int repair = 0;

};

int AddPipe(Pipe& pipe) {
	if ((pipe.pipelength == 0) || (pipe.pipediameter == 0) || (pipe.pipename == "") || (pipe.piperepair != 2) || (pipe.piperepair != 1))
	{
		system("cls");

		cout << "Введите название трубы: ";
		cin.ignore();
		getline(cin, pipe.pipename);
		cout << "Введите длину трубы: ";
		InputCorrectNumber(pipe.pipelength);

		cout << "Введите диаметр трубы: ";
		InputCorrectNumber(pipe.pipediameter);
		cout << "Находится ли труба сейчас в ремонте?? (1 - Yes, 2 - No) ";
		cin >> pipe.repair;
		InputCorrectNumber(pipe.repair);
		if (pipe.repair == 1 || pipe.repair == 2)
		{
			pipe.piperepair = pipe.repair;
		}

		else
		{

			cout << "Ошибка! Введите значение 1 или 2";
			cout << "\n\n";
		}
		system("cls");
	}
	else 
	{
		cout << "У вас уже есть труба\n\n";
		return 1;
	}
};


void show_Pipe(const Pipe& p)
{
	if (p.pipename != "")
	{
		system("cls");
		cout << "------ТРУБА------" <<
			"\nНазвание: " << p.pipename <<
			"\nДлина: " << p.pipelength <<
			"\nДиаметр: " << p.pipediameter <<
			"\nНаходится в ремонте? " << p.piperepair <<
			"\n--------------------\n\n";

	}
	else
	{
		system("cls");
		cout << "Создайте свою первую трубу\n\n";
	}
};

int ChangeRepair(Pipe& pipe)
{
	//cout << "изменить ремонт\n\n";
	if (!(pipe.piperepair == 0))
	{
		cout << "Труба в ремонте? (1 - Да, 2 - Нет) ";
		cin >> pipe.repair;
		InputCorrectNumber(pipe.repair);
		if (pipe.repair == 1 || pipe.repair == 2)
		{
			pipe.piperepair = pipe.repair;
		}
		else
		{
			system("cls");
			cout << "Ошибка! Введите 1 или 2 ";
			cout << "\n\n";
		}

		system("cls");
	}
	else
	{
		system("cls");
		cout << "У вас нет трубы\n\n";
	}
	return 1;
};

struct CS
{
	string csname = "";
	int csworkshop = 0;
	int csworkshop_in_active = 0;
	int cseffective = 0;

};

//void AddCS(CS& cs) {
//	cout << "Enter the name of the CS: ";
//	cin.ignore();
//	getline(cin, cs.csname);
//	cout << "Enter the number of workshops: ";
//	InputCorrectNumber(cs.csworkshop;
//
//	cout << "Enter the number of workshops in operation: ";
//	InputCorrectNumber(cs.csworkshop_in_active);
//	cout << "Enter efficiency CS ";
//	cin >> cs.cseffective;
//	while (cs.cseffective < 0)
//	{
//		cin.clear();
//		cin.ignore(1000, '\n');
//		cout << "Error! Please enter correct data: ";
//		pipe.piperepair = pipe.repair;
//	}

//};







int main()
{

	setlocale(LC_ALL, "Russian");
	Pipe pipeline;

	int chose;

	do
	{

		cout << "------МЕНЮ------\n";
		cout << "1. Показать информацию о трубе\n";
		cout << "2. Добавить трубу\n";
		cout << "3. Изменить состояние ремонта\n";
		cout << "----------------\n";

		cout << "\nВыбор действия: ";

		cin >> chose;


		switch (chose)
		{
		case 1:
			show_Pipe(pipeline);
			break;

		case 2:
			AddPipe(pipeline);
			break;

		case 3:
			ChangeRepair(pipeline);
			break;


		default:
			system("cls");
			cout << "Такого пункта нет в меню\n\n";
			break;
		}

	} while (chose != 0);
	return 0;
}