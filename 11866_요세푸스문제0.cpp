#include<iostream>
using namespace std;
bool visited[1001];
int main(void){
    int N,K;
    cin>>N>>K;
    int index=1;
    int sum=0;
    int cnt=0;
    if(N==1&&K==1){
        cout<<"<1>";
    }
    else{
        while(true){
            if(!visited[index]){
                cnt++;
                if(cnt==K){
                    visited[index]=true;
                    sum++;
                    cnt=0;
                    if(sum==1){
                        cout<<"<"<<index<<", ";
                    }
                    else if(sum==N){
                        cout<<index<<">";
                        break;
                    }
                    else{
                        cout<<index<<", ";
                    }
                }
            }
            index++;
            index%=(N+1);
            if(index==0){
                index++;
            }
        }
    }
    return 0;
}