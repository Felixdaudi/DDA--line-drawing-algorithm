/* DAUDI FELIX KOKI
SCT212-0062/2018 */

#include<stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

float x1,y3,x2,y4,m,i,j;
float dx,dy;
void display(void)
{
/* clear all pixels */
glClear (GL_COLOR_BUFFER_BIT);
/* draw white polygon (rectangle) with corners at
* (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
*/
glEnd();

glColor3f (1, 0, 0);
glBegin(GL_LINES);
//write your code here

if(m>0 && m<=1)
{
while(x1<=x2 && y3<=y4)
{
    x1=x1+1;
    y3=y3+m;
    glVertex3d(x1/100,y3/100,0.0);
   printf("%f %f",x1,y3);

}
}
else if(m>1)
{
    while(x1<=x2 && y3<=y4)
{
    x1=x1+(1/m);
    y3=y3+1;
   glVertex3d(x1/100,y3/100,0.0);
   printf("%f %f",x1,y3);
}
}

else if(m>-1 && m<=0)
{
    while(x1>=x2 && y3>=y4)
{
    x1=x1-1;
    y3=y3-m;
   glVertex3d(x1/100,y3/100,0.0);
   printf("%f %f",x1,y3);
}
}
else if(m<-1)

  {

    while(x1>=x2 && y3>=y4)
{
    x1=x1-(1/m);
    y3=y3-1;
    glVertex3d(x1/100,y3/100,0.0);
    printf("%f %f",x1,y3);
}
  }

glEnd();



glFlush ();
}
void init (void)
{
/* select clearing (background) color */
glClearColor (0.0, 0.0, 0.0, 0.0);
/* initialize viewing values */
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{

    
    printf("Enter value of X1 :");
    scanf("%f",&x1);
    printf("Enter value of y3 :");
    scanf("%f",&y3);
    printf("Enter value of X2 :");
    scanf("%f",&x2);
    printf("Enter value of y4 :");
    scanf("%f",&y4);
    dx=x2-x1;
    dy=y4-y3;
    m=dy/dx;


glutInit(&argc, argv);
/*initialise glut libarary*/
glutInitDisplayMode (GLUT_SINGLE);
/*initialize mode of display*/
glutInitWindowSize (400, 300); 
//screen size/window
glutInitWindowPosition (100, 100); 
//screen position
glutCreateWindow ("DDA");
//screen title
init ();
glutDisplayFunc(display);
glutMainLoop();
return 0; 
}

