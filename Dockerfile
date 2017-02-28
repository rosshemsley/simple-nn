FROM rosshemsley/simplenn-base

COPY . simplenn

RUN cd simplenn \
    && cmake . \
    && make \
    && make test
