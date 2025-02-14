#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
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
    int gcd(int a, int b ) {
        if (b < a) {
            b = std::exchange(a,b);
        }
        while (b != 0) {
            a = std::exchange(b, a % b);
        }
        return a;
    }
    int findGCD(vector<int>& nums) {
        // Don't want any side affects
        vector<int> other = nums;
        std::sort(other.begin(), other.end());
        return (gcd(other[0], other[other.size()-1]));
    }
};

int main(int argc, char** argv) {

    return 0;
}
