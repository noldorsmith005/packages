#include <iostream>
#include <string>
#include "./map.hh"

using namespace std;



int main() {
    Map<string, int> map;
    map.print();
    map.insert("test", 9); // "test" hashes to 6
    map.print();
}
