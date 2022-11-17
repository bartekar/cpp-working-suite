#include "data.h"
#include <csignal>
#include <cmath>
#include <iostream>

using namespace std;

Point::Point(float x, float y)
{
	this->x = x;
	this->y = y;
	this->len = std::sqrt(x * x + y * y);
};

Point::~Point()
{
};

void Point::print(void)
{
	std::cout << "x: " << x << " y: " << y << endl;
};

float Point::length(void)
{
	return this->len;
};


float Point::dot(Point* a)
{
	float dotProduct= x * a->x + y * a->y;
	return dotProduct;
};

void Point::scale(float factor)
{
	x *= factor;
	y *= factor;
	len *= factor;
};

void Point::add(Point* a, Point* b, Point* res)
{
	res->x = a->x + b->x;
	res->y = a->y + b->y;
	res->len = std::sqrt(res->x * res->x + res->y * res->y);
}

void Point::sub(Point* a, Point* b, Point* res)
{
	res->x = a->x - b->x;
	res->y = a->y - b->y;
	res->len = std::sqrt(res->x * res->x + res->y * res->y);
}


BBox::BBox(float cx, float cy, float width, float height, float phi)
{
	this->cx = cx;
	this->cy = cy;
	this->width = width;
	this->height = height;
	this->phi = phi;
};

BBox::~BBox()
{
};

float BBox::area()
{
	return width * height;
}

bool BBox::containsPoint(Point* p)
{
	float w2 = width / 2.0f;
	float h2 = height / 2.0f;
	float sinPhi = sin(phi);
	float cosPhi = cos(phi);

	Point pA = Point(cosPhi * (-w2) - sinPhi * (-h2) + cx, sinPhi * (-w2) + cosPhi * (-h2) + cy);
	Point pB = Point(cosPhi * (+w2) - sinPhi * (-h2) + cx, sinPhi * (+w2) + cosPhi * (-h2) + cy);
	Point pC = Point(cosPhi * (+w2) - sinPhi * (+h2) + cx, sinPhi * (+w2) + cosPhi * (+h2) + cy);
	Point pD = Point(cosPhi * (-w2) - sinPhi * (+h2) + cx, sinPhi * (-w2) + cosPhi * (+h2) + cy);
	
	pA.print();
	pB.print();
	pC.print();
	pD.print();

	Point pAB = Point(0.0f, 0.0f);
	Point::sub(&pB, &pA, &pAB);
	Point pAP = Point(0.0f, 0.0f);
	Point::sub(p, &pA, &pAP);
	Point pAD = Point(0.0f, 0.0f);
	Point::sub(&pD, &pA, &pAD);

	cout << "pAB ";
	pAB.print();
	cout << "pAP ";
	pAP.print();
	cout << "pAD ";
	pAD.print();

	// 0 <= AB dot AP <= AB dot AB and 0 <= AD dot AP <= AD dot AD
	cout << pAB.dot(&pAP) << endl;
	cout << pAB.dot(&pAB) << endl;
	cout << pAD.dot(&pAP) << endl;
	cout << pAD.dot(&pAD) << endl;
	if ( (0 <= pAB.dot(&pAP)) && (pAB.dot(&pAP) <= pAB.dot(&pAB)) && (0 <= pAD.dot(&pAP)) && (pAD.dot(&pAP) <= pAD.dot(&pAD)) )
		return true;

	return false;
}

bool intersectsBBox(BBox*)
{
	raise(SIGINT);
	return false;
}

bool containsBBox(BBox*)
{
	raise(SIGINT);
	return false;
}
