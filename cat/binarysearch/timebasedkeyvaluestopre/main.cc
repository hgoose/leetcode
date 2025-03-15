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
#include <numeric> // std::accumulate
#include <climits> // INT_MAX, INT_MIN, ...
#include <tuple>
#include <unordered_set>
#include <algorithm>
#include <stack>
using std::pair;
using std::stack;
using std::unordered_set;
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

template<typename T>
using pset = unordered_set<T>;

template<typename T, typename U, typename W=std::less<T>>
using pq = priority_queue<T,U,W>;

template<typename T>
using lims = std::numeric_limits<T>;

template<typename T, typename U>
using pmap = unordered_map<T,U>;

class TimeMap {
public:
    TimeMap() { }
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        vector<pair<string, int>>& values = map[key];    
        int left = 0, right = values.size()-1;

        int max = -1, maxidx=-1;
        while (left <= right) {
            int mid = left + (right-left) / 2;

            if (values[mid].second <= timestamp) {
                left = mid +1;
                if (values[mid].second > max) maxidx = mid;
            } else {
                right = mid-1;
            }
        }         
        return maxidx != -1 ? values[maxidx].first : "";
    }
private:
    pmap<string, vector<pair<string, int>>> map;
};

int main(int argc, char** argv) {

    return 0;
}
