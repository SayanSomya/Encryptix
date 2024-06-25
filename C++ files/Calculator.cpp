#include <bits/stdc++.h>
using namespace std;

void displayMenu() {
    cout << "Select an operation to perform:" << endl;
    cout << "1. Addition (+)" << endl;
    cout << "2. Subtraction (-)" << endl;
    cout << "3. Multiplication (*)" << endl;
    cout << "4. Division (/)" << endl;
    cout << "Enter your choice (1-4) or (+,-,*,/): ";
}

int main(){
    cout << "Welcome to the Calculator!"<<endl;
    cout << "Enter numbers: "<<endl;
    int a,b;cin>>a>>b;
    displayMenu();
    char op;cin>>op;
    switch(op){
        case '+':
        case '1':
            cout<<a<<" + "<<b<<" = "<<a+b<<endl;
            break;
        case '-':
        case '2':
            cout<<a<<" - "<<b<<" = "<<a-b<<endl;
            break;
        case '*' :
        case '3':
            cout<<a<<" * "<<b<<" = "<<a*b<<endl;
            break;
        case '/':
        case '4':
            if(b==0){
                cout<<"Division by zero is not allowed"<<endl;
            }else{
                cout<<a<<" / "<<b<<" = "<<a/b<<endl;
            }
            break;
        default:
            cout<<"Invalid operation"<<endl;
    }

    return 0;
}