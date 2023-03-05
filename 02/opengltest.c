// https://www3.ntu.edu.sg/home/ehchua/programming/opengl/cg_introduction.html
// https://cs.lmu.edu/~ray/notes/openglexamples/

#include <GL/gl.h>
#include <GL/glut.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Global variables
char	title[] = "Full-Screen & Windowed Mode"; // Windowed mode's title

GLubyte	fish[] = {
	0x00,
	0x60,
	0x01,
	0x00,
	0x00,
	0x90,
	0x01,
	0x00,
	0x03,
	0xf8,
	0x02,
	0x80,
	0x1c,
	0x37,
	0xe4,
	0x40,
	0x20,
	0x40,
	0x90,
	0x40,
	0xc0,
	0x40,
	0x78,
	0x80,
	0x41,
	0x37,
	0x84,
	0x80,
	0x1c,
	0x1a,
	0x04,
	0x80,
	0x03,
	0xe2,
	0x02,
	0x40,
	0x00,
	0x11,
	0x01,
	0x40,
	0x00,
	0x0f,
	0x00,
	0xe0,
};

/* Initialize OpenGL Graphics */
void	initGL(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0); // Set background (clear) color to black
}

void	display(void)
{
	// Clear the color buffer with current clearing color
	glClear(GL_COLOR_BUFFER_BIT);
	glBitmap(27, 11, 0, 0, 0, 0, fish);
	// Render now
	glFlush();
}

/* Callback handler for normal-key event */
void	keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27: // ESC key
		exit(0);
		break ;
	}
}

/* Callback handler for special-key event */
void	specialKeys(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_F1: // F1: Toggle between full-screen and windowed mode
		break ;
	case GLUT_KEY_RIGHT: // Right: increase x speed
		break ;
	case GLUT_KEY_LEFT: // Left: decrease x speed
		break ;
	case GLUT_KEY_UP: // Up: increase y speed
		break ;
	case GLUT_KEY_DOWN: // Down: decrease y speed
		break ;
	case GLUT_KEY_PAGE_UP: // Page-Up: increase ball's radius
		break ;
	case GLUT_KEY_PAGE_DOWN: // Page-Down: decrease ball's radius
		break ;
	}
}

/* Main function: GLUT runs as a console application starting at main() */
int	main(int argc, char **argv)
{
	// Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	// Create window with given title
	glutCreateWindow(title);
	// Register callback handler for window re-paint
	glutDisplayFunc(display);
	// First timer call immediately

	// Register callback handler for special-key event
	glutSpecialFunc(specialKeys);
	// Register callback handler for special-key event
	glutKeyboardFunc(keyboard);
	// Our own OpenGL initialization
	initGL();
	// Enter event-processing loop
	glutMainLoop();
	return (0);
}