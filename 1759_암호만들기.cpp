#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<char> v;
bool visited[15];
int candidate_len;
int key_len;
void DFS(int startIndex,int mo,int ja,int cnt){
    if(cnt==key_len){
        if(mo>=1&&ja>=2){
            for(int i=0;i<candidate_len;i++){
                if(visited[i]){
                    cout<<v[i];
                }
            }
            cout<<'\n';
        }
        return;
    }
    for(int i=startIndex;i<candidate_len;i++){
        visited[i]=true;
        if(v[i]=='a' || v[i]=='e' || v[i]=='i' || v[i]=='o' || v[i]=='u'){
            DFS(i+1,mo+1,ja,cnt+1);
        }
        else{
            DFS(i+1,mo,ja+1,cnt+1);
        }
        visited[i]=false;
    }
}
int main(void){
    cin>>key_len>>candidate_len;
    for(int i=0;i<candidate_len;i++){
        char tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    DFS(0,0,0,0);
    return 0;
}