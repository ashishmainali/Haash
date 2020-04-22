CXXFLAGS += --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
default: main



debug: CXXFLAGS += -g
debug: default
main: hashVal.o SHA512.o
	${CXX} ${CXXFLAGS} -o main hashVal.o SHA512.o
SHA512.o: SHA512.cpp *.h
	${CXX} ${CXXFLAGS} -c SHA512.cpp
hashVal.o: hashVal.cpp *.h
	${CXX} ${CXXFLAGS} -c hashVal.cpp



clean:
	-rm -f *.gch *.o SHA512.o hashVal.o main