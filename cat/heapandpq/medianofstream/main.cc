#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <utility>
#include <cmath>
#include <bitset>
#include <array>
#include <map>
#include <limits>
#include <tuple>
using std::tuple;
using std::map;
using std::array;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::unordered_map;
using std::queue;
using std::priority_queue;
using std::bitset;

typedef long long dword;

template<typename T, typename U>
using pmap = unordered_map<T,U>;

template<typename T, typename U, typename W=std::less<T>>
using pq = priority_queue<T,U,W>;

template<typename T>
using lims = std::numeric_limits<T>;

class MedianFinder {
public:
    pq<int, vector<int>> left;
    pq<int, vector<int>, std::greater<int>> right;

    MedianFinder() { }
    
    void addNum(int num) {
        if (left.empty() || (num <= left.top())) {
            left.push(num);
        } else {
            right.push(num);
        }

        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        } else if (right.size() > left.size() + 1) {
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if (left.empty()) return 0;

        if ((left.size() + right.size()) % 2 == 0) {
            return (static_cast<double>(left.top()) + right.top()) / 2;
        }
        return left.size() > right.size() ? left.top() : right.top();
    }
};

int main(int argc, char** argv) {

    MedianFinder* mf = new MedianFinder();
    mf->addNum(2);
    mf->addNum(2);
    cout << mf->findMedian();

    return 0;
}
