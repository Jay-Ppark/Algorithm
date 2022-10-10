#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N,Q;
int icemap[64][64];
int tmpicemap[64][64];
int mapsize=1;
vector<int> Qv;
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};
bool melted[64][64];
bool visited[64][64];
int totalicecnt=0;
void doright(int y,int x,int lsize){
    int maxx=x+lsize-1;
    int tmpy=y;
    for(int i=y;i<tmpy+lsize;i++){
        y=tmpy;
        for(int j=x;j<x+lsize;j++){
            tmpicemap[y][maxx]=icemap[i][j];
            y++;
        }
        maxx--;
    }
}
void turnright(int lsize){
    for(int i=0;i<mapsize;i=i+lsize){
        for(int j=0;j<mapsize;j=j+lsize){
            doright(i,j,lsize);
        }
    }
    for(int i=0;i<mapsize;i++){
        for(int j=0;j<mapsize;j++){
            icemap[i][j]=tmpicemap[i][j];
        }
    }
}
void meltice(){
    for(int i=0;i<mapsize;i++){
        for(int j=0;j<mapsize;j++){
            int cnt=0;
            for(int d=0;d<4;d++){
                int ny=i+dy[d];
                int nx=j+dx[d];
                if(ny>=0&&ny<mapsize&&nx>=0&&nx<mapsize){
                    if(icemap[ny][nx]>0){
                        cnt++;
                    }
                }
            }
            if(cnt<3){
                melted[i][j]=true;
            }
        }
    }
    for(int i=0;i<mapsize;i++){
        for(int j=0;j<mapsize;j++){
            if(melted[i][j]){
                if(icemap[i][j]>0){
                    icemap[i][j]--;
                }
                melted[i][j]=false;
            }
            totalicecnt=totalicecnt+icemap[i][j];
        }
    }
}
int calice(int y,int x){
    int cnt=1;
    visited[y][x]=true;
    queue<pair<int,int> > q;
    q.push({y,x});
    while(!q.empty()){
        int tmpy=q.front().first;
        int tmpx=q.front().second;
        q.pop();
        for(int d=0;d<4;d++){
            int ny=tmpy+dy[d];
            int nx=tmpx+dx[d];
            if(ny>=0&&ny<mapsize&&nx>=0&&nx<mapsize){
                if(icemap[ny][nx]>0&&!visited[ny][nx]){
                    q.push({ny,nx});
                    visited[ny][nx]=true;
                    cnt++;
                }
            }
        }
    }
    return cnt;
}
int findmaxice(){
    int maxice=-1;
    for(int i=0;i<mapsize;i++){
        for(int j=0;j<mapsize;j++){
            if(!visited[i][j]&&icemap[i][j]>0){
                int tmpmax=calice(i,j);
                if(maxice<tmpmax){
                    maxice=tmpmax;
                }
            }
        }
    }
    if(maxice==-1){
        return 0;
    }
    return maxice;
}
int main(void){
    cin>>N>>Q;
    for(int i=0;i<N;i++){
        mapsize=mapsize*2;
    }
    for(int i=0;i<mapsize;i++){
        for(int j=0;j<mapsize;j++){
            cin>>icemap[i][j];
        }
    }
    for(int i=0;i<Q;i++){
        int tmp;
        cin>>tmp;
        Qv.push_back(tmp);
    }
    for(int i=0;i<Qv.size();i++){
        int Lsize=1;
        totalicecnt=0;
        for(int j=0;j<Qv[i];j++){
            Lsize=Lsize*2;
        }
        if(Lsize>1){
            turnright(Lsize);
        }
        meltice();
    }
    cout<<totalicecnt<<'\n';
    cout<<findmaxice();
    return 0;
}