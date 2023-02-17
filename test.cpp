#include<iostream>
#include<algorithm>
using namespace std;
int a[3]={1,2,3};
int main(void){
    do{
        for(int i=0;i<3;i++){
            cout<<a[i];
        }
        cout<<'\n';
    }while(next_permutation(a,a+3));// 다음 순열이 존재하지 않는다면 false를 반환
    return 0;
    //123
    //132
    //213
    //231
    //312
    //321
}