#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<int> ve({1, 2, 3, 6, 0});
    vector<int>::iterator iter;
    
    for (iter = ve.begin(); iter != ve.end(); iter++) {
        cout << *iter << endl;
    }
    return 0;
}