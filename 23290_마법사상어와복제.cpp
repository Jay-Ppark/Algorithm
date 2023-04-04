#include<iostream>
#include<vector>
using namespace std;
vector<int> fish[4][4];
vector<int> cfish[4][4];
int dy[8]={0,-1,-1,-1,0,1,1,1};
int dx[8]={-1,-1,0,1,1,1,0,-1};
int sy[4]={-1,0,1,0};
int sx[4]={0,-1,0,1};
int smell[4][4];
int sharky,sharkx;
int tmpsharkd[3];
int sharkd[3];
int maxeatfish;
void showfish(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<fish[i][j].size()<<' ';
        }
        cout<<'\n';
    }
}
void copyfish(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cfish[i][j]=fish[i][j];
        }
    }
}
void movefish(){
    vector<int> tmpfish[4][4];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<fish[i][j].size();k++){
                int d=fish[i][j][k];
                bool canmove=false;
                for(int t=0;t<8;t++){
                    int y=i+dy[d];
                    int x=j+dx[d];
                    if(y>=0&&y<4&&x>=0&&x<4){
                        if(y==sharky&&x==sharkx){
    
                        }
                        else{
                            if(smell[y][x]==0){
                                tmpfish[y][x].push_back(d);
                                canmove=true;
                                break;
                            }
                        }
                    }
                    d--;
                    if(d==-1){
                        d=7;
                    }
                }
                if(!canmove){
                    tmpfish[i][j].push_back(fish[i][j][k]);
                }
            }
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            fish[i][j].clear();
            fish[i][j]=tmpfish[i][j];
        }
    }
}
int countfish(){
    int result=0;
    int ty=sharky;
    int tx=sharkx;
    bool visited[4][4]={false,};
    for(int i=0;i<3;i++){
        ty=ty+sy[tmpsharkd[i]];
        tx=tx+sx[tmpsharkd[i]];
        if(ty>=0&&ty<4&&tx>=0&&tx<4){
            if(!visited[ty][tx]){
                result=result+fish[ty][tx].size();
                visited[ty][tx]=true;
            }
        }
        else{
            return -1;
        }
    }
    return result;
}
void moveshark(int cnt){
    if(cnt==3){
        int tmp=countfish();
        if(tmp==-1){
            return;
        }
        if(tmp>maxeatfish){
            maxeatfish=tmp;
            for(int i=0;i<3;i++){
                sharkd[i]=tmpsharkd[i];
            }
        }
        return;
    }
    for(int i=0;i<4;i++){
        tmpsharkd[cnt]=i;
        moveshark(cnt+1);
    }
}
void eatfish(int t){
    for(int i=0;i<3;i++){
        sharky=sharky+sy[sharkd[i]];
        sharkx=sharkx+sx[sharkd[i]];
        if(!fish[sharky][sharkx].empty()){
            smell[sharky][sharkx]=t;
            fish[sharky][sharkx].clear();
        }
    }
}
void deletesmell(int t){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(t-smell[i][j]==2){
                smell[i][j]=0;
            }
        }
    }
}
void pastefish(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<cfish[i][j].size();k++){
                fish[i][j].push_back(cfish[i][j][k]);
            }
            cfish[i][j].empty();
        }
    }
}
int main(void){
    int fishnum,magicnum;
    cin>>fishnum>>magicnum;
    for(int i=0;i<fishnum;i++){
        int ty,tx,td;
        cin>>ty>>tx>>td;
        fish[ty-1][tx-1].push_back(td-1);
    }
    cin>>sharky>>sharkx;
    sharky--;
    sharkx--;
    for(int t=1;t<=magicnum;t++){
        maxeatfish=-1;
        copyfish();
        movefish();
        //showfish();
        moveshark(0);
        eatfish(t);
        //showfish();
        deletesmell(t);
        pastefish();
    }
    int answer=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            answer=answer+fish[i][j].size();
        }
    }
    cout<<answer;
    return 0;
}