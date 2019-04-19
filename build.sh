# .ppp (post preprossessing) files created here is the code after the preproccessor
clear
echo start build
blockwarnings=" -Wno-multichar -Wno-overflow "
buildoptions=" -ggdb -Wall -fexec-charset=UTF-8 $blockwarnings -pie -x c++"

# make exe
i686-w64-mingw32-gcc $buildoptions -E Windows.cpp 2> /dev/null 1> debug/Windows.ppp
i686-w64-mingw32-gcc $buildoptions -o "./debug/Windows.exe" ./Windows.cpp -lgdi32 -lwinmm -static
# make dll
i686-w64-mingw32-gcc $buildoptions -E ProgramCode.cpp > debug/ProgramCode.ppp
#i686-w64-mingw32-gcc $buildoptions -shared -c -o "./debug/ProgramCode.o"  ./ProgramCode.cpp
#i686-w64-mingw32-gcc $buildoptions -shared -o "./debug/ProgramCode.dll" ./debug/ProgramCode.o
i686-w64-mingw32-gcc $buildoptions -shared -o "./debug/ProgramCode.dll" ./ProgramCode.cpp
# 2> debug/complaints 1> debug/complaints

echo end build
