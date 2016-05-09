
CC=g++ 
CFLAGS= -g -pthread
LFLAGS= -pthread

exclude="_test"
#src=$(wildcard *[^$(exclude)].c)
src=$(wildcard *.c)
dir=$(notdir $(src))
obj=$(patsubst %.c,%,$(dir) )

all: $(obj)

$(obj):

show:
	@echo $(src)
	@echo $(dir)
	@echo $(obj)

clean:
	rm -rf $(obj)
