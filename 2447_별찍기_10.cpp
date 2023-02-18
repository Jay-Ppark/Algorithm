#include<iostream>
using namespace std;
char arr[2200][2200];
void makeblank(int y,int x,int z){
    if(z==1){
        arr[y][x]='*';
        return;
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i==1&&j==1){
                continue;
            }
            makeblank(y+i*z/3,x+j*z/3,z/3);
        }
    }
}
int main(void){
    int N;
    cin>>N;
    makeblank(0,0,N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(arr[i][j]=='*'){
                cout<<arr[i][j];
            }
            else{
                cout<<' ';
            }
        }
        cout<<'\n';
    }
    return 0;
}