#include <math.h>
//#include "gMatrix.h"
//#include "gVector.h"
#include "algebra3.h"
#include <iostream>

// A class for storing camera transforms
class Camera {
	private:
		mat4 rot;				//gMatrix rot;	// Current rotation matrix 
		vec3 up;				//gVector up;	// Current up vector
		vec3 eye;				//gVector eye;	// Current eye/camera position
	public:
		Camera(float r, float y, float x);
		void increasePhi(float inc);		// increase the phi angle. Note a negative value will decrease it. 
		void increaseTheta(float inc);		// increase the theta angle
		void increaseRad(float inc);	// increase the radius
		const vec3 getEye();//const gVector getEye();	// get the current eye position
		const vec3 getUp();//const gVector getUp();		// get the current up vector
		const mat4 getRotation();
};
