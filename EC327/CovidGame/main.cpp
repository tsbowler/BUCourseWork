#include "Point2D.h"
#include "View.h"
#include "Model.h"
#include "GameCommand.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <ctime>
#include <fstream>

using namespace std;

//Function prototypes
bool IsNumber(string s);
bool IsWhiteSpace(string s);

const string COVID_BANNER = 
"                                  \n"
" _______ _______ __   __ ___ ______    _______ __   __ _______ _______ ______   _______ _______ ___   _ \n"
"|       |       |  | |  |   |      |  |       |  | |  |       |  _    |    _ | |       |   _   |   | | |\n"
"|       |   _   |  |_|  |   |  _    | |   _   |  | |  |_     _| |_|   |   | || |    ___|  |_|  |   |_| |\n"
"|       |  | |  |       |   | | |   | |  | |  |  |_|  | |   | |       |   |_||_|   |___|       |      _|\n"
"|      _|  |_|  |       |   | |_|   | |  |_|  |       | |   | |  _   ||    __  |    ___|       |     |_ \n"
"|     |_|       ||     ||   |       | |       |       | |   | | |_|   |   |  | |   |___|   _   |    _  |\n"
"|_______|_______| |___| |___|______|  |_______|_______| |___| |_______|___|  |_|_______|__| |__|___| |_|\n"
"                                  \n";

// TODO: Add help menu
int main(int argc, char** argv) {
    // Welcome Message
    cout << "EC327: Introduction to Software Engineering" << endl;
    cout << "Fall 2021" << endl;
    cout << "Programming Assignment 3" << endl;
    cout << COVID_BANNER << endl;
    //constructing the game model
    Model game_model;
    View game_view;

    bool game_is_running = true;

    bool read_from_file = false;
    game_model.ShowStatus();
    game_model.Display(game_view);
    ifstream input_file;
    if (argc == 2) {
        input_file.open(argv[1], ios_base::in);
        if (!input_file.is_open()) {
            cout << "Failed to open input file " << argv[1] << endl;
            exit(EXIT_FAILURE);
        }
        read_from_file = true;
        srand(0);
    } else
        srand(time(NULL));

    while (game_is_running) {
        cout << "Enter command: ";
        char command = 'a';
        int id = 0;
        int id1 = 0;
        int id2 = 0;
        bool error = false;
        string input = "'";
        double x = 0;
        double y = 0;
        unsigned int vaccine_amount = 0;
        unsigned int assignments_amount = 0;
        if (read_from_file) {
            getline(input_file, input);
        } else
            getline(cin, input);
        if (input.length() > 0 and !IsWhiteSpace(input)) {
            istringstream iss(input);
            vector<string> tokens;
            copy(istream_iterator<string>(iss),
                 istream_iterator<string>(),
                 back_inserter<vector<string> >(tokens));
            if (tokens[0].length() == 1)
                command = tokens[0][0];
            else
                error = true;
            switch (command) {
                //moving a Student to a location
                case 'm':
                    if (tokens.size() == 4) {
                        id = atoi(tokens[1].c_str());
                        x = atof(tokens[2].c_str());
                        y = atof(tokens[3].c_str());
                    }
                    else {
                        error = true;
                    }
                    if (!error) {
                        Point2D moveTo = Point2D(x, y);
                        DoMoveCommand(game_model, id, moveTo);
                        game_model.Display(game_view);
                    }
                    break;
                case 'd':
                    if (tokens.size() == 3) {
                        id = atoi(tokens[1].c_str());
                        id2 = atoi(tokens[2].c_str());
                    }
                    else {
                        error = true;
                    }
                    if (!error) {
                        DoMoveToDoctorCommand(game_model, id, id2);
                        game_model.Display(game_view);
                    }
                    break;
                case 'c':
                    if (tokens.size() == 3) {
                        id = atoi(tokens[1].c_str());
                        id2 = atoi(tokens[2].c_str());
                    }
                    else {
                        error = true;
                    }
                    if (!error) {
                        DoMoveToClassCommand(game_model, id, id2);
                        game_model.Display(game_view);
                    }
                    break;
                case 'v':
                    if (tokens.size() == 3) {
                        id = atoi(tokens[1].c_str());
                        vaccine_amount = atoi(tokens[2].c_str());
                    }
                    else {
                        error = true;
                    }
                    if (!error) {
                        DoRecoverInOfficeCommand(game_model, id, vaccine_amount);
                        game_model.Display(game_view);
                    }
                    break;
                case 'a':
                    if (tokens.size() == 3) {
                        id = atoi(tokens[1].c_str());
                        assignments_amount = atoi(tokens[2].c_str());
                    }
                    else {
                        error = true;
                    }
                    if (!error) {
                        DoLearningCommand(game_model, id, assignments_amount);
                        game_model.Display(game_view);
                    }
                    break;
                case 's':
                    if (tokens.size() == 2) {
                        id = atoi(tokens[1].c_str());
                    }
                    else {
                        error = true;
                    }
                    if (!error) {
                        DoStopCommand(game_model, id);
                        game_model.Display(game_view);
                    }
                    break;
                case 'g':
                    if (tokens.size() == 1) {
                        DoGoCommand(game_model, game_view);
                    }
                    else {
                        error = true;
                    }
                    break;
                //advance 5 time ticks or until next event
                case 'r':
                    if (tokens.size() == 1) {
                        DoRunCommand(game_model, game_view);
                    }
                    else {
                        error = true;
                    }
                    break;
                //quit the program
                case 'q':
                    if (tokens.size() == 1) {
                        cout << "Terminating program." << endl;
                        game_is_running = false;
                    }
                    else {
                        error = true;
                    }
                    break;
                default:
                    error = true;
                    break;
            }
        }
        else
            error = true;
        if (error)
            cout << "ERROR: Please enter a valid command!" << endl;
    }
    return 0;
}

bool IsNumber(string s){
    for(int i = 0; i < s.length(); i++) {
        if(!(s[i] >= '0' && s[i] <= '9')) {
            return false;
        }
    }
    return true;
}

bool IsWhiteSpace(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ' && s[i] != '\t') {
            return false;
        }
    }
    return true;
}

