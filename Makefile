CC = gcc
AR = ar
DEBUG = # -g -Wall
CXXFLAGS = -O2 -std=c++14 $(DEBUG)
CFLAGS = -O2 $(DEBUG)
ARFLAGS = rcs
LDFLAGS = -lstdc++ -lm
OUT = libfraction.a
OBJDIR = obj
BUILDDIR = build

all: directories $(OUT)

directories: $(OBJDIR) $(BUILDDIR)

clean:
	rm -r $(OBJDIR)
	rm -r $(BUILDDIR)

test: $(OUT)
	wget https://github.com/catchorg/Catch2/releases/download/v2.11.1/catch.hpp -O catch.hpp
	$(CC) -c tests.cpp $(CXXFLAGS) -o $(OBJDIR)/tests.o
	$(CC) $(OBJDIR)/tests.o $(OBJDIR)/fraction.o -o $(BUILDDIR)/tests $(LDFLAGS)
	$(BUILDDIR)/tests
	rm catch.hpp

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

$(OUT):  fraction.o
	$(AR) $(ARFLAGS) $(BUILDDIR)/$(OUT) $(OBJDIR)/fraction.o


fraction.o: fraction.cpp
	$(CC) -c fraction.cpp $(CXXFLAGS) -o $(OBJDIR)/fraction.o
