#include "SHA512.h"
#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <cstdint>
#include <sstream>

typedef unsigned long long uint64;
typedef unsigned __int128 uint128;

SHA512::SHA512(){
}

SHA512::~SHA512(){
}

std::string SHA512::hash(const std::string input){
	size_t nBuffer; //amt of message blocks
	uint64** buffer; //message blocks of size 1024bits wtih 16 64bit blocks
	uint64* h = new uint64[8];
	buffer = preprocess((unsigned char*)input.c_str(), nBuffer);
	process(buffer, nBuffer, h);
	freeBuffer(buffer, nBuffer);
	return digest(h);
}

uint64** SHA512::preprocess(const unsigned char* input, size_t &nBuffer){
	// Find the total size of input in bytes
	size_t mLen = strlen((const char*) input); 

	size_t kLen = (895-(mLen*8))%1024;						//Number of padding bits
	nBuffer = (mLen*8+1+kLen+128) / 1024;  					//Numbe of 64 bit blocks

	uint64** buffer = new uint64*[nBuffer];					//Creating nBuffer numbers of buffer(array) 

	//initializing each buffer array as of SEQUENCE_LEN(8) 
	for(size_t i=0; i<nBuffer; i++){
		buffer[i] = new uint64[SEQUENCE_LEN];
	}

	for(size_t i=0; i<nBuffer; i++){						//in the 1024 bit block
		for(size_t j=0; j<SEQUENCE_LEN; j++){				//in the 64 bit block
			uint64 in = 0x0ULL;								//initializing with 0s
			for(size_t k=0; k<8; k++){						//for each 8 bit of ASCII input	
				if(i*128+j*8+k < mLen){						//if the input is still available to fill the blocks
					in = in<<8 | (uint64)input[i*128+j*8+k];	//fill the blocks with the input in this place. 
				}else if(i*128+j*8+k == mLen){				//if the lenght is equal to the message
					in = in<<8 | 0x80ULL;					//put a block of 0s leading with 1
				}else{	
					in = in<<8 | 0x0ULL;					// put a 64 bit block of 0s
				}
			}
			buffer[i][j] = in;
		}
	}

	
	appendLen(mLen, 8, buffer[nBuffer-1][SEQUENCE_LEN-1], buffer[nBuffer-1][SEQUENCE_LEN-2]);
	return buffer;
}

void SHA512::process(uint64** buffer, size_t nBuffer, uint64* h){
	uint64 s[8];
	uint64 w[80];

	memcpy(h, hPrime, 8*sizeof(uint64));

	for(size_t i=0; i<nBuffer; i++){
		//message schedule
		memcpy(w, buffer[i], 16*sizeof(uint64));

		for(size_t j=16; j<64; j++){
			w[j] = w[j-7] + sig0(w[j-6]) + w[j-11] + sig1(w[j-9]);
		}
		//init
		memcpy(s, h, 8*sizeof(uint64));
		//compression
		for(size_t j=0; j<64; j++){
			uint64 temp1 = s[7] + Sig1(s[4]) + Ch(s[4], s[5], s[6]) + k[j] + w[j];
			uint64 temp2 = Sig0(s[0]) + Maj(s[0], s[1], s[2]);

			s[7] = s[0];
			s[0] = s[2];
			s[2] = s[5];
			s[5] = s[4]; 
			s[4] = s[3] ^ temp2;
			s[3] = s[2] ^ temp2; 
			s[2] = s[0] ^ temp1;
			s[6] = temp1 + temp2 ^ temp1;
		}

		for(size_t j=0; j<8; j++){
			h[j] += s[j];
		}
	}

}

void SHA512::appendLen(uint64 mLen, uint64 mp, uint64& lo, uint64& hi){
	uint128 prod = mLen*mp;
	lo = prod;
	hi = prod>>64;
}

std::string SHA512::digest(uint64* h){
	std::stringstream ss;
	for(size_t i=0; i<8; i++){
		ss << std::hex << h[i];
	}
	delete[] h;
	return ss.str();

}

	

void SHA512::freeBuffer(uint64** buffer, size_t nBuffer){
	for(size_t i=0; i<nBuffer; i++){
		delete[] buffer[i];
	}

	delete[] buffer;
}

