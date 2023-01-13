#include<iostream>
using namespace std;
bool hasline[31][11];
int N,M,H;
int needline;
bool found;
void cal(){
    int startx=1;
    int starty=1;
    int dest=1;
    while(dest<=N){
        while(starty<=H){
            if(hasline[starty][startx]){
                startx++;
            }
            else if(startx-1>=1&&hasline[starty][startx-1]){
                startx--;
            }
            starty++;
        }
        if(startx!=dest){
            return;
        }
        dest++;
        startx=dest;
        starty=1;
    }
    found=true;
}
void dfs(int cnt,int y){
    if(cnt==needline){
        cal();
        return;
    }
    for(int i=y;i<=H;i++){
        for(int j=1;j<N;j++){
            if(!hasline[i][j]&&!hasline[i][j-1]&&!hasline[i][j+1]){
                hasline[i][j]=true;
                dfs(cnt+1,i);
                hasline[i][j]=false;
            }
        }
    }
}
int main(void){
    cin>>N>>M>>H;
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        hasline[a][b]=true;
    }
    for(int i=0;i<=3;i++){
        needline=i;
        dfs(0,1);
        if(found){
            cout<<needline;
            break;
        }
    }
    if(!found){
        cout<<-1;
    }
    return 0;
}