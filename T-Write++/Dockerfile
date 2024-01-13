FROM ubuntu:20.04

ENV DEBIAN_FRONTEND noninteractive
RUN apt-get update && \
    apt-get -y install g++ make && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . /app

RUN make -B

ENTRYPOINT [ "/app/program" ]