FROM rosshemsley/simplenn-base

COPY . simplenn

RUN mkdir build && cd build && cmake ../simplenn/ && make && make test
