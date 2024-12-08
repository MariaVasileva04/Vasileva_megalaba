#include <iostream>
#include "pipe.h"
#include "pipe_f.h"
#include "CS.h"
#include "CS_f.h"
#include "menu.h"
#include "ost.h"
#include "filter.h"
#include "logger.h"
#include <unordered_map>
#include <unordered_set>
#include <chrono>
#include <format>

using namespace std;
using namespace chrono;


// pipe menu
void print_pipes_menu() {
    cout << endl;
    cout << endl;
    cout << "-----Menu pipe-----\n";
    cout << "0 - back\n";
    cout << "1 - add pipe\n";
    cout << "2 - select pipes\n";
    cout << "--------------\n";
}

void pipes_menu(unordered_map<int, Pipe>& pipes, unordered_set<int>& selected_pipes) {
    while (true) {
        print_pipes_menu();

        int choice = GetCorrectNumber<int>("input number: ", 0, 2);

        switch (choice)
        {
        case 0:
            return;
        case 1:
            add_obj(pipes);
            break;
        case 2:
            select_pipes_menu(pipes, selected_pipes);
            break;
        default:
            cout << "You choose the number, that not exist!\n";
            break;
        }
    }
}

void print_select_pipes_menu() {
    cout << endl;
    cout << endl;
    cout << "-----Menu select pipe-----\n";
    cout << "0 - back\n";
    cout << "1 - see selected pipes\n";
    cout << "2 - edit selected pipes\n";
    cout << "3 - select from filter\n";
    cout << "4 - choose ids from selected\n";
    cout << "5 - remove from selected\n";
    cout << "--------------\n";
}

void select_pipes_menu(unordered_map<int, Pipe>& pipes, unordered_set<int>& selected_pipes) {
    while (true) {
        print_select_pipes_menu();

        int choice = GetCorrectNumber<int>("input number: ", 0, 5);

        switch (choice)
        {
        case 0:
            return;
        case 1:
            print_selected(pipes, selected_pipes);
            break;
        case 2:
            edit_pipes_menu(pipes, selected_pipes);
            break;
        case 3:
            filter_pipe_menu(pipes, selected_pipes);
            break;
        case 4:
            selected_pipes = selectByID(selected_pipes);
            break;
        case 5:
            CLEAR_SELECTED(selected_pipes);
            break;
        default:
            cout << "You choose the number, that not exist!\n";
            break;
        }
    }
}

void print_filter_pipe() {
    cout << endl;
    cout << endl;
    cout << "-----Menu filter pipe-----\n";
    cout << "*new selections are added to the old ones*\n";
    cout << "0 - back\n";
    cout << "1 - select all pipes\n";
    cout << "2 - select by id\n";
    cout << "3 - select by name\n";
    cout << "4 - select by work status\n";
    cout << "--------------\n";
}

void filter_pipe_menu(unordered_map<int, Pipe>& pipes, unordered_set<int>& selected_pipes) {
    while (true) {
        print_filter_pipe();

        int choice = GetCorrectNumber<int>("input number: ", 0, 4);

        switch (choice)
        {
        case 0:
            return;
        case 1:
            selectAll(pipes, selected_pipes);
            break;
        case 2:
            selected_pipes = selectByID(pipes);
            break;
        case 3:
            findByName(pipes, selected_pipes);
            break;
        case 4:
            findByIsWorking(pipes, selected_pipes);
            break;
        default:
            cout << "You choose the number, that not exist!\n";
            break;
        }
    }
}

void print_edit_pipe_menu() {
    cout << endl;
    cout << endl;
    cout << "-----Menu edit pipe-----\n";
    cout << "0 - back\n";
    cout << "1 - change work status for selected pipes\n";
    cout << "2 - delete selected pipes\n";
    cout << "--------------\n";
}

void edit_pipes_menu(unordered_map<int, Pipe>& pipes, unordered_set<int>& selected_pipes) {
    while (true) {
        print_edit_pipe_menu();

        int choice = GetCorrectNumber<int>("input number: ", 0, 2);

        switch (choice)
        {
        case 0:
            return;
        case 1:
            change_selectedPipes_workStatus(pipes, selected_pipes);
            break;
        case 2:
            delete_selectedObj(pipes, selected_pipes);
            break;
        default:
            cout << "You choose the number, that not exist!\n";
            break;
        }
    }
}


// CS menu
void print_CS_menu() {
    cout << endl;
    cout << endl;
    cout << "-----Menu C Station-----\n";
    cout << "0 - back\n";
    cout << "1 - add C Station\n";
    cout << "2 - select C Station\n";
    cout << "--------------\n";
}

