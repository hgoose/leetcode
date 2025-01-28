#include <iostream>
#include <map>
#include <vector>
using std::cout;
using std::vector;
using std::endl;
using std::map;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> m;

        for (const auto& item: nums) {
            ++m[item];

            if (m[item] > 1) return true;
        }
        return false;
    }
};

int main(int argc, char** argv) {

    cout << "Hello world" << endl;

    return 0;
}
