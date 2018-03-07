###############################################################################
# Makefile para ARM Linux con funciones avanzadas
# Probado con Raspbian en un Raspberry Pi 2
# Copyright (C) 2015 por Joel Bodenmann <joel@embedded.pro>
# Modificado el 7 de enero de 2018 por Byron Quezada <github.com/byque>
#
# Se puede usar este makefile libremente sin ninguna garantía y bajo el propio
# riesgo del usuario.
###############################################################################

# Éste es el nombre de los binarios que serán generados
TARGET  = linuxI2C-binario

# Aquí añadimos todos los archivos *.c que se quieren compilar
CSRCS   = main.c linuxI2C.c

# Aquí añadimos las rutas a los directorios include
IDIR    = ../include

# Aquí añadimos las librerías estándar que se van a usar
LIBS    =

# Configuración del compilador
CC      = gcc
SIZE    = size
CFLAGS  = -g -std=gnu99 -Wall
LDFLAGS = -g -Wall

###############################################################################
# No cambiar nada después de esta línea
###############################################################################

BINDIR   = ../bin
BUILDDIR = ../build
OBJDIR   = $(BUILDDIR)/obj

# Generar el nombre de los archivos objeto
OBJS     = $(addprefix $(OBJDIR)/,$(addsuffix .o,$(basename $(CSRCS:%.c=%.o))))

# Añadir las rutas
CFLAGS   += $(IDIR:%=-I %)
LDFLAGS  += $(IDIR:%=-I %)

# Añadir las librerías estándar
LDFLAGS  += $(LIBS)

# Aquí se definen los archivos generados por defecto cuando el usuario llama
# solamente 'make'
all: build size

# Crear todos los archivos y el binario
build: builddirs $(BINDIR)/$(TARGET)

# Crear los directorios requeridos (si no existen previamente)
builddirs:
	@echo
	@echo "Creando directorios..."
	@mkdir -p $(BINDIR)
	@mkdir -p $(BUILDDIR)
	@mkdir -p $(OBJDIR)

# Enlazar todo junto
$(BINDIR)/$(TARGET): $(OBJS)
	@echo
	@echo Enlazando $@
	@$(CC) $(LDFLAGS) -o $(BINDIR)/$(TARGET) $(OBJS)

# Compilar los archivos en c
$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo
	@echo Compilando $^
	@$(CC) $(CFLAGS) -c -o $@ $^

# Imprimir la información del tamaño
size: $(BINDIR)/$(TARGET)
	@echo
	$(SIZE) $^

# Limpiar código
clean:
	@echo
	@echo "Limpiando..."
	@rm -rf $(BINDIR) $(BUILDDIR) $(OBJS) $(TARGET) $(TARGET).* *.a *.o *~
	@echo
	@echo "Limpieza terminada!"

# Clean debe ser phony tal que make nunca salga de ejecución como un archivo
.PHONY: clean
