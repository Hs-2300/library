# makefile template for CSC3002
# 
# Special Symbols used:
# 	$@ name of the file to be made (target)
# 	$* prefix of the file to be made (target)
# 	$? names of the CHANGED dependents.
#	$^ names of ALL the dependents (dependency).
# 	$< name of the related file that caused the action (command)
#
# Usage:
#	make all
#		It compiles everything so that you can do local testing 
#		before installing applications.
#
#	make clean
#		It cleans applications, gets rid of the executables, 
#		any temporary files, object files, etc.
#
#	make echo
#		It echo a string to the console.
#
# Custom Macros:
#
#	PROGRAM
#		Name of the executable program used to test your assignment
#
#	OBJECTS
#		Names of all the object files needed to be linked
#
# Assumptions:
#
#	If header file is used, it must share the SAME filename as
#	the source file.  Ex: Assignment1.cpp, Assignment1.h
#
#
# Note:
#	C++17 version is used to compile the source files.
#
#	lib.cpp contains the functions extracted from the stanford library.
#	
# Revision History:
#	2022/Sept/04	Initial Creation	Kinley
#	2023/Jan/25		new version			Hs-2300


# ##Version 1--------------------------------------
# hello: main.cpp printhello.cpp factorial.cpp
# 	g++ -o hello main.cpp printhello.cpp factorial.cpp

#--------------------------------------
# ##Version 2
# CC = g++
# TARGET = hello
# OBJ = main.o printhello.o factorial.o

# $(TARGET): $(OBJ)
# 	$(CC) -o $(TARGET) $(OBJ)

# main.o: main.cpp
# 	$(CC) -c main.cpp

# printhello.o: printhello.cpp
# 	$(CC) -c printhello.cpp

# factorial.o: factorial.cpp
# 	$(CC) -c factorial.cpp

# #--------------------------------------
# ##Version 3
# CC = g++
# TARGET = hello
# OBJ = main.o printhello.o factorial.o

# CFLAGS = -c -Wall#打开所有编译警告

# $(TARGET): $(OBJ)
# 	$(CC) -o  $@ $^
# #@:TARGET
# #^依赖的所有文件；<依赖的第一个文件
# %.o: %.cpp
# 	$(CC) $(CFLAGS) $< -o $@


# #avoid another file named 'clean'
# .peach:clean

# clean:
# 	rm -f *.o $(TARGET)

##Version 4
CC = g++
TARGET = main
SRC = $(wildcard *.cpp)#所有的cpp文件
OBJ = $(patsubst %.cpp, %.o,$(SRC))#路径替换 %.cpp 替换成 %.o

CFLAGS = -c -Wall -std=c++17#打开所有编译警告

all:$(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o  $@ $^
#@:TARGET
#^依赖的所有文件；<依赖的第一个文件
%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@


#avoid another file named 'clean'
.peach:clean


echo:
	@echo I love CSC3002 !!!!!

clean:
	rm -f *.o $(TARGET)
