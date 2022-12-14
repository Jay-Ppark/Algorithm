#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int N;
int stu[32001];
vector<int> v[32001];
void topology(){
    queue<int> q;
    for(int i=1;i<=N;i++){
        if(stu[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int y=q.front();
        q.pop();
        cout<<y<<" ";
        for(int i=0;i<v[y].size();i++){
            stu[v[y][i]]--;
            if(stu[v[y][i]]==0){
                q.push(v[y][i]);
            }
        }
    }
}
int main(void){
    int testcase;
    cin>>N>>testcase;
    for(int t=0;t<testcase;t++){
        int x,y;
        cin>>x>>y;
        stu[y]++;
        v[x].push_back(y);
    }
    topology();
    return 0;
}