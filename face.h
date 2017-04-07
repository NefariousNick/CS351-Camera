#pragma once

#include "algebra3.h"
//#include "gVector.h"
//#include "gMatrix.h"

// Simple class for hold face data
class Face{
	private:
		mat4 points;
	public:
		//Face(const gVector& v1, const gVector& v2, const gVector& v3, const gVector& v4):points(3, 4){
		Face(const vec4& v1, const vec4& v2, const vec4& v3, const vec4& v4):points(3, 4, 0, 0){
			points[0] = v1;
			points[1] = v2;
			points[2] = v3;
			points[3] = v4;
			points = points.transpose();
			
			/*points[0][0] = v1[0];
			points[1][0] = v1[1];
			points[2][0] = v1[2];
			points[0][1] = v2[0];
			points[1][1] = v2[1];
			points[2][1] = v2[2];
			points[0][2] = v3[0];
			points[1][2] = v3[1];
			points[2][2] = v3[2];
			points[0][3] = v4[0];
			points[1][3] = v4[1];
			points[2][3] = v4[2];
			*/
		}
		const mat4 getPoints(){
			return points;
		}
		const vec4 getNormal(){
			vec3 r = -1 * (points.getCol(1) - points.getCol(0)) ^ (points.getCol(2) - points.getCol(1));
			//gVector r = -1*(points.getCol(1)-points.getCol(0))^(points.getCol(2)-points.getCol(1));
			return r/r.length();
	}
};