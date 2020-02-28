//assignment 2
// g++ main.c -lglut -lGL -lGLEW -lGLU -o example
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <math.h>
#include <stdio.h>
#define pf printf 
#define sf scanf 
int r,xc,yc;
void bresenham(int x1,int y1,int x2,int y2);
void bre_circle( int r);
void mid_circle(int radius);
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
    
    bresenham(xc-r*1.732, yc-r, xc+r*1.732, yc-r);
    bresenham(xc, yc+2*r, xc+r*1.732, yc-r);
    bresenham(xc-r*1.732, yc-r, xc, yc+2*r);
	bre_circle(r);
	mid_circle(2*r);
    glFlush();
}
void draw_pixel(int x,int y)
{
	glBegin(GL_POINTS);
        glVertex2i(x,y);
    glEnd();
}
void mid_circle(int radius)
{
	int x = radius;
	int y = 0;
	int pk = 1-radius;
	while(x > y)
	{
		draw_pixel(x+xc,y+yc);
	    draw_pixel(-x+xc,-y+yc);
	    draw_pixel(-x+xc,y+yc);
	    draw_pixel(x+xc,-y+yc);
	    draw_pixel(y+xc,x+yc);
	    draw_pixel(-y+xc,-x+yc);
	    draw_pixel(y+xc,-x+yc);
	    draw_pixel(-y+xc,x+yc);
		y++;
		if(pk <= 0)
			pk = pk + 2*y + 1;
		else
		{
			x--;
			pk = pk + 2*y - 2*x + 1; 
		}
		
	}
}

void bre_circle( int r)
{
	int x1=0, y1=r;
	int d=3-2*r;
	while(x1<=y1)
	{
		draw_pixel(xc+x1, yc+y1);
		draw_pixel(xc+x1, yc-y1);
		draw_pixel(xc-x1, yc+y1);
		draw_pixel(xc-x1, yc-y1);
		draw_pixel(xc+y1, yc+x1);
		draw_pixel(xc+y1, yc-x1);
		draw_pixel(xc-y1, yc+x1);
		draw_pixel(xc-y1, yc-x1);
		if(d<=0)
		{
			x1++;
			d=d+4*x1+6;
		}
		else
		{
			x1++;
			y1--;
			d=d+4*(x1-y1)+10;
		}
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
    pf("\n\tEnter The Co-ordinates\n");
    pf("\tFirst Point : \n");
    pf("\tEnter Radius : ");
    scanf("%d",&r);
    pf("\tEnter XC and YC :");
    sf("%d%d",&xc,&yc);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(1024,768);
    glutInitWindowPosition(100,100);
    glutCreateWindow("OpenGL - First window demo");
    glutDisplayFunc(renderFunction);
    glutMainLoop();    
    return 0;
}
