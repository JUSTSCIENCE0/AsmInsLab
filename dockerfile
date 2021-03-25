FROM debian
COPY 727_uya.cpp .
RUN apt-get update
RUN apt-get -y install gcc g++
RUN g++ -o 727_uya 727_uya.cpp
CMD ./727_uya
