#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <utility>
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
    // This is in the recursion category so I'll do it recursively
    bool isPowerOfTthree(int n) {
        if (n == 0) return false;
        return ((log10(n)/log10(3)) == floor(log10(n) / log10(3)));
    }
    // Need a way to do exponentiation
    double r_fe(double& x, int& n, double& res) {
        if (n <= 0) return res; 

        if (n % 2 == 1) {
            res*=x;
            --n;
        }
        n/=2;
        x*=x;
        return r_fe(x,n,res);
    }
    double fe(double x, int n) {
        double res{1.0};
        return r_fe(x, n, res); 
    }

    bool r_p3(const int& n, int x) {
        // Insanely stupid to bound x by the correct answer but my other bounds got TLE's
        if (x>(log10(n)/log10(3))) return false; 
        if (n == fe(3,x)) return true;
        return r_p3(n,x+1);
    }
    bool isPowerOfThree(int n) {
        if (n == 1) return true;
        if (n < 0) return false;
        return r_p3(n,0);
    }
};

int main(int argc, char** argv) {

    return 0;
}
