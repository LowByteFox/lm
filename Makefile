TARGET = x86_64
CC = cc
AS = cc
CFLAGS = -g -Os -Iinclude -fno-stack-protector
CFLAGS_EXTRA = -static -nostartfiles -nostdlib -z noexecstack

OBJS = arch/$(TARGET)/crti.o arch/$(TARGET)/crtn.o arch/$(TARGET)/start.o \
	arch/$(TARGET)/syscalls.o src/main.o src/print.o

all: lm

lm: $(OBJS)
	$(CC) $(CFLAGS_EXTRA) $(OBJS) -o $@

.s.o:
	$(AS) -c $< -o $@

.c.o:
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJS)

.PHONY: all clean 
.SUFFIXES: .c .s
