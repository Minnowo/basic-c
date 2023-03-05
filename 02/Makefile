
all: opengltest structs


# # these are for using X11 and imlib2 
# gcc opengltest.c -o opengltest.o -lglut -lGLU -lGL -L /usr/X11R6/lib -lX11 -lImlib2 -lglut -lGLU -lGL

opengltest:

	gcc opengltest.c -o opengltest.o -lglut -lGLU -lGL

structs:
	gcc structs.c -o structs.o

clean:
	rm opengltest.o structs.o
