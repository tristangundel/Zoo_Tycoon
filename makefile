CXX = g++
CXXFLAGS = -std=c++0x -Wall -g
LDFLAGS = -lboost_date_time

OBJS = animal.o penguin.o menu.o tiger.o turtle.o zoo.o  main.o

SRCS = animal.cpp penguin.cpp menu.cpp tiger.cpp turtle.cpp zoo.cpp main.cpp

HEADERS = animal.hpp penguin.hpp menu.hpp tiger.hpp turtle.hpp zoo.hpp

zooTycoon: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -g -o zooTycoon 

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)
clean:
	rm zooTycoon ${OBJS}
                                 
