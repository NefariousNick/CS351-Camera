// window.h
// The Window class has the main Qt components and links together the GUI with your scene graph

#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QtWidgets>
#include <QSlider>
#include <algebra3.h>
//#include "gMatrix.h"
#include "eController.h"

class Data;  // forward declaration of my simple little data class
class Controller; 

namespace Ui {
class Window;
}

class Window : public QWidget
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = 0);
    ~Window();
	void updateBrowser();											// update the browser
	void select(int selected);			// set the selection
	void updateDrawing();				// redraw the OpenGL window
	const int numPolys();											// get the number of faces
//	const gMatrix getPoly(int i);									// get a face
	const mat4 getPoly(int i);									// get a face
	const int getSelected();										// get the index of the face selected
	const float getExtrude();
	void setController(Controller* c); 
	mat4 rotateMatrix = mat4(1, 1, 1, 1);
	
protected:
    void keyPressEvent(QKeyEvent *event);
	void mousePressEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent *event);

	signals:
	
public slots :
	void on_treeWidget_currentItemChanged(int value);  // Called when a different item in the tree view is selected. 
    void on_horizontalSlider_valueChanged(int value); // Called when the slider is slid. 
	void on_clicked_extrudeButton();
		
private:
    Ui::Window *ui;				// A Qt internal mechanism
	Controller* controller;		// Pointer to the controller
	QPoint lastPos;				// For mouse movement
	
};

#endif // WINDOW_H
