#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int blockMap[20][20];
bool visited[20][20];
int Mapsize, blockCnt;
int maxblocks = 450;
int BFS(int block){
    for(int i=0;i<Mapsize;i++){
        for(int j=0;j<Mapsize;j++){
            if(!visited[i][j]){
                queue<pair<int,int>> q;
            }
        }
    }
}
int main(void){
    cin>>Mapsize>>blockCnt;
    for(int i=0;i<Mapsize;i++){
        for(int j=0;j<Mapsize;j++){
            cin>>blockMap[i][j];
        }
    }
    for(int i=1;i<=Mapsize;i++){
        BFS(i)
    }
    return 0;
}