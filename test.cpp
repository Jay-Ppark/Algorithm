#include<iostream>
#include<deque>
using namespace std;
deque<int> glass[100];
int main(void){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            glass[i].push_back(j);
        }
    }
    deque<int> tmp[100];
    for(int i=0;i<5;i++){
        tmp[i]=glass[i];
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<tmp[i].size();j++){
            cout<<tmp[i][j]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}