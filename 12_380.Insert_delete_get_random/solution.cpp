#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>

class RandomizedSet {
    std::vector<int> vec;
    std::unordered_map<int, int> idx;
public:
    RandomizedSet() {}

    bool insert(int val) {
        if (idx.count(val)) return false;
        idx[val] = vec.size();
        vec.push_back(val);
        return true;
    }

    bool remove(int val) {
        auto it = idx.find(val);
        if (it == idx.end()) return false;
        int i = it->second;
        int last = vec.back();
        vec[i] = last;
        idx[last] = i;
        vec.pop_back();
        idx.erase(val);
        return true;
    }

    int getRandom() {
        return vec[rand() % vec.size()];
    }
};

int main() {
    RandomizedSet randomizedSet;
    std::cout << randomizedSet.insert(1) << std::endl; // true
    std::cout << randomizedSet.remove(2) << std::endl; // false
    std::cout << randomizedSet.insert(2) << std::endl; // true
    std::cout << randomizedSet.getRandom() << std::endl; // 1 or 2
    std::cout << randomizedSet.remove(1) << std::endl; // true
    std::cout << randomizedSet.insert(2) << std::endl; // false
    std::cout << randomizedSet.getRandom() << std::endl; // 2
    return 0;
}