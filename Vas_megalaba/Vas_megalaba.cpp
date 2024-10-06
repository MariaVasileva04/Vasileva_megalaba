#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Pipe
{
    string pipename;
    int pipelength;
    int pipediameter;
    int piperepair;
	int repair;

};

struct CS
{
    string csname;
    int csshop;
    int csworkshop;
    double csefficiency;
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