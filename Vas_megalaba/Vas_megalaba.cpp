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
		cout << "Находится ли труба сейчас в ремонте?? (1 - Да, 2 - Нет) ";
		InputCorrectNumber(pipe.repair);
		if (pipe.repair == 1 || pipe.repair == 2)
		{
			pipe.piperepair = pipe.repair;
			
			
		}

		else
		{
			system("cls");
			cout << "Ошибка! Введите значение 1 или 2\n\n";
			pipe.piperepair = 0;
			pipe.pipename = "";
			pipe.pipelength = 0;
			pipe.pipediameter = 0;
			
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
			"\nНаходится в ремонте? (1 - Да, 2 - Нет) " << p.piperepair <<
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
		InputCorrectNumber(pipe.repair);
		if (pipe.repair == 1 || pipe.repair == 2)
		{
			pipe.piperepair = pipe.repair;

		}

		else
		{
			system("cls");
			cout << "Ошибка! Введите значение 1 или 2\n\n";
			pipe.piperepair = 2;

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
	int csws = 0;
	double cseffective = 0;

};
int AddCS(CS& cs) 
{
	if ((cs.csworkshop == 0) || (cs.csworkshop_in_active == 0) || (cs.cseffective == 0) || (cs.csname == ""))
	{
		system("cls");

		cout << "Введите название компрессорной станции: ";
		cin.ignore();
		getline(cin, cs.csname);
		cout << "Введите количество цехов: ";
		InputCorrectNumber(cs.csworkshop);

		cout << "Введите количество цехов в работе: ";
		InputCorrectNumber(cs.csws);
		if ((cs.csws) > (cs.csworkshop))
		{
			system("cls");
			cout << "Количество активных цехов не должно превышать количество всех цехов\n\n";
			cs.csworkshop = 0;
			cs.csworkshop_in_active = 0;
			cs.csname = "";
		}
		else
		{
			cs.csworkshop_in_active = cs.csws;
		}

		cs.cseffective = double(cs.csworkshop_in_active) / double(cs.csworkshop);
	}
	else
	{
		system("cls");
		cout << "У вас уже есть компрессорная станция \n\n";
	}
	return 1;
};

	void show_CS(const CS & cs)
	 {
		if (cs.csname != "")
		{
			system("cls");
			cout << "------КС------" <<
				"\nНазвание: " << cs.csname <<
				"\nКоличество цехов: " << cs.csworkshop <<
				"\nКоличество цехов в работе: " << cs.csworkshop_in_active <<
				"\nЭффективность: " << cs.cseffective <<
				"\n--------------------\n\n";

		}
		else
		{
			system("cls");
			cout << "Создайте свою первую КС\n\n";
		}
	};

	int ChangeCS(CS& cs)
	{
	
		if (cs.csworkshop > 0)
		{
			while (true)
			{
				
				cout << "Введите количество цехов: \n";
				InputCorrectNumber(cs.csworkshop);
				cout << "Введите количество работающих цехов: \n";
				InputCorrectNumber(cs.csws);
				if ((cs.csws) > (cs.csworkshop))
				{
					system("cls");
					cout << "Количество активных цехов не должно превышать количество всех цехов\n\n";
					cs.csworkshop = 1;
					cs.csworkshop_in_active = 1;

					
				}
				else
				{
					cs.csworkshop_in_active = cs.csws;
				}
				if (cs.csworkshop > 0 || cs.csworkshop_in_active > 0)
				{
					break;
				}
			}
		}
		else
		{
			system("cls");
			cout << "Создайте компрессорную станцию \n\n";
		}

		cs.cseffective = double(cs.csworkshop_in_active) / double(cs.csworkshop);
		return  1;
	};



int main()
{

	setlocale(LC_ALL, "Russian");
	Pipe pipeline;
	CS cs;

	int chose;

	do
	{

		cout << "------МЕНЮ------\n";
		cout << "1. Показать информацию о трубе\n";
		cout << "2. Добавить трубу\n";
		cout << "3. Изменить состояние ремонта\n";
		cout << "4. Показать информацию о КС\n";
		cout << "5. Добавить КС\n";
		cout << "6. Изменить количество рабочих цехов\n";
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

		case 4:
			show_CS(cs);
			break;

		case 5: 
			AddCS(cs);
			break;

		case 6:
			ChangeCS(cs);
			break;


		default:
			system("cls");
			cout << "Такого пункта нет в меню\n\n";
			break;
		}

	} while (chose != 0);
	return 0;
}