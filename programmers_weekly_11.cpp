#include <string>
#include <vector>
#include <iostream>
#include <queue>
bool visited[102][102];
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
using namespace std;
void fillRectangle(int leftX, int leftY, int rightX, int rightY){
    for(int i=leftY;i<=rightY;i++){
        for(int j=leftX;j<=rightX;j++){
            visited[i][j]=true;
        }
    }
}
void makeEdge(int leftX, int leftY, int rightX, int rightY){
    for(int i=leftY+1;i<rightY;i++){
        for(int j=leftX+1;j<rightX;j++){
            visited[i][j]=false;
        }
    }
}
int BFS(int startX, int startY, int endX, int endY){
    queue<pair<pair<int,int>,int>> q;
    q.push({{startX,startY},0});
    
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second;
        visited[y][x]=false;
        q.pop();
        if(y==endY && x==endX){
            return cnt;
        }
        
        for(int i=0;i<4;i++){
            int tmpy = y+dy[i];
            int tmpx = x+dx[i];
            if(tmpy>=0&&tmpy<=100&&tmpx>=0&&tmpx<=100&&visited[tmpy][tmpx]){
                q.push({{tmpx,tmpy},cnt+1});
            }
        }
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    for(int i=0;i<rectangle.size();i++){
        fillRectangle(rectangle[i][0]*2,rectangle[i][1]*2,rectangle[i][2]*2,rectangle[i][3]*2);
    }
    for(int i=0;i<rectangle.size();i++){
        makeEdge(rectangle[i][0]*2,rectangle[i][1]*2,rectangle[i][2]*2,rectangle[i][3]*2);
    }
    answer = BFS(characterX*2,characterY*2,itemX*2,itemY*2);
    answer = answer/2;
    
    return answer;
}