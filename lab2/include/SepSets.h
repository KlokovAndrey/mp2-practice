#pragma once 
class SepSets
{
private:
	int *marks;
	int *sizes;
	int n;
public:
	SepSets(int);
	~SepSets();
	void create_set(int);
	int find_set(int);
	void merge_set(int, int);
};

SepSets::SepSets(int i)
{
	if (i < 0) throw "the number must be positive";
	marks = new int[i];
	for (int j = 0; j < i; j++)
	{
		marks[j] = -1;
	}
	sizes = new int[i];
	n = i;
}
SepSets::~SepSets()
{
	delete marks;
	delete sizes;
}
void SepSets::create_set(int x)
{
	if ((x > n) || (x < 0))
		throw ("Error");
	if (marks[x] != -1)
		return;
	marks[x] = x;
	sizes[x] = 1;
}
int SepSets::find_set(int x)
{
	if ((x > n) || (x < 0))
		throw ("out of range");
	if (sizes[x] == -1)
		return -1;
	while (marks[x] != x)
		x = marks[x];
	return x;
}
void SepSets::merge_set(int x, int y)
{
	if ((x > n) || (x < 0) || (y > n) || (y < 0))
		throw ("out of range");
	if ((marks[x] == -1) || (marks[y] == -1))
		throw ("Set is empty");
	x = find_set(x);
	y = find_set(y);
	if (sizes[x] > sizes[y])
		marks[y] = x;
	else if (sizes[x] < sizes[y])
		marks[x] = y;
	else
	{
		marks[y] = x;
		sizes[x]++;
	}
}



