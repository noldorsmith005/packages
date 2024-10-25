#include <iostream>
#include <string>
#include "./map.hh"

using namespace std;



int main() {
    Map<string, int> map;
    // List<string, int> list;
    // KVP<string, int> kvp("test", 9);
    // KVP<string, int> kvp2("test2", 3);
    // list.append(kvp);
    // list.append(kvp2);
    // list.print();

    map.insert("test1", 1);
    map.insert("test2", 3);
    map.insert("test3", 5);
    map.print();
    int value = map.get("test2");
    cout << value << "\n";
    map.remove("test2");
    map.print();
}
