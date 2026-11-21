#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <string>

class bigint
{
	std::string s;
public:
	bigint(unsigned long n = 0)
	{
		do { s.insert(s.begin(), '0' + n % 10); n /= 10; } while (n);
	}

	const std::string &str() const { return s; }

	bigint &operator+=(const bigint &o)
	{
		std::string r;
		int c = 0;
		for (int i = s.size() - 1, j = o.s.size() - 1; i >= 0 || j >= 0 || c; i--, j--)
		{
			if (i >= 0) c += s[i] - '0';
			if (j >= 0) c += o.s[j] - '0';
			r.insert(r.begin(), '0' + c % 10);
			c /= 10;
		}
		s = r;
		return *this;
	}
	bigint operator+(const bigint &o) const { return bigint(*this) += o; }
	bigint &operator++() { return *this += 1; }
	bigint operator++(int) { bigint t(*this); *this += 1; return t; }

	bigint &operator<<=(unsigned int k) { if (s != "0") s.append(k, '0'); return *this; }
	bigint &operator>>=(unsigned int k) { if (k >= s.size()) s = "0"; else s.erase(s.size() - k); return *this; }
	bigint operator<<(unsigned int k) const { return bigint(*this) <<= k; }
	bigint operator>>(unsigned int k) const { return bigint(*this) >>= k; }

	unsigned int toUint() const { unsigned int n = 0; for (size_t i = 0; i < s.size(); i++) n = n * 10 + s[i] - '0'; return n; }
	bigint &operator<<=(const bigint &k) { return *this <<= k.toUint(); }
	bigint &operator>>=(const bigint &k) { return *this >>= k.toUint(); }
	bigint operator<<(const bigint &k) const { return *this << k.toUint(); }
	bigint operator>>(const bigint &k) const { return *this >> k.toUint(); }

	bool operator<(const bigint &o) const { return s.size() != o.s.size() ? s.size() < o.s.size() : s < o.s; }
	bool operator>(const bigint &o) const { return o < *this; }
	bool operator<=(const bigint &o) const { return !(o < *this); }
	bool operator>=(const bigint &o) const { return !(*this < o); }
	bool operator==(const bigint &o) const { return s == o.s; }
	bool operator!=(const bigint &o) const { return s != o.s; }
};

std::ostream &operator<<(std::ostream &os, const bigint &b);

#endif
