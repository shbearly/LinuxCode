
CC=g++ 
CFLAGS= -g

all:

sem: semphore

sha: sharemem_r sharemem_w

.PHONY : clean
clean: sharemem_r sharemem_w semphore
	rm -rf $^
