ARCH ?= x86

ifeq ($(ARCH),x86)
	cc = gcc
else
	cc = arm-linux-gnueabihf-gcc
endif

TARGET = led
BUILD_DIR = build
SRC_DIR = src 
INC_DIR = .
CFLAGS = $(patsubst %, -I%, $(INC_DIR))
INCLUDES = $(foreach dir, $(INC_DIR), $(wildcard $(dir)/*.h))

SOURCES = $(foreach dir, $(SRC_DIR), $(wildcard $(dir)/*.c))
OBJS = $(patsubst %.c, $(BUILD_DIR)/%.o, $(notdir $(SOURCES)))
VPATH = $(SRC_DIR)

$(BUILD_DIR)/$(TARGET):$(OBJS)
	$(cc) $^ -o $@

$(BUILD_DIR)/%.o:%.c $(INCLUDES) | create_build
	$(cc) -c $< -o $@ $(CFLAGS)

.PHONY:clear create_build clear_out

clear:
	rm -r $(BUILD_DIR)

create_build:
	mkdir -p $(BUILD_DIR)

clear_out:
	rm $(foreach dir, $(BUILD_DIR), $(wildcard $(dir)/*.o))