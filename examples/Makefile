# Compiler
CC := gcc

# Directories
EXAMPLES_DIR := ../examples
BUILD_DIR := ../build
INCLUDE_DIR := ../include
LIB_DIR := ../build

# Flags
CFLAGS := -Wall -Wextra -I$(INCLUDE_DIR)
LDFLAGS := -L$(LIB_DIR) -lapue
# Add the library path to the linker flags
LDFLAGS += -Wl,-rpath=$(abspath $(LIB_DIR))

# Source files
SRC_FILES := $(wildcard $(EXAMPLES_DIR)/*.c)

# Executable files
EXE_FILES := $(patsubst $(EXAMPLES_DIR)/%.c,$(BUILD_DIR)/%,$(SRC_FILES))

# Targets
all: $(EXE_FILES)

$(BUILD_DIR)/%: $(EXAMPLES_DIR)/%.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

clean:
	rm -rf $(BUILD_DIR)/*.o
	find $(BUILD_DIR) -maxdepth 1 -type f -executable -delete
