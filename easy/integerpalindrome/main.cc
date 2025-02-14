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
typedef unsigned long long dword;

template<typename T, typename U>
using pmap = unordered_map<T,U>;

template<typename T, typename U, typename W=std::less<T>>
using pq = priority_queue<T,U,W>;

class Solution {
public:
    int nDig(int x) {
        int dig{}; 
        while (x >0) {
            x/=10;
            ++dig;
        } 
        return dig;
    }
    dword reverseInt(dword x) {
        dword res{};
        int n = nDig(x);
        for (int i=n-1; i>=0; --i) {
            int dig = x%10;
            res += dig * pow(10,i);
            x/=10;
        }
        return res;
    }
    bool isPalindrome(int x) {
      if (x == reverseInt(x))   return true;
      return false;
    }
};


int main(int argc, char** argv) {

    return 0;
}
