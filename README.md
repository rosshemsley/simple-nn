# SimpleNet

![build status](https://circleci.com/gh/rosshemsley/simple-nn.png?style=shield)

A simple feed-forward neural network library in C++14. Uses Armadillo for fast  linear algebra.

A project to get better at NNs.

### Requirements

- CMake
- Armadillo
- C++14 compliant compiler


### Docker

The easiest way to get going is to build this project in Docker.

```
docker build .
```

The base image is built from `Docker.base`.


### Compiling natively

You can build the library natively using
```
cmake .
make
```


### Testing

Tests are run using
```
make test
```
