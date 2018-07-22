#pragma once
class point
{
public:
	point()
	{}
	point(const int x, const int y) :x(x), y(y){}
	void Print();
	void Clear();
	void ChangePosition(const int x, const int y);
	bool operator==(const point& mypoint)
	{
		return((mypoint.x == this->x) && (mypoint.y == this->y));
	}
	int GetX()
	{
		return this->x;
	}
	int GetY()
	{
		return this->y;
	}
private:
	int x, y;
};

