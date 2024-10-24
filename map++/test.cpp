#include <iostream>
#include <string>
#include "./map.hh"

using namespace std;



int main() {
    // List<string, int> list;
    // KVP<string, int> pair("item1", 1);
    // KVP<string, int> pair2("item2", 3);
    // list.print();
    // list.append(pair);
    // list.print();
    // list.append(pair2);
    // list.print();
    Map<string, int> map;
    map.print();
    map.insert("test", 9); // "test" hashes to 6
    //map.print();
}
