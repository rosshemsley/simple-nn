#include <load_mnist.h>

#include <fstream>
#include <iostream>

using namespace std;
using namespace mnist;

int main() {
    auto stream = fstream();
    stream.open("_data/train-images-idx3-ubyte");
    const auto images = load_images(stream);

    cout << "Loaded " << images.size() << " images" << endl;
}
