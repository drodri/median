#pragma once

struct Point2d{
	Point2d(float x_, float y_): x(x_), y(y_){}
	float x;
	float y;
};

Point2d sin_signal(float A=1.0f, float step=0.1f);
Point2d add_noise(Point2d v, float amount=0.10f);