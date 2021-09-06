#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
vector<string> v;
bool compare(string s1, string s2){
	if (s1.size() == s2.size()){
		return s1 < s2;
	}
	else{
		return s1.size() < s2.size();
	}
}
int main(void){
	int N;
	cin >> N;
	string tmp;
	for (int i = 0; i < N; i++){
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end(), compare);
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << '\n';
	}
	return 0;
}