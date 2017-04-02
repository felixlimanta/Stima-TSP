CC = g++
OPTIONS = -std=c++11
SRC = $(wildcard *.cpp)
OBJS = $(SRC:.cpp=.o)
BIN = ../bin/tsp.exe

.PHONY: subdirs $(SUBDIRS) all clean

all: $(OBJS)
	$(CC) $(OPTIONS) $(OBJS) -o $(BIN)

$(SUBDIRS):
	$(MAKE) -C $@	

%.o: %.cpp
	$(CC) $(OPTIONS) -c -o $@ $<

clean:
	rm -rf $(OBJS)