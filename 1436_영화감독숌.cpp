#include<iostream>
using namespace std;
int main(void){
    int N;
    cin>>N;
    int num=666;
    int cnt=1;
    while(true){
        if(cnt==N){
            break;
        }
        num++;
        string s=to_string(num);
        if(s.find("666")!=-1){
            cnt++;
        }
    }
    cout<<num;
    return 0;
}