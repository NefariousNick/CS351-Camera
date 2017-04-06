#include "camera.h"

Camera::Camera(float r, float phi, float theta){
			//rot = gMatrix::identityMatrix(4);
			//up = gVector(0, 1, 0, 0);
			//eye = gVector(0, 0, r, 1);

	rot = rotation3D(vec3(0, 1, 0), theta);//rotate by the theta value
	rot = rot * rotation3D(vec3(1, 0, 0), phi);//rotate by the phi value
	up = vec3(0, 1, 0);
	eye = vec3(0, 0, r);
					
}

void Camera::increasePhi(float inc){
	rot = rot * rotation3D(vec3(1, 0, 0), inc);
}

void Camera::increaseTheta(float inc){

	rot = rot * rotation3D(vec3(0, 1, 0), inc);
}


void Camera::increaseRad(float inc) {
	eye[2] += inc;
}

//const gVector Camera::getEye(){
const vec3 Camera::getEye() {
	return eye * rot;
}

//const gVector Camera::getUp(){
const vec3 Camera::getUp() {
	return up * rot;
}