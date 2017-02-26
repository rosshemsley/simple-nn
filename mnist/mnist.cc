#include <mnist.h>

#include <algorithm>
#include <cstdint>
#include <iostream>

constexpr auto MNIST_HEADER_IMAGES = 2051;
constexpr auto MNIST_HEADER_LABELS = 2049;

using namespace std;
using namespace mnist;

namespace {

using byte = unsigned char;

int32_t read_int32(const char* buff) {
    return byte(buff[3]) << 0 | byte(buff[2]) << 8 | byte(buff[1]) << 16 | byte(buff[0]) << 24;
}

Image read_image(size_t n_rows, size_t n_cols, istream& stream) {
    auto result = Image(arma::zeros<Image>(n_rows, n_cols));
    auto buff = vector<char>(n_cols);

    for (size_t r = 0; r != n_rows; ++r) {
        stream.read(buff.data(), int(buff.size()));
        for (size_t c = 0; c != n_cols; ++c) {
            result(r, c) = uint8_t(buff[c]);
        }
    }

    return result;
}
} // Anonymous namespace

vector<Image> mnist::load_images(istream& stream) {
    auto result = vector<Image>();
    auto buff = vector<char>(16);
    stream.read(buff.data(), int(buff.size()));

    if (!stream) {
        cerr << "failed to read file header" << endl;
        return result;
    }

    const auto magic_constant = read_int32(buff.data() + 0);
    const auto image_count = size_t(read_int32(buff.data() + 4));
    const auto n_rows = size_t(read_int32(buff.data() + 8));
    const auto n_cols = size_t(read_int32(buff.data() + 12));

    if (magic_constant != MNIST_HEADER_IMAGES) {
        cerr << "not a valid mnist file header: " << magic_constant << endl;
        return result;
    }

    result.resize(image_count);

    for (size_t i = 0; i != image_count; ++i) {
        result[i] = read_image(n_rows, n_cols, stream);
    }

    return result;
}

vector<Label> mnist::load_labels(istream& stream) {
    auto result = vector<Label>();
    auto buff = vector<char>(8);
    stream.read(buff.data(), int(buff.size()));

    if (!stream) {
        cerr << "failed to read file header" << endl;
        return result;
    }

    const auto magic_constant = read_int32(buff.data() + 0);
    const auto label_count = size_t(read_int32(buff.data() + 4));

    if (magic_constant != MNIST_HEADER_LABELS) {
        cerr << "not a valid mnist label file header: " << magic_constant << endl;
        return result;
    }

    result.resize(label_count);
    auto buffer = vector<char>(1);

    for (size_t i = 0; i != label_count; ++i) {
        stream.read(buffer.data(), int(buffer.size()));
        if (!stream)
            return result;
        result[i] = Label(buffer[0]);
    }

    return result;
}

void mnist::write_image_bmp(const Image& img, ostream& stream) {
    const auto height = img.n_rows;
    const auto width = img.n_cols;

    auto data = vector<byte>(3 * width * height);
    for (size_t x = 0; x != width; ++x) {
        for (size_t y = 0; y != height; ++y) {
            const auto img_index = (x + y * width) * 3;
            const auto pixel = img(y, x);
            data[img_index + 0] = 255 - pixel;
            data[img_index + 1] = 255 - pixel;
            data[img_index + 2] = 255 - pixel;
        }
    }

    byte fheader[14] = {'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0};
    byte iheader[40] = {40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24, 0};
    const byte padding[] = {0, 0, 0};

    const auto fheader_bytes = size_t(distance(begin(fheader), end(fheader)));
    const auto iheader_bytes = size_t(distance(begin(iheader), end(iheader)));
    const auto filesize = fheader_bytes + iheader_bytes + 3 * width * height;

    fheader[2] = byte(filesize >> 0);
    fheader[3] = byte(filesize >> 8);
    fheader[4] = byte(filesize >> 16);
    fheader[5] = byte(filesize >> 24);
    iheader[4] = byte(width >> 0);
    iheader[5] = byte(width >> 8);
    iheader[6] = byte(width >> 16);
    iheader[7] = byte(width >> 24);
    iheader[8] = byte(height >> 0);
    iheader[9] = byte(height >> 8);
    iheader[10] = byte(height >> 16);
    iheader[11] = byte(height >> 24);

    stream.write(reinterpret_cast<char*>(fheader), distance(begin(fheader), end(fheader)));
    stream.write(reinterpret_cast<char*>(iheader), distance(begin(iheader), end(iheader)));
    for (size_t i = 0; i != height; ++i) {
        const auto row_start = (width * (height - i - 1) * 3);
        stream.write(reinterpret_cast<char*>(&data[row_start]), int(3 * width));
        stream.write(reinterpret_cast<const char*>(padding), (4 - (width * 3) % 4) % 4);
    }
}
