# compiler
CC = gcc

DEBUG = no

ifeq ($(DEBUG),yes)
  CFLAGS  = -g -Wpointer-arith -Wall -std=c17
else
  CFLAGS  = -O2 -std=c17
endif

lib = $(libG3X) $(DBG_LIB)
inc = -I./include $(incG3X)
src = src/

# cible pour les binaires (.a,.so)
obj = obj/

str = structure/
sha = shape/

struct = $(obj)Shape.o $(obj)Tree.o $(obj)Display.o
shape = $(obj)Cone.o $(obj)Cube.o $(obj)Cylinder.o $(obj)Sphere.o $(obj)Torus.o

all:
	@mkdir -p $(obj)
	@make --no-print-directory adaptation_camera
	@make --no-print-directory homothetie 
	@make --no-print-directory salon 

adaptation_camera : $(struct) $(shape)
homothetie : $(struct) $(shape)
salon : $(struct) $(shape)

# règle générique de création de xxx.o à partir de src/structure/xxx.c
$(obj)%.o : $(src)$(str)/%.c
	@echo "module $@"
	@$(CC) $(CFLAGS) $(inc) -c $< -o $@

# règle générique de création de xxx.o à partir de src/shape/xxx.c
$(obj)%.o : $(src)$(sha)%.c
	@echo "module $@"
	@$(CC) $(CFLAGS) $(inc) -c $< -o $@

# règle générique de création de xxx.o à partir de src/xxx.c
$(obj)%.o : $(src)%.c
	@echo "module $@"
	@$(CC) $(CFLAGS) $(inc) -c $< -o $@

# règle générique de création de l'executable xxx à partir de src/xxx.c (1 seul module)
% : $(obj)%.o
	@echo "------------------------"
	@echo "assemblage [$^]->$@"
	@$(CC) $^ $(lib) -o $@
	@echo "------------------------"

.PHONY : clean ?

# informations sur les paramètres de compilation
? :
	@echo "---------compilation informations----------"
	@echo "  processor      : $(PROCBIT)"
	@echo "  compiler       : $(CC)"
	@echo "  options        : $(CFLAGS)"
	@echo "  lib g3Ox/OpenGl : $(libG3X)$(COMP)"
	@echo "  headers        : $(incG3X)"

clean :
	@rm -rf $(obj)
cleanall :
	@rm -rf $(obj) adaptation_camera salon homothetie

