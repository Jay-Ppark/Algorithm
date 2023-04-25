#include<iostream>
using namespace std;
int arr[500][500];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M,B;
    cin>>N>>M>>B;
    int mintime=1e9;
    int maxh=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<=256;i++){
        int needB=0;
        int getB=0;
        for(int y=0;y<N;y++){
            for(int x=0;x<M;x++){
                //블럭을 쌓아야하는 경우
                if(i>arr[y][x]){
                    needB+=i-arr[y][x];
                }
                //블럭을 없애야하는 경우
                else{
                    getB+=arr[y][x]-i;
                }
            }
        }
        //가능
        if(needB<=getB+B){
            int tmpt=getB*2+needB;
            if(tmpt<=mintime){
                mintime=tmpt;
                maxh=i;
            }
        }
    }
    cout<<mintime<<' '<<maxh;
    return 0;
}