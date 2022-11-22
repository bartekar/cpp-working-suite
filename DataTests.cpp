#include "Data.h"

#include <cmath>
#include <gtest/gtest.h>

const double PI = 2 * acos(0.0);

struct Box 
	: public ::testing::Test
{
	BBox* boxDiamond = nullptr;
	BBox* boxRect = nullptr;
	BBox* boxMoved = nullptr;
	BBox* boxRandom = nullptr;

	virtual void SetUp() override
	{
		boxDiamond = new BBox(0.0f, 0.0f, 2.0f, 2.0f, PI / 4.0f);
		boxRect = new BBox(0.0f, 0.0f, 10.0f, 1.0f, 0.0f);
		boxMoved = new BBox(-3.0f, 3.0f, 1.0f, 1.0f, 0.0f);
		boxRandom = new BBox(5.0f, 5.0f, 8.0f, 4.0f, PI / 8.0f);
	}

	virtual void TearDown() override
	{
		if (boxDiamond != nullptr)
			delete boxDiamond;
		if (boxRect != nullptr)
			delete boxRect;
		if (boxMoved != nullptr)
			delete boxMoved;
		if (boxRandom != nullptr)
			delete boxRandom;
	}
};

// if tests pass stdout is suppressed

TEST(Tests, Demonstration) {
	EXPECT_TRUE(true);
	//ASSERT_TRUE(false); // stricter version of expect. In case of an 
	//EXPECT_TRUE(false) << "information about the error";
}

TEST(PointTest, sanity) {
	Point* p = new Point(1.0f, 0.0f);
	float exp_len = 1.0f;
	ASSERT_EQ(exp_len, p->length());
	
	Point* q = new Point(0.0f, 1.0f);
	ASSERT_EQ(exp_len, q->length());

	float exp_dot = 0.0f;
	ASSERT_EQ(exp_dot, p->dot(q));

	p->scale(2.0f);
	exp_len *= 2.0f;
	ASSERT_EQ(exp_len, p->length());

	Point* r = new Point(0.0f, 0.0f);
	Point::add(p, q, r);
	exp_len = sqrt(5.0f);
	ASSERT_EQ(exp_len, r->length());

	Point::sub(p, q, r);
	exp_len = sqrt(5.0f);
	ASSERT_EQ(exp_len, r->length());

	delete r;
	delete p;
	delete q;
}

TEST(BBoxTest, area) {
	BBox* box = new BBox(0.0f, 0.0f, 2.0f, 1.0f, 0.0f);
	
	float exp_area = 2.0f;
	ASSERT_EQ(exp_area, box->area());
	
	delete box;
}

TEST_F(Box, diamondTest) {
	float exp_area = 4.0f;
	EXPECT_EQ(exp_area, boxDiamond->area()) << "area test";

	Point* p = new Point(0.5f, 0.5f);
	ASSERT_TRUE(boxDiamond->containsPoint(p)) << "contains point";
	delete p;

	p = new Point(1.0f, 0.0f);
	ASSERT_TRUE(boxDiamond->containsPoint(p)) << "contains point";
	delete p;

	p = new Point(1.42f, 0.0f);
	ASSERT_FALSE(boxDiamond->containsPoint(p)) << "almost contains point";
	delete p;
}

TEST_F(Box, rectTest) {
	float exp_area = 10.0f;
	EXPECT_EQ(exp_area, boxRect->area()) << "area test";

	Point* p = new Point(0.5f, 0.5f);
	ASSERT_TRUE(boxRect->containsPoint(p)) << "contains point on top edge";
	delete p;

	p = new Point(4.0f, 0.0f);
	ASSERT_TRUE(boxRect->containsPoint(p)) << "contains point";
	delete p;

	p = new Point(0.0f, 4.0f);
	ASSERT_FALSE(boxRect->containsPoint(p)) << "point outside the rect";
	delete p;

        p = new Point(-5.0f, -0.5f);
	ASSERT_TRUE(boxRect->containsPoint(p)) << "left lower corner case";
	delete p;
}
/*
TEST_F(Box, containingPoints) {
	float exp_area = 4.0f;
	EXPECT_EQ(exp_area, boxDiamond->area()) << "area test";

	Point* p = new Point(0.5f, 0.5f);
	ASSERT_TRUE(boxDiamond->containsPoint(p)) << "contains point 0";
	delete p;

	p = new Point(1.0f, 0.0f);
	ASSERT_TRUE(boxDiamond->containsPoint(p)) << "contains point 1";
	delete p;

	p = new Point(1.42f, 0.0f);
	ASSERT_FALSE(boxDiamond->containsPoint(p)) << "contains point 2";
	delete p;
}

TEST_F(Box, containingPoints) {
	float exp_area = 4.0f;
	EXPECT_EQ(exp_area, boxDiamond->area()) << "area test";

	Point* p = new Point(0.5f, 0.5f);
	ASSERT_TRUE(boxDiamond->containsPoint(p)) << "contains point 0";
	delete p;

	p = new Point(1.0f, 0.0f);
	ASSERT_TRUE(boxDiamond->containsPoint(p)) << "contains point 1";
	delete p;

	p = new Point(1.42f, 0.0f);
	ASSERT_FALSE(boxDiamond->containsPoint(p)) << "contains point 2";
	delete p;
}*/
