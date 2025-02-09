#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::string;
using std::vector;
using std::endl;

typedef long long dword;

class Solution {
public:
    int mySqrt(int x) {
        dword start{}, end = x, mid, res;
        while (start <= end) {
            mid = (start + end) / 2;

            if (mid * mid > x) {
                end = mid-1;
            } else if (mid * mid < x) {
                start = mid + 1;
                res = mid;
            } else {
                return mid;
            }
        }
        return res;
    }
};

int main(int argc, char** argv) {

    return 0;
}
