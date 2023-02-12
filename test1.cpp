#include<iostream>
#include<deque>
using namespace std;
int main(void){
    deque<int> DQ;
    DQ.push_front(10); // 10
    DQ.push_back(20); // 10 20
    cout<<DQ.size()<<'\n'; // 2
    for(auto x : DQ){
        cout<<x<<'\n';
    }
    DQ.pop_front(); // 20
    DQ.pop_back(); // 
    if(DQ.empty()){
        cout<<"Empty\n";
    }
    DQ.push_front(10); // 10
    DQ.push_back(20); // 10 20
    DQ[0]=3; // 3 20
    DQ.insert(DQ.begin()+1, 22); // 3 22 20
    DQ.erase(DQ.begin()+1); // 3 20
    for(auto x : DQ){
        cout<<x<<'\n';
    }
    return 0;
}