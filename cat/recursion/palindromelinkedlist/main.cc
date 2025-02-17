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

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool r_isPalindrome(ListNode* p, ListNode*& front) {
        if (!p) return true;
        bool check = 1;
        check = r_isPalindrome(p->next, front);

        if (front->val != p->val) {
            check = 0;
        }
        front=front->next;
        return check;
    }

    bool isPalindrome(ListNode* head) {
        if (!head) return false;
        ListNode* front = head;
        return r_isPalindrome(head, front);
    }
};

int main(int argc, char** argv) {

    return 0;
}
