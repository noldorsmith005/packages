#include <iostream>
#include <string>
#include "./list.hh"

using namespace std;

template <typename K, typename V>

struct KVP {
    K key;
    V value;

    KVP(K k, V v) {
        this->key = k;
        this->value = v;
    }
};


template <typename K, typename V>

class Map {
    private:
        int size;
        List<KVP<K, V>> **backing;

        void initialize() {
            size = 10;
            backing = new List<KVP<K, V>>*[size];
            for (int i = 0; i < size; i++) {
                backing[i] = nullptr;
            }
        }

        bool nullcheck() {
            if (backing == nullptr) {
                return true;
            }
            else {
                return false;
            }
        }


    public:
        Map() {
           initialize();
        }

        void print() {
            if (!nullcheck()) {
                
            }
            else {
                initialize();
                print();
            }
        }

        int hash(string key) {
            int hash_val = 0;
            for(int i = 0; i < key.length(); i++) {
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
            if (!nullcheck()) {
                int index = hash(key);
                cout << index;
                KVP<K, V> new_pair(key, value);
                if (backing[index] == nullptr) {
                    backing[index] = new List<KVP<K, V>>;
                    List<KVP<K, V>> chain = *backing[index];
                    chain.append(new_pair);
                }
                // else {
                //     int idx = backing[index].find(key);
                //     if (idx != -1) {
                //         backing[index].append(new_pair);
                //     }
                //     else {
                //         backing[index].remove(idx);
                //         backing[index].append(new_pair);
                //     }
                // }
            }
            else {
                initialize();
                insert(key, value);
            }
        }

        void remove(int idx) {
            if (!nullcheck()) {

            }
            else {
                initialize();
                remove(idx);
            }
            
        }

        int get(K key) {

        }
};