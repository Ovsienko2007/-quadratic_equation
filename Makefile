CC = g++
EXECUTABLE_NAME = quadratic_equation.exe
DIR = Direct
FLAGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

.PHONY = all clean start

all: $(EXECUTABLE_NAME)

$(EXECUTABLE_NAME): make_folder main.o input.o unitest.o solving.o output.o work_with_colours.o
	$(CC) ./$(DIR)/main.o ./$(DIR)/input.o ./$(DIR)/unitest.o ./$(DIR)/solving.o ./$(DIR)/output.o ./$(DIR)/work_with_colours.o -o ./$(DIR)/$(EXECUTABLE_NAME)

make_folder:
	mkdir -p $(DIR) 

main.o: main.cpp
	$(CC) $(FLAGS) -c main.cpp -o ./$(DIR)/main.o

input.o: input.cpp
	$(CC) $(FLAGS) -c input.cpp -o ./$(DIR)/input.o

unitest.o: unitest.cpp
	$(CC) $(FLAGS) -c unitest.cpp -o ./$(DIR)/unitest.o

solving.o: solving.cpp
	$(CC) $(FLAGS) -c solving.cpp -o ./$(DIR)/solving.o

output.o: output.cpp
	$(CC) $(FLAGS) -c output.cpp -o ./$(DIR)/output.o

work_with_colours.o: work_with_colours.cpp
	$(CC) $(FLAGS) -c work_with_colours.cpp -o ./$(DIR)/work_with_colours.o

start:
	./$(DIR)/$(EXECUTABLE_NAME)

clean:
	rm -r $(DIR)
	@echo "Files were deleted!"