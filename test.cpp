#include<iostream>
#include<list>
using namespace std;
int main(void){
    list<int> L = {1,2}; // 1 2
    list<int>::iterator t = L.end(); // t는 1을 가리키는 중
    t=L.erase(t);
    for(list<int>::iterator it = L.begin(); it!=L.end();it++){
        cout<<*it<<' ';
    }
    return 0;
}