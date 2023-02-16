#include<iostream>
#include<vector>
using namespace std;
int R,C;
int sharkmap[100][100];
struct SharkInfo{
    int y;
    int x;
    int s;
    int d;
    int size;
    bool live=true;
};
vector<SharkInfo> shark;
int result;
void moveandcatch(int x){
    for(int i=0;i<R;i++){
        if(sharkmap[i][x]>0){
            sharkmap[i][x]=0;
            for(int j=0;j<shark.size();j++){
                if(shark[j].y==i&&shark[j].x==x){
                    shark[j].live=false;
                    result=result+shark[j].size;
                }
            }
            break;
        }
    }
}
void moveshark(){
    for(int i=0;i<shark.size();i++){
        if(shark[i].live){
            int y=shark[i].y;
            int x=shark[i].x;
        }
    }
}
int main(void){
    int sharknum;
    cin>>R>>C>>sharknum;
    for(int i=0;i<sharknum;i++){
        SharkInfo tmp;
        cin>>tmp.y>>tmp.x>>tmp.x>>tmp.s>>tmp.d>>tmp.size;
        tmp.y--;
        tmp.x--;
        shark.push_back(tmp);
        sharkmap[tmp.y][tmp.x]++;
    }
    for(int t=0;t<C;t++){
        moveandcatch(t);
        moveshark();
    }
    return 0;
}