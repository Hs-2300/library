TARGET =p1\
		p2\
		p3

CPPFLAGS = -w -std=c++17
CC = g++

all: $(TARGET)

p1: RemoveComments.cpp lib.cpp
	$(CC) $(CPPFLAGS) -o $@ $^

p2: AllComments.cpp
	$(CC) $(CPPFLAGS) -o $@ $^

p3: removeAllComments.cpp lib.cpp
	$(CC) $(CPPFLAGS) -o $@ $^

clean:
	rm -f $(TARGET) *.o