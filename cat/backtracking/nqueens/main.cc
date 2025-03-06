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
#include <unordered_set>
#include <algorithm>
using std::unordered_set;
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

template<typename T>
using pset = unordered_set<T>;

template<typename T, typename U, typename W=std::less<T>>
using pq = priority_queue<T,U,W>;

template<typename T>
using lims = std::numeric_limits<T>;
#define INT_MAX lims<int>::max();
#define INT_MIN lims<int>::min();

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> curr(n, string(n,'.'));
        _bt(res, curr, n, 0);
        return res;
    }
private:
    static bool inBounds(int n, int row, int col) {
        if ((row >= 0 && row < n) && (col >=0 && col < n)) return true;
        return false;
    }
    bool checkAttack(vector<string> config, int n, int row, int col) {
        for (int j=0; j<n; ++j) {
            if (j == col) continue;
            if (config[row][j] == 'Q') return false;
        }

        for (int j=0; j<n; ++j) {
            if (j == row) continue;
            if (config[j][col] == 'Q') return false;
        }

        int r = row-1, c = col-1;
        while (inBounds(n, r,c)) {
            if (config[r][c] == 'Q') return false; 
            --r, --c;
        }

        r = row-1, c = col+1;
        while (inBounds(n, r,c)) {
            if (config[r][c] == 'Q') return false; 
            --r, ++c;
        }

        r = row+1, c = col-1;
        while (inBounds(n, r,c)) {
            if (config[r][c] == 'Q') return false; 
            ++r, --c;
        }

        r = row+1, c = col+1;
        while (inBounds(n, r,c)) {
            if (config[r][c] == 'Q') return false; 
            ++r, ++c;
        }

        return true;
    }

    bool _bt(vector<vector<string>>& res, vector<string>& curr, int n, int row) {
        if (row == n) {
            res.push_back(curr);
            return true;
        }

        for (int i=row; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                if (checkAttack(curr, n, i, j)) {
                    curr[i][j] = 'Q';
                    _bt(res, curr, n, i+1); 
                    curr[i][j] = '.';
                }
            }
            return false;
        }
        
        return false;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<vector<string>> res = s.solveNQueens(4);
    for (const auto& vector : res) {
        for (const auto& str : vector) {
            cout << str << endl;
        }
        cout << endl;
    }

    return 0;
}
