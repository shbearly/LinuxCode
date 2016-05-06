#Makefile for Utopia memdata library code

default:all

STATIC_TARGETS=libmemdata
DYNAMIC_TARGETS=libmemdata
OBJDIR=.

SOURCES= $(wildcard *.c)
OBJECTS=$(SOURCES:%.c=$(OBJDIR)/%.o)
OUTPUT_DIR=$(OBJDIR)


$(OUTPUT_DIR)/libmemdata.so : $(OBJECTS)
$(OUTPUT_DIR)/libmemdata.a : $(OBJECTS)


CFLAGS = -g 
EXTRA_CFLAGS += -Wall -D_GNU_SOURCE -DSC_SYSV_SEM #-I$(SPIDERPORK_OUTPUT)/include/linux
#include linux headers here too, if necessary

####common targets-------------------

STATLIB_TARGETS = $(STATIC_TARGETS:%=$(OUTPUT_DIR)/%.a)
SO_TARGETS = $(DYNAMIC_TARGETS:%=$(OUTPUT_DIR)/%.so)
EXETARGETS = $(XTARGETS:%=$(OUTPUT_DIR)/%)


all: $(SO_TARGETS) $(STATLIB_TARGETS) $(EXETARGETS)
	 

$(EXETARGETS): 
	$(CC) $(CFLAGS) $(LDFLAGS) $(EXTRA_CFLAGS) $(EXTRA_LDFLAGS) -o $@  $^

$(SO_TARGETS):
	$(CC) -shared $(LDFLAGS) $(EXTRA_LDFLAGS) -o $@ $^

$(STATLIB_TARGETS):
	$(LD) -r -o $@ $^

$(OBJDIR)/%.o: %.c
	$(CC) -g $(CFLAGS) $(LDFLAGS) $(EXTRA_CFLAGS) $(EXTRA_LDFLAGS) -c -o $@ $^

.PHONY : clean
clean: 
	rm -f $(OTARGETS) $(SO_TARGETS) $(STATLIB_TARGETS) $(EXETARGETS) *.o
