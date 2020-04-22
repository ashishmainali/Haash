CXXFLAGS += --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
default: main



debug: CXXFLAGS += -g
debug: default
main: hashVal.o HAASH.o
	${CXX} ${CXXFLAGS} -o main hashVal.o HAASH.o
HAASH.o: HAASH.cpp *.h
	${CXX} ${CXXFLAGS} -c HAASH.cpp
hashVal.o: hashVal.cpp *.h
	${CXX} ${CXXFLAGS} -c hashVal.cpp



clean:
	-rm -f *.gch *.o HAASH.o hashVal.o main