// This is free and unencumbered software released into the public domain.
// 
// Anyone is free to copy, modify, publish, use, compile, sell, or
// distribute this software, either in source code form or as a compiled
// binary, for any purpose, commercial or non-commercial, and by any
// means.
// 
// In jurisdictions that recognize copyright laws, the author or authors
// of this software dedicate any and all copyright interest in the
// software to the public domain. We make this dedication for the benefit
// of the public at large and to the detriment of our heirs and
// successors. We intend this dedication to be an overt act of
// relinquishment in perpetuity of all present and future rights to this
// software under copyright law.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
// OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
// OTHER DEALINGS IN THE SOFTWARE.

#if !defined(NUMBER_H)
#define NUMBER_H

#include <stdint.h>
typedef int8_t int8;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;

typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;

typedef intmax_t intmax;

typedef float number32;
typedef double number64;

// definitions of the integer types to be used when using a unit that should be good in all cases
// ends with _u (unit) to not interfere with variable names

typedef uint16 PixelCount_u;
typedef uint8 ControllerCount_u;

// definitions of the integer types to be used when using a unit that should be good based on the code

typedef uint16 SampleCount_u;
typedef uint16 Hertz_u;

// unspecified as in the size to prevent confusion and unused memory. use once in a while because free headers use int
#ifdef NO_UNSPECIFIED_INT
#define int _Pragma("message(\"An unspecified int size was made. Do not define NO_UNSPECIFIED_INT or specify the int type like uint8 to remove this note.\")") int
#endif

#ifdef min
#undef min
#endif

#ifdef max
#undef max
#endif

#ifdef abs
#undef abs
#endif

#define min(x, y) ((x) >= (y) ? (y) : (x))
#define max(x, y) ((x) >= (y) ? (x) : (y))

#define MaxNumberFromBits(x) (2 ^ x)
inline uint8 _LengthOfNumber(intmax x) {
	uint8 Length = 0;
	for (; x; x /= 10) { ++Length; }
	return Length;
}
inline uint8 _LengthOfNumberInBits(intmax x) {
	uint8 Length = 0;
	for (; x; x = x >> 1) { ++Length; }
	return Length;
}
#define LengthOfNumber(x) _LengthOfNumber(x)
#define LengthOfNumberInBits(x) _LengthOfNumberInBits(x)

inline uint8 IntegerToString(intmax num, char* buffer) {
	if (num < 0) {
		num = -num;
		*buffer = '-';
		buffer++;
	}
	uint8 digitsInNumber = 0;
	while (num) {
		(buffer[digitsInNumber]) = (num % 10) + '0';
		num = num / 10;
		digitsInNumber++;
	}

	if (digitsInNumber) {
		digitsInNumber--;
		char temp; //a reversing method. may want to put in a seperate function
		for (uint8 letterOn = 0; letterOn <= (uint8)(digitsInNumber / 2); letterOn++) {
			temp = buffer[letterOn];
			*(buffer + (sizeof(char) * letterOn)) = *(buffer + (sizeof(char) * (digitsInNumber - letterOn)));
			*(buffer + (sizeof(char) * (digitsInNumber - letterOn))) = temp;
		}
		digitsInNumber++;
	}
	else
		*buffer = '0';
	return digitsInNumber;
}
inline uint8 DoubleToString(number64 num, char* buffer) {
	uint8 bytesWritten = IntegerToString((int64)num, buffer);
	buffer[bytesWritten++] = '.';
	num = num - (int64)num;
	while ((int64)num != num)
		num = num * 10;
	bytesWritten += IntegerToString((int64)num, buffer + bytesWritten);
	return bytesWritten;
}
#endif
