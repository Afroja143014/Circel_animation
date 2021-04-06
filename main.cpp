#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include <windows.h>
#include <glut.h>
#define pi (2*acos(0.0))


double angle;
double cx=0, cy=0;
double incx=0, incy=0;
bool Play=true;


int state;
struct point
{
	double x,y,z;
};

void keyboardListener(unsigned char key, int x,int y){
	switch(key){

        case '1':
            // code animating
             angle+=0.5;
            break;
        case '2':
            angle-=0.5;
            break;
        case '3':
          cx+=40;
          cy+=40;
            break;
        case '4':
             cx-=40;
          cy-=40;
            break;
        case 'w':
            incx+=1;
            break;
        case 'd':
            //code
            break;

		default:
			break;
	}
}

void specialKeyListener(int key, int x,int y){
	switch(key){
		case GLUT_KEY_DOWN:		//down arrow key
			break;
		case GLUT_KEY_UP:		// up arrow key
			break;

		case GLUT_KEY_RIGHT:
			break;
		case GLUT_KEY_LEFT:
			break;

		case GLUT_KEY_PAGE_UP:
			break;
		case GLUT_KEY_PAGE_DOWN:
		    //code
			break;

		case GLUT_KEY_INSERT:
			break;

		case GLUT_KEY_HOME:
			break;
		case GLUT_KEY_END:
			break;

		default:
			break;
	}
}


void draw_tri()
{
    glBegin(GL_POLYGON);
        glVertex2f(10, 10);
        glVertex2f(10, 0);
        glVertex2f(-10, 0);
          glVertex2f(0, 0);
    glEnd();
}
void push_pop(void)
{
    glPushMatrix();
        //glRotatef(45, 0, 0, 1);

        glPushMatrix(); // Furthest Triangle, Draw first
            //glRotatef(45, 0, 0, 1);
            glTranslatef(-20, 0, 0);
            //glScaled(2, 1, 0);
            glColor3f(0.0, 0.0, 1.0);
            draw_tri();

        glPopMatrix();

        glPushMatrix(); // Middle Triangle, Draw 2nd
            glTranslatef(0, 20, 0);
            glColor3f(0.0, 1.0, 0.0);
            draw_tri();
        glPopMatrix();

        glPushMatrix(); // Nearest Triangle, Draw last
            glTranslatef(20, 0, 0);
            glColor3f(1.0, 0.0, 0.0);
            draw_tri();
        glPopMatrix();


    glPopMatrix();

}


void drawAxes()
{

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);{
        glVertex3f( 100,0,0);
        glVertex3f(-100,0,0);

        glVertex3f(0,-100,0);
        glVertex3f(0, 100,0);

        glVertex3f(0,0, 100);
        glVertex3f(0,0,-100);
    }glEnd();

}


void drawGrid()
{
	int i;

    glColor3f(0.6, 0.6, 0.6);	//grey
    glBegin(GL_LINES);{
        for(i=-8;i<=8;i++){

            if(i==0)
                continue;	//SKIP the MAIN axes

            //lines parallel to Y-axis
            glVertex3f(i*10, -90, 0);
            glVertex3f(i*10,  90, 0);

            //lines parallel to X-axis
            glVertex3f(-90, i*10, 0);
            glVertex3f( 90, i*10, 0);
        }
    }glEnd();

}

void drawSquare(double a)
{
    //glColor3f(1.0,0.0,0.0);
	glBegin(GL_QUADS);{
		glVertex3f( a, a,2);
		glVertex3f( a,-a,2);
		glVertex3f(-a,-a,2);
		glVertex3f(-a, a,2);
	}glEnd();
}


void drawCircle(float radius_x, float radius_y)
{
	int i = 0;
	float angle = 0;



	glBegin(GL_POLYGON);
    {
		for(i = 0; i < 100; i++)
		{
			angle =  (3.1416/2) * i / 100;

			glColor3f(1.0, 0, 0);
            glVertex3f (cos(angle) * radius_x, sin(angle) * radius_y, 0);

		}

    }
	glEnd();
}
void rec_animation()
{
    glColor3f(0,1,0);
    //glRotatef(5*angle,0,0,1);

    glTranslatef(incx,incy,0);

    glRotatef(50*angle,0,0,1);
    drawSquare(1);

}
void draw_rec()
{

    drawSquare(5);

}
void drawSS()
{
    glColor3f(1,0,0);
    drawSquare(20);
    //glPushMatrix();
    glRotatef(angle,0,0,1);
    glTranslatef(110,0,0);
    glRotatef(2*angle,0,0,1);
    glColor3f(0,1,0);
    drawSquare(15);
    //glPopMatrix();

    glRotatef(angle,0,0,1);
    glTranslatef(60,0,0);
    glRotatef(2*angle,0,0,1);
    glColor3f(0,0,1);
    drawSquare(10);




}

