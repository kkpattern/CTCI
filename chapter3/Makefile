OBJDIR := ../build
CC = gcc
CCFLAGS = -I ../ -std=c99

SRCS = $(wildcard *.c)

PROGS = $(patsubst %.c,$(OBJDIR)/%,$(SRCS))

all: $(PROGS)

$(OBJDIR)/%: %.c $(OBJDIR)/stacks.o
	$(CC) $(CCFLAGS) -o $@ $^
