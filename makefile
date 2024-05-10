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
CPPFLAGS=-g -c -Wall -std=c++20

# top-level goal
all: main.out .vscode/cc_opts .vscode/cc_objs

# produce 'main' executable in project directory
main.out: $(OBJS)
	g++ -o main.out $(OBJS)

clean:
	@echo removing 'main.out' executable and compiled 'out' directory
	rm -rf main.out out

# rule to compile .o from .cpp files (creates subdirs)
out/%.o: src/%.cpp
	@[ ! -d $(dir $@) ] && echo create $(dir $@) && mkdir -p $(dir $@) || true
	$(CC) $(INCLUDES) $(CPPFLAGS) -c $< -o $@

# make cc_opts and cc_objs option files used in launch.json
.vscode/cc_objs: makefile
	@echo creating .vscode/cc_objs
	@echo $(OBJS) | tr ' ' '\n' | egrep -v 'main.o' > .vscode/cc_objs

.vscode/cc_opts: makefile
	@echo creating .vscode/cc_objs
	@echo $(INCLUDES) "-std=c++20" > .vscode/cc_opts

# file dependencies (should be generated using makedepend)
main.cpp:   src/demo/demo.h src/numbers/numbers.h

out/main.o: src/main.h src/main.cpp
out/demo/demo.o:  src/demo/demo.h src/demo/demo.cpp
out/numbers/numbers.o:  src/numbers/numbers.h src/numbers/numbers.cpp
out/numbers/ostream_helper.o:  src/numbers/ostream_helper.h src/numbers/ostream_helper.cpp
out/numbers/numbers_functions.o:  src/numbers/numbers.h src/numbers/numbers_functions.cpp $(if $(wildcard src/numbers/numbers_sol.cpp), src/numbers/numbers_sol.cpp)
