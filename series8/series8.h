#ifndef SERIES8_CPP_DES_H
#define SERIES8_CPP_DES_H

struct Pair
{
	int yp;
	int yq;
};

struct RabinDecode
{
	int r;
	int nr;
	int s;
	int ns;
};

int encodeRabin(int p, int q, int m);
RabinDecode decodeRabin(int c, int p, int q);

#endif //SERIES8_CPP_DES_H