#pragma once

#include "algebra3.h"
#include <vector>

class mesh {
public:
	mesh();
	mesh(int row, int col, int rowDepth, int colDepth);

	int rows;
	int col;
	int rowDepth;
	int colDepth;

	vec3 colorMesh;
	vec3 colorSolid;

	vector<vec3> tempPoints;	//temporary points
	vector<vector<vec3>> points;	//vector of vector of vec3's

	bool highlight = false;
	bool madeMesh = false;
	bool randomField = false;

};