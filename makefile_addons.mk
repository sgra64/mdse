# make cc_opts and cc_objs option files used in launch.json
.vscode/cc_objs: makefile
	@echo creating .vscode/cc_objs
	@echo $(OBJS) | tr ' ' '\n' | egrep -v 'main.o' > .vscode/cc_objs

.vscode/cc_opts: makefile
	@echo creating .vscode/cc_objs
	@echo $(INCLUDES) "-std=c++20" > .vscode/cc_opts

# solution files (not checked-in)
SOL_TAR = tmp/sol.tar
SOL_FILES = \
	makefile_solutions.mk \
	src/numbers/numbers_sol.cpp \
	src/numbers/powerset_sol.cpp

tarsol: $(SOL_TAR)

# create solution .tar
$(SOL_TAR): $(SOL_FILES)
	@[ ! -d tmp ] && echo "mkdir tmp" && mkdir tmp; \
	[ -f $(SOL_TAR) ] && cp $(SOL_TAR) $(SOL_TAR).BAK; \
	tar cvf $(SOL_TAR) $(SOL_FILES)

# restore solution files from solution .tar
addsol:
	[ -f "$(SOL_TAR)" ] && tar xvf $(SOL_TAR)

# remove solution files from project directory (only if tar exists)
rmsol:
	[ -f "$(SOL_TAR)" ] && rm -f $(SOL_FILES)
