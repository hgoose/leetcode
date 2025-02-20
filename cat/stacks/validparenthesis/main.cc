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
#include <stack>
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
using std::stack;
typedef long long dword;

template<typename T, typename U>
using pmap = unordered_map<T,U>;

template<typename T, typename U, typename W=std::less<T>>
using pq = priority_queue<T,U,W>;


class Solution {
public:
    bool isValid(string s) {
       stack<char> sck; 
       int stackchecks = 0;
       int stacksize = 0;
       for (char& item : s) {
           switch (item) {
               case '(':
               case '[':
               case '{':
                   sck.push(item);
                   ++stacksize;
                   break;
               default:
                    if (sck.empty()) return false;
                   char top = sck.top();
                   sck.pop();
                   ++stackchecks;
                   switch (top) {
                       case '(':
                           if (item != ')') return false;
                           break;
                       case '[':
                           if (item != ']') return false;
                           break;
                       case '{':
                           if (item != '}') return false;
                           break;
                   }
           }
       }
        return (stackchecks == stacksize ? true : false); 
    }
};

int main(int argc, char** argv) {

    Solution s;
    s.isValid("()");

    return 0;
}
