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
    int count{};
    string r_perms(string& p, const int& n, const char& last, const int& k) {
        if (p.size() == n) {
            ++count;
            if (count == k) {
                return p;
            } else return "";
        } 

        for (char i=97; i<100; ++i) {
           if (i != last) {
               p.push_back(i);
               if (r_perms(p,n,i, k) != "") {return p;};
               p.pop_back();
           } 
        }
        return "";
    }

    string perms(const int& n, const int& k) {
        // static const vector<char> v{'A','B', 'C'};
        string p{};
        char last{};
        return r_perms(p,n,last,k);
    }
    string getHappyString(const int& n, const int& k) {
        return perms(n,k);
    }
};

int main(int argc, char** argv) {

    Solution s;
    cout << s.getHappyString(10,100);
    return 0;
}
