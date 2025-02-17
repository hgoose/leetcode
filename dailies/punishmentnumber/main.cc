#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <cmath>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::unordered_map;
using std::queue;
using std::priority_queue;
typedef long long dword;

template<typename T, typename U>
using pmap = unordered_map<T,U>;

template<typename T, typename U, typename W=std::less<T>>
using pq = priority_queue<T,U,W>;

class Solution {
public:
    bool canPartition(string s,int target) {
        if (s=="" && target==0) return true;
        if (target<0) return false;

        for(int i=0;i<s.size();i++) {
            if (canPartition(s.substr(i + 1) , target - stoi(s.substr(0, i + 1)))) {return true;}
        }
        return false;
    }       
    int punishmentNumber(int n) {
        int sum = 0;
        for (int num  = 1; num <= n; num++) {
            int sqr = num * num;
            if (canPartition(std::to_string(sqr), num)) {
                sum += sqr;
            }
        }
        return sum;
    }
};      

int main(int argc, char** argv) {

    return 0;
}
