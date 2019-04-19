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

#if !defined(CHAR_MANIPULATION_H)
#define CHAR_MANIPULATION_H
#include <cstddef>
extern "C" {
	inline void CopyString(size_t CopyCount, const char* Copy, char* Dest) {
		for (size_t Index = 0; Index < CopyCount; ++Index) {
			*Dest++ = *Copy++;
		}
	}
	inline void CatStrings(
		size_t SourceACount, const char* SourceA,
		size_t SourceBCount, const char* SourceB,
		size_t DestCount, char* Dest)
	{
		CopyString(SourceACount, SourceA, Dest);
		CopyString(SourceBCount, SourceB, Dest + SourceACount);

		*(Dest + SourceACount + SourceBCount) = 0;
	}
}
#endif