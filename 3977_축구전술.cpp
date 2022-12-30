#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
#define MAX 100001
using namespace std;
int N,M;
vector<int> v[MAX];
vector<vector<int> > SCC;
bool finished[MAX];
int d[MAX];
int group[MAX];
bool inDegree[MAX];
int id=1;
stack<int> s;
void init(){
    id=1;
    SCC.clear();
    for(int i=0;i<MAX;i++){
        v[i].clear();
        finished[i]=false;
        d[i]=0;
        group[i]=0;
        inDegree[i]=false;
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
    if(d[x]==parent){
        vector<int> tmpscc;
        while(true){
            int t=s.top();
            s.pop();
            tmpscc.push_back(t);
            finished[t]=true;
            group[t]=SCC.size()+1;
            if(t==x){
                break;
            }
        }
        SCC.push_back(tmpscc);
    }
    return parent;
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
            v[s+1].push_back(e+1);
        }
        for(int i=1;i<=N;i++){
            if(d[i]==0){
                dfs(i);
            }
        }
        for(int i=1;i<=N;i++){
            for(int j=0;j<v[i].size();j++){
                int y=v[i][j];
                if(group[i]!=group[y]){
                    inDegree[group[y]]=true;
                }
            }
        }
        int count=0;
        vector<int> result;
        for(int i=1;i<=SCC.size();i++){
            if(!inDegree[i]){
                count++;
                for(int j=0;j<SCC[i-1].size();j++){
                    result.push_back(SCC[i-1][j]-1);
                }
            }
        }
        if(count!=1){
            cout<<"Confused\n\n";
        }
        else{
            sort(result.begin(),result.end());
            for(int i=0;i<result.size();i++){
                cout<<result[i]<<"\n";
            }
            cout<<'\n';
        }
    }
    return 0;
}