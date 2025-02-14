#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <iterator>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::unordered_map;
using std::priority_queue;
typedef long long dword;

template<typename T, typename U>
using pmap = unordered_map<T,U>;

template<typename T, typename U, typename W=std::less<T>>
using pq = priority_queue<T,U,W>;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        auto slow = numbers.begin(), fast = numbers.end() - 1;

        while (slow < fast) {
            if ((*slow + *fast) > target) {
                --fast;
            } else if ((*slow + *fast) < target) {
                ++slow;
            } else {
                cout << "Slow: " << *slow << endl << "Fast: " << *fast << endl;
                return {(int)std::distance(numbers.begin(), slow), (int)std::distance(numbers.begin(), fast)};
            }
        }
        return {};
    }
};

int main(int argc, char** argv) {

    vector<int> v{1,2,3,4};
    Solution s;
    auto res = s.twoSum(v, 3);
    for (const auto& item : res) cout << item << " ";


    return 0;
}
