#include<iostream>
using namespace std;
int main(void){
    int N,K;
    cin>>N>>K;
    int mul=N;
    if(K==0){
        cout<<1;
        return 0;
    }
    for(int i=1;i<K;i++){
        mul=mul*(N-i);
    }
    for(int i=1;i<=K;i++){
        mul=mul/i;
    }
    cout<<mul;
    return 0;
}