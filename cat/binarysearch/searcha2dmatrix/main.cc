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

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int row = -1;
        if (matrix.size() > 1) {
            int top = 0, bot = matrix.size();
            while (top < bot) {
                int mid = (top + bot) / 2;
                if (matrix[mid][0] > target) {
                    bot = mid-1;
                } else if (matrix[mid][0] < target) {
                    top = mid;
                } else return true;
        }
            row = bot;
        }
        row = row == -1 ? 0 : row;

        int left = 0, right = matrix[row].size();
        while (left <= right) {
            int mid = (left + right) / 2;

            if (matrix[row][mid] > target) {
                right = mid - 1;
            } else if (matrix[row][mid] < target) {
                left = mid + 1;
            } else return true;
        }
        return false;
    }
};


int main(int argc, char** argv) {

    return 0;
}
