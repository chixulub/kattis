int gcd(int a, int b)
{
	while (b)
	{
		int t = b;
		b = a % b;
		a = t;
	}

	return a;
}

struct Rational
{
	int a, b;

	Rational(int _a, int _b)
	: a(_a)
	, b(_b)
	{
		int d = gcd(a,b);
		a /= d;
		b /= d;
	}
};

Rational operator * (Rational const& lhs, Rational const& rhs)
{
	return Rational(lhs.a * rhs.a, lhs.b * rhs.b);
}

ostream& operator << (ostream& os, Rational const& r)
{
	os << r.a << "/" << r.b;
	return os;
}
