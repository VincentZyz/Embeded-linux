ARCH ?= x86
OBJS  = main.o use.o
TARGET = out

ifeq ($(ARCH),x86)
	cc = gcc
else
	cc = arm-linux-gnueabihf-gcc
endif

$(TARGET): $(OBJS)
	$(cc) $^ -o $@

main.o:
	$(cc) -c main.c -o main.o

use.o:
	$(cc) -c use.c -o use.o

.PHONY:clear
clear:
	rm $(TARGET) $(OBJS)
