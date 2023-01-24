# ##Version 1--------------------------------------
# hello: main.cpp printhello.cpp factorial.cpp
# 	g++ -o hello main.cpp printhello.cpp factorial.cpp

#--------------------------------------
# ##Version 2
# CXX = g++
# TARGET = hello
# OBJ = main.o printhello.o factorial.o

# $(TARGET): $(OBJ)
# 	$(CXX) -o $(TARGET) $(OBJ)

# main.o: main.cpp
# 	$(CXX) -c main.cpp

# printhello.o: printhello.cpp
# 	$(CXX) -c printhello.cpp

# factorial.o: factorial.cpp
# 	$(CXX) -c factorial.cpp

# #--------------------------------------
# ##Version 3
# CXX = g++
# TARGET = hello
# OBJ = main.o printhello.o factorial.o

# CXXFLAGS = -c -Wall#打开所有编译警告

# $(TARGET): $(OBJ)
# 	$(CXX) -o  $@ $^
# #@:TARGET
# #^依赖的所有文件；<依赖的第一个文件
# %.o: %.cpp
# 	$(CXX) $(CXXFLAGS) $< -o $@


# #avoid another file named 'clean'
# .peach:clean

# clean:
# 	rm -f *.o $(TARGET)

##Version 4
CXX = g++
TARGET = hello
SRC = $(wildcard *.cpp)#所有的cpp文件
OBJ = $(patsubst %.cpp, %.o,$(SRC))#路径替换 %.cpp 替换成 %.o

CXXFLAGS = -c -Wall#打开所有编译警告

$(TARGET): $(OBJ)
	$(CXX) -o  $@ $^
#@:TARGET
#^依赖的所有文件；<依赖的第一个文件
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@


#avoid another file named 'clean'
.peach:clean

clean:
	rm -f *.o $(TARGET)
