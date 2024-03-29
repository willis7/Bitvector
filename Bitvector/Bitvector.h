#pragma once

class Bitvector
{
protected:
	unsigned long int* bitArray;
	int size;

public:
	Bitvect (int pSize);
	~Bitvector(void);

	void Resize(int pSize);
	void Set(int pIndex, bool pValue);
	void ClearAll();
	void SetAll();

	bool operator[] (int pIndex)
	{
		int cell = pIndex / 32;
		int bit = pIndex % 32;

		return(bitArray[cell] & (1 << bit)) >> bit;
	}
};


