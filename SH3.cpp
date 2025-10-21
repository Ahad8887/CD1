
#include <iostream>
#include <string>
using namespace std;
int main() {
    string line;
    cout << "Enter a line: ";
    getline(cin, line); // Trim leading spaces
    size_t start = line.find_first_not_of(" \t");
    if (start == string::npos) start = 0;// empty or all spaces
    string trimmed = line.substr(start);

    if (trimmed.find("//") == 0) {
        cout << "It's a comment line.\n";
    } else if (trimmed.find("/*") == 0 && trimmed.find("*/") != string::npos) {
        cout << "It's a comment line.\n";
    } else {
        cout << "It's not a comment line.\n";
    }
    return 0;
}

