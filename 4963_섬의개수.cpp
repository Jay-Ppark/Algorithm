#include<iostream>
#include<queue>
using namespace std;
int w;
int h;
int sq_map[50][50];
bool visited[50][50];
int dx[8]={-1,0,1,-1,1,-1,0,1};
int dy[8]={-1,-1,-1,0,0,1,1,1};
void init(){
    for(int i=0;i<50;i++){
        for(int j=0;j<50;j++){
            visited[i][j]=false;
        }
    }
}
void BFS(int y,int x){
    queue<pair<int,int>> q;
    q.push({y,x});
    visited[y][x]=true;
    while(!q.empty()){
        int yy=q.front().first;
        int xx=q.front().second;
        q.pop();
        for(int i=0;i<8;i++){
            int tmpy=yy+dy[i];
            int tmpx=xx+dx[i];
            if(tmpy>=0 && tmpy<h && tmpx>=0 && tmpx<w && !visited[tmpy][tmpx]){
                if(sq_map[tmpy][tmpx]==1){
                    q.push({tmpy,tmpx});
                    visited[tmpy][tmpx]=true;
                }
            }
        }
    }
}
int main(void){
    int island_cnt=0;
    while(true){
        cin>>w>>h;
        if(w==0 && h==0){
            break;
        }
        island_cnt=0;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin>>sq_map[i][j];
            }
        }
        init();
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(sq_map[i][j]==1 && !visited[i][j]){
                    BFS(i,j);
                    island_cnt++;
                }
            }
        }
        cout<<island_cnt<<'\n';
    }

    return 0;
}