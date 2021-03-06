#ifndef TYPEDEF_H_
#define TYPEDEF_H_

#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;

typedef enum
{
	Base32,
	Base64,
	DEC,
	HEX
} StringType;

static const char* const BASE32_TABLE_E2 = "0123456789ABCDEFGHIJKLMNOPQRSTUV";
static const char* const BASE64_TABLE_E2 = "+/0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz=";

//here use the ASCII as index
static const unsigned char BASE64_TABLE_D2[] = {
	/*00-07*/ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	/*08-0f*/ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	/*10-17*/ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	/*18-1f*/ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	/*20-27*/ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	/*28-2f*/ 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0x01, /*2 = '+' and '/'*/
	/*30-37*/ 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, /*8 = '0'-'7'*/
	/*38-3f*/ 0x0a, 0x0b, 0xFF, 0xFF, 0xFF, 0x40, 0xFF, 0xFF, /*2 = '8'-'9' and '='*/
	/*40-47*/ 0xFF, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, /*7 = 'A'-'G'*/
	/*48-4f*/ 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, /*8 = 'H'-'O'*/
	/*50-57*/ 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x22, /*8 = 'P'-'W'*/
	/*58-5f*/ 0x23, 0x24, 0x25, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, /*3 = 'X'-'Z'*/
	/*60-67*/ 0xFF, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, /*7 = 'a'-'g'*/
	/*68-6f*/ 0x2d, 0x2e, 0x2f, 0x30, 0x31, 0x32, 0x33, 0x34, /*8 = 'h'-'o'*/
	/*70-77*/ 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b, 0x3c, /*8 = 'p'-'w'*/
	/*78-7f*/ 0x3d, 0x3e, 0x3f, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF  /*3 = 'x'-'z'*/
};

/* define the bitmask_t type as an integer of sufficient size */
typedef  uint256_t bitmask_t; // unsigned long long / uint256_t
/* define the halfmask_t type as an integer of 1/2 the size of bitmask_t */
typedef  unsigned int halfmask_t; //unsigned long  /uint128_t

typedef  uint256_t sfc_bigint;

#endif