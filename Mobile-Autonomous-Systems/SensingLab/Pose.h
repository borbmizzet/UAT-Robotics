#ifndef POSE_H
#define POSE_H

#pragma once

#include "Point.h"

struct Pose
{
	Point location;
	double headingInRadians;
};
#endif