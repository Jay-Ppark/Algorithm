#include <iostream>
#include <vector>
using namespace std;
 
struct fish {
    int y;
    int x;
    int dir;
};
int sharky, sharkx; 
int maxEating;
int tempRoute[3], route[3];
int smellMap[4][4];
vector<fish> fishMap[4][4];
vector<fish> cMap[4][4];
 
int fdy[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int fdx[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
 
int sdy[] = { 0, -1, 0, 1, 0 };
int sdx[] = { 0, 0, -1, 0, 1 };
  
void copyMap(vector<fish> A[4][4], vector<fish> B[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            A[i][j] = B[i][j];
        }
    }
}
 
void copyFish() {
    copyMap(cMap, fishMap);
}
 
int changeDir(int d) {
    if(d==1){
        d=8;
    }
    else if(d==2){
        d=1;
    }
    else if(d==3){
        d=2;
    }
    else if(d==4){
        d=3;
    }
    else if(d==5){
        d=4;
    }
    else if(d==6){
        d=5;
    }
    else if(d==7){
        d=6;
    }
    else{
        d=7;
    }
    return d;
}
 
void moveFish() {
    vector<fish> tempMap[4][4];
 
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < fishMap[i][j].size(); k++) {
                int y = fishMap[i][j][k].y;
                int x = fishMap[i][j][k].x;
                int dir = fishMap[i][j][k].dir;
                int ny = y;
                int nx = x;
                bool Flag = false;
                for (int l = 0; l < 8; l++) {
                    ny = y + fdy[dir];
                    nx = x + fdx[dir];
                    if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4) {
                        if ((nx == sharkx) && (ny == sharky)){

                        }
                        else{
                            if(smellMap[ny][nx]==0){
                                Flag=true;
                                break;
                            }
                        }
                    }
                    dir = changeDir(dir);
                }
                if (Flag == true) {
                    fish f = { ny, nx, dir };
                    tempMap[ny][nx].push_back(f);
                }
                else {
                    fish f = { y, x, dir };
                    tempMap[y][x].push_back(f);
                }
            }
        }
    }
    copyMap(fishMap, tempMap);
}
 
int routeSimulation() {
    bool visit[4][4] = { false, };
    int x = sharkx;
    int y = sharky;
    int eat = 0;
    for (int i = 0; i < 3; i++) {
        int dir = tempRoute[i];
        int nx = x + sdx[dir];
        int ny = y + sdy[dir];
        if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4) return -1;
        if (visit[ny][nx] == false) {
            visit[ny][nx] = true;
            eat += fishMap[ny][nx].size();
        }
        x = nx;
        y = ny;
    }
    return eat;
}
 
void findRoute(int cnt) {
    if (cnt == 3) {
        int eatNum = routeSimulation();
        if (eatNum > maxEating) {
            for (int i = 0; i < 3; i++) {
                route[i] = tempRoute[i];
            }
            maxEating = eatNum;
        }
        return;
    }
 
    for (int i = 1; i <= 4; i++) {
        tempRoute[cnt] = i;
        findRoute(cnt + 1);
    }
}
 
void moveShark(int time) {
    vector<fish> tempMap[4][4];
    copyMap(tempMap, fishMap);
 
    int x = sharkx;
    int y = sharky;
    for (int i = 0; i < 3; i++) {
        int dir = route[i];
        int nx = x + sdx[dir];
        int ny = y + sdy[dir];
        if (tempMap[ny][nx].size() != 0) {
            smellMap[ny][nx] = time;
            tempMap[ny][nx].clear();
        }
        x = nx;
        y = ny;
        sharky = y;
        sharkx = x;
    }
    copyMap(fishMap, tempMap);
}
 
void aboutShark(int time) {
    maxEating = -1;
    findRoute(0);
    moveShark(time);
}
 
void removeSmell(int time) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (smellMap[i][j] == 0) continue;
            if (time - smellMap[i][j] == 2) {
                smellMap[i][j] = 0;
            }
        }
    }
}
 
void bornFish() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < cMap[i][j].size(); k++) {
                fishMap[i][j].push_back(cMap[i][j][k]);
            }
        }
    }
}
 
int findAnswer() {
    int ret = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            ret += fishMap[i][j].size();
        }
    }
    return ret;
}
int main(void) {
    int fishnum, magicnum;
    cin >> fishnum >> magicnum;
    for (int i = 0; i < fishnum; i++) {
        int y, x, d;
        cin >> y >> x >> d;
        x--; y--;
        fish f = { y, x, d };
        fishMap[y][x].push_back(f);
    }
    cin >> sharky >> sharkx;
    sharky--;
    sharkx--;
    for(int i=1;i<=magicnum;i++){
        copyFish();
        moveFish();
        aboutShark(i);
        removeSmell(i);
        bornFish();
    }
    cout<<findAnswer();
    return 0;
}
