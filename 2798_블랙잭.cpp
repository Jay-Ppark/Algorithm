#include<iostream>
using namespace std;
int N,M;
int arr[100];
int pick[3];
int maxnum=0;
void dfs(int index,int cnt){
    if(cnt==3){
        int tmpsum=0;
        for(int i=0;i<3;i++){
            tmpsum+=pick[i];
        }
        if(tmpsum<=M&&tmpsum>maxnum){
            maxnum=tmpsum;
        }
        return;
    }
    for(int i=index;i<N;i++){
        pick[cnt]=arr[i];
        dfs(i+1,cnt+1);
    }
}
int main(void){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    dfs(0,0);
    cout<<maxnum;
    return 0;
}