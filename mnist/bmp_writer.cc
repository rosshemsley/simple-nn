#include <load_mnist.h>

constexpr auto FILE_HEADER_BYTES = 14;
constexpr auto INFO_HEADER_BYTES = 40;

using namespace std;
using namespace mnist;

void mnist::write_image_bmp(const Image& img, ostream& stream) {
    const auto height = img.n_rows;
    const auto width = img.n_cols;
    const auto filesize = FILE_HEADER_BYTES + INFO_HEADER_BYTES + 3 * width * height; 
    auto data = vector<unsigned char>(3 * width * height);

    for (size_t x = 0; x != width; ++x) {
        for (size_t y = 0; y != height; ++y) {
            const auto img_index = (x + y * width) * 3;
            const auto pixel = img(y, x);
            data[img_index + 0] = pixel;
            data[img_index + 1] = pixel;
            data[img_index + 2] = pixel;
        }
    }

    unsigned char fheader[FILE_HEADER_BYTES] = {'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0};
    unsigned char iheader[INFO_HEADER_BYTES] = {40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24, 0};
    const unsigned char bmppad[3] = {0, 0, 0};

    fheader[2] = (unsigned char)(filesize >> 0);
    fheader[3] = (unsigned char)(filesize >> 8);
    fheader[4] = (unsigned char)(filesize >> 16);
    fheader[5] = (unsigned char)(filesize >> 24);
    iheader[4] = (unsigned char)(width >> 0);
    iheader[5] = (unsigned char)(width >> 8);
    iheader[6] = (unsigned char)(width >> 16);
    iheader[7] = (unsigned char)(width >> 24);
    iheader[8] = (unsigned char)(height >> 0);
    iheader[9] = (unsigned char)(height >> 8);
    iheader[10] = (unsigned char)(height >> 16);
    iheader[11] = (unsigned char)(height >> 24);

    stream.write(reinterpret_cast<char*>(fheader), FILE_HEADER_BYTES);
    stream.write(reinterpret_cast<char*>(iheader), INFO_HEADER_BYTES);

    for(size_t i = 0; i != height; ++i)
    {
        const auto row_start = (width * (height - i - 1) * 3);
        stream.write(reinterpret_cast<char*>(&data[row_start]), int(3 * width));
        stream.write(reinterpret_cast<const char*>(bmppad), (4 - (width * 3) % 4) % 4);
    }
}
