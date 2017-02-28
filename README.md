# SimpleNet

![build status](https://circleci.com/gh/rosshemsley/simple-nn.png?style=shield)

A *work-in-progress* feed-forward neural network library in C++14. Uses Armadillo for fast  linear algebra.
A project to get better at neural nets.

## Docker

The easiest way to get going is to build this project with Docker

```
docker build .
```

Currently this just builds the library and runs the tests.
The base image is was built from `Dockerfile.base` in this repository.


## Compiling natively

### Requirements

- CMake
- Armadillo
- C++14 compliant compiler

You can build the library natively using

```
cmake .
make
```

Out-of-source builds are also supported and recommended.


## Testing

Tests are run using
```
make test
```
