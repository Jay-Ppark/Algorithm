#include<iostream>
using namespace std;
int main(void){
    //1:1->0
    //2:2~7->1~6    0 1
    //3:8~19->7~18  1 2 3
    //4:20~37->19~36 3 4 5 6
    //5:38~61->37~60 6 7 8 9 10
    int N;
    cin>>N;
    int tmpmax=1;
    int cnt=1;
    while(true){
        if(N<=tmpmax){
            break;
        }
        tmpmax+=6*cnt;
        cnt++;
    }
    cout<<cnt;
    return 0;
}