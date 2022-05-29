CXX=g++
CXXFLAGS = -std=c++17 -Wall -Wextra

test: pa1b.o
	${CXX} ${CXXFLAGS} $^ -o $@

clean:
	rm -f *.o 