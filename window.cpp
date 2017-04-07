//Demonstrating connecting the Qt Tree View widget to another class (like a scene graph)

#include <iostream>
#include <sstream>
#include <string>
#include "window.h"
#include "ui_window.h"

#include "myglwidget.h"


Window::Window(QWidget *parent) :  // Window constructor
    QWidget(parent),
    ui(new Ui::Window)
{
	ui->setupUi(this);				// Standard Qt stuff

	ui->horizontalSlider->setMinimum(0); ui->horizontalSlider->setMaximum(5); ui->horizontalSlider->setSingleStep(1);

	connect(ui->listWidget, &QListWidget::currentRowChanged, this, &Window::on_treeWidget_currentItemChanged);
	connect(ui->horizontalSlider, &QSlider::valueChanged, this, &Window::on_horizontalSlider_valueChanged);
	connect(ui->extrudeButton, &QPushButton::clicked, this, &Window::on_clicked_extrudeButton);
}

Window::~Window()
{
    delete ui;
}

void Window::keyPressEvent(QKeyEvent *e)  // If the user hits esc, close the program. 
{
    if (e->key() == Qt::Key_Escape)
        close();
	else if (e->key() == Qt::Key_A)
	{
		ui->myGLWidget->cam->increasePhi(-7);
		ui->myGLWidget->update();
	}
	else if (e->key() == Qt::Key_D)
	{
		ui->myGLWidget->cam->increasePhi(7);
		ui->myGLWidget->update();
	}
	else if (e->key() == Qt::Key_W)
	{
		ui->myGLWidget->cam->increaseTheta(-7);
		ui->myGLWidget->update();
	}
	else if (e->key() == Qt::Key_S)
	{
		ui->myGLWidget->cam->increaseTheta(7);
		ui->myGLWidget->update();
	}
	else if (e->key() == Qt::Key_E)
	{
		ui->myGLWidget->cam->increaseRad(-0.5);
		ui->myGLWidget->update();
	}
	else if (e->key() == Qt::Key_F)
	{
		ui->myGLWidget->cam->increaseRad(0.5);
		ui->myGLWidget->update();
	}
    else
        QWidget::keyPressEvent(e);
}
void Window::mousePressEvent(QMouseEvent* event)
{
	lastPos = event->pos();
}

void Window::mouseMoveEvent(QMouseEvent *event)
{
	int dx = event->x() - lastPos.x();
	int dy = event->y() - lastPos.y();

	if (event->buttons() & Qt::LeftButton) {
		ui->myGLWidget->cam->increasePhi(dx);
		ui->myGLWidget->cam->increaseTheta(dy);
	}
	else if (event->buttons() & Qt::RightButton) {
		ui->myGLWidget->cam->increasePhi(dx);
		ui->myGLWidget->cam->increaseTheta(dy);
	}

	lastPos = event->pos();
}

void Window::setController(Controller* c)
{
	this->controller = c; 
}

void Window::updateBrowser()		// update the face browser
{
	for (int i = ui->listWidget->count(); i < controller->numPolys(); i++)
	{
		ui->listWidget->addItem("Face"); 
	}
}

void Window::select(int selected) 		// set the selection
{
	QListWidgetItem *item = ui->listWidget->item(selected);
	ui->listWidget->setCurrentItem(item);
}

void Window::updateDrawing() 			// redraw the OpenGL window
{
	ui->myGLWidget->update(); 
}


const int Window::numPolys()			// get the number of faces
{
	return controller->numPolys();
}

//const gMatrix Window::getPoly(int i)			// get a face
const mat4 Window::getPoly(int i)			// get a face

{
	return controller->getPoly(i);
}

const int Window::getSelected()					// get the index of the face selected
{
	return controller->getSelected();
}

const float Window::getExtrude()			  // return the distance to extrude to. 
{
	return ui->horizontalSlider->value();
}

void Window::on_treeWidget_currentItemChanged(int value)
{
	controller->select(value); //  ui->listWidget->currentRow());
}

void Window::on_horizontalSlider_valueChanged(int value)
{
	// not doing anything interactive with the slider. See getExtrude
}

void Window::on_clicked_extrudeButton()
{
	controller->extrudeSelected(this->getExtrude());
}
