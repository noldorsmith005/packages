#include <iostream>
#include <string>
#include "./map.hh"

using namespace std;



int main() {
    Map<int, int> map;
    // List<string, int> list;
    // KVP<string, int> kvp("test", 9);
    // KVP<string, int> kvp2("test2", 3);
    // list.append(kvp);
    // list.append(kvp2);
    // list.print();

    map.insert(1, 1);
    map.print();
    map.insert(11, 3);
    map.insert(2, 5);
    map.print();
}
