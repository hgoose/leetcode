#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
using std::cout;
using std::string;
using std::vector;
using std::unordered_map;
using std::endl;
using std::priority_queue;

typedef long long dword;

template<typename T, typename U>
using pmap = unordered_map<T,U>;

template<typename T, typename U, typename W=std::less<T>>
using pq = priority_queue<T,U,W>;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        pq<dword, vector<dword>, std::greater<dword>> heap;

        for (const auto& item : nums) {
            heap.push(item);
        }

        int operations{};
        while (!heap.empty()) {
            if (heap.top() >= k) return operations;

            dword first = static_cast<dword>(heap.top()); heap.pop();
            dword second = static_cast<dword>(heap.top()); heap.pop();

            dword res = std::min(first, second) * 2 + std::max(first, second);
            heap.push(res);
            ++operations;
        }
        return operations;
    }
};
int main(int argc, char** argv) {

    vector<int> v{2,10,11,1,3};

    Solution s;
    cout << s.minOperations(v, 10);


    return 0;
}
