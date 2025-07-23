#include <iostream>
#include <vector>
#include <list>
#include <utility>

using namespace std;

template<typename K, typename V>
class HashMap {
private:
    static const int DEFAULT_CAPACITY = 10;
    static constexpr float LOAD_FACTOR = 0.75;

    vector<list<pair<K, V>>> table;
    int size;
    int capacity;

    int hash(K key) {
        return hashFunc(key) % capacity;
    }

    void rehash() {
        int oldCapacity = capacity;
        capacity *= 2;
        vector<list<pair<K, V>>> oldTable = table;

        table.clear();
        table.resize(capacity);
        size = 0;

        for (int i = 0; i < oldCapacity; ++i) {
            for (auto& p : oldTable[i]) {
                put(p.first, p.second);
            }
        }
    }

    hash<K> hashFunc;  // std::hash for key

public:
    HashMap() {
        capacity = DEFAULT_CAPACITY;
        table.resize(capacity);
        size = 0;
    }

    void put(K key, V value) {
        int idx = hash(key);
        for (auto& p : table[idx]) {
            if (p.first == key) {
                p.second = value; // Update value
                return;
            }
        }
        table[idx].push_back({key, value});
        size++;

        if ((float)size / capacity > LOAD_FACTOR) {
            rehash();
        }
    }

    bool get(K key, V& value) {
        int idx = hash(key);
        for (auto& p : table[idx]) {
            if (p.first == key) {
                value = p.second;
                return true;
            }
        }
        return false;
    }

    bool remove(K key) {
        int idx = hash(key);
        for (auto it = table[idx].begin(); it != table[idx].end(); ++it) {
            if (it->first == key) {
                table[idx].erase(it);
                size--;
                return true;
            }
        }
        return false;
    }

    int getSize() const {
        return size;
    }

    void print() {
        for (int i = 0; i < capacity; ++i) {
            cout << "[" << i << "]: ";
            for (auto& p : table[i]) {
                cout << "(" << p.first << " => " << p.second << ") ";
            }
            cout << endl;
        }
    }
};


int main() {
    HashMap<string, int> map;
    map.put("apple", 3);
    map.put("banana", 7);
    map.put("orange", 5);

    int val;
    if (map.get("banana", val)) {
        cout << "banana: " << val << endl;
    }

    map.put("banana", 9); // Update value
    map.remove("apple");

    map.print();

    return 0;
}
