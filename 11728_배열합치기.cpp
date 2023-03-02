#include<iostream>
using namespace std;
int arra[1000000];
int arrb[1000000];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int asize, bsize;
    cin>>asize>>bsize;
    for(int i=0;i<asize;i++){
        cin>>arra[i];
    }
    for(int i=0;i<bsize;i++){
        cin>>arrb[i];
    }
    int aindex=0;
    int bindex=0;
    while(aindex<asize||bindex<bsize){
        if(aindex<asize&&bindex<bsize){
            if(arra[aindex]<=arrb[bindex]){
                cout<<arra[aindex]<<' ';
                aindex++;
            }
            else{
                cout<<arrb[bindex]<<' ';
                bindex++;
            }
        }
        else{
            if(aindex<asize){
                cout<<arra[aindex]<<' ';
                aindex++;
            }
            else if(bindex<bsize){
                cout<<arrb[bindex]<<' ';
                bindex++;
            }
        }
    }
    return 0;
}