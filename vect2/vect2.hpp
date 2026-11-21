#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>

class vect2
{
	int v[2];
public:
	vect2(int x = 0, int y = 0) { v[0] = x; v[1] = y; }

	int &operator[](int i) { return v[i]; }
	int operator[](int i) const { return v[i]; }

	vect2 &operator+=(const vect2 &o) { v[0] += o[0]; v[1] += o[1]; return *this; }
	vect2 &operator-=(const vect2 &o) { v[0] -= o[0]; v[1] -= o[1]; return *this; }
	vect2 &operator*=(int k) { v[0] *= k; v[1] *= k; return *this; }

	vect2 operator+(const vect2 &o) const { return vect2(*this) += o; }
	vect2 operator-(const vect2 &o) const { return vect2(*this) -= o; }
	vect2 operator*(int k) const { return vect2(*this) *= k; }
	vect2 operator-() const { return vect2(-v[0], -v[1]); }

	vect2 &operator++() { return *this += vect2(1, 1); }
	vect2 &operator--() { return *this -= vect2(1, 1); }
	vect2 operator++(int) { vect2 t(*this); ++*this; return t; }
	vect2 operator--(int) { vect2 t(*this); --*this; return t; }

	bool operator==(const vect2 &o) const { return v[0] == o[0] && v[1] == o[1]; }
	bool operator!=(const vect2 &o) const { return !(*this == o); }
};

vect2 operator*(int k, const vect2 &v);
std::ostream &operator<<(std::ostream &os, const vect2 &v);

#endif
