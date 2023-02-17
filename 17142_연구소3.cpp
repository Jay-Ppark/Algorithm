#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int labmap[50][50];
int livevirusnum;
int N;
vector<pair<int,int>> virus;
bool virusselected[10];
bool visited[50][50];
int dy[4]={-1,0,1,0};
int dx[4]={0,-1,0,1};
int result=100000;
int blank;
int BFS(){
    queue<pair<int,int>> q;
    for(int i=0;i<50;i++){
        fill(&visited[i][0],&visited[i][0]+50,false);
    }
    for(int i=0;i<10;i++){
        if(virusselected[i]){
           q.push({virus[i].first,virus[i].second});
           visited[virus[i].first][virus[i].second]=true; 
        }
    }
    int cnt=0;
    int copyblank=blank;
    while(!q.empty()){
        int qsize=q.size();
        if(copyblank==0){
            break;
        }
        for(int qs=0;qs<qsize;qs++){
            int y=q.front().first;
            int x=q.front().second;
            q.pop();
            for(int d=0;d<4;d++){
                int ny=y+dy[d];
                int nx=x+dx[d];
                if(ny>=0&&ny<N&&nx>=0&&nx<N){
                    if(!visited[ny][nx]&&labmap[ny][nx]!=1){
                        visited[ny][nx]=true;
                        if(labmap[ny][nx]==0){
                            copyblank--;
                        }
                        q.push({ny,nx});
                    }
                }
            }
        }
        cnt++;
    }
    if(copyblank==0){
        return cnt;
    }
    else{
        return -1;
    }
}
void selectvirus(int c,int cur){
    if(c==livevirusnum){
        int tmpcnt=BFS();
        if(tmpcnt!=-1&&tmpcnt<result){
            result=tmpcnt;
        }
        return;
    }
    for(int i=cur;i<virus.size();i++){
        if(!virusselected[i]){
            virusselected[i]=true;
            selectvirus(c+1,i+1);
            virusselected[i]=false;
        }
    }
}
int main(void){
    cin>>N>>livevirusnum;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>labmap[i][j];
            if(labmap[i][j]==2){
                virus.push_back({i,j});
            }
            else if(labmap[i][j]==0){
                blank++;
            }
        }
    }
    selectvirus(0,0);
    if(result!=100000){
        cout<<result;
    }
    else{
        cout<<-1;
    }
    return 0;
}