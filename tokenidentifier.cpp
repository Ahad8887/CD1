#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>

using namespace std;

const int MAX_TOKENS = 100;
const string keywords[] = {"int", "return", "using", "namespace", "include","main","char","#"};
const string operators[] = {"=", "<<", "+", "-", "*", "/", "++", "--", "==", "!="};
const char punctuation[] = {';', '{', '}', '(', ')', '<', '>', ','};

bool isKeyword(string word) {
    for (int i = 0; i < 12; i++) {
        if (word == keywords[i]) {
            return true;
        }
    }
    return false;
}

bool isOperator(string word) {
    for (int i = 0; i < 15; i++) {
        if (word == operators[i]) {
            return true;
        }
    }
    return false;
}

bool isPunctuation(char c) {
    for (int i = 0; i < 7; i++) {
        if (c == punctuation[i]) {
            return true;
        }
    }
    return false;
}

int main() {
    ifstream file("sample.txt");
    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    string line;
    string sample;
    while (getline(file, line)) {
        sample += line + "\n";
    }
    file.close();

    string keywordsFound[MAX_TOKENS];
    string identifiersFound[MAX_TOKENS];
    string operatorsFound[MAX_TOKENS];
    string literalsFound[MAX_TOKENS];
    char punctuationFound[MAX_TOKENS];

    int keywordCount = 0, identifierCount = 0, operatorCount = 0, literalCount = 0, punctuationCount = 0;

    stringstream ss(sample);
    string token;

    while (ss >> token) {
        if (token.front() == '"' && token.back() == '"') {
            literalsFound[literalCount++] = token;
        }
        else if (isdigit(token[0])) {
            literalsFound[literalCount++] = token;
        }
        else if (isKeyword(token)) {
            keywordsFound[keywordCount++] = token;
        }
        else if (isOperator(token)) {
            operatorsFound[operatorCount++] = token;
        }
        else if (isalpha(token[0])) {
            identifiersFound[identifierCount++] = token;
        }
    }

    for (int i = 0; i < sample.length(); i++) {
        if (isPunctuation(sample[i])) {
            punctuationFound[punctuationCount++] = sample[i];
        }
    }

    cout << "Keywords: ";
    for (int i = 0; i < keywordCount; i++) {
        cout << keywordsFound[i] << ", ";
    }
    cout << endl;

    cout << "Identifiers: ";
    for (int i = 0; i < identifierCount; i++) {
        cout << identifiersFound[i] << ", ";
    }
    cout << endl;

    cout << "Operators: ";
    for (int i = 0; i < operatorCount; i++) {
        cout << operatorsFound[i] << ", ";
    }
    cout << endl;

    cout << "Literals: ";
    for (int i = 0; i < literalCount; i++) {
        cout << literalsFound[i] << ", ";
    }
    cout << endl;

    cout << "Punctuation: ";
    for (int i = 0; i < punctuationCount; i++) {
        cout << punctuationFound[i] << ", ";
    }
    cout << endl;

    return 0;
}
