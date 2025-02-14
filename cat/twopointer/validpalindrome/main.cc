#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <cctype>
#include <sstream>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::unordered_map;
using std::priority_queue;
using std::ostringstream;

typedef long long dword;

template<typename T, typename U>
using pmap = unordered_map<T,U>;

template<typename T, typename U, typename W=std::less<T>>
using pq = priority_queue<T,U,W>;

class Solution {
public:
    static string augmentString(const string& s) {
        ostringstream os;

        for (const auto& item : s) {
            if (isalnum(item)) os << (char)tolower(item);
        }
        return os.str();
    }
    bool isPalindrome(string s) {
        // s = augmentString(s);
        auto left = s.begin(), right = s.end() - 1;

        while (left < right) {
            if (!isalnum(*left)) { ++left; continue; }
            if (!isalnum(*right)) { --right; continue; }


            if ((char)tolower(*left) != (char)tolower(*right)) return false;
            ++left, --right;
        }
        return true;
    }
};

int main(int argc, char** argv) {

    string s = "A man, a plan, a canal: Panama";

    // Solution sol;

    cout << Solution::augmentString(s);


    return 0;
}
