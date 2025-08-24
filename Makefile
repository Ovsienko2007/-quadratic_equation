CC = g++
CFLAGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE
OBJECTS = main.o flags.o input.o unittest.o solving.o output.o work_with_colours.o
EXECUTABLE_NAME = quadratic_equation.exe
DIR = Build

all: $(EXECUTABLE_NAME)

.PHONY = all clean start

$(EXECUTABLE_NAME): make_folder $(OBJECTS)
	$(CC) $(addprefix ./$(DIR)/, $(OBJECTS)) -o ./$(DIR)/$(EXECUTABLE_NAME)

$(OBJECTS): %.o: %.cpp
	$(CC) $(CFLAGS) -c  $^ -o ./$(DIR)/$@

make_folder:
	mkdir -p $(DIR) 

start:
	./$(DIR)/$(EXECUTABLE_NAME)

start_test:
	./$(DIR)/$(EXECUTABLE_NAME) --test

clean:
	rm -rf $(DIR)
	rm -f *.o *.exe
	@echo "Files were deleted!"