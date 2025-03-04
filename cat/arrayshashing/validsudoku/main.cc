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

class Solution {
public:
    pmap<int,int> umap;
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i=0; i<9; ++i) {
            umap.clear();
            for (int j=0; j<9; ++j) {
                if (board[i][j] == '.') continue;
                ++umap[board[i][j]];
                if (umap[board[i][j]] > 1)  {
                    cout << "False 1" << endl;
                    return false;

                }
            }
        }

        for (int i=0; i<9; ++i) {
            umap.clear();
            for (int j=0; j<9; ++j) {
                if (board[j][i] == '.') continue;
                ++umap[board[j][i]];
                if (umap[board[j][i]] > 1)  {
                    cout << "False 2" << endl;
                    cout << "for: " << board[j][i] << endl;
                    cout << "at: " << i << ", " << j << endl;
                    return false;
                }
            }
        }

        int gc{}, rs{}, cs{};
        while (gc < 9) {
            umap.clear();
            for (int i=rs; i<rs+3; i++) {
                for (int j=cs; j<cs+3; j++) {
                    if (board[i][j] == '.') continue;
                    ++umap[board[i][j]];
                    if (umap[board[i][j]] > 1)  {
                        cout << "False 3" << endl;
                        return false;
                    }
                        
                }
            }
            ++gc, cs+=3;
            if (gc % 3 == 0)  {
                rs += 3;
                cs = 0;
            }
        }

        return true;
    }
};

int main(int argc, char** argv) {

    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    Solution s;
    cout << std::boolalpha << s.isValidSudoku(board);

    return 0;
}
