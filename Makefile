CC=g++
CFLAGS=-c -Wall
SOURCES=main.cpp Evaluador.cpp Libro.cpp NodoBinario.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=Examen

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	-find . -name '*.o' -exec rm -r {} \;
	-rm -f $(EXECUTABLE)

test:
	$ ./$(EXECUTABLE)
