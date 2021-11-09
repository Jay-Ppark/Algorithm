#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    for(long long int i = left;i<=right;i++){
        long long int q = i/n;
        long long int r = i%n;
        if(r<=q){
            answer.push_back(q+1);
        }
        else{
            answer.push_back(r+1);
        }
    }
    return answer;
}