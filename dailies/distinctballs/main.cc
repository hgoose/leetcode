#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using std::cout;
using std::string;
using std::vector;
using std::endl;

typedef std::unordered_map<int, int> pmap;

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> res(queries.size(), 0);
        pmap on_board;
        pmap is_colored;

        for (int i=0; i<(int)queries.size(); ++i) {
            int ball = queries[i][0], color=queries[i][1];
            if (is_colored[ball] == 0) {
                is_colored[ball] = color;
                if (on_board[color] == 0) {
                    res[i] = (i - 1 >= 0 ? res[i-1] : 0) + 1;
                } else {
                    res[i] = (i - 1 >= 0 ? res[i-1] : 0);
                }
                ++on_board[color];
            } else {
                int old_color = is_colored[ball];
                --on_board[old_color];
                is_colored[ball] = color;
                if (on_board[old_color] == 0) {
                    if (on_board[color] > 0 ) {
                        res[i] = res[i-1]-1;
                    } else res[i] = res[i-1];
                } else {
                    if (on_board[color] == 0) {
                        res[i] = res[i-1] + 1;
                    } else {
                        res[i] = res[i-1];
                    }
                }
                ++on_board[color];
            }
        }
        return res;
    }
};

int main(int argc, char** argv) {

    int limit = 4;
    vector<vector<int>> q = {{1,4},{2,5},{1,3},{3,4}};

    Solution s;
    s.queryResults(limit, q);



    return 0;
}
