#include "eController.h"
#include <iostream>


Controller::Controller(Window* window){	
	// Create a cube
	//faces.push_back(new Face(gVector(-1, 1, -1), gVector(-1, -1, -1), gVector(1, -1, -1), gVector(1, 1, -1))); // order is important
	//faces.push_back(new Face(gVector(-1, 1, 1), gVector(-1, 1, -1), gVector(1, 1, -1), gVector(1, 1, 1)));
	//faces.push_back(new Face(gVector(1, 1, 1), gVector(1, 1, -1), gVector(1, -1, -1), gVector(1, -1, 1)));
	//faces.push_back(new Face(gVector(-1, -1, 1), gVector(-1, 1, 1), gVector(1, 1, 1), gVector(1, -1, 1)));
	//faces.push_back(new Face(gVector(-1, -1, -1), gVector(-1, -1, 1), gVector(1, -1, 1), gVector(1, -1, -1)));
	//faces.push_back(new Face(gVector(-1, 1, -1), gVector(-1, 1, 1), gVector(-1, -1, 1), gVector(-1, -1, -1)));
/*
	Face* temp = new Face(vec4(0, 0, 0, 0), vec4(3, 0, 0, 0), vec4(3, 3, 0, 0), vec4(0, 3, 0, 1));
	faces.push_back(temp);
	Face* temp2 = new Face(vec4(3, 0, 0, 0), vec4(3, 0, 3, 0), vec4(3, 3, 3, 0), vec4(3, 3, 0, 1));
	faces.push_back(temp2);
	Face* temp3 = new Face(vec4(3, 0, 3, 0), vec4(0, 0, 3, 0), vec4(0, 3, 3, 0), vec4(3, 3, 3, 1));
	faces.push_back(temp3);
	Face* temp4 = new Face(vec4(0, 0, 3, 0), vec4(0, 0, 0, 0), vec4(0, 3, 0, 0), vec4(0, 3, 3, 1));
	faces.push_back(temp4);
	Face* temp5 = new Face(vec4(0, 3, 0, 0), vec4(3, 3, 0, 0), vec4(3, 3, 3, 0), vec4(0, 3, 3, 1));
	faces.push_back(temp5);
	Face* temp6 = new Face(vec4(0, 0, 0, 0), vec4(3, 0, 0, 0), vec4(3, 0, 3, 0), vec4(0, 0, 3, 1));
	faces.push_back(temp6);
*/
	parser("sampleInput.txt", &faces);		// Will load a model from a file
	selected = 0;								// Start with the zero-ith face selected
	win = window; 

	win->setController(this);  // Now the window class has access to the controller and vice versa 
	
	win->updateBrowser();
	win->updateDrawing();
}

Controller::~Controller(){};

const int Controller::numPolys(){							// Get the number of faces
	return faces.size();
}
//const gMatrix Controller::getPoly(int i) {					// Get a certain face
const mat4 Controller::getPoly(int i){					// Get a certain face
	return faces[i]->getPoints();
}
const int Controller::getSelected(){						// Get which face has been selected
	return selected;
}
void Controller::select(int i){								// Set the selected face
	selected = i; 
	win->updateDrawing();
}

void Controller::extrudeSelected(float depth){				// Do an extrusion
	int sel = getSelected();
	//gMatrix points = faces[sel]->getPoints();
	mat4 points = faces[sel]->getPoints();

	Face *f = faces[sel];
	faces.erase(faces.begin() + sel);
//	gVector v1New = depth * f->getNormal() + points.getCol(0);
//	gVector v2New = depth * f->getNormal() + points.getCol(1);
//	gVector v3New = depth * f->getNormal() + points.getCol(2);
//	gVector v4New = depth * f->getNormal() + points.getCol(3);
	vec4 v1New = depth * f->getNormal() + points.getCol(0);
	vec4 v2New = depth * f->getNormal() + points.getCol(1);
	vec4 v3New = depth * f->getNormal() + points.getCol(2);
	vec4 v4New = depth * f->getNormal() + points.getCol(3);
	faces.push_back(new Face(points.getCol(0), points.getCol(1), v2New, v1New));
	faces.push_back(new Face(points.getCol(1), points.getCol(2), v3New, v2New ));
	faces.push_back(new Face(points.getCol(2), points.getCol(3), v4New, v3New ));
	faces.push_back(new Face(points.getCol(3), points.getCol(0), v1New, v4New));
	faces.push_back(new Face(v1New, v2New, v3New, v4New));
	win->updateBrowser();
	win->updateDrawing();
	delete f;
}
