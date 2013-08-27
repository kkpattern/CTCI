OBJDIR := build
SUBDIRS = ctci chapter1 chapter2 chapter3

.PHONY: subdirs $(SUBDIRS)
subdirs: $(SUBDIRS)

$(SUBDIRS): $(OBJDIR)
	$(MAKE) -C $@

$(OBJDIR):
	mkdir -p $@
