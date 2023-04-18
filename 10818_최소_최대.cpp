#include<iostream>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin>>N;
    int minnum=1000001;
    int maxnum=-1000001;
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        if(tmp>maxnum){
            maxnum=tmp;
        }
        if(tmp<minnum){
            minnum=tmp;
        }
    }
    cout<<minnum<<' '<<maxnum;
    return 0;
}