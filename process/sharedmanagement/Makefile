#Makefile for Utopia memdata module code

SUBDIRS = lib cmd
CFLAGS = -g 

.PHONY : all clean $(SUBDIRS)
all: $(SUBDIRS)

#dependencies
cmd : lib

$(SUBDIRS):
	$(MAKE) -C $@

clean:
	for f in $(SUBDIRS); do \
		make -C $$f clean; \
	done 
