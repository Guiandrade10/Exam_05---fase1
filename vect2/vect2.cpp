#include "vect2.hpp"

vect2 operator*(int k, const vect2 &v)
{
	return v * k;
}

std::ostream &operator<<(std::ostream &os, const vect2 &v)
{
	return os << "{" << v[0] << ", " << v[1] << "}";
}
