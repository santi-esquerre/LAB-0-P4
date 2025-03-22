CMP = g++
OPCIONES = -std=c++98 -Wall -Iheader
SRC = src/ArticuloRevista.cpp src/DTFecha.cpp src/Investigador.cpp src/Libro.cpp src/PaginaWeb.cpp src/Publicacion.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = program

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CMP) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CMP) $(OPCIONES) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)