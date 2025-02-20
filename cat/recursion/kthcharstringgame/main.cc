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
        char r_kth(string& s, int k) {
            if (s.size() >= k) return s[k-1]; 

            int n = s.size();
            for (int i=0; i<n; ++i) {
                char newchar = (s[i] == 'z' ? 'a' : s[i] + 1);
                s+=newchar;
            }
            return r_kth(s,k);
        }
    char kthCharacter(int k) {
        string str = "a";
        return r_kth(str,k);
    }
};

int main(int argc, char** argv) {

    Solution s;
    cout << s.kthCharacter(2);

    return 0;
}
