OBJDIR := ../build
CC = gcc
CCFLAGS = -I ../ -std=c99

SRCS = $(wildcard *.c)

PROGS = $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))

all: $(PROGS)

$(OBJDIR)/%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@ 
