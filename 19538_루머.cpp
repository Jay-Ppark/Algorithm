#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> v[200001];
queue<int> q;
queue<int> subq;
int N,M;
int rumortime[200001];
void init(){
    for(int i=1;i<=N;i++){
        rumortime[i]=-1;
    }
}
int main(void){
    cin>>N;
    for(int i=1;i<=N;i++){
        while(true){
            int tmp;
            cin>>tmp;
            if(tmp==0){
                break;
            }
            else{
                v[i].push_back(tmp);
            }
        }
    }
    init();
    cin>>M;
    for(int i=0;i<M;i++){
        int tmp;
        cin>>tmp;
        q.push(tmp);
        rumortime[tmp]=0;
    }
    
    
    return 0;
}