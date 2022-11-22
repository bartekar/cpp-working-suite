#ifndef DATA_H
#define DATA_H

class Point
{
public:
	Point(float, float);
	~Point();
	void print(void);
	float length(void);
	float dot(Point*);
	void scale(float);
	

	static void add(Point*, Point*, Point*);
	static void sub(Point*, Point*, Point*);
private:
	float x = 0.0f;
	float y = 0.0f;
	float len = -1.0f;
};

class BBox
{
public:
	BBox(float cx, float cy, float width, float height, float phi);
	~BBox();
	float area();
	bool containsPoint(Point*);
        bool intersectLine(Point*, Point*);
	bool intersectsBBox(BBox*);
	bool containsBBox(BBox*);
private:
	float cx;
	float cy;
	float width;
	float height;
	float phi;
};

#endif /* DATA_H */