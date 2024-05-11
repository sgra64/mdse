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
all: .vscode/cc_opts .vscode/cc_objs main.out

# include goals to make .vscode/cc_opts .vscode/cc_objs
include makefile_addons.mk

# include additional definitions and dependencies (if present)
MK_SOL=$(if $(wildcard makefile_solutions.mk),makefile_solutions.mk)
ifneq ($MK_SOL,)
include $(MK_SOL)
endif

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


# file dependencies (should be generated using a tool like makedepend)
main.cpp:   src/demo/demo.h src/numbers/numbers.h

out/main.o: src/main.h src/main.cpp
out/demo/demo.o:  src/demo/demo.h src/demo/demo.cpp
out/numbers/numbers.o:  src/numbers/numbers.h src/numbers/numbers.cpp
out/numbers/ostream_helper.o:  src/numbers/ostream_helper.h src/numbers/ostream_helper.cpp
out/numbers/numbers_functions.o:  src/numbers/numbers.h src/numbers/numbers_functions.cpp $(NUMBERS_SOLUTION_DEPS)
