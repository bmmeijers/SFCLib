#pragma once
#ifndef SFCCONERSION_H_
#define SFCCONERSION_H_

#include <array>            // std::array
#include "Point.h"


template< int nDims,  int  mBits>
class SFCConversion
{
private:
	std::array< long, nDims > g_mask;

	unsigned int calc_P3(int i, Point<long, mBits> H);
	unsigned int calc_P2(unsigned int S);
	unsigned int calc_J(unsigned int P);
	unsigned int calc_T(unsigned int P);
	unsigned int calc_tS_tT(unsigned int xJ, unsigned int val);
	unsigned int calc_tS_tT2(unsigned int xJ, unsigned int val);

public:
	Point<long, nDims> ptCoord; //n*m
	Point<long,  mBits> ptBits; //m*n

	SFCConversion::SFCConversion()
	{
		for (int i = 0; i < nDims; i++)
		{
			g_mask[i] = 1 << i;
		}
	}

	void MortonEncode(void); // from n*m coords to m*n bitsequence
	void MortonDecode(void); // from m*n bitsequence to n*m coords
	 
	void HilbertEncode(void); // from n*m coords to m*n bitsequence
	void HilbertDecode(void); // from m*n bitsequence to n*m coords
};
#endif