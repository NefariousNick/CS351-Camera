// Implementation of the MyGLWidget class
// Your scene graph will be created and called from here and OpenGL calls to display it. 

#include <QtWidgets>
#include <QtOpenGL>  // Note that some of the OpenGL calls are Qt specific and not standard OpenGL

#include "myglwidget.h"
#include "window.h"
#include <GL/glu.h>

MyGLWidget::MyGLWidget(QWidget *parent)					 // Constructor 
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)   // Call to parent constructor
{
	win = (Window*)parent;  // casting parent to type Window (which it is)

	cam = new Camera(4, 0, 0); // Create the 3D camera
	
}

MyGLWidget::~MyGLWidget()	// Destructor
{
	
}

////////////////////////////////////////////////////////////////////////////
// A few more Qt methods that you don't need to worry about yet. 
QSize MyGLWidget::minimumSizeHint() const
{
    return QSize(50, 50);
}

QSize MyGLWidget::sizeHint() const
{
    return QSize(400, 400);
}

static void qNormalizeAngle(int &angle)
{
    while (angle < 0)
        angle += 360 * 16;
    while (angle > 360)
        angle -= 360 * 16;
}
///////////////////////////////////////////////////////////////////////////////


// Initializing OpenGL
void MyGLWidget::initializeGL()
{
	qglClearColor(Qt::darkBlue);	// Set the background color. Note this isn't standard OpenGL. It's Qt. 

}

// This method gets called whenever the widget needs updating. 
void MyGLWidget::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT); // Clear the window using the background color set in initialization
 
    draw();

}

// YOUR CODE GOES IN THIS DRAW METHOD
// Actual code for drawing the primitives
void MyGLWidget::draw()
{
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	vec3 tempUp = cam->getUp();
	vec3 tempEye = cam->getEye();

	// set the camera
	gluLookAt(	tempEye[0], tempEye[1], tempEye[2], 
				0, 0, 0,
				tempUp[0], tempUp[1], tempUp[2]);


	for (int i = 0; i < win->numPolys(); i++) {

		if (i == win->getSelected())
			glColor3f(1, 0, 0);
		else
			glColor3f(0, 0, 1);

		mat4 tempM4 = mat4(win->getPoly(i));

		tempM4 = win->rotateMatrix * tempM4;

		vec4 v1 = tempM4.getCol(0);//gVector v1 = d->getPoly(i).getCol(0);
		vec4 v2 = tempM4.getCol(1);//gVector v2 = d->getPoly(i).getCol(1);
		vec4 v3 = tempM4.getCol(2);//gVector v3 = d->getPoly(i).getCol(2);
		vec4 v4 = tempM4.getCol(3);//gVector v4 = d->getPoly(i).getCol(3);




		glBegin(GL_QUADS);
		glVertex3f(v1[0], v1[1], v1[2]);
		glVertex3f(v2[0], v2[1], v2[2]);
		glVertex3f(v3[0], v3[1], v3[2]);
		glVertex3f(v4[0], v4[1], v4[2]);
		glEnd();

		glColor3f(1, 1, 1);			// outline the faces so that they are easier to see
		glBegin(GL_LINE_LOOP);
		glVertex3f(v1[0], v1[1], v1[2]);
		glVertex3f(v2[0], v2[1], v2[2]);
		glVertex3f(v3[0], v3[1], v3[2]);
		glVertex3f(v4[0], v4[1], v4[2]);
		glEnd();
	}

}

/////////////////////////////////////////////////////////////////
// More Qt methods that you do not have to worry about just now
void MyGLWidget::resizeGL(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(-10, 10, -10, 10, -5, 5);  // left, right, bottom, top, near, far
	gluPerspective(90, 1, 0.1, 10);		// experiment with these settings to see their effects
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClearColor(0, 0, 0, 0);
	glEnable(GL_DEPTH_TEST);
	
}

void MyGLWidget::mousePressEvent(QMouseEvent *event)
{
    
}

void MyGLWidget::mouseMoveEvent(QMouseEvent *event)
{
   
}

//////////////////////////////////////////////////////////////////////////
