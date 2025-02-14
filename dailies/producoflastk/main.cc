#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
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

class ProductOfNumbers {
public:
    vector<int> prefixProducts{};

    ProductOfNumbers() { }
    
    void add(int num) {
        if (!num) {
            prefixProducts = {1};
            return;
        }
        prefixProducts.push_back(num); 
        prefixProducts[prefixProducts.size()-1] = prefixProducts[prefixProducts.size()-1] * ((prefixProducts.size()-2 >= 0) ? prefixProducts[prefixProducts.size()-2] : 1);
    }
    
    int getProduct(int k) {
        return (k < prefixProducts.size() ? prefixProducts[prefixProducts.size()-1] / prefixProducts[prefixProducts.size() - 1 - k] : 0);
    }
};

int main(int argc, char** argv) {

    return 0;
}
