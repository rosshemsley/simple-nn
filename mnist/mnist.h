#pragma once

#include <armadillo>

#include <cstdint>
#include <iostream>
#include <vector>

namespace mnist {

using Image = arma::Mat<uint8_t>;
using Label = uint8_t;

/**
 * @brief       Load MNIST data from a stream
 *
 * Data is available at http://yann.lecun.com/exdb/mnist
 * Reads binary files in the following form
 *
 * [offset] [type]          [value]          [description]
 * 0000     32 bit integer  0x00000803(2051) magic number
 * 0004     32 bit integer  60000            number of images
 * 0008     32 bit integer  28               number of rows
 * 0012     32 bit integer  28               number of columns
 * 0016     unsigned byte   ??               pixel
 * 0017     unsigned byte   ??               pixel
 * ........
 * xxxx     unsigned byte   ??               pixel
 *
 */
std::vector<Image> load_images(std::istream&);

/**
 * @brief      Load MNIST labels data from a stream
 *
 * Reads binary files in the following form
 *
 * [offset] [type]          [value]          [description]
 * 0000     32 bit integer  0x00000801(2049) magic number (MSB first)
 * 0004     32 bit integer  10000            number of items
 * 0008     unsigned byte   ??               label
 * 0009     unsigned byte   ??               label
 * ........
 * xxxx     unsigned byte   ??               label
 */
std::vector<Label> load_labels(std::istream&);

/**
 * @brief      Write a bmp file to a stream from a loaded image.
 */
void write_image_bmp(const Image&, std::ostream&);

} // namespace mnist
