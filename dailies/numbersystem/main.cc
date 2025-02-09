#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
using std::cout;
using std::string;
using std::vector;
using std::endl;
using std::unordered_map;
using std::priority_queue;



class NumberContainers {
public:
    unordered_map<int, priority_queue<int, vector<int>, std::greater<int>>> num_to_indices;
    unordered_map<int, int> index_to_num;

    NumberContainers() = default;
    
    void change(int index, int number) {
        index_to_num[index] = number;
        num_to_indices[number].push(index);
    }
    
    int find(int number) {
        while (!num_to_indices[number].empty()) {
            int index = num_to_indices[number].top();
            if (index_to_num[index] == number) return index;
            num_to_indices[number].pop();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */

int main(int argc, char** argv) {

    return 0;
}
