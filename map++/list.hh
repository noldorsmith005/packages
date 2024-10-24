#include <iostream>
#include <string>

using namespace std;

template <typename K, typename V>

struct KVP {
    K key;
    V value;

    KVP(const K &k, const V &v) {
        this->key = k;
        this->value = v;
    }
};


template <typename K, typename V>

struct List {
    private:
        int curr_index; 
        int size;
        KVP<K, V> **backing;


    public:
        List() {
            curr_index = 0;
            size = 10;
            backing = new KVP<K, V>*[size];
        }

        void free() {
            delete[] backing;
            backing = nullptr;
        }

        int len() {
            return curr_index;
        }

        void print() {
            cout << "\n[\n";
            for (int i = 0; i < curr_index; i++) {
                KVP<K, V> item = *backing[i];
                cout << " {" << item.key << ", " << item.value << "}" << "\n";
            }
            cout << "]";
        }

        void append(KVP<K, V> item) {
            if ((curr_index + 1) < size) {
                KVP<K, V> *new_item = new KVP<K, V>(item.key, item.value);
                backing[curr_index] = new_item;
            }
            else {
                int new_size = (size * 2);
                KVP<K, V> *old_array[curr_index];
                for (int i = 0; i < curr_index; i++) {
                    old_array[i] = backing[i];
                }
                backing = new KVP<K, V>*[new_size];
                size = new_size;
                for (int c = 0; c < curr_index; c++) {
                    backing[c] = old_array[c];
                }
                backing[curr_index] = &item;
            }
            curr_index += 1;
        }

        void remove(int idx) {
            if (idx < curr_index) {
                for (int i = idx; i < curr_index; i++) {
                    backing[i] = backing[(i + 1)];
                }
                curr_index -= 1;
            }
            else {
                throw invalid_argument("Index out of bounds. ");
            }
        }

        int find(K item) {
            for (int i = 0; i < curr_index; i++) {
                KVP<K, V> kvp = *backing[i];
                if (kvp.key == item) {
                    return i;
                }
            }
            cout << "Item not present in list. ";
            return -1;
        }

        KVP<K, V> get(int idx) {
            if (idx < curr_index) {
                return *backing[idx];
            }
            else {
                throw invalid_argument("Index out of bounds. ");
            }
        }
};