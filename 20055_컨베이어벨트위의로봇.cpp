#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int beltmap[200];
bool visited[200];
int N,maxzerobelt;
int startb, endb;
queue<int> robotq;
void movebelt(){
    if(startb==0){
        startb=2*N-1;
    }
    else{
        startb--;
    }
    if(endb==0){
        endb=2*N-1;
    }
    else{
        endb--;
    }
}
void moverobot(){
    queue<int> tmpq;
    while(!robotq.empty()){
        int index=robotq.front();
        robotq.pop();
        if(index==endb){
            visited[index]=false;
        }
        else{
            int nextindex=index+1;
            if(nextindex>=2*N){
                nextindex=0;
            }
            if(!visited[nextindex]&&beltmap[nextindex]>=1){
                visited[index]=false;
                beltmap[nextindex]--;
                if(endb==nextindex){
                    continue;
                }
                visited[nextindex]=true;
                tmpq.push(nextindex);
            }
            else{
                tmpq.push(index);
            }
        }
    }
    while(!tmpq.empty()){
        int tmp=tmpq.front();
        tmpq.pop();
        robotq.push(tmp);
    }
}
void makerobot(){
    if(beltmap[startb]>0){
        visited[startb]=true;
        beltmap[startb]--;
        robotq.push(startb);
    }
}
bool checkdur(){
    int cnt=0;
    for(int i=0;i<2*N;i++){
        if(beltmap[i]==0){
            cnt++;
        }
    }
    if(cnt>=maxzerobelt){
        return true;
    }
    else{
        return false;
    }
}
int main(void){
    cin>>N>>maxzerobelt;
    for(int i=0;i<2*N;i++){
        cin>>beltmap[i];
    }
    startb=0;
    endb=N-1;
    int ans=0;
    while(true){
        ans++;
        movebelt();
        if(!robotq.empty()){
            moverobot();
        }
        makerobot();
        if(checkdur()){
            break;
        }
    }
    cout<<ans;
    return 0;
}