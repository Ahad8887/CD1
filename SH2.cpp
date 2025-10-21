#include<iostream>
using namespace std;
int main(){
string input;
cout<<"Enter expression:";
cin>>input;
int n=1;
for(char c:input){
    if (c=='+' || c=='-'||c=='*'||c=='/'||c=='%'||c=='='){
        cout<<"oprator"<<n<<";"<<input<<endl;n++;
    }
}
return 0;
}

