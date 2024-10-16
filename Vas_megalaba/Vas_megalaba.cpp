#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;



template <typename T>
void InputCorrectNumber(T& var)
{
	cin >> var;
	while (cin.fail() || cin.peek() != '\n' || var < 0)
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
	double pipelength = 0;
	int pipediameter = 0;
	bool piperepair =0;
	
};

int AddPipe(Pipe& pipe) {
	if ((pipe.pipename != ""))
	{
		system("cls");
		cout << "У вас уже есть труба\n\n";
		return 1;
	}

	system("cls");//!

	cout << "Введите название трубы: ";
	cin.ignore();
	getline(cin, pipe.pipename);
	cout << "Введите длину трубы: ";
	InputCorrectNumber(pipe.pipelength);

	cout << "Введите диаметр трубы: ";
	InputCorrectNumber(pipe.pipediameter);
	cout << "Находится ли труба сейчас в ремонте?? (1 - Да, 0 - Нет) ";
	InputCorrectNumber(pipe.piperepair);
	/*if (pipe.repair!= 1 || pipe.repair != 2)
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
	}*/


	system("cls");//!!!!

	//!!???
}



int ChangeRepair(Pipe& pipe)
{
	//cout << "изменить ремонт\n\n";
	if (pipe.pipelength != 0)
	{
		pipe.piperepair = 0;
		cout << "Находится ли труба сейчас в ремонте?? (1 - Да, 0 - Нет) ";
		InputCorrectNumber(pipe.piperepair);
		 
		/*if (pipe.repair != 1 || pipe.repair != 2)
		{
			pipe.piperepair = pipe.repair;
			while (!(pipe.piperepair == 2 || pipe.piperepair == 1))
			{

				cout << "Ошибка! Введите 1 или 2: ";
				InputCorrectNumber(pipe.piperepair);

			}
		}*/
		


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
	if ((cs.csname==""))
	{
		system("cls");

		cout << "Введите название компрессорной станции: ";
		cin.ignore();
		getline(cin, cs.csname);
		cout << "Введите количество цехов: ";
		InputCorrectNumber(cs.csworkshop);

		cout << "Введите количество цехов в работе: ";
		InputCorrectNumber(cs.csworkshop_in_active);
		while (!((cs.csworkshop) >= (cs.csworkshop_in_active)))
		{
			
			cout<< "Количество активных цехов не должно превышать количество всех цехов\n\n";
			cout << "Введите корректное значение: ";
			InputCorrectNumber(cs.csworkshop_in_active);
		}
		
		if (cs.csworkshop != 0)
		{
			cs.cseffective = double(cs.csworkshop_in_active) / double(cs.csworkshop);
		}
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

	if (cs.csname != "")
	{
		cout << "Введите количество цехов: ";
		InputCorrectNumber(cs.csworkshop);

		cout << "Введите количество цехов в работе: ";
		InputCorrectNumber(cs.csworkshop_in_active);
		while (((cs.csworkshop) < (cs.csworkshop_in_active)))
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

void show_Pipe(const Pipe& p)//!!!
{
	if (p.pipelength != 0)
	{
		
		cout << "------ТРУБА------" <<
			"\nНазвание: " << p.pipename <<
			"\nДлина: " << p.pipelength <<
			"\nДиаметр: " << p.pipediameter <<
			"\nНаходится в ремонте? (1 - Да, 0 - Нет) " << p.piperepair <<
			"\n--------------------\n\n";

			

	}

	else
	{
		
		cout << "Создайте свою первую трубу\n\n";
		
	}
};

void show_CS(const CS& cs)//!!!
{
	if (cs.csname != "")
	{

		cout << "------КС------" <<
			"\nНазвание: " << cs.csname <<
			"\nКоличество цехов: " << cs.csworkshop <<
			"\nКоличество цехов в работе: " << cs.csworkshop_in_active <<
			"\nЭффективность: " << cs.cseffective <<
			"\n--------------------\n\n";



	}
	else
	{
		cout << "Создайте свою первую кс\n\n";

	}
};

void Save(Pipe& pipe, CS& cs)//!!
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
			
			out << (pipe.pipename) << endl;
			
			out << pipe.pipelength << endl;
			
			out << pipe.pipediameter << endl;
			
			out << pipe.piperepair << endl;
		}

		if (cs.csname == "")
		{
			cout << "У вас нет компрессорной станции\n";

		}
		else {
			
			out << cs.csname << endl;
			out << cs.csworkshop << endl;
			
			out << cs.csworkshop_in_active << endl;
			
			out << cs.cseffective << endl;
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
		int lenghtStr, diameterStr, repairStr, numShopsStr, workingShopsStr;///!!!!!!!!
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
		cout << "1. Показать трубу\n";
		cout << "2. Показать КС\n";
		cout << "3. Добавить трубу\n";
		cout << "4. Изменить состояние ремонта\n";
		cout << "5. Добавить КС\n";
		cout << "6. Изменить количество рабочих цехов\n";
		cout << "7. Cохранить в файл\n";
		cout << "8. Взять данные из файла\n";
		cout << "9. Выйти из программы\n";
		cout << "----------------\n";

		cout << "\nВыбор действия: ";

		InputCorrectNumber(chose);


		switch (chose)
		{
		case 1:
			show_Pipe(pipeline);
			break;

		case 2:
			show_CS(cs);
			break;

		case 3:
			AddPipe(pipeline);
			break;

		case 4:
			ChangeRepair(pipeline);
			break;

		case 5:
			AddCS(cs);
			break;

		case 6:
			ChangeCS(cs);
			break;

		case 7:
			Save(pipeline, cs);
			break;

		case 8:
			Load("save.txt",pipeline, cs);
			break;

		case 9:
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