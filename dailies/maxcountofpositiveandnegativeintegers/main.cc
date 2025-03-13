#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        return std::max(LB(nums), (int)nums.size()-UB(nums));
    }
private: 
    int LB(vector<int>& nums) {
        int left = 0, right = nums.size()-1;

        int lb = nums.size();
        while (left <= right) {
            int mid = (left + right)/2;

            if (nums[mid] < 0)  {
                left = mid+1;
            } else {
                lb = mid;
                right = mid-1;
            }
        }
        cout << "LB: " << lb << endl;

        return lb;
    }

    int UB(vector<int>& nums) {
        int left = 0, right = nums.size()-1;

        int ub = nums.size();
        while (left <= right) {
            int mid = (left + right)/2;

            if (nums[mid] <= 0) {
                left = mid+1;
            } else {
                ub = mid;
                right = mid-1;
            }
        }
        cout << "UB: " << ub << endl;

        return ub;
    }
};

int main(int argc, char** argv) {

    Solution s;
    vector<int> v{0,0,0,0,0};
    // vector<int> v{-2,-1,-1,-1,-1,};
    // vector<int> v{2,1,1,1,1,1};
    cout << s.maximumCount(v);



    return 0;
}
