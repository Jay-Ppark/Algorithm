#include<iostream>
#include<vector>
#include<stack>
#define MAX 100001 
using namespace std;
int N,M;
vector<int> v[MAX];
vector<vector<int> > SCC;
bool finished[MAX];
int d[MAX];
int id=1;
stack<int> s;
void init(){
    SCC.clear();
    id=1;
    for(int i=0;i<MAX;i++){
        v[i].clear();
        finished[i]=false;
        d[i]=0;
    }
}
int dfs(int x){
    d[x]=id;
    id++;
    s.push(x);
    int parent=d[x];
    for(int i=0;i<v[x].size();i++){
        int y=v[x][i];
        if(d[y]==0){
            parent=min(parent,dfs(y));
        }
        else if(!finished[y]){
            parent=min(parent,d[y]);
        }
    }
    if(parent==d[x]){
        vector<int> tmpscc;
        while(true){
            int t=s.top();
            s.pop();
            tmpscc.push_back(t);
            finished[t]=true;
            if(t==x){
                break;
            }
        }
        SCC.push_back(tmpscc);
    }
}
int main(void){
    int testcase;
    cin>>testcase;
    for(int t=0;t<testcase;t++){
        init();
        cin>>N>>M;
        for(int i=0;i<M;i++){
            int s,e;
            cin>>s>>e;
            v[s].push_back(e);
        }
        for(int i=1;i<=N;i++){
            if(d[i]==0){
                dfs(i);
            }
        }
    }
    return 0;
}