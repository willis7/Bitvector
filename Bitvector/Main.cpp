#include "Bitvector.h"


void main()
{
	// create a bitvector with 32 bits.
	Bitvector bitv( 32 );
	bool b;

	// set index 0 to true and retrieve it again.
	bitv.Set( 0, true );
	b = bitv[0];

	// set index 31 o false and retrieve it again.
	bitv.Set( 31, false );
	b = bitv[31];

	// set all the bits in the vector to 0
	bitv.ClearAll();

	// set all the bits in the vector to 1
	bitv.SetAll();

	// resize the bitvector to 48 bits
	bitv.Resize( 48 );

}