void CS_menu(std::unordered_map<int, CompressorStation>& c_ss, std::unordered_set<int>& selected_css) {
    while (true) {
        print_CS_menu();

        int choice = GetCorrectNumber<int>("input number: ", 0, 2);

        switch (choice)
        {
        case 0:
            return;
        case 1:
            add_obj(c_ss);
            break;
        case 2:
            select_CS_menu(c_ss, selected_css);
            break;
        default:
            cout << "You choose the number, that not exist!\n";
            break;
        }
    }
}

void print_select_CS_menu() {
    cout << endl;
    cout << endl;
    cout << "-----Menu select C Station-----\n";
    cout << "0 - back\n";
    cout << "1 - see selected CS\n";
    cout << "2 - edit selected CS\n";
    cout << "3 - select from filter\n";
    cout << "4 - choose ids from selected\n";
    cout << "5 - remove from selected\n";
    cout << "--------------\n";
}

void select_CS_menu(unordered_map<int, CompressorStation>& c_ss, unordered_set<int>& selected_css) {
    while (true) {
        print_select_CS_menu();

        int choice = GetCorrectNumber<int>("input number: ", 0, 4);

        switch (choice)
        {
        case 0:
            return;
        case 1:
            print_selected(c_ss, selected_css);
            break;
        case 2:
            edit_CS_menu(c_ss, selected_css);
            break;
        case 3:
            filter_CS_menu(c_ss, selected_css);
            break;
        case 4:
            selected_css = selectByID(selected_css);
            break;
        case 5:
            CLEAR_SELECTED(selected_css);
            break;
        default:
            cout << "You choose the number, that not exist!\n";
            break;
        }
    }
}

void print_filter_CS() {
    cout << endl;
    cout << endl;
    cout << "-----Menu filter CS-----\n";
    cout << "*new selections are added to the old ones*\n";
    cout << "0 - back\n";
    cout << "1 - select all CS\n";
    cout << "2 - select by id\n";
    cout << "3 - select by name\n";
    cout << "4 - select by unused workshops\n";
    cout << "--------------\n";
}

void filter_CS_menu(unordered_map<int, CompressorStation>& c_ss, unordered_set<int>& selected_css) {
    while (true) {
        print_filter_CS();

        int choice = GetCorrectNumber<int>("input number: ", 0, 4);

        switch (choice)
        {
        case 0:
            return;
        case 1:
            selectAll(c_ss, selected_css);
            break;
        case 2:
            selected_css = selectByID(c_ss);
            break;
        case 3:
            findByName(c_ss, selected_css);
            break;
        case 4:
            findByUnusedWorkshops(c_ss, selected_css);
            break;
        default:
            cout << "You choose the number, that not exist!\n";
            break;
        }
    }
}

void print_edit_CS_menu() {
    cout << endl;
    cout << endl;
    cout << "-----Menu edit CS-----\n";
    cout << "0 - back\n";
    cout << "1 - change number of active workshops\n";
    cout << "2 - delete selected CS\n";
    cout << "--------------\n";
}

void edit_CS_menu(unordered_map<int, CompressorStation>& c_ss, unordered_set<int>& selected_css) {
    while (true) {
        print_edit_CS_menu();

        int choice = GetCorrectNumber<int>("input number: ", 0, 2);

        switch (choice)
        {
        case 0:
            return;
        case 1:
            change_selectedCS_workload(c_ss, selected_css);
            break;
        case 2:
            delete_selectedObj(c_ss, selected_css);
            break;
        default:
            cout << "You choose the number, that not exist!\n";
            break;
        }
    }
}


// main menu
void print_main_menu() {
    cout << endl;
    cout << endl;
    cout << "-----Menu-----\n";
    cout << "0 - exit\n";
    cout << "1 - pipes actions\n";
    cout << "2 - compressor stations actions\n";
    cout << "3 - see all objects\n";
    cout << "4 - save in file\n";
    cout << "5 - load from file\n";
    cout << "--------------\n";
};

void main_menu() {
    Logger logger("log_" + std::string(std::format("{:%d_%m_%Y_%H_%M}", system_clock::now())) + ".txt");

    unordered_map<int, Pipe> pipes;
    unordered_set<int> selected_pipes;

    unordered_map<int, CompressorStation> c_ss;
    unordered_set<int> selected_css;

    while (true) {
        print_main_menu();

        int choice = GetCorrectNumber<int>("input number: ", 0, 5);

        switch (choice)
        {
        case 0:
            cout << endl;
            cout << "Goodbye!\n";
            return;
        case 1:
            pipes_menu(pipes, selected_pipes);
            break;
        case 2:
            CS_menu(c_ss, selected_css);
            break;
        case 3:
            see_all_objects(pipes, c_ss);
            break;
        case 4:
            save_obj(pipes, c_ss);
            break;
        case 5:
            load_obj(pipes, c_ss, selected_pipes, selected_css);
            break;
        default:
            cout << "You choose the number, that not exist!\n";
            break;
        }
    }
};