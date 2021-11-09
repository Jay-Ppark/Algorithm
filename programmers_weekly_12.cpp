#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool visited[8];
vector<vector<int>> d;
int maxcnt=0;
void DFS(int cur, int health, int cnt){
    visited[cur]=true;
    health = health-d[cur][1];
    for(int i=0;i<d.size();i++){
        if(!visited[i]&&health>=d[i][0]){
            DFS(i,health,cnt+1);
        }
    }
    visited[cur]=false;
    if(maxcnt<cnt){
        maxcnt=cnt;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    d.resize(dungeons.size());
    copy(dungeons.begin(),dungeons.end(),d.begin());
    for(int i=0;i<dungeons.size();i++){
        if(k>=dungeons[i][0]){
            DFS(i,k,1);
        }
    }
    answer=maxcnt;
    return answer;
}