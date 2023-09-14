#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

string removeBOM(const string& input) {
    if (input.size() >= 3 && input[0] == '\xEF' && input[1] == '\xBB' && input[2] == '\xBF') {
        return input.substr(3);
    }
    return input;
}

vector<string> tokenize(const string& input) {
    vector<string> tokens;
    istringstream iss(input);
    string token;
    while (getline(iss, token, ' ')) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    ifstream inputFile("program.synjaz");
    if (!inputFile.is_open()) {
        cerr << "Chyba: 'program.synjaz' nebol najdeny!" << endl;
        cin.get();
        return 404;
    }

    vector<bool> conditionalStack;
    map<string, int> gotoLabels;

    map<string, string> stringVariables;
    map<string, int> numericVariables;
    map<string, bool> booleanVariables;

    string line;
    int lineNumber = 0;
    while (getline(inputFile, line)) {
        line = removeBOM(line);
        lineNumber++;

        vector<string> tokens = tokenize(line);
        if (tokens.size() < 1) {
            continue;
        }
        string operation = tokens[0];

        if (conditionalStack.empty() || (!conditionalStack.empty() && conditionalStack.back())) {
            if (operation == "pokial" && tokens.size() == 2) {
                conditionalStack.push_back(booleanVariables[tokens[1]]);
            }
            else if (operation == "vytlac" && tokens.size() >= 2) {
                for (int i = 1; i < tokens.size(); i++) {
                    if (stringVariables.count(tokens[i])) {
                        cout << stringVariables[tokens[i]] << " ";
                    }
                    else if (numericVariables.count(tokens[i])) {
                        cout << numericVariables[tokens[i]] << " ";
                    }
                    else if (booleanVariables.count(tokens[i])) {
                        if (booleanVariables[tokens[i]]) cout << "pravda ";
                        else cout << "loz ";
                    }
                }
                cout << "" << endl;
            }
            else if (operation == "precitaj") {
                if (tokens.size() < 2) cin.get();
                else {
                    for (int i = 3; i < tokens.size(); i++) {
                        cout << tokens[i] + " ";
                    }
                    getline(cin, stringVariables[tokens[1]]);
                }
            }
            else if (operation == "retazec" && tokens.size() >= 4 && tokens[2] == "=") {
                string variable = tokens[1];
                stringVariables[variable] = "";
                stringVariables[variable] = tokens[3];
                for (int i = 4; i < tokens.size(); i++) {
                    stringVariables[variable] += " " + tokens[i];
                }
            }
            else if (operation == "cislo" && tokens.size() == 4 && tokens[2] == "=") {
                string variable = tokens[1];
                int value = stoi(tokens[3]);
                numericVariables[variable] = value;
            }
            else if (operation == "pravdivost" && tokens.size() >= 4 && tokens[2] == "=") {
                string variable = tokens[1];
                int value = 0;
                if (tokens.size() == 4) {
                    if (tokens[3] == "loz") value = 0;
                    else value = 1;
                }
                else if (tokens.size() == 6) {
                    string action = tokens[4];
                    if (stringVariables.count(tokens[3]) && stringVariables.count(tokens[5])) {
                        string left = stringVariables[tokens[3]];
                        string right = stringVariables[tokens[5]];
                        if (action == "!=") value = left != right;
                        else value = left == right;
                    }
                    else if (numericVariables.count(tokens[3]) && numericVariables.count(tokens[5])) {
                        int left = numericVariables[tokens[3]];
                        int right = numericVariables[tokens[5]];
                        if (action == "!=") value = left != right;
                        else value = left == right;
                    }
                    else if (booleanVariables.count(tokens[3]) && booleanVariables.count(tokens[5])) {
                        bool left = booleanVariables[tokens[3]];
                        bool right = booleanVariables[tokens[5]];
                        if (action == "!=") value = left != right;
                        else value = left == right;
                    }
                }
                booleanVariables[variable] = value;
            }
            else if (operation == "oznac" && tokens.size() == 2) {
                string label = tokens[1];
                gotoLabels[label] = lineNumber;
            }
            else if (operation == "preskoc" && tokens.size() == 2) {
                string label = tokens[1];
                if (gotoLabels.count(label)) {
                    int targetLine = gotoLabels[label];
                    inputFile.seekg(0);
                    lineNumber = targetLine;
                    for (int i = 0; i < targetLine; i++) {
                        getline(inputFile, line);
                    }
                }
                else {
                    cerr << "Chyba: Oznacenie '" << label << "' nebolo najdene!" << endl;
                }
            }
        }
        else if (operation == "koniec") {
            if (!conditionalStack.empty()) {
                conditionalStack.pop_back();
            }
            else {
                cerr << "Chyba: koniec nema zaciatok!" << endl;
            }
        }
    }

    inputFile.close();
    return 0;
}
