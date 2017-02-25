#include <load_mnist.h>

#include <iostream>
#include <cstdint>
#include <algorithm>

constexpr auto MNIST_HEADER_VALUE = 2051;

using namespace std;
using namespace mnist;

namespace {

int32_t bigendian_int32(const char* buff) {
    return int32_t((uint8_t(buff[3]) << 0) | (uint8_t(buff[2]) << 8) | (uint8_t(buff[1]) << 16) |
                   (uint8_t(buff[0]) << 24));
}

Image read_image(unsigned rows, unsigned cols, istream& stream) {
    auto result = Image(arma::zeros<Image>(rows, cols));
    auto buff = vector<char>(rows);

    for (unsigned r = 0; r != cols; ++r) {
        stream.read(buff.data(), int(buff.size()));

        for (unsigned c = 0; c != rows; ++c) {
            result(r, c) = uint8_t(buff[c]);
        }
    }

    return result;
}

}

vector<Image> mnist::load_images(istream& stream) {
    auto result = vector<Image>();

    auto buff = vector<char>(16);
    stream.read(buff.data(), int(buff.size()));

    if(!stream) {
        cerr << "failed to read file header" << endl;
        return result;
    }

    const auto magic_constant = bigendian_int32(buff.data() + 0);
    const auto image_count = unsigned(bigendian_int32(buff.data() + 4));
    const auto rows = unsigned(bigendian_int32(buff.data() + 8));
    const auto cols = unsigned(bigendian_int32(buff.data() + 12));

    if (magic_constant != MNIST_HEADER_VALUE) {
        cerr << "not a valid mnist file header: " << magic_constant << endl;
        return result;
    }

    result.resize(image_count);

    for (unsigned i = 0; i != image_count; ++i) {
        result[i] = read_image(rows, cols, stream);
    }

    return result;
}

