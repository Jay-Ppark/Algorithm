#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N;
int sharkmap[20][20];
int sharky,sharkx;
int sharksize=2;
int eatfishcnt;
int result;
int dy[4]={-1,0,1,0};
int dx[4]={0,-1,0,1};
bool BFS(){
    bool visited[20][20]={false,};
    queue<pair<pair<int,int>,int>> q;
    vector<pair<pair<int,int>,int>> tmpfish;
    q.push({{sharky,sharkx},0});
    visited[sharky][sharkx]=true;
    while(!q.empty()){
        int y=q.front().first.first;
        int x=q.front().first.second;
        int t=q.front().second;
        q.pop();
        for(int d=0;d<4;d++){
            int ny=y+dy[d];
            int nx=x+dx[d];
            if(ny>=0&&ny<N&&nx>=0&&nx<N){
                if(!visited[ny][nx]&&sharkmap[ny][nx]<=sharksize){
                    if(sharkmap[ny][nx]==0||sharkmap[ny][nx]==sharksize){
                        q.push({{ny,nx},t+1});
                    }
                    else{
                        q.push({{ny,nx},t+1});
                        tmpfish.push_back({{ny,nx},t+1});
                    }
                    visited[ny][nx]=true;
                }
            }
        }
    }
    if(tmpfish.empty()){
        return false;
    }
    int maxy=tmpfish[0].first.first;
    int maxx=tmpfish[0].first.second;
    int maxt=tmpfish[0].second;
    for(int i=1;i<tmpfish.size();i++){
        if(maxt>tmpfish[i].second){
            maxy=tmpfish[i].first.first;
            maxx=tmpfish[i].first.second;
            maxt=tmpfish[i].second;
        }
        else if(maxt==tmpfish[i].second){
            if(maxy>tmpfish[i].first.first){
                maxy=tmpfish[i].first.first;
                maxx=tmpfish[i].first.second;
            }
            else if(maxy==tmpfish[i].first.first&&maxx>=tmpfish[i].first.second){
                maxy=tmpfish[i].first.first;
                maxx=tmpfish[i].first.second;
            }
        }
    }
    result=result+maxt;
    sharky=maxy;
    sharkx=maxx;
    eatfishcnt++;
    sharkmap[sharky][sharkx]=0;
    if(eatfishcnt==sharksize){
        sharksize++;
        eatfishcnt=0;
    }
    return true;
}
int main(void){
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>sharkmap[i][j];
            if(sharkmap[i][j]==9){
                sharkmap[i][j]=0;
                sharky=i;
                sharkx=j;
            }
        }
    }
    while(true){
        bool eaten=BFS();
        if(!eaten){
            break;
        }
    }
    cout<<result;
    return 0;
}