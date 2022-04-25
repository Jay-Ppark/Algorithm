#include<iostream>
#include<queue>
#include<cstdlib>
using namespace std;
struct INFO{
    int ry,rx,by,bx,cnt;
};
INFO start;
int N,M;
char board[10][10];
bool visited[10][10][10][10];
int BFS(){
    queue<INFO> q;
    q.push(start);
    visited[start.ry][start.rx][start.by][start.bx]=true;
    int dy[4]={-1,1,0,0};
    int dx[4]={0,0,-1,1};
    while(!q.empty()){
        INFO cur = q.front();
        q.pop();
        //실패한 경우
        if(cur.cnt>10){
            break;
        }
        //성공한 경우
        if(board[cur.ry][cur.rx]=='O'&&board[cur.by][cur.bx]!='O'){
            return cur.cnt;
        }
        //구슬이 움직이는 경우
        //4방향으로 움직임
        for(int i=0;i<4;i++){
            int newRy=cur.ry;
            int newRx=cur.rx;
            int newBy=cur.by;
            int newBx=cur.bx;
            //빨간 구슬일 경우
            while(1){
                if(board[newRy][newRx]!='#'&&board[newRy][newRx]!='O'){
                    newRy=newRy+dy[i];
                    newRx=newRx+dx[i];
                }
                else{
                    if(board[newRy][newRx]=='#'){
                        newRy=newRy-dy[i];
                        newRx=newRx-dx[i];
                    }
                    break;
                }
            }
            //파란구슬인 경우
            while(1){
                if(board[newBy][newBx]!='#'&&board[newBy][newBx]!='O'){
                    newBy=newBy+dy[i];
                    newBx=newBx+dx[i];
                }
                else{
                    if(board[newBy][newBx]=='#'){
                        newBy=newBy-dy[i];
                        newBx=newBx-dx[i];
                    }
                    break;
                }
            }
            //구슬이 겹친 경우
            if(newRy==newBy&&newRx==newBx){
                //구멍에 빠지지 않은 경우
                if(board[newRy][newRx]!='O'){
                    int absr=abs(newRy-cur.ry)+abs(newRx-cur.rx);
                    int absb=abs(newBy-cur.by)+abs(newBx-cur.bx);
                    if(absr>absb){
                        newRy=newRy-dy[i];
                        newRx=newRx-dx[i];
                    }
                    else{
                        newBy=newBy-dy[i];
                        newBx=newBx-dx[i];
                    }
                }
            }
            //visit
            if(visited[newRy][newRx][newBy][newBx]==false){
                visited[newRy][newRx][newBy][newBx]=true;
                INFO next;
                next.ry=newRy;
                next.rx=newRx;
                next.by=newBy;
                next.bx=newBx;
                next.cnt=cur.cnt+1;
                q.push(next);
            }
        }    
    }
    return -1;
}
int main(void){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>board[i][j];
            if(board[i][j]=='R'){
                start.ry=i;
                start.rx=j;
            }
            if(board[i][j]=='B'){
                start.by=i;
                start.bx=j;
            }
        }
    }
    start.cnt=0;
    int answer = BFS();
    cout<<answer;
    return 0;
}