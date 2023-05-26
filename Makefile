ifndef DEBUG
DEBUG := 0
endif

OPTCFLAGS := -O3 -march=native
DBGFLAGS := -O0 -g #-fsanitize=address

CC  := gcc -fdiagnostics-color=always
CXX := g++ -fdiagnostics-color=always

CFLAGS   := -Wall -Wextra -Wno-unused-parameter -std=c17
CXXFLAGS := -Wall -Wextra -Wno-unused-parameter -std=c++20

LDFLAGS := -Wl,--copy-dt-needed-entries
LDLIBS :=

ifeq ($(DEBUG),)
DEBUG := 0
endif

ifeq ($(DEBUG),0)
CFLAGS := $(CFLAGS) $(OPTCFLAGS)
CXXFLAGS := $(CXXFLAGS) $(OPTCFLAGS)
LDFLAGS := $(LDFLAGS) $(OPTCFLAGS)
else
CFLAGS := $(CFLAGS) $(DBGFLAGS)
CXXFLAGS := $(CXXFLAGS) $(DBGFLAGS)
LDFLAGS := $(LDFLAGS) $(DBGFLAGS)
endif

SRC_DIR := src
OBJ_DIR := obj
BUILD_DIR := build

OUTPUT := main

INCLUDES := -I$(SRC_DIR)

HDR_FILES := $(shell find $(SRC_DIR)/ -type f -name '*.h')
SRC_FILES := $(shell find $(SRC_DIR)/ -type f -name '*.cpp')
#SRC_FILES := $(filter-out $(SRC_MAINS),$(SRC_FILES))

OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))

all: $(OUTPUT)

$(OUTPUT): $(OBJ_FILES)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $(BUILD_DIR)/$@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(BUILD_DIR)

-include $(patsubst %.o, %.d, $(OBJ_FILES))
