#include<iostream>
using namespace std;
int main(void){
    int arr[10]={1,10,5,8,7,6,4,3,2,9};
    for(int i=0;i<9;i++){
        int j=i;
        while(arr[j]>arr[j+1]){
            int tmp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=tmp;
            j--;
        }
    }
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}