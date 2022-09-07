#include <iostream>
#include <map> 
#include <vector>

using namespace std;

template <typename K, typename T>
vector<K> get_keys(map<K, T> m) {
    vector<K> v; 
    for (pair<K, T> p: m) v.push_back(p.first);
    return v; 
} 

template <typename K, typename T>
vector<T> get_values(map<K, T> m) {
    vector<T> x;
    for (pair<K, T> p : m) x.push_back(p.second);
    return x;
}

int main() {
  
    // calls template function 
    cout << get_keys(map<int, int>{{1, 2}, {3,4}, {5,6}})[1] << endl; 
    cout << get_values(map<int, int>{{1, 2}, {3,4}, {5,6}})[2] << endl; 
  return 0;
}

