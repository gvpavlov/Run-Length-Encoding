#include "RLE.h"

RLE::RLE(char* string)
{
	capacity = SIZE;
	symbol = new char[capacity];
	count = new int[capacity];
	int l = strlen(string), i = 1, j = 0;
	totalCount = 0;
	symbol[j] = string[j];
	count[j] = 1;
	top = 0;
	for (int k = 0; k < l; k++)
	{
		if (full())
			resize();
		if (string[i] == symbol[j])
			count[j]++;
		else 
		{
			symbol[++j] = string[i];
			count[j] = 1;
		}
		i++;
		top=j;
	}
	for (int i = 0; i < top; i++)
		totalCount += count[i];	
}

void RLE::resize()
{
	capacity*=2;
	char* tmpsymbol = new char[capacity];
	int* tmpcount = new int[capacity];
	for (int i = 0; i <= top; i++)
	{
		tmpsymbol[i] = symbol[i];
		tmpcount[i] = count[i];
	}
	del();
	symbol = tmpsymbol;
	count = tmpcount;
}

bool RLE::full()
{
	if (top == capacity-1)
		return 1;
	else 
		return 0;
}

bool RLE::empty()
{
	if (top <= 0)
		return 1;
	else
		return 0;
}

void RLE::del()
{
	if (symbol)
	{
		delete[] symbol;
		symbol = NULL;
	}
	if (count)
	{
		delete[] count;
		count = NULL;
	}
}

void RLE::copy(RLE const& s)
{
	if (this->symbol != NULL || this->count != NULL)
		del();
	this->symbol = new char[s.capacity];
	this->count = new int[s.capacity];
	for (int i = 0; i < s.top; i++)
	{
		this->symbol[i] = s.symbol[i];
		this->count[i] = s.count[i];
	}
	this->top = s.top;
	this->capacity = s.capacity;
	this->totalCount = s.totalCount;
}

RLE::RLE(RLE const& s) : symbol(NULL), count(NULL)
{
	copy(s);
}

RLE& RLE::operator=(RLE const& s)
{
	if (this != &s)
		copy(s);
	return *this;
}

RLE::~RLE()
{
	del();
}

char* RLE::decode() const
{
	int counter = 0;
	char* s = new char[totalCount];
		for (int i = 0; i < top; i++)
		{
			int tmp = count[i];
			for (int j = 0; j < tmp; j++)
				s[counter++] = symbol[i];
		}
	s[totalCount] = '\0';
	return s;
}

ostream& operator<<(ostream& out, RLE const& s)
{
	out<<"R = ";
	for (int i = 0; i < s.top; i++)
		out<<"("<<s.count[i]<<","<<s.symbol[i]<<")";
	return out;
}

const char RLE::operator[](const int ind) const
{
	int counter = 0;
	for (int i = 0; i < top; i++)
	{
		for (int j = 0; j < count[i]; j++)
		{
			if (counter == ind)
				return symbol[i];
			counter++;
		}
	}
	return '\0';
}

RLE& RLE::operator+=(RLE const& s)
{
	int i=0;
	if (this->symbol[top-1] == s.symbol[0]) 
	{
		this->count[top-1] += s.count[0];
		i = 1;
	}
	for (; i < s.top; i++)
	{
		if (this->full())
			this->resize();
		this->symbol[this->top] = s.symbol[i];
		this->count[(this->top)++] = s.count[i];
	}
	this->totalCount += s.totalCount;
	return *this;
}

RLE RLE::operator+(RLE const& s)
{
	RLE tmp = *this;
	tmp+=s;
	return tmp;
}

RLE& RLE::operator++()
{
	if (empty())
		return *this;
	this->count[top-1]++;
	this->totalCount++;
	return *this;
}

RLE RLE::operator++(int hax)
{
	if (empty())
		return *this;
	RLE tmp = *this;
	++(*this);
	return tmp;
}

RLE& RLE::operator--()
{
	if (empty())
		return *this;
	if (this->count[top-1]-1 <= 0)
		top--;
	else
		this->count[top-1]--;
	this->totalCount--; 
	return *this;
}

RLE RLE::operator--(int hax)
{
	if (empty())
		return *this;
	RLE tmp = *this;
	--(*this);
	return tmp;
}

RLE RLE::operator()(int position, const int length) const
{
	char* tmp = new char[length];
	for (int i = 0; i < length; i++)
		tmp[i] = (*this)[position++];
	tmp[length] = '\0';
	RLE temp(tmp);
	return temp;
}

RLE& RLE::operator()(const int position, RLE const& s)
{
	int breakPoint = position;
	RLE firstPart = (*this)(0, breakPoint);
	RLE lastPart = (*this)(breakPoint, this->totalCount);
	*this = (firstPart + s); 
	*this += lastPart; 
	return *this;
}

RLE& RLE::deleteSymbols(const int position, const int length)
{
	int breakPoint = position + length;
	RLE firstPart = (*this)(0, breakPoint);
	RLE lastPart = (*this)(breakPoint, this->totalCount);
	for (int i = 0; i < length; i++)
		firstPart--;
	*this = (firstPart + lastPart);
	return *this;
}

bool RLE::operator==(RLE const& s) const
{
	if (this->top != s.top || this->totalCount != s.totalCount)
		return false;
	for (int i = 0; i < this->top; i++)
	{
		if (this->count[i] != s.count[i] || this->symbol[i] != s.symbol[i])
			return false;
	}
	return true;
}

bool RLE::operator!=(RLE const& s) const
{
	return !(*this==s);
}

bool RLE::operator<(RLE const& s) const
{
	if (this->top > s.top || this->totalCount >= s.totalCount)
		return false;
	for (int i = 0; i < s.top; i++)
	{
		if (this->symbol[0] == s.symbol[i] && this->count[0] <= s.count[i])
		{
			int sum = 0;
			for (int j = i + 1; j < s.top; j++)
				sum += s.count[j];
			int position = s.totalCount - sum - this->count[0];
			if (s(position, this->totalCount) == *this)
				return true;
		}
	}
	return false;
}

bool RLE::operator<=(RLE const& s) const
{
	if (*this < s || *this == s)
		return true;
	else
		return false;
}

bool RLE::operator>(RLE const& s) const
{
	if (s < *this)
		return true;
	else 
		return false;
}

bool RLE::operator>=(RLE const& s) const
{
	if (*this > s || *this == s)
		return true;
	else
		return false;
}

RLE RLE::operator*()
{
	RLE tmp("");
	tmp.symbol[0] = this->symbol[0];
	tmp.count[0] = this->count[0];
	tmp.top = 1;
	for (int i = 1; i < this->top; i++)
	{
		bool check = true;
		for (int j = 0; j < tmp.top; j++)
		{
			if (this->symbol[i] == tmp.symbol[j])
			{
				tmp.count[j] += this->count[i];
				check = false;
			}
		}
		if (check)
		{
			tmp.symbol[tmp.top] = this->symbol[i];
			tmp.count[tmp.top++] = this->count[i];
		}
	}
	tmp.totalCount = this->totalCount;
	return tmp;
}