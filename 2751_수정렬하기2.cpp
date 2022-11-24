#include<iostream>
using namespace std;
bool visited[2000001];
int main(void){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        visited[tmp+1000000]=true;
    }
    for(int i=0;i<=2000000;i++){
        if(visited[i]){
            cout<<i-1000000<<"\n";
        }
    }
    return 0;
}