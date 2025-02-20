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

    void F_subset(const vector<int>& candidates, vector<vector<int>>& res, vector<int>& subset, const int& target, const int& currsum, const int& start) {
        if (currsum == target) {
            res.push_back(subset);
            return;
        } // else if (currsum > target) return;

        for (int i=start; i<(int)candidates.size(); ++i) {
            if ((currsum + candidates[i]) <= target) {
                subset.push_back(candidates[i]);
                F_subset(candidates, res, subset, target, currsum+candidates[i], i);
                subset.pop_back();
            } 
        } 
    }
    vector<vector<int>> combinationSum(const vector<int>& candidates, const int& target) {
        vector<vector<int>> res;
        vector<int> sub;
        F_subset(candidates, res, sub, target, 0, 0);
        return res;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<vector<int>> res = s.combinationSum({2,3,6,7}, 7);
    for (const auto& vector : res) {
        for (const auto& item : vector) {
            cout << item << " ";
        }
        cout << endl << endl;
    }

    return 0;
}
