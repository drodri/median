#include "generator.h"
#include <math.h>
#include <stdlib.h>

Point2d sin_signal(float A, float step){
	static float angle = -3 * 3.14159f;
	angle += step;
	return Point2d(angle, A*sin(angle));
}
Point2d add_noise(Point2d v, float amount)
{
	return Point2d(v.x, v.y*(1 + (-amount/2.0f + amount*rand()/(float)RAND_MAX)));
}