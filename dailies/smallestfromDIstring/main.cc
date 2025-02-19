#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <utility>
#include <cmath>
#include <bitset>
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
        bool r_perms(string& p, std::bitset<10>& used, const string& pattern, const int& pidx){
            if (p.size() == (pattern.size() + 1)) {
                return true;
            }

            for (int i=1; i<10;++i) {
                if (!used[i]) {
                    if ((pattern[pidx] == 'I') && (((int)p.back() - '0') < i))  {
                        p.push_back(std::to_string(i)[0]);
                        used[i] = true;
                        if (r_perms(p, used, pattern, pidx+1)) return true;
                    } else if ((pattern[pidx] == 'D') && (((int)p.back()-'0') > i)) {
                        p.push_back(std::to_string(i)[0]); 
                        used[i] = true;
                        if (r_perms(p, used, pattern, pidx+1)) return true;
                    } else continue;
                    p.pop_back();
                    used[i] = false;
                }
            }
            return false;
        }

        string perms(const string& pattern) {
            string perm;
            std::bitset<10> used;
            if (r_perms(perm,used, pattern,0)) return perm;
            return {};
        }
        string smallestNumber(string pattern) {
            string res = perms(pattern);
            return res;
        }
};

int main(int argc, char** argv) {

    vector<int> pool = {0,1,2,3,4,5,6,7,8,9};
    Solution s;
    string pattern = "DDD";
    string res = s.smallestNumber(pattern);
    cout << res; 

    return 0;
}
