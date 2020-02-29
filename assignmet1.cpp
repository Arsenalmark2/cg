//assignment 1
//Pattern
//g++ main.c -lglut -lGL -lGLEW -lGLU -o OpenGLExample
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <math.h>
#include <stdio.h>

int gX1,gX2,gY1,gY2;
float DDA(float x1,float y1,float x2,float y2);
void renderFunction()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    gluOrtho2D(-320,320,-240,240);
    glBegin(GL_LINES);
        glVertex2i(-320, 0);
        glVertex2i(320, 0);
        glVertex2i(0, -240);
        glVertex2i(0, 240);
    glEnd();
    
	DDA(gX1,gY1,gX2,gY1);
	DDA(gX2,gY1,gX2,gY2);
	DDA(gX2,gY2,gX1,gY2);
	DDA(gX1,gY2,gX1,gY1);
	int x3=(gX1+gX2)/2;
	int y3=gY2;
	
	int x4=gX2;
	int y4=(gY1+gY2)/2;
	
	int x5=x3;
	int y5=gY1;
	
	int x6=gX1;
	int y6=y4;
	
	int x7=(x3+x4)/2;
	int y7=(y3+y4)/2;
	
	int x8=(x4+x5)/2;
	int y8=(y4+y5)/2;
	
	int x9=(x5+x6)/2;
	int y9=(y5+y6)/2;
	
	int x10=(x3+x6)/2;
	int y10=(y3+y6)/2;
	
	DDA(x3,y3,x4,y4);
	DDA(x5,y5,x4,y4);
	DDA(x5,y5,x6,y6);
	DDA(x3,y3,x6,y6);
	
	DDA(x7,y7,x8,y8);
	DDA(x8,y8,x9,y9);
	DDA(x9,y9,x10,y10);
	DDA(x10,y10,x7,y7);
    glFlush();
}
void putpoint(int x,int y)
{
	glBegin(GL_POINTS);
        glVertex2i(x,y);
    glEnd();
}
float DDA(float x1,float y1,float x2,float y2)
{
	float dx=x2-x1;
	float dy=y2-y1;
	float steps=(abs(dx)>abs(dy))?abs(dx):abs(dy);
	float Xinc=(float)dx/steps;
	float Yinc=(float)dy/steps;
	putpoint(round(x1),round(y1));
	int i=0;
	while(i++<steps)
	{
		x1+=Xinc;
		y1+=Yinc;
		putpoint((int)round(x1),(int)round(y1));
	}
}
void bresenham(int x1,int y1,int x2,int y2)
{
	int dx, dy, i, p;
	int incx, incy, inc1, inc2;
	int x,y;
	dx = x2-x1;
	dy = y2-y1;
	if (dx < 0) dx = -dx;
	if (dy < 0) dy = -dy;
	incx = 1;
	if (x2 < x1) incx = -1;
	incy = 1;
	if (y2 < y1) incy = -1;
	x = x1; y = y1;
	if (dx > dy) {
		draw_pixel(x, y);
		p = 2 * dy-dx;
		inc1 = 2*(dy-dx);
		inc2 = 2*dy;
		for (i=0; i<dx; i++) {
			if (p > 0) {
				y += incy;
				p += inc1;
			}
			else
				p += inc2;
			x += incx;
			draw_pixel(x, y);
		}
	} else {
		draw_pixel(x, y);
		p = 2*dx-dy;
		inc1 = 2*(dx-dy);
		inc2 = 2*dx;
		for (i=0; i<dy; i++) {
			if (p > 0) {
				x += incx;
				p += inc1;
			}
			else
				p += inc2;
			y += incy;
			draw_pixel(x, y);
	}
}
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    scanf("%d",&gX1);
    scanf("%d",&gY1);
    scanf("%d",&gX2);
    scanf("%d",&gY2);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(1024,768);
    glutInitWindowPosition(100,100);
    glutCreateWindow("OpenGL - First window demo");
    glutDisplayFunc(renderFunction);
    glutMainLoop();    
    return 0;
}
