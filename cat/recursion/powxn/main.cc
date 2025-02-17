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
    double r_myPow(double x, int n) {
        if (n == 0) return 1;

        return x * myPow(x, n-1);
    }
    double myPow(double x, int n) {
        if (n < 0) return 1.0 / r_myPow(x,-n);
        return r_myPow(x,n);
    }
};

int main(int argc, char** argv) {

    return 0;
}
