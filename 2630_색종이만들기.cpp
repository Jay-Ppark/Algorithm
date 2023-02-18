#include<iostream>
using namespace std;
int arr[130][130];
int cnt[2];
bool check(int y,int x,int z){
    for(int i=y;i<y+z;i++){
        for(int j=x;j<x+z;j++){
            if(arr[y][x]!=arr[i][j]){
                return false;
            }
        }
    }
    return true;
}
void countarr(int y,int x,int z){
    if(check(y,x,z)){
        cnt[arr[y][x]]++;
        return;
    }
    int n=z/2;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            countarr(y+i*n,x+j*n,n);
        }
    }
}
int main(void){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>arr[i][j];
        }
    }
    countarr(0,0,N);
    for(int i=0;i<2;i++){
        cout<<cnt[i]<<'\n';
    }
    return 0;
}