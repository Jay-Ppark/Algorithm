#include<iostream>
#include<deque>
using namespace std;
int applemap[100][100];
bool visited[100][100];
int N;
deque<pair<int,char>> dirs;
int diry[4]={0,1,0,-1};
int dirx[4]={1,0,-1,0};
int main(void){
    cin>>N;
    int applenum;
    cin>>applenum;
    for(int i=0;i<applenum;i++){
        int tmpy,tmpx;
        cin>>tmpy>>tmpx;
        applemap[tmpy-1][tmpx-1]=1;
    }
    int dirnum;
    cin>>dirnum;
    for(int i=0;i<dirnum;i++){
        int t;
        char c;
        cin>>t>>c;
        dirs.push_back({t,c});
    }
    deque<pair<int,int>> snake;
    int dir=0;
    int gametime=0;
    snake.push_back({0,0});
    visited[0][0]=true;
    int dirindex=0;
    while(1){
        gametime++;
        pair<int,int> snakehead=snake.front();
        int nexty=snakehead.first+diry[dir];
        int nextx=snakehead.second+dirx[dir];
        if((nexty<0||nexty==N||nextx<0||nextx==N)||visited[nexty][nextx]){
            break;
        }
        visited[nexty][nextx]=true;
        snake.push_front({nexty,nextx});
        if(applemap[nexty][nextx]==1){
            applemap[nexty][nextx]=0;
        }
        else{
            pair<int,int> tail=snake.back();
            snake.pop_back();
            visited[tail.first][tail.second]=false;
        }
        if(dirindex<dirs.size()&&dirs[dirindex].first==gametime){
            if(dirs[dirindex].second=='L'){
                dir=dir+3;
                dir=dir%4;
            }
            else{
                dir=dir+1;
                dir=dir%4;
            }
            dirindex++;
        }
    }
    cout<<gametime;
    return 0;
}