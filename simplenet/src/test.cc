#include <simplenet/simplenet.h>

#include <simplenet/network.h>

#include <string>

using namespace std;
using namespace simplenet;

namespace {
template <typename T>
void run_test(string name, T test) {
    cout << "Testing " << name << endl;
    test();
    cout << "[success]" << endl;
}
}

int main() {
    run_test("network", test_network);
    run_test("layer", test_layer);
}
