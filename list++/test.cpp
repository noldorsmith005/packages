#include "./list.hh"

using namespace std;



int main() {
    List<int> list;
    list.print();
    for (int i = 0; i < 1000000; i++) {
        int random = rand()%10;
        list.append(random);
    }
    // list.append("hello world");
    // list.append("a");
    // list.append("e");
    // list.append("i");
    // list.append("o");
    // list.append("u");
    list.print();
    cout << "\n" << list.len() << "\n";
    list.empty();
    list.print();
    list.empty();
}
