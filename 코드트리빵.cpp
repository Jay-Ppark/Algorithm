#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N,M;
int basemap[15][15];
pair<int,int> cv[31];
pair<int,int> human[31];
bool visited[15][15];
int step[15][15];
bool arrived[31];
bool started[31];
int needtime;
int dy[4]={-1,0,0,1};
int dx[4]={0,-1,1,0};
void movecv(){
    for(int i=1;i<=M;i++){
        if(!started[i]||arrived[i]){
            continue;
        }
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                visited[j][k]=false;
                step[j][k]=0;
            }
        }
        queue<pair<int,int>> q;
        q.push({cv[i].first,cv[i].second});
        visited[cv[i].first][cv[i].second]=true;
        while(!q.empty()){
            int y=q.front().first;
            int x=q.front().second;
            q.pop();
            for(int d=0;d<4;d++){
                int ny=y+dy[d];
                int nx=x+dx[d];
                if(ny>=0&&ny<N&&nx>=0&&nx<N){
                    if(!visited[ny][nx]){
                        if(basemap[ny][nx]!=2){
                            q.push({ny,nx});
                            visited[ny][nx]=true;
                            step[ny][nx]=step[y][x]+1;
                        }
                    }
                }
            }
        }
        int maxcnt=1000000;
        int y=human[i].first;
        int x=human[i].second;
        for(int d=0;d<4;d++){
            int ny=human[i].first+dy[d];
            int nx=human[i].second+dx[d];
            if(ny>=0&&ny<N&&nx>=0&&nx<N){
                if(visited[ny][nx]){
                    if(basemap[ny][nx]!=2){
                        if(maxcnt>step[ny][nx]){
                            maxcnt=step[ny][nx];
                            y=ny;
                            x=nx;
                        }
                    }
                }
            }
        }
        human[i]={y,x};
    }
}
void arrivecv(){
    for(int i=1;i<=M;i++){
        if(started[i]&&!arrived[i]){
            if(human[i].first==cv[i].first&&human[i].second==cv[i].second){
                arrived[i]=true;
                basemap[human[i].first][human[i].second]=2;
            }
        }
    }
}
void movecamp(){
    if(needtime<=M){
        if(!started[needtime]){
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    visited[i][j]=false;
                }
            }
            queue<pair<int,int>> q;
            q.push({cv[needtime].first,cv[needtime].second});
            visited[cv[needtime].first][cv[needtime].second]=true;
            while(!q.empty()){
                int y=q.front().first;
                int x=q.front().second;
                q.pop();
                if(basemap[y][x]==1){
                    basemap[y][x]=2;
                    human[needtime]={y,x};
                    started[needtime]=true;
                    break;
                }
                for(int i=0;i<4;i++){
                    int ny=y+dy[i];
                    int nx=x+dx[i];
                    if(ny>=0&&ny<N&&nx>=0&&nx<N){
                        if(!visited[ny][nx]){
                            if(basemap[ny][nx]!=2){
                                q.push({ny,nx});
                                visited[ny][nx]=true;
                            }
                        }
                    }
                }
            }
        }
    }
}
bool endmove(){
    for(int i=1;i<=M;i++){
        if(!arrived[i]){
            return false;
        }
    }
    return true;
}
int main(void){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>basemap[i][j];
        }
    }
    for(int i=1;i<=M;i++){
        int y,x;
        cin>>y>>x;
        cv[i]={y-1,x-1};
    }
    while(true){
        needtime++;
        //cout<<needtime;
        movecv();
        arrivecv();
        movecamp();
        if(endmove()){
            break;
        }
        
    }
    cout<<needtime;
    /*
    int index=1;
    for(int i=1;i<=M;i++){
        cout<<human[i].first<<human[i].second<<'\n';
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<basemap[i][j]<<' ';
        }
        cout<<'\n';
    }
    */
    return 0;
}