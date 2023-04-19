#include<iostream>
using namespace std;
int main(void){
    int N;
    cin>>N;
    if(N%4==0){
        if(N%400==0){
            cout<<1;
        }
        else if(N%100==0){
            cout<<0;
        }
        else{
            cout<<1;
        }
    }
    else{
        cout<<0;
    }
    return 0;
}