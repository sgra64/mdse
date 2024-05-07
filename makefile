# source directories with header files
INCLUDES = \
	-Isrc/demo \
	-Isrc/numbers

# all compiled files
OBJS = \
	out/main.o \
	out/demo/demo.o \
	out/numbers/numbers.o \
	out/numbers/numbers_functions.o \
	out/numbers/ostream_helper.o

# compiler options
CC=g++
CPPFLAGS=-g -c -Wall


# main goal produces 'main' executable in project directory
main: $(OBJS)
	g++ -o main $(OBJS)

clean:
	rm -rf main out

# rule to compile .o from .cpp files, creates subdirs in out
out/%.o: src/%.cpp
	@[ ! -d $(dir $@) ] && echo create $(dir $@) && mkdir -p $(dir $@) || true
	$(CC) $(INCLUDES) $(CPPFLAGS) -c $< -o $@

# file dependencies (should be generated using makedepend)
main.cpp:  src/demo/demo.h src/numbers/numbers.h

out/main.o:  src/main.h src/main.cpp
out/demo/demo.o:  src/demo/demo.h src/demo/demo.cpp
out/numbers/numbers.o:  src/numbers/numbers.h src/numbers/numbers.cpp
out/numbers/numbers_functions.o:  src/numbers/numbers.h src/numbers/numbers_functions.cpp
out/numbers/ostream_helper.o:  src/numbers/ostream_helper.h src/numbers/ostream_helper.cpp
