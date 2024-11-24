#include <iostream>
#include "CS.h"
#include "pipe.h"
#include "CS_f.h"
#include "ost.h"
#include <fstream>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;


void change_selectedCS_workload(std::unordered_map<int, CompressorStation>& c_ss, const std::unordered_set<int>& selected_css) {
    cout << "Stop(1) or Start(2) the workshop: ";
    int counter = 0;
    int choice = GetCorrectNumber<int>("Stop(1) or Start(2) the workshop: ", 1, 2);

    for (const int& id : selected_css) {
        c_ss.find(id)->second.edit_workshop_status(choice);
        ++counter;
    }
    cout << counter << " workshops was changed!" << endl;
}