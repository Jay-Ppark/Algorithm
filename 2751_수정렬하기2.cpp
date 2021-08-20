#include<iostream>
#include<queue>
#include<functional>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;
int main(void){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        pq.push(tmp);
    }
    while(!pq.empty()){
        cout<<pq.top()<<'\n';
        pq.pop();
    }
    return 0;
}