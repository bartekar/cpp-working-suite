#include <Data.h>

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
		boxRect = new BBox(0.0f, 0.0f, 2.0f, 2.0f, PI / 4.0f);
		boxMoved = new BBox(0.0f, 0.0f, 2.0f, 2.0f, PI / 4.0f);
		boxRandom = new BBox(0.0f, 0.0f, 2.0f, 2.0f, PI / 4.0f);
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

TEST_F(Box, containingPoint) {
	float exp_area = 4.0f;
	EXPECT_EQ(exp_area, boxDiamond->area()) << "area test";

	Point* p = new Point(0.5f, 0.5f);
	ASSERT_TRUE(boxDiamond->containsPoint(p));
	delete p;
}
