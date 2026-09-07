FROM ubuntu:latest

RUN apt-get update && apt-get install -y \
    g++ \
    make \
    valgrind \
    gdb \
    && rm -rf /var/lib/apt/lists/* 

WORKDIR /main

COPY . .

RUN make

# Run the compiled executable (taskforge or main depending on your Makefile)
CMD ["./taskforge"]