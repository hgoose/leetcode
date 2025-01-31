#include <iostream>
#include <vector>
#include <string>
#include <queue>
using std::cout;
using std::string;
using std::vector;
using std::endl;

typedef vector<vector<int>> Grid;
typedef std::queue<std::pair<int,int>> Q;

class Solution {
    public:
        static inline vector<std::pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        bool checkbounds(int r, int mrb, int c, int mcb) {
            return ((r >= 0 && r < mrb) && (c >= 0 && c < mcb) ? true : false); 
        }

        void twoflipdfs(Grid& grid, const int& r, const int& c) {
            if (grid[r][c] == 2) grid[r][c] = 1;
            for (const auto& [dr, dc] : dirs) {
                if (checkbounds(r+dr, grid.size(), c+dc, grid[0].size()) && grid[r+dr][c+dc] == 2) {
                    grid[r+dr][c+dc] = 1;
                    twoflipdfs(grid, r+dr, c+dc);
                }
            }
        }

        int dfs(Grid& grid, const int& r, const int& c) {
            int count=0;

            if (grid[r][c] && grid[r][c] != 2) {
                ++count;
                grid[r][c] = 2;
            }

            for (const auto& [dr, dc] : dirs) {
                if (checkbounds(r + dr, grid.size(), c + dc, grid[0].size()) && grid[r+dr][c+dc] && (grid[r+dr][c+dc] != 2)) {
                    ++count;
                    grid[r+dr][c+dc] = 2;
                    count += dfs(grid, r+dr, c+dc);
                }
            }
            return count;
        }

        int countIsland(Grid& grid, int r, int c) {
            int d =  dfs(grid, r,c);
            twoflipdfs(grid, r,c);
            return d;
        }

        int largestIsland(Grid& grid) {
            int max = 0;

            int flipped  = 0;
            for (int i=0; i<static_cast<int>(grid.size()); ++i) {
                for (int j=0; j<static_cast<int>(grid[0].size()); ++j) {
                    if (!grid[i][j]) {
                        ++flipped;
                        grid[i][j] = 1;
                        int check = countIsland(grid,i,j);
                        if (check > max) max = check;
                        grid[i][j] = 0;
                    }
                }
            }

            if (!flipped) return grid.size() * grid.size();
            return max;
        }
};

int main(int argc, char** argv) {

    return 0;
}
