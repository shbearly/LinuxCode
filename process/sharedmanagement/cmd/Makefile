#Makefile for utopia memdata command line code

default:all

TARGETS = memdata 
OBJDIR = .

#OBJECTS=$(SOURCES:%.c=$(OBJDIR)/%)
OUTPUT_DIR = $(OBJDIR)

$(OUTPUT_DIR)/memdata: memdatacmd.c

CFLAGS += -g 
EXTRA_LDFLAGS += ../lib/libmemdata.a


####common targets-------------------

OBJECTS = $(TARGETS:%=$(OUTPUT_DIR)/%)

all: $(OBJECTS)

$(OBJECTS): 
	$(CC) $(CFLAGS) $(LDFLAGS) $(EXTRA_CFLAGS) $(EXTRA_LDFLAGS) -o $@  $^
	ln -s memdata memdata_create

.PHONY : clean
clean: 
	rm -f $(OBJECTS)
	rm -f memdata_create
