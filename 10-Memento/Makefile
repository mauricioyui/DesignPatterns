CC=g++

BINDIR=Binary
BLDDIR=Build
INCDIR=Include
ROOTDIR=Root
BRANCHDIR=Branch

CFLAGS=-Wall -I $(INCDIR) -lncurses

FILES=$(wildcard */*.cc)
OBJECTS=$(patsubst %.cc, $(BLDDIR)/%.o, $(FILES))

TARGETNAME=$(basename $(notdir $(wildcard $(ROOTDIR)/*.cc)))
TARGET=$(BINDIR)/$(TARGETNAME)

all: $(OBJECTS) $(TARGET)

$(OBJECTS): $(BLDDIR)/%.o: %.cc $(INCDIR)/*.h
	mkdir -p $(dir $@)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJECTS)
	mkdir -p $(dir $@)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f -r $(BLDDIR)
	rm -f -r $(BINDIR)
