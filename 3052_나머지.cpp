#include<iostream>
using namespace std;
bool visited[42];
int main(void){
    int ans=0;
    for(int i=0;i<10;i++){
        int tmp;
        cin>>tmp;
        if(!visited[tmp%42]){
            visited[tmp%42]=true;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}