#include<iostream>
using namespace std;
int N;
int arr[2200][2200];
int cnt[3];
bool check(int y,int x,int n){
    for(int i=y;i<y+n;i++){
        for(int j=x;j<x+n;j++){
            if(arr[y][x]!=arr[i][j]){
                return false;
            }
        }
    }
    return true;
}
void countarr(int y,int x,int z){
    if(check(y,x,z)){
        cnt[arr[y][x]+1]++;
        return;
    }
    int n=z/3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            countarr(y+n*i,x+n*j,n);
        }
    }
}
int main(void){
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>arr[i][j];
        }
    }
    countarr(0,0,N);
    for(int i=0;i<3;i++){
        cout<<cnt[i]<<'\n';
    }
    return 0;
}