#include <iostream>

using namespace std;

bool isValidIdentifier(const string& input) {

    if (!(isalpha(input[0]) || input[0] == '_')) {
        return false;
    }

    for (size_t i = 1; i < input.length(); ++i) {
        if (!(isalnum(input[i]) || input[i] == '_')) {
            return false;
        }
    }

    return true;
}

int main() {
    string input;

    cout << "Enter an identifier: ";
    cin >> input;

    if (isValidIdentifier(input)) {
        cout << "The input is a valid identifier." << endl;
    } else {
        cout << "The input is NOT a valid identifier." << endl;
    }

    return 0;
}
