#include<iostream>
#include<vector>
using namespace std;
bool visited[9];
vector<int> v;
int N,M;
void makeorder(int cnt){
    if(cnt==M){
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i=1;i<=N;i++){
        if(!visited[i]){
            visited[i]=true;
            v.push_back(i);
            makeorder(cnt+1);
            v.pop_back();
            visited[i]=false;
        }
    }
}
int main(void){
    cin>>N>>M;
    makeorder(0);
    return 0;
}