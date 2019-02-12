#include<bits/stdc++.h>

using namespace std;

class LRUCache {
public:
    unordered_map<int, list<pair<int, int>>::iterator> cache_table;
    list<pair<int, int>> cache;
    int n;
    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
        if (cache_table.find(key) == cache_table.end()) return -1;
        list<pair<int, int>>::iterator it = cache_table[key];
        int val = it->second;
        cache.erase(it);
        cache.push_back({key, val});
        cache_table[key] = --cache.end();
        return val;
    }
    
    void put(int key, int value) {
        pair<int, int> pp;
        if (cache_table.find(key) != cache_table.end()) {
            list<pair<int, int>>::iterator it = cache_table[key];
            pp = *it;
            cache.erase(it);
            cache.push_back({key, value});
            cache_table[key] = (--cache.end());
            return;
        }
        if (cache.size() < n) {
            cache.push_back({key, value});
            cache_table[key] = (--cache.end());
            return;
        }
        if (cache.size() == n) {
            pp = cache.front();
            cache_table.erase(pp.first);
            cache.pop_front();
            cache.push_back({key, value});
            cache_table[key] = --cache.end();
            return;
        }
	}
};