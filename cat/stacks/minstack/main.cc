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
using std::numeric_limits;
typedef long long dword;

template<typename T, typename U>
using pmap = unordered_map<T,U>;

template<typename T, typename U, typename W=std::less<T>>
using pq = priority_queue<T,U,W>;

class MinStack {
public:
    vector<std::pair<int,int>> stack;
    int minElement = numeric_limits<int>::max();
    MinStack() {
        
    }
    
    void push(long val) {
        minElement = (stack.size() ? stack.back().second : numeric_limits<int>::max());
       if (val < minElement) minElement = val;
       stack.push_back({val, minElement}); 
    }
    
    void pop() {
        long l_top = top();
        stack.pop_back();    
    }
    
    int top() {
       return stack.back().first; 
    }
    
    int getMin() {
       return stack.back().second; 
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(int argc, char** argv) {

    MinStack* obj = new MinStack();
    obj->push(2147483646);
    obj->push(2147483647);
    obj->pop();
    cout << obj->getMin();

    return 0;
}
