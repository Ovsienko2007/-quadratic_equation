CC = g++
CFLAGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef \
   -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations \
   -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ \
   -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion\
   -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2\
   -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers\
   -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo\
   -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits\
   -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE -DCOLOR_PRINT
   
OBJECTS = main.o consol.o args.o input.o unit_test.o solving.o output.o work_with_colors.o my_assert.o
EXECUTABLE_NAME = quadratic_equation.exe
DIR_BUILD = Build
DIR_SOURCE = Source
CFLAGSH = -I Include
all: $(EXECUTABLE_NAME)


.PHONY = all clean start

$(EXECUTABLE_NAME): make_folder  $(addprefix ./$(DIR_SOURCE)/, $(OBJECTS))
	$(CC) $(addprefix ./$(DIR_BUILD)/$(DIR_SOURCE)/, $(OBJECTS)) -o ./$(DIR_BUILD)/$(EXECUTABLE_NAME)


$(addprefix ./$(DIR_SOURCE)/, $(OBJECTS)): %.o: %.cpp
	$(CC) $(CFLAGS) $(CFLAGSH) -c $^ -o ./$(DIR_BUILD)/$@

make_folder:
	mkdir -p $(DIR_BUILD)/$(DIR_SOURCE)

start:
	./$(DIR_BUILD)/$(EXECUTABLE_NAME)

start_embedded_test:
	./$(DIR_BUILD)/$(EXECUTABLE_NAME) --embedded-test

start_file_test:
	./$(DIR_BUILD)/$(EXECUTABLE_NAME) --file-test test

start_consol:
	./$(DIR_BUILD)/$(EXECUTABLE_NAME) --consol

clean:
	rm -rf $(DIR_BUILD)/$(DIR_SOURCE)/
	@echo "Files were deleted!"