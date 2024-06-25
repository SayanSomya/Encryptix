#include <bits/stdc++.h>
using namespace std;

int main(){
    cout << "Welcome to the Number Guessing Game!"<<endl;
    char wantToPlay='y';
    while(wantToPlay=='y' || wantToPlay=='Y'){
        srand(time(0));
        cout<<"Enter the lower and upper bounds of the number to be guessed"<<endl;
        int lb,ub;cin>>lb>>ub;
        int numberToGuess = rand()%(ub-lb+1);
        int guess;
        int attempts = 0;
        cout<<"Guess the number between "<<lb<<" and "<<ub<< endl;
        do{
            cin>>guess;
            attempts++;
            if(guess<lb || guess>ub){
                cout<<"Please enter a number between "<<lb<<" and "<<ub<<endl;
                continue;
            }
            if(guess>numberToGuess){
                cout<<"Too high"<<endl;
            }else if(guess<numberToGuess){
                cout<<"Too low"<<endl;
            }
        }while(guess!=numberToGuess);
        cout<<"Congratulations! You guessed the number in "<<attempts<<" attempts"<<endl;
        cout<<"Do you want to play again? (y/n)"<<endl;
        cin>>wantToPlay;
    }

    return 0;
}