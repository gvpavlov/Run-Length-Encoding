#ifndef RLE_H_
#define RLE_H_

#include <cstring>
#include <iostream>
using namespace std;

const int SIZE = 10;

class RLE
{
	char* symbol;
	int* count;
	int top;
	int capacity;
	int totalCount;
	void resize();
	bool full();
	bool empty();
	void copy(RLE const&);
	void del();
public:
	RLE(char* = "");
	RLE(RLE const&);
	RLE& operator=(RLE const&);
	~RLE();
	char* decode() const;
	friend ostream& operator<<(ostream&, RLE const&);
	const char operator[](const int) const;
	RLE& operator+=(RLE const&);
	RLE operator+(RLE const&);
	RLE& operator++();
	RLE operator++(int);
	RLE& operator--();
	RLE operator--(int);
	RLE operator()(int, const int) const;
	RLE& operator()(const int, RLE const&);
	RLE& deleteSymbols(int, int);
	bool operator==(RLE const&) const;
	bool operator!=(RLE const&) const;
	bool operator<(RLE const&) const;
	bool operator<=(RLE const&) const;
	bool operator>(RLE const&) const;
	bool operator>=(RLE const&) const;
	RLE operator*();
};

#endif