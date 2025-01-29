#include <iostream>
#include <vector>
#include <string>
#include <utility>
using std::cout;
using std::string;
using std::vector;
using std::endl;
using std::pair;

typedef vector<vector<int>> pmatrix;

class Solution {
public:

    static inline vector<pair<int,int>> dirs{{0,-1}, {0,1}, {1,0}, {-1,0}};

    bool inbounds(int row, int rmb, int col, int cmb) { return ((((row >= 0) && (row < rmb)) && ((col >= 0) && (col < cmb)))) ? true : false; }

    int dfs(pmatrix& grid, int row, int col) {
        int fish;
        if (grid[row][col])  {
            fish = grid[row][col];
            grid[row][col]  = 0;
        } else return 0;

        for (const auto& [dr,dc] : dirs) {
            if ( inbounds(row + dr, grid.size(), col + dc, grid[0].size()) && grid[row+dr][col+dc]) {
                cout << "Old fish" << fish << endl; 
                fish += dfs(grid, row + dr, col + dc);
                cout << "New fish" << fish << endl; 
                grid[row+dr][col+dc] = 0;
            }
        }
        return fish;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int max = 0;
        pmatrix visited(grid.size(), vector<int>(grid[0].size(),0));

        for (int i=0; i<(int)grid.size(); ++i) {
            for (int j=0; j<(int)grid[0].size(); ++j) {
                if (grid[i][j] > 0 ) {
                    int check_max = dfs(grid, i, j);
                    if (check_max > max) max = check_max;
                }
            }
        }
        return max;
    }
};

int main(int argc, char** argv) {

    vector<vector<int>> in1 = {
        {9,10}
    };

    Solution s;

    cout << s.findMaxFish(in1) << endl;




    return 0;
}
