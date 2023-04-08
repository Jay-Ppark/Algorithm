#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int N;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int colormap[29][29];
bool visited[29][29];
int groupmap[29][29];
int tmpcolormap[29][29];
int colorindex=1;
vector<int> colorsize;
int score;
void init(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            visited[i][j]=false;
        }
    }
}
void BFS(int y,int x,int index){
    queue<pair<int,int>> q;
    q.push({y,x});
    visited[y][x]=true;
    groupmap[y][x]=index;
    int cnt=1;
    while(!q.empty()){
        int yy=q.front().first;
        int xx=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int ny=yy+dy[i];
            int nx=xx+dx[i];
            if(ny>=0&&ny<N&&nx>=0&&nx<N){
                if(!visited[ny][nx]&&colormap[y][x]==colormap[ny][nx]){
                    q.push({ny,nx});
                    visited[ny][nx]=true;
                    groupmap[ny][nx]=index;
                    cnt++;
                }
            }
        }
    }
    colorsize.push_back(cnt);
}
void makegroup(){
    colorindex=1;
    colorsize.clear();
    init();
    //같은 번호끼리 그룹화
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(!visited[i][j]){
                BFS(i,j,colorindex);
                colorindex++;
            }
        }
    }
}
void calscore(){
    int tmpscore=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int d=0;d<4;d++){
                int ny=i+dy[d];
                int nx=j+dx[d];
                if(ny>=0&&ny<N&&nx>=0&&nx<N){
                    if(groupmap[i][j]!=groupmap[ny][nx]){
                        //점수계산
                        tmpscore+=(colorsize[groupmap[i][j]-1]+colorsize[groupmap[ny][nx]-1])*colormap[i][j]*colormap[ny][nx];
                    }
                }
            }
        }
    }
    tmpscore=tmpscore/2;
    score+=tmpscore;
}
void turn(){
    int t=N/2;
    //가운데 저장
    tmpcolormap[t][t]=colormap[t][t];
    //십자모양 반시계 회전
    for(int i=0;i<t;i++){
        tmpcolormap[t][i]=colormap[i][t];
        tmpcolormap[N-1-i][t]=colormap[t][i];
        tmpcolormap[t][N-1-i]=colormap[N-1-i][t];
        tmpcolormap[i][t]=colormap[t][N-1-i];
    }
    //각 모양 시계방향 회전
    for(int i=0;i<t;i++){
        for(int j=0;j<t;j++){
            tmpcolormap[j][t-1-i]=colormap[i][j];
        }
    }
    for(int i=0;i<t;i++){
        for(int j=0;j<t;j++){
            tmpcolormap[j][N-1-i]=colormap[i][j+t+1];
        }
    }
    for(int i=0;i<t;i++){
        for(int j=0;j<t;j++){
            tmpcolormap[j+t+1][t-1-i]=colormap[i+t+1][j];
        }
    }
    for(int i=0;i<t;i++){
        for(int j=0;j<t;j++){
            tmpcolormap[t+j+1][N-1-i]=colormap[i+t+1][j+t+1];
        }
    }
    //다시 복사
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            colormap[i][j]=tmpcolormap[i][j];
        }
    }
}
void show(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<groupmap[i][j]<<' ';
        }
        cout<<'\n';
    }
    for(int i=0;i<(int)colorsize.size();i++){
        cout<<colorsize[i]<<' ';
    }
    cout<<'\n';
    cout<<"colormap\n";
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<colormap[i][j]<<' ';
        }
        cout<<'\n';
    }
}
int main(void){
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>colormap[i][j];
        }
    }
    int round=0;
    while(round<4){
        //그룹화
        makegroup();
        //show();
        //점수계산
        calscore();
        if(round==3){
            break;
        }
        turn();
        round++;
    }
    //show();
    cout<<score;
    return 0;
}