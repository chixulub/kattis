struct vec
{
	int x, y;
};

bool operator < (vec const& a, vec const& b)
{
	if (a.x == b.x)
	{
		return a.y < b.y;
	}

	return a.x < b.x;
}

vec operator - (vec const& a, vec const& b)
{
	return vec{a.x-b.x, a.y-b.y};
}

int dot(vec const& a, vec const& b)
{
	return a.x * b.x + a.y * b.y;
}
