# Variables / Macros
cflags = -Wall -Werror -std=c99 -O2 -c -MMD -MP
includes = -I src/usuario -I src
# Fuentes y Objetos
SOURCES_1 = $(wildcard src/*.c) 
SOURCES_2 = $(wildcard src/usuario/*.c) 
SOURCES = $(SOURCES_1) $(SOURCES_2)

# Genera la lista de .o correspondiente en lib/
OBJECTS = $(patsubst src/%.c, lib/%.o, $(SOURCES))
DEPS = $(OBJECTS:.o=.d)
output = bin/practica7

# Tarea / Target principal
all: link

# Regla de patrón: se ejecuta UNA VEZ POR CADA archivo .c individual
lib/%.o: src/%.c
	gcc $(cflags) $< -o $@ $(includes)
-include $(DEPS)

build: $(OBJECTS)
	echo "Compilado Exitosamente"

# Target link: toma los .o de lib/ y genera el ejecutable final en bin/
link: $(OBJECTS)
	gcc $(OBJECTS) -o $(output)
	@echo "Enlazado Exitosamente"

run:
	$(output)