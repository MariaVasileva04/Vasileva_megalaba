#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

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
		if (pipe.repair!= 1 || pipe.repair != 2)
		{
			pipe.piperepair = pipe.repair;
			while (!(pipe.piperepair == 2 || pipe.piperepair == 1))
			{
				cin.clear();
				cin.ignore(100000, '\n');
				cout << "Ошибка! Введите 1 или 2: ";
				InputCorrectNumber(pipe.piperepair);

			}
		}
		else
		{
			pipe.piperepair = pipe.repair;
		}

		
		system("cls");

		
	}
	else
	{
		system("cls");
		cout << "У вас уже есть труба\n\n";
		return 1;
	}
};




int ChangeRepair(Pipe& pipe)
{
	//cout << "изменить ремонт\n\n";
	if (!(pipe.piperepair == 0))
	{
		pipe.piperepair = 0;
		cout << "Находится ли труба сейчас в ремонте?? (1 - Да, 2 - Нет) ";
		InputCorrectNumber(pipe.repair);
		 
		if (pipe.repair != 1 || pipe.repair != 2)
		{
			pipe.piperepair = pipe.repair;
			while (!(pipe.piperepair == 2 || pipe.piperepair == 1))
			{

				cout << "Ошибка! Введите 1 или 2: ";
				InputCorrectNumber(pipe.piperepair);

			}
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
		InputCorrectNumber(cs.csworkshop_in_active);
		while (!((cs.csworkshop) > (cs.csworkshop_in_active)))
		{
			
			cout<< "Количество активных цехов не должно превышать количество всех цехов\n\n";
			cout << "Введите корректное значение: ";
			InputCorrectNumber(cs.csworkshop_in_active);
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



int ChangeCS(CS& cs)
{

	if (cs.csworkshop > 0)
	{
		cout << "Введите количество цехов: ";
		InputCorrectNumber(cs.csworkshop);

		cout << "Введите количество цехов в работе: ";
		InputCorrectNumber(cs.csworkshop_in_active);
		while (!((cs.csworkshop) > (cs.csworkshop_in_active)))
		{

			cout << "Количество активных цехов не должно превышать количество всех цехов\n\n";
			cout << "Введите корректное значение: ";
			InputCorrectNumber(cs.csworkshop_in_active);
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

void show_All( Pipe& p, CS& cs)
{
	if ((p.pipename != "")&&(cs.csname!=""))
	{
		system("cls");
		cout << "------ТРУБА------" <<
			"\nНазвание: " << p.pipename <<
			"\nДлина: " << p.pipelength <<
			"\nДиаметр: " << p.pipediameter <<
			"\nНаходится в ремонте? (1 - Да, 2 - Нет) " << p.piperepair <<
			"\n--------------------\n\n";

			cout << "------КС------" <<
			"\nНазвание: " << cs.csname <<
			"\nКоличество цехов: " << cs.csworkshop <<
			"\nКоличество цехов в работе: " << cs.csworkshop_in_active <<
			"\nЭффективность: " << cs.cseffective <<
			"\n--------------------\n\n";

	}

	else if ((p.pipename != "") && (cs.csname == ""))
	{
		system("cls");
		cout << "------ТРУБА------" <<
			"\nНазвание: " << p.pipename <<
			"\nДлина: " << p.pipelength <<
			"\nДиаметр: " << p.pipediameter <<
			"\nНаходится в ремонте? (1 - Да, 2 - Нет) " << p.piperepair <<
			"\n--------------------\n\n";
		cout << "Создайте свою первую КС\n\n";
	}
	else if ((p.pipename == "") && (cs.csname != ""))
	{
		system("cls");
		cout << "------КС------" <<
			"\nНазвание: " << cs.csname <<
			"\nКоличество цехов: " << cs.csworkshop <<
			"\nКоличество цехов в работе: " << cs.csworkshop_in_active <<
			"\nЭффективность: " << cs.cseffective <<
			"\n--------------------\n\n";
		cout << "Создайте свою первую трубу\n\n";
	}
	else
	{
		system("cls");
		cout << "Создайте свою первую трубу\n\n";
		cout << "Создайте свою первую КС\n\n";
	}
};

void Save(Pipe& pipe, CS& cs)
{
	ofstream out;
	out.open("save.txt");
	if (out.is_open())
	{
		if (pipe.pipename == "")
		{
			cout << "У вас нет трубы \n";
		}
		else
		{
			out << "Name of pipe: "  ;
			out << (pipe.pipename) << endl;
			out << "lenght of pipe: ";
			out << std::to_string(pipe.pipelength) << endl;
			out << "diametr of pipe: ";
			out << std::to_string(pipe.pipediameter) << endl;
			out << "Is repairing (1 - Yes, 2 - No)?: ";
			out << std::to_string(pipe.piperepair) << endl;
		}

		if (cs.csname == "")
		{
			cout << "У вас нет компрессорной станции\n";

		}
		else {
			out << "Name of CS: ";
			out << cs.csname << endl;
			out << "Workshop: ";
			out << std::to_string(cs.csworkshop) << endl;
			out << "Workshop in active: ";
			out << std::to_string(cs.csworkshop_in_active) << endl;
			out << "Effectivity: ";
			out << std::to_string(cs.cseffective) << endl;
		}
	}
	out.close();
	cout << "Данные записаны в файл\n";
}

void Load(string filename, Pipe& pipe, CS& cs)
{
	ifstream infile;
		infile.open(filename);
	if (infile.is_open())
	{
		string name, nameC;
		int lenghtStr, diameterStr, repairStr, numShopsStr, workingShopsStr;
		double effeciencyStr;
		infile >> name;
		infile >> lenghtStr;
		infile >> diameterStr;
		infile >> repairStr;
		pipe.pipename = name;
		pipe.pipelength = lenghtStr;
		pipe.pipediameter = diameterStr;
		pipe.piperepair = repairStr;

		infile >> nameC;
		infile >> numShopsStr;
		infile >> workingShopsStr;
		infile >> effeciencyStr;
		cs.csname = nameC;
		cs.csworkshop = numShopsStr;
		cs.csworkshop_in_active = workingShopsStr;
		cs.cseffective = effeciencyStr;
	}
	infile.close();
	cout << "Данные из файла сохранены " << filename;
	cout << "\n\n";
}


int main()
{

	setlocale(LC_ALL, "Russian");
	Pipe pipeline;
	CS cs;

	int chose;

	do
	{

		cout << "------МЕНЮ------\n";
		cout << "1. Показать все объекты\n";
		cout << "2. Добавить трубу\n";
		cout << "3. Изменить состояние ремонта\n";
		cout << "4. Добавить КС\n";
		cout << "5. Изменить количество рабочих цехов\n";
		cout << "6. Cохранить в файл\n";
		cout << "7. Взять данные из файла\n";
		cout << "8. Выйти из программы\n";
		cout << "----------------\n";

		cout << "\nВыбор действия: ";

		InputCorrectNumber(chose);


		switch (chose)
		{
		case 1:
			show_All(pipeline, cs);
			break;

		case 2:
			AddPipe(pipeline);
			break;

		case 3:
			ChangeRepair(pipeline);
			break;

		case 4:
			AddCS(cs);
			break;

		case 5:
			ChangeCS(cs);
			break;

		case 6:
			Save(pipeline, cs);
			break;

		case 7:
			Load("import.txt",pipeline, cs);
			break;

		case 8:
			cout << "До новых встреч!" << endl;
			return 0;


		default:
			system("cls");
			cout << "Такого пункта нет в меню\n\n";
			break;
		}

	} while (chose != 0);
	return 0;
}