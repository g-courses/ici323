SRCDIR=ex01 ex02 ex03
default: all

all: 
	@for i in $(SRCDIR); do \
	echo "make all in $$i..."; \
	(cd $$i && $(MAKE)); done

clean:
	@for i in $(SRCDIR); do \
	echo "make clean in $$i..."; \
	(cd $$i && $(MAKE) clean); done

distclean:
	@for i in $(SRCDIR); do \
	echo "make clean && make distclean in $$i..."; \
	(cd $$i && $(MAKE) clean && $(MAKE) distclean); done


.PHONY: all clean distclean

