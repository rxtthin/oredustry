OUT := bin/oredustry
CC := g++
DIR_SRC := src src/core src/core/ui
INC := -Isrc -Iinclude
CFLAGS := -std=c++17
SRC := $(wildcard $(addsuffix /*.cpp, $(DIR_SRC)))
SRC += $(wildcard $(addsuffix /*.c, $(DIR_SRC)))
OBJ := $(patsubst %.cpp, %.o, $(SRC))
LIBS := -lSDL2 -lSDLmain -lSDL2_ttf -lSDL2_image 

.PHONY: all clean

all: $(OBJ) $(OUT)

%.o: %.cpp
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OUT): $(OBJ)
	$(CC) $(CFLAGS) $(LIBS) $(OBJ) -o $@

clean:
	rm $(OBJ) $(OUT)
