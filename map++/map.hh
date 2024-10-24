#include <iostream>
#include <string>
#include "./list.hh"

using namespace std;


template <typename K, typename V>

struct Map {
    private:
        int size;
        int items;
        List<K, V> **backing;

    public:
        Map() {
           size = 10;
           items = 0;
            backing = new List<K, V>*[size];
            for (int i = 0; i < size; i++) {
                backing[i] = nullptr;
            }
        }

        ~Map() {
            for (int i = 0; i < size; i++) {
                if (backing[i] != nullptr) {
                    delete backing[i];
                }
            }
            delete[] backing;
            backing = nullptr;
        }

        void print() {
            cout << "{\n";
            for (int i = 0; i < size; i++) {
                if (backing[i] != nullptr) {
                    List<K, V> chain = *backing[i];
                    for (int c = 0; c < chain.len(); c++) {
                        KVP<K, V> item = chain.get(c);
                        cout << "   {" << item.key << ", " << item.value << "}" << "\n";
                    }
                }
            }
            cout << "}\n\n";
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
            List<K, V> *new_chain = new List<K, V>;
            if (backing[index] == nullptr) {
                (*new_chain).append(new_pair);
                backing[index] = new_chain;
            }
            else {
                List<K, V> old_chain = *backing[index];
                int idx = old_chain.find(key);
                if (idx != -1) {
                    old_chain.remove(idx);
                }
                for (int i = 0; i < old_chain.len(); i++) {
                    KVP<K, V> item = old_chain.get(i);
                    (*new_chain).append(item);
                }
                (*new_chain).append(new_pair);
                backing[index] = new_chain;
            }
            items += 1;
        }

        void remove(K key) {
            for (int i = 0; i < size; i++) {
                if (backing[i] != nullptr) {
                    List<K, V> chain = *backing[i];
                    int idx = chain.find(key);
                    if (idx != -1) {
                        chain.remove(idx);
                    }
                    *backing[i] = chain;
                }
            }
        }

        V get(K key) {
            for (int i = 0; i < size; i++) {
                if (backing[i] != nullptr) {
                    List<K, V> chain = *backing[i];
                    for (int c = 0; c < chain.len(); c++) {
                        KVP<K, V> item = chain.get(c);
                        if (item.key == key) {
                            return item.value;
                        }
                    }
                }
            }
            throw invalid_argument("Key not found. ");
        }
};