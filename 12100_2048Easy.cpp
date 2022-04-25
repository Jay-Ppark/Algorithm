#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int N;
int board[20][20];
int copyBoard[20][20];
int c[5];
int maxanswer;
vector<int> v;
void FindMax(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(copyBoard[i][j]>maxanswer){
                maxanswer=copyBoard[i][j];
            }
        }
    }
}
void Init(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            copyBoard[i][j]=board[i][j];
        }
    }
}
void left(){
    //이동
    for(int i=0;i<N;i++){
        for(int j=0;j<N-1;j++){
            bool check=false;
            if(copyBoard[i][j]==0){
                int k=j;
                while(k<N){
                    if(copyBoard[i][k]!=0){
                        check=true;
                        break;
                    }
                    k++;
                }
                if(check){
                    copyBoard[i][j]=copyBoard[i][k];
                    copyBoard[i][k]=0;
                }
            }
        }
    }
    //합치기
    for(int i=0;i<N;i++){
        for(int j=0;j<N-1;j++){
            if(copyBoard[i][j]==copyBoard[i][j+1]){
                copyBoard[i][j]=copyBoard[i][j]*2;
                copyBoard[i][j+1]=0;
            }
        }
    }
    //이동
    for(int i=0;i<N;i++){
        for(int j=0;j<N-1;j++){
            bool check=false;
            if(copyBoard[i][j]==0){
                int k=j;
                while(k<N){
                    if(copyBoard[i][k]!=0){
                        check=true;
                        break;
                    }
                    k++;
                }
                if(check){
                    copyBoard[i][j]=copyBoard[i][k];
                    copyBoard[i][k]=0;
                }
            }
        }
    }
}
void right(){
    //이동
    for(int i=0;i<N;i++){
        for(int j=N-1;j>0;j--){
            bool check=false;
            if(copyBoard[i][j]==0){
                int k=j;
                while(k>=0){
                    if(copyBoard[i][k]!=0){
                        check=true;
                        break;
                    }
                    k--;
                }
                if(check){
                    copyBoard[i][j]=copyBoard[i][k];
                    copyBoard[i][k]=0;
                }
            }
        }
    }
    //합치기
    for(int i=0;i<N;i++){
        for(int j=N-1;j>0;j--){
            if(copyBoard[i][j]==copyBoard[i][j-1]){
                copyBoard[i][j]=copyBoard[i][j]*2;
                copyBoard[i][j-1]=0;
            }
        }
    }
    //이동
    for(int i=0;i<N;i++){
        for(int j=N-1;j>0;j--){
            bool check=false;
            if(copyBoard[i][j]==0){
                int k=j;
                while(k>=0){
                    if(copyBoard[i][k]!=0){
                        check=true;
                        break;
                    }
                    k--;
                }
                if(check){
                    copyBoard[i][j]=copyBoard[i][k];
                    copyBoard[i][k]=0;
                }
            }
        }
    }
}
void up(){
    //이동
    for(int i=0;i<N-1;i++){
        for(int j=0;j<N;j++){
            bool check=false;
            if(copyBoard[i][j]==0){
                int k=i;
                while(k<N){
                    if(copyBoard[k][j]!=0){
                        check=true;
                        break;
                    }
                    k++;
                }
                if(check){
                    copyBoard[i][j]=copyBoard[k][j];
                    copyBoard[k][j]=0;
                }
            }
        }
    }
    //합치기
    for(int i=0;i<N-1;i++){
        for(int j=0;j<N;j++){
            if(copyBoard[i][j]==copyBoard[i+1][j]){
                copyBoard[i][j]=copyBoard[i][j]*2;
                copyBoard[i+1][j]=0;
            }
        }
    }
    //이동
    for(int i=0;i<N-1;i++){
        for(int j=0;j<N;j++){
            bool check=false;
            if(copyBoard[i][j]==0){
                int k=i;
                while(k<N){
                    if(copyBoard[k][j]!=0){
                        check=true;
                        break;
                    }
                    k++;
                }
                if(check){
                    copyBoard[i][j]=copyBoard[k][j];
                    copyBoard[k][j]=0;
                }
            }
        }
    }
}
void down(){
    //이동
    for(int i=N-1;i>0;i--){
        for(int j=0;j<N;j++){
            bool check=false;
            if(copyBoard[i][j]==0){
                int k=i;
                while(k>=0){
                    if(copyBoard[k][j]!=0){
                        check=true;
                        break;
                    }
                    k--;
                }
                if(check){
                    copyBoard[i][j]=copyBoard[k][j];
                    copyBoard[k][j]=0;
                }
            }
        }
    }
    //합치기
    for(int i=N-1;i>0;i--){
        for(int j=0;j<N;j++){
            if(copyBoard[i][j]==copyBoard[i-1][j]){
                copyBoard[i][j]=copyBoard[i][j]*2;
                copyBoard[i-1][j]=0;
            }
        }
    }
    //이동
    for(int i=N-1;i>0;i--){
        for(int j=0;j<N;j++){
            bool check=false;
            if(copyBoard[i][j]==0){
                int k=i;
                while(k>=0){
                    if(copyBoard[k][j]!=0){
                        check=true;
                        break;
                    }
                    k--;
                }
                if(check){
                    copyBoard[i][j]=copyBoard[k][j];
                    copyBoard[k][j]=0;
                }
            }
        }
    }
}
void DFS(){
    for(int i=0;i<5;i++){
        if(v[i]==0){
            left();
        }
        else if(v[i]==1){
            right();
        }
        else if(v[i]==2){
            up();
        }
        else{
            down();
        }
    }
    FindMax();
}
void makeorder(){//(int idx, int cnt){
    if(v.size()==5){
        Init();
        DFS();
        return;
    }
    else{
        for(int i=0;i<4;i++){
            v.push_back(i);
            makeorder();
            v.pop_back();
        }
    }
    //if(cnt==5){
    //    Init();
    //    DFS();
    //    return;
    //}
    //for(int i=0;i<4;i++){
    //    c[cnt]=i;
    //    makeorder(i,cnt+1);
    //}
}
void solve(){
    //makeorder(0,0);
    makeorder();
}
int main(void){
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>board[i][j];
        }
    }
    solve();
    cout<<maxanswer;
    return 0;
}