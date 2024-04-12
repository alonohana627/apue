# Compiler
CC := gcc

# Directories
SRC_DIR := src
LIB_DIR := lib
INCLUDE_DIR := include
BUILD_DIR := build

# Flags
CFLAGS := -Wall -Wextra -O2 -Wpedantic -I$(INCLUDE_DIR) -lc

# Source files
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
LIB_FILES := $(wildcard $(LIB_DIR)/*.c)

# Object files
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC_FILES))
OBJ_FILES += $(patsubst $(LIB_DIR)/%.c,$(BUILD_DIR)/%.o,$(LIB_FILES))

# Library
LIB_NAME := apue
STATIC_LIB := $(BUILD_DIR)/lib$(LIB_NAME).a
SHARED_LIB := $(BUILD_DIR)/lib$(LIB_NAME).so

# Targets
all: $(STATIC_LIB) $(SHARED_LIB)

$(STATIC_LIB): $(OBJ_FILES)
	ar rcs $@ $^

$(SHARED_LIB): $(OBJ_FILES)
	$(CC) -fPIC -shared -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(LIB_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

exmp:
	make -C ./examples M='pwd'

exmp-clean:
	make -C ./examples M='pwd'

clean:
	rm -rf $(BUILD_DIR)/*.o $(STATIC_LIB) $(SHARED_LIB)
	find $(BUILD_DIR) -maxdepth 1 -type f -executable -delete
