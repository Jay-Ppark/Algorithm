#include<iostream>
using namespace std;
int N,M;
int papermap[500][500];
bool visited[500][500];
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};
int maxnum=0;
void DFS(int y,int x,int cnt,int sum){
    if(cnt==4){
        if(maxnum<sum){
            maxnum=sum;
        }
    }
    else{
        for(int i=0;i<4;i++){
            int ty=y+dy[i];
            int tx=x+dx[i];
            if(ty>=0&&ty<N&&tx>=0&&tx<M){
                if(!visited[ty][tx]){
                    visited[ty][tx]=true;
                    DFS(ty,tx,cnt+1,sum+papermap[ty][tx]);
                    visited[ty][tx]=false;
                }
            }
        }
    }
}
void shape1(int y,int x){
    int tmpsum=0;
    tmpsum=papermap[y][x]+papermap[y][x+1]+papermap[y][x+2]+papermap[y+1][x+1];
    if(tmpsum>maxnum){
        maxnum=tmpsum;
    }
}
void shape2(int y,int x){
    int tmpsum=0;
    tmpsum=papermap[y][x]+papermap[y][x+1]+papermap[y][x+2]+papermap[y-1][x+1];
    if(tmpsum>maxnum){
        maxnum=tmpsum;
    }
}
void shape3(int y,int x){
    int tmpsum=0;
    tmpsum=papermap[y][x]+papermap[y+1][x]+papermap[y+2][x]+papermap[y+1][x+1];
    if(tmpsum>maxnum){
        maxnum=tmpsum;
    }
}
void shape4(int y,int x){
    int tmpsum=0;
    tmpsum=papermap[y][x]+papermap[y-1][x+1]+papermap[y][x+1]+papermap[y+1][x+1];
    if(tmpsum>maxnum){
        maxnum=tmpsum;
    }
}
int main(void){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>papermap[i][j];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            visited[i][j]=true;
            DFS(i,j,1,papermap[i][j]);
            if(j+2<M&&i+1<N){
                shape1(i,j);
            }
            if(j+2<M&&i-1>=0){
                shape2(i,j);
            }
            if(j+1<M&&i+2<N){
                shape3(i,j);
            }
            if(j+1<M&&i-1>=0&&i+1<N){
                shape4(i,j);
            }
            visited[i][j]=false;
        }
    }
    cout<<maxnum;
    return 0;
}