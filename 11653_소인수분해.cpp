#include<iostream>
using namespace std;
int main(void){
    int N;
    cin>>N;
    if(N>1){
        int start=2;
        while(N>1){
            if(N%start==0){
                cout<<start<<'\n';
                N=N/start;
            }
            else{
                start++;
            }
        }
    }
    return 0;
}