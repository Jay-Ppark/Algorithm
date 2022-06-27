#include<iostream>
#include<queue>
using namespace std;
long long int dp[1000001];
queue<long long int> q;
void init(){
    for(int i=0;i<=1000000;i++){
        dp[i]=-1;
    }
}
int main(void){
    int N;
    cin>>N;
    init();
    for(int i=0;i<10;i++){
        q.push(i);
        dp[i]=i;
    }
    if(N<10){
        cout<<dp[N];
    }
    else{
        int index=9;
        while(index<N&&!q.empty()){
            long long int a = q.front();
            q.pop();
            int lastnum=a%10;
            for(int i=0;i<lastnum;i++){
                index++;
                q.push(a*10+i);
                dp[index]=a*10+i;
            }
        }
        cout<<dp[N];
    }
    return 0;
}