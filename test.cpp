#include<iostream>
using namespace std;
bool visited[6];
int arr[3];
int t=1;
void DFS(int index,int cnt){
    if(cnt==3){
        cout<<"---------"<<t<<'\n';
        for(int i=0;i<3;i++){
            cout<<arr[i];
        }
        cout<<'\n';
        t++;
        return;
    }
    for(int i=index;i<6;i++){
        arr[cnt]=i;
        DFS(i,cnt+1);
    }
}
int main(void){
    DFS(0,0);
    return 0;
}