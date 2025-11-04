#include <iostream>
#include<string>
using namespace std;

int main() {

    string s;
    cout<<"Enter a line";
    getline(cin,s);

    if (s.substr(0,2)=="//")

    cout<<"Single line comment";

    else if (s.substr(0,2)=="/*" && s.substr (s.length()-2 )=="*/" )

         cout<<"Multiline line comment";
    else
        cout<<"Not a comment line";

    return 0;
}

