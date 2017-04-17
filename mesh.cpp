#include "mesh.h"

mesh::mesh()
{
	this->rows = 6;
	this->col = 6;
	this->rowDepth = 1;
	this->colDepth = 1;
	this->colorMesh = vec3(0, 0.5, 0);
	this->colorSolid = vec3(1, 0, 0);

}

mesh::mesh(int row, int col, int rowDepth, int colDepth)
{
	this->rows = row;
	this->col = col;
	this->rowDepth = rowDepth;
	this->colDepth = colDepth;
	this->colorMesh = vec3(0, 0.5, 0);
	this->colorSolid = vec3(1, 0, 0);
}
