#include "Bitvector.h"

//Constructor - clears the array pointer to 0, sets the size to 0, and then calls the
//Resize algorithm to resize the array to the correct size.
Bitvector::Bitvector(int pSize)
{
	bitArray = 0;
	size = 0;
	Resize(pSize);
}
//Deconstructor - deletes the array if it exists
Bitvector::~Bitvector(void)
{
	if(bitArray != 0)
		delete[] bitArray;
	bitArray = 0;
} 
//Performs a few calculations and resizes the vector to a given number of bits.
//Allows users of the class to request a certain number of bits without having to figure
//out how many integers they will turn into.
void Bitvector::Resize(int pSize)
{
	unsigned long int* newVector = 0;

	//Check to see if the number of bits is divisible by 32
	//If so, then the size of the array is the number of bits required divided by 32
	if(pSize % 32 == 0)
		pSize = pSize / 32;
	else
		pSize = (pSize / 32) + 1;

	newVector = new unsigned long int[pSize];

	if(newVector == 0)
		return;

	int min;

	if(pSize < size)
		min = pSize;
	else
		min = size;

	int index;

	for(index = 0; index < min; index++)
		newVector[index] = bitArray[index];

	size = pSize;

	if(bitArray != 0)
		delete[] bitArray;

	bitArray = newVector;
}
//Set the bit within the bitvector using binary math.
//Use the and operator to clear bits and use the or operator to set bits.
void Bitvector::Set(int pIndex, bool pValue)
{
	int cell = pIndex / 32;
	int bit = pIndex % 32;

	if(pValue == true)
		bitArray[cell] = (bitArray[cell] | (1 << bit));
	else
		bitArray[cell] = (bitArray[cell] & (~(1 << bit)));
}
//Sets all bits to 0
void Bitvector::ClearAll()
{
	int index;

	for(index = 0; index < size; index++)
		bitArray[index] = 0;
}
//Sets all bits to 1On a 32-bit system, 
//this number would be hexadecimal FFFFFFFF
void Bitvector::SetAll()
{
	int index;

	for( index = 0; index < size; index++ )
	bitArray[index] = 0xFFFFFFFF;
}



