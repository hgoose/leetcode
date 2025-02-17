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
//
// class Solution {
// public:
//     vector<int> constructDistancedSequence(int n) {
//         vector<int> ans(n * 2 - 1, 0);
//
//         vector<bool> visited(n + 1, false);
//         calc(0, ans, visited, n);
//         return ans;
//     }
//
// private :
//     bool calc(int index, vector<int> &ans, vector<bool> &visited, int n) {
//         if (index == ans.size()) {
//             return true;
//         }
//         if (ans[index] != 0)
//             return calc(index + 1, ans, visited,
//                         n); // value already assigned in this position. So go ahead with the next index.
//         else {
//             // we start from n to 1 since we need to find out the lexicographically largest sequence.
//             for (int i = n; i >= 1; i--) {
//                 if (visited[i]) continue;
//                 visited[i] = true;
//                 ans[index] = i;
//                 if (i == 1) {
//                     if (calc(index + 1, ans, visited, n)) return true;
//                 } else if (index + i < ans.size() && ans[index + i] == 0) {
//                     ans[i +
//                         index] = i; // assigning the second occurence of i in the desired position i.e, (current index + i )
//                     if (calc(index + 1, ans, visited, n))
//                         return true; // largest possible sequence satisfying the given conditions found.
//                     ans[index + i] = 0;
//                 }
//                 ans[index] = 0;
//                 visited[i] = false;
//             }
//
//         }
//         return false;
//     }
//
//
// };

// class Solution {
// public:
//     static inline pmap<int, int> umap;
//     static inline pmap<int, int> count;
//
//     static bool check(const vector<int> &v) {
//         umap.clear();
//         count.clear();
//
//         for (int i = 0; i < (int)v.size(); ++i) {
//             if (v[i] == 1) {
//                 continue;
//             } else {
//                 umap[v[i]] = abs(umap[v[i]] - i);
//                 ++count[v[i]];
//                 if ((count[v[i]] == 2) && v[i] != umap[v[i]]) return false;
//             }
//         }
//
//         // for (const auto &[key, value] : umap) {
//         //     if (key != value) return false;
//         // }
//         return true;
//     }
//
//     bool r_next_permutation(vector<int>& v, vector<int>& p, vector<bool>& used, const int& k) {
//         if (p.size() == k) {
//             return true;
//         }
//
//         for (int i=0; i<(int)v.size(); ++i) {
//             if (!used[i]) {
//                 p.push_back(v[i]);
//                 used[i] = true;
//                 if (!check(p)) {
//                     p.pop_back();
//                     used[i] = false;
//                     continue;
//                 }
//                 if (r_next_permutation(v, p,used, k)) {return true;};
//                 p.pop_back();
//                 used[i] = false;
//             }
//         }
//         return false;
//     }
//
//     vector<int> next_permutation(vector<int>& v) {
//         const int n = v.size();
//         vector<bool> used(v.size(),0);
//         vector<int> p;
//         // vector<vector<int>> res;
//
//         r_next_permutation(v,p,used,n);
//         return p;
//     }
//
//     vector<int> constructDistancedSequence(int n) {
//         vector<int> first = {1};
//
//         for (int i=2; i<=n; ++i) {
//             first.push_back(i); first.push_back(i);
//         }
//         std::reverse(first.begin(), first.end());
//
//         vector<int> res = next_permutation(first);
//         return  res;
//     }
// };

class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
   }
};

int main(int argc, char** argv) {
    Solution s;
    auto sol = s.constructDistancedSequence(5);
    for (const auto& item : sol) cout << item << " ";


    return 0;
}
