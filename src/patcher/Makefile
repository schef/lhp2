CXX = g++

LIB_DIR := .

CXXFLAGS += -g -Wall
CXXFLAGS += -std=c++11

SRC_FILES += \
	$(LIB_DIR)/tests-strings.cpp \
	$(LIB_DIR)/tests-brass.cpp \
	$(LIB_DIR)/strings.cpp \
	$(LIB_DIR)/brass.cpp \
	$(LIB_DIR)/lilytools.cpp \

INC_FOLDERS += \
	$(LIB_DIR)/ \

INC_PARAMS=$(foreach d, $(INC_FOLDERS), -I$d)

default:
	$(CXX) $(CXXFLAGS) tests-main.o $(SRC_FILES) $(INC_PARAMS) -o tests
	./tests -r compact

main:
	$(CXX) $(CXXFLAGS) tests-main.cpp -c
