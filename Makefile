SRCDIR=$(dir $(wildcard */))

all: $(SRCDIR)

$(SRCDIR):
	$(MAKE) -C $@

.PHONY: all $(SRCDIR) clean

clean:
	for dir in $(SRCDIR); do \
	$(MAKE) -C $$dir clean; \
	done
