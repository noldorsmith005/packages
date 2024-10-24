#include <iostream>
#include <string>
#include "./list.hh"

using namespace std;


template <typename K, typename V>

class Map {
    private:
        int size;
        List<K, V> **backing;

    public:
        Map() {
           size = 10;
            backing = new List<K, V>*[size];
            for (int i = 0; i < size; i++) {
                backing[i] = nullptr;
            }
        }

        ~Map() {
            delete[] backing;
            backing = nullptr;
        }

        void print() {
            for (int i = 0; i < size; i++) {
                cout << i;
                if (backing[i] != nullptr) {
                    List<K, V> chain = *backing[i];
                    chain.print();
                }
            }
        }

        int hash(string key) {
            int hash_val = 0;
            for(int i = 0; i < (int)key.length(); i++) {
                int curr_char = key.at(i);
                hash_val = (hash_val * 19 + curr_char) % size;
            }
            return hash_val;
        }

        int hash(int key) {
            int hash_val = 0;
            hash_val = key % size;
            return hash_val;
        }

        void insert(K key, V value) {
            int index = hash(key);
            KVP<K, V> new_pair(key, value);
            if (backing[index] == nullptr) {
                backing[index] = new List<K, V>;
                List<K, V> chain = *backing[index];
                chain.append(new_pair);
                chain.print();
            }
            else {
                
            }
        }

        void remove(int idx) {
            
        }

        int get(K key) {

        }
};