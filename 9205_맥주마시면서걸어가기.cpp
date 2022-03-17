#include<iostream>
#include<queue>
#include<cstdlib>
using namespace std;
int conv[2][100];
bool visited[100];
void Init(){
    for(int i=0;i<100;i++){
        conv[0][i]=0;
        conv[1][i]=0;
        visited[i]=false;
    }
}
void BFS(int sx,int sy,int ex,int ey,int n){
    queue<pair<int,int>> q;
    q.push({sx,sy});
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(abs(x-ex)+abs(y-ey)<=1000){
            cout<<"happy\n";
            return;
        }
        else{
            for(int i=0;i<n;i++){
                if(!visited[i]){
                    if(abs(x-conv[0][i])+abs(y-conv[1][i])<=1000){
                        q.push({conv[0][i],conv[1][i]});
                        visited[i]=true;
                    }
                }
            }
        }
    }
    cout<<"sad\n";
}
int main(void){
    int testcase;
    cin>>testcase;
    while(testcase>0){
        int convn;
        cin>>convn;
        int startx, starty;
        cin>>startx>>starty;
        for(int i=0;i<convn;i++){
            cin>>conv[0][i]>>conv[1][i];
        }
        int endx, endy;
        cin>>endx>>endy;
        BFS(startx,starty,endx,endy,convn);
        Init();
        testcase--;
    }
    return 0;
}