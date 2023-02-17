#include<iostream>
#include<queue>
using namespace std;
char miro[1001][1001];
int firemap[1000][1000];
int humanmap[1000][1000];
int R,C;
queue<pair<int,int>> fire;
queue<pair<int,int>> human;
int dy[4]={-1,0,1,0};
int dx[4]={0,-1,0,1};
void BFS(){
    while(!fire.empty()){
        int y=fire.front().first;
        int x=fire.front().second;
        fire.pop();
        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(ny>=0&&ny<R&&nx>=0&&nx<C){
                if(miro[ny][nx]!='#'){
                    if(firemap[ny][nx]>firemap[y][x]+1){
                        fire.push({ny,nx});
                        firemap[ny][nx]=firemap[y][x]+1;
                    }
                }
            }
        }
    }
    while(!human.empty()){
        int y=human.front().first;
        int x=human.front().second;
        human.pop();
        if(y==0||y==R-1||x==0||x==C-1){
            cout<<humanmap[y][x]+1;
            return;
        }
        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(ny>=0&&ny<R&&nx>=0&&nx<C){
                if(miro[ny][nx]!='#'&&humanmap[ny][nx]==-1){
                    if(humanmap[y][x]+1<firemap[ny][nx]){
                        human.push({ny,nx});
                        humanmap[ny][nx]=humanmap[y][x]+1;
                    }
                }
            }
        }
    }
    cout<<"IMPOSSIBLE";
}
int main(void){
    cin>>R>>C;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>miro[i][j];
            if(miro[i][j]=='J'){
                human.push({i,j});
                humanmap[i][j]=0;
            }
            else if(miro[i][j]=='F'){
                firemap[i][j]=0;
                fire.push({i,j});
            }
            else{
                firemap[i][j]=987654321;
                humanmap[i][j]=-1;
            }
        }
    }
    BFS();
    return 0;
}