#include<iostream>
using namespace std;
int main(void){
    int arr[10]={1,10,5,8,7,6,4,3,2,9};
    int index=0;
    int min=0;
    for(int i=0;i<10;i++){
        min=9999;
        index=i;
        for(int j=i;j<10;j++){
            if(min>arr[j]){
                index=j;
                min=arr[j];
            }
        }
        arr[index]=arr[i];
        arr[i]=min;
    }
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}