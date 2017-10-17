CXX = g++

LIB_DIR := .

CXXFLAGS += -g -Wall
CXXFLAGS += -std=c++11

SRC_FILES += \
  $(LIB_DIR)/tests-patcher.cpp \
  $(LIB_DIR)/patcher.cpp \

INC_FOLDERS += \
  $(LIB_DIR)/ \

INC_PARAMS=$(foreach d, $(INC_FOLDERS), -I$d)

default:
	$(CXX) $(CXXFLAGS) tests-main.o $(SRC_FILES) $(INC_PARAMS) -o tests
	./tests -r compact

main:
	$(CXX) $(CXXFLAGS) tests-main.cpp -c
