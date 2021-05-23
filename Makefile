# Name of the project
PROJECT_NAME = root

TEST_PROJECT_NAME = Test_$(PROJECT_NAME)

COVERAGE_TEST_NAME = coverage_$(PROJECT_NAME)

# Output directory
BUILD = build

# All source code files
SRC = src/root.c\
src/trigo_calc.c\
src/trigo.c\


TEST_SRC = test.c\
unity/unity.c\
# All include folders with header files
INC	= -Iinc\
-Iunity\


#Library Inlcudes
#INCLUDE_LIBS = 

ifdef OS
   RM = del /q
   FixPath = $(subst /,\,$1)
   EXEC = exe
   editor = notepad
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
	  EXEC = out
	  editor = cat
   endif
endif



# Document files
DOCUMENTATION_OUTPUT = documentation/html

# Default target built
$(PROJECT_NAME):all

# Run the target even if the matching name exists
.PHONY: run clean test doc all valgrind coverage

all: 
	gcc main.c  $(SRC) $(INC) -o $(call FixPath,$(PROJECT_NAME).$(EXEC))

	
test: $(SRC) $(TEST_SRC)
	gcc $(TEST_SRC) $(SRC) $(INC) $(INC_T) -lm -o $(TEST_PROJ_NAME).$(EXEC)
	./$(TEST_PROJ_NAME).$(EXEC)

# Call `make run` to run the application
run:$(PROJECT_NAME)
	./$(PROJECT_NAME).$(EXEC)

# Document the code using Doxygen
doc:
	make -C ./documentation
	
coverage: 
	gcc -fprofile-arcs -ftest-coverage main.c $(SRC) $(INC) -lm -o $(PROJ_NAME).$(EXEC)
	./$(PROJ_NAME).$(EXEC) < input.txt
	gcov -a main.c

staticcheck: 
	cppcheck --enable=all --suppress=missingIncludeSystem main.c $(SRC) inc/anm.h $(INC)

memcheck:
	valgrind ./$(PROJ_NAME).$(EXEC)

clean:
	$(RM) *.$(EXEC) *.gcov *.gcda *.gcno 

analyze: all run test coverage staticcheck memcheck clean

# Create new build folder if not present
$(BUILD):
	mkdir build