void simple_trans()
{


    /*glTranslatef(0, 20, 0);
    glPushMatrix();

        glRotatef(45, 0, 0, 1);

        //glColor3f(0.0, 0.0, 1.0);
        draw_rec();



        glPushMatrix();
            glTranslatef(-20, 0, 0);
                //glRotatef(45, 0, 0, 1);
            glColor3f(0.0, 1.0, 0.0);
            draw_rec();
        glPopMatrix();

    glPopMatrix();


    //glRotatef(45, 0, 0, 1);*/
    glTranslatef(incx, incy, 0);
    glColor3f(1.0, 0.0, 0.0);
    draw_rec();

}
double curve_by_points()
{
    ///
}
double func(double x)
{
    return x*x;
}
void curve()
{
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_LINES);
    for(double i =-180; i<180;i+=.5)
    {
        glVertex2d(i,10*func(i));
        glVertex2d(i+.5, 10*func(i+.5));
    }
     // It can be any type Gl_POINT,_LINE
    glEnd();

}
void   c1(GLfloat rx,GLfloat ry,GLfloat cx,GLfloat cy )
{
  glBegin(GL_TRIANGLE_FAN); // DRAWING 3 SIDED TRIANGLE
  glColor3f(1.0, 0.0, 0.0);
  glVertex2f( cx,cy);
 for(int i=0;i<100;i++)
 {
     float angle=2.0f*3.1416*i/398;
     float x=rx*cosf(angle);
     float y=ry*sinf(angle);
  glVertex2d((x+cx),(y+cy));

 }

glEnd();

}
void   c2(GLfloat rx,GLfloat ry,GLfloat cx,GLfloat cy )
{
  glBegin(GL_TRIANGLE_FAN); // DRAWING 3 SIDED TRIANGLE
     glColor3f(0.0, 1.0, 0.0);
  glVertex2f( cx,cy);
 for(int i=0;i<100;i++)
 {
     float angle=2.0f*3.1416*i/398;
     float x=rx*cosf(angle);
     float y=ry*sinf(angle);
  glVertex2d((x+cx),(y+cy));

 }

glEnd();

}
void   c3(GLfloat rx,GLfloat ry,GLfloat cx,GLfloat cy )
{
  glBegin(GL_TRIANGLE_FAN); // DRAWING 3 SIDED TRIANGLE
     glColor3f(1.0, 0.0, 0.0);
  glVertex2f( cx,cy);
 for(int i=0;i<100;i++)
 {
     float angle=2.0f*3.1416*i/398;
     float x=rx*cosf(angle);
     float y=ry*sinf(angle);
  glVertex2d((x+cx),(y+cy));

 }

glEnd();

}
void   c4(GLfloat rx,GLfloat ry,GLfloat cx,GLfloat cy )
{
  glBegin(GL_TRIANGLE_FAN); // DRAWING 3 SIDED TRIANGLE
     glColor3f(0.0, 1.0, 0.0);
  glVertex2f( cx,cy);
 for(int i=0;i<100;i++)
 {
     float angle=2.0f*3.1416*i/398;
     float x=rx*cosf(angle);
     float y=ry*sinf(angle);
  glVertex2d((x+cx),(y+cy));

 }

glEnd();

}


void display(){

	//clear the display
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0,0,0,0);	//color black
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



	glMatrixMode(GL_MODELVIEW);


	glLoadIdentity();


	gluLookAt(0,0,100,	0,0,0,	0,1,0);



	glMatrixMode(GL_MODELVIEW);

	drawAxes();
	//drawGrid();
	//drawCircle(30, 30);
    //simple_trans();
    //push_pop();
    //rec_animation();

    //ADD this line in the end --- if you use double buffer (i.e. GL_DOUBLE)

    glPushMatrix();
    glRotatef(angle, 0, 0, 1);
    glTranslatef(cx, cy, 0);
    c1(25,25,0,0);
    glPopMatrix();
    //........c2...........
    glPushMatrix();
    glRotatef(angle, 0, 0, 1);
    glTranslatef(-cx, cy, 0);
    c2(-25,25,0,0);
     glPopMatrix();
     //........c3..........

     glPushMatrix();
     glRotatef(angle, 0, 0, 1);
     glTranslatef(-cx, -cy, 0);
     c3(-25,-25,0,0);
     glPopMatrix();
     //...........c4..............

     glPushMatrix();
     glRotatef(angle, 0, 0, 1);
     glTranslatef(cx, -cy, 0);
     c4(25,-25,0,0);
     glPushMatrix();
     //...............
	glutSwapBuffers();
	glFlush();
}


void animate(){
    //rotation
    /*/angle+=0.01;
    //incy = 10*sin(angle);
    //incx+=0.01;
    //incy+=0.05;


	//codes for any changes in Models, Camera
	//linear_oscillation

    if(state ==0 && incx>50){ state =1;}
    if(state ==1 && incx <-50){state =0;}

    if(state == 0) incx+=0.05;
    else incx-=0.05;//*/

	glutPostRedisplay();
}

void init(){
	//codes for initialization
	angle=0;

	//clear the screen
	glClearColor(0,0,0,0);


	//load the PROJECTION matrix
	glMatrixMode(GL_PROJECTION);

	//initialize the matrix
	glLoadIdentity();

	//give PERSPECTIVE parameters
	gluPerspective(80,	1,	1,	1000.0);

}

int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);	//Depth, Double buffer, RGB color

	glutCreateWindow("My OpenGL Program");

	init();

	glEnable(GL_DEPTH_TEST);	//enable Depth Testing

	glutDisplayFunc(display);	//display callback function
	glutIdleFunc(animate);		//what you want to do in the idle time (when no drawing is occuring)

	glutKeyboardFunc(keyboardListener);
	glutSpecialFunc(specialKeyListener);
	//glutMouseFunc(mouseListener);

	glutMainLoop();		//The main loop of OpenGL

	return 0;
}

