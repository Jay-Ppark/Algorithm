#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N;
int inDegree[501];
int needtime[501];
int answer[501];
vector<int> v[501];
void topology(){
    queue<int> q;
    for(int i=1;i<=N;i++){
        if(inDegree[i]==0){
            q.push(i);
            answer[i]=needtime[i];
        }
    }
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=0;i<v[x].size();i++){
            int nx=v[x][i];
            inDegree[nx]--;
            answer[nx]=max(answer[nx],answer[x]+needtime[nx]);
            if(inDegree[nx]==0){
                q.push(nx);
            }
        }
    }
}
int main(void){
    cin>>N;
    for(int i=1;i<=N;i++){
        int t;
        cin>>t;
        needtime[i]=t;
        while(true){
            int tmp;
            cin>>tmp;
            if(tmp==-1){
                break;
            }
            v[tmp].push_back(i);
            inDegree[i]++;
        }
    }
    topology();
    for(int i=1;i<=N;i++){
        cout<<answer[i]<<'\n';
    }
    return 0;
}