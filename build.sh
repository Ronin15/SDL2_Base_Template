#1/bin/bash
COMPILE="bear -- g++ -std=c++20 ./src/*.cpp -o ./bin/prog -I./include  -lSDL2"
echo ${COMPILE}
eval $COMPILE
