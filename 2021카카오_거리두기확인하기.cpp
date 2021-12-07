#include <string>
#include <vector>
#include <iostream>
using namespace std;
int dy[4]={0,-1,0,1};
int dx[4]={-1,0,1,0};
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(int i=0;i<5;i++){
        bool check = true;
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++){
                if(places[i][j][k]=='P'){
                    for(int s=0;s<4;s++){
                        int tmpj = dy[s]+j;
                        int tmpk = dx[s]+k;
                        if(tmpj>=0 && tmpj<5 && tmpk>=0 && tmpk<5){
                            if(places[i][tmpj][tmpk]=='P'){
                                check=false;
                                break;
                            }
                        }
                    }
                }
                else if(places[i][j][k]=='O'){
                    int cnt = 0;
                    for(int s=0;s<4;s++){
                        int tmpj = dy[s]+j;
                        int tmpk = dx[s]+k;
                        if(tmpj>=0 && tmpj<5 && tmpk>=0 && tmpk<5){
                            if(places[i][tmpj][tmpk]=='P'){
                                cnt++;
                            }
                            if(cnt>=2){
                                check=false;
                                break;
                            }
                        }
                    }
                }
                if(check==false){
                    break;
                }
            }
            if(check==false){
                answer.push_back(0);
                break;
            }
        }
        if(check==true){
            answer.push_back(1);
        }
    }
    //for(int i=0;i<5;i++){
    //    for(int j=0;j<5;j++){
    //        cout<<cvector[i][j];
    //    }
    //    cout<<'\n';
    //}
    return answer;
}