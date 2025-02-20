#include <bits/stdc++.h>
#include <cctype>
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
    int evalRPN(vector<string>& tokens) {
        stack<string> s; 
        for (auto& item : tokens) {
            if (isdigit(item[0])) {
                s.push(item);
            } else {
                int d1 = stoi(s.top()); s.pop();
                int d2 = stoi(s.top()); s.pop();
                switch (item[0]) {
                    case '+':
                        s.push(std::to_string(d1+d2));
                        break;
                    case '-':
                        s.push(std::to_string(d1-d2));
                        break;
                    case '*':
                        s.push(std::to_string(d1*d2));
                        break;
                    case '/':
                        s.push(std::to_string(d2/d1));
                }
            }
        }
        return stoi(s.top());
    }
};

int main(int argc, char** argv) {
    Solution s;
    // vector<string> eval{"4", "13", "5", "/" ,"+"};
    vector<string> eval{"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout << s.evalRPN(eval);

    return 0;
}
