# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# Makefile that builds the project.
# - make -n             ; show commands to build the main goal
# - make                ; build the main goal 'out/main'
# - make clean          ; clean-up the project
# - make show_vars      ; show internal variables
# 
# Tutorials and further information:
# - https://gertjanvandenburg.com/files/talk/make.html
# - https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
# - https://makefiletutorial.com/
# 
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# 
# make variables:

     OUT := out
    OUTC := $(OUT)/compiled
     SRC := src
 INCLUDE := $(SRC)/include
     CPP := g++ -I./$(INCLUDE)

    SRCS := $(shell find $(SRC) -name '*.cpp')
    OBJS := $(patsubst $(SRC)/%.cpp,$(OUTC)/%.o,$(SRCS))
SRC_DIRS := $(shell find $(SRC) -type d)
OBJ_DIRS := $(sort $(dir $(OBJS)))

# main goal that builds the link goal and the $(OBJ_DIRS) folders
goal: $(OUTC) $(OUT)/main 

# link goal
$(OUT)/main: $(OBJS)
	$(CPP) -o $@ $^

# compile rule
$(OUTC)/%.o: $(SRC)/%.cpp
	$(CPP) -c $< -o $@

clean:
	rm -rf $(OUT)

.PHONY: clean

show_vars:
	@echo "     OUT: $(OUT)"
	@echo "    OUTC: $(OUTC)"
	@echo "     SRC: $(SRC)"
	@echo " INCLUDE: $(INCLUDE)"
	@echo "     CPP: $(CPP)"
	@echo "SRC_DIRS: $(SRC_DIRS)"
	@echo "OBJ_DIRS: $(OBJ_DIRS)"
	@echo "    SRCS: $(SRCS)"
	@echo "    OBJS: $(OBJS)"

$(OUTC):
	mkdir -p $(OBJ_DIRS)

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# dependencies (manually maintained):

$(OUTC)/main.o: $(SRC)/main.cpp $(INCLUDE)/collections.h $(INCLUDE)/collections.tpp
# $(OUTC)/pset.o: $(SRC)/pset.cpp $(INCLUDE)/collections.h $(INCLUDE)/collections.tpp
$(OUTC)/demo-b1/shape.o: $(SRC)/demo-b1/shape.cpp

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
