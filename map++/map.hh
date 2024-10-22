#include <iostream>
#include <string>
#include "./list.hh";

using namespace std;

template <typename T>


class Map {
    private:
        int size;
        T *backing;

        void initialize() {
            size = 100;
            backing = new T[size];
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


        int len() {
            if (!nullcheck()) {
                return curr_index;
            }
            else {
                initialize();
                return len();
            }
        }

        void print() {
            if (!nullcheck()) {
                cout << "\n[";
                for (int i = 0; i < curr_index; i++) {
                    cout << backing[i];
                    if ((i + 1) < curr_index) {
                        cout << ", ";
                    }
                }
                cout << "]\n";
            }
            else {
                initialize();
                print();
            }
        }

        void append(T item) {
            if (!nullcheck()) {
                if ((curr_index + 1) < size) {
                    backing[curr_index] = item;
                }
                else {
                    int new_size = (size * 2);
                    T old_array[curr_index];
                    for (int i = 0; i < curr_index; i++) {
                        old_array[i] = backing[i];
                    }
                    backing = new T[new_size];
                    size = new_size;
                    for (int c = 0; c < curr_index; c++) {
                        backing[c] = old_array[c];
                    }
                    backing[curr_index] = item;
                }
                curr_index += 1;
            }
            else {
                initialize();
                append(item);
            }
        }

        void remove(int idx) {
            if (!nullcheck()) {
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
            else {
                initialize();
                remove(idx);
            }
            
        }

        int find(T item) {
            if (!nullcheck()) {
                for (int i = 0; i < curr_index; i++) {
                    if (backing[i] == item) {
                        return i;
                    }
                }
                cout << "Item not present in list. ";
                return -1;
            }
            else {
                initialize();
                cout << "Item not present in list. ";
                return -1;
            }
        }

        int get(int idx) {
            if (!nullcheck()) {
                if (idx < curr_index) {
                    return backing[idx];
                }
                else {
                    throw invalid_argument("Index out of bounds. ");
                }
            }
            else {
                initialize();
                return get(idx);
            }
        }

        void empty() {
            if (!nullcheck()) {
                delete[] backing;
                backing = nullptr;
            }
        }
};

class KVP {
    public:
        int key;
        int value;

        KVP(int k, int v) {
            key = k;
            value = v;
        }
};