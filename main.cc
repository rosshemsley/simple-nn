#include <mnist.h>

#include <layer.h>
#include <network.h>

#include <fstream>
#include <iostream>
#include <string>

using namespace std;
using namespace mnist;

void build_network() {
    auto network = simplenet::Network{
        new simplenet::FullyConnectedLayer(30, 30),
        new simplenet::FullyConnectedLayer(30, 30),
        new simplenet::FullyConnectedLayer(30, 10),
    };
}

int main() {
    fstream image_stream("_data/train-images-idx3-ubyte");
    fstream label_stream("_data/train-labels-idx1-ubyte");
    const auto images = load_images(image_stream);
    const auto labels = load_labels(label_stream);

    cout << "Loaded " << images.size() << " images" << endl;
    cout << "Loaded " << labels.size() << " labels" << endl;

    ofstream outstream("img.bmp");
    write_image_bmp(images[5], outstream);
}
