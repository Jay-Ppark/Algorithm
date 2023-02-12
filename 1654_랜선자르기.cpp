#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<long long int> v;
int already_line;
int needline;
bool calline(long long int x){
	int result=0;
	for(int i=0;i<already_line;i++){
		result=result+v[i]/x;
	}
	if(result>=needline){
		return true;
	}
	else{
		return false;
	}
}
int findMaxLine(){
	long long int min_line=1;
	long long int max_line=v[already_line-1];
	int answer=0;
	while(min_line<=max_line){
		long long int mid_line=(min_line+max_line)/2;
		if(calline(mid_line)){
			if(answer<mid_line){
				answer=mid_line;
			}
			min_line=mid_line+1;
		}
		else{
			max_line=mid_line-1;
		}
	}
	return answer;
}
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>already_line>>needline;
	for(int i=0;i<already_line;i++){
		int tmp;
		cin>>tmp;
		v.push_back(tmp);
	}
	sort(v.begin(),v.end());
	cout<<findMaxLine();
	return 0;
}