#include <mnist.h>

#include <string>
#include <fstream>
#include <iostream>

using namespace std;
using namespace mnist;

int main() {
    auto image_stream = fstream();
    auto label_stream = fstream();
    image_stream.open("_data/train-images-idx3-ubyte");
    label_stream.open("_data/train-labels-idx1-ubyte");
    const auto images = load_images(image_stream);
    const auto labels = load_labels(label_stream);

    cout << "Loaded " << images.size() << " images" << endl;
    cout << "Loaded " << labels.size() << " labels" << endl;

    auto outstream = ofstream("img.bmp");
    write_image_bmp(images[5], outstream);
}
