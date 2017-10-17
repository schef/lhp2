CXX = g++

PROJ_DIR := .

CXXFLAGS += -g -Wall
CXXFLAGS += -std=c++11

SRC_FILES += \
  $(PROJ_DIR)/main.cpp \

INC_FOLDERS += \
  $(PROJ_DIR)/ \

INC_PARAMS=$(foreach d, $(INC_FOLDERS), -I$d)

default:
	$(CXX) $(CXXFLAGS) $(SRC_FILES) $(INC_PARAMS) -o lhp2
	./lhp2
