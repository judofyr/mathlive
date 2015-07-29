FREETYPE2="vendor/freetype2"

CFLAGS="-I$FREETYPE2/include"
LDFLAGS="-Lbuild -lfreetype"

cc -std=c++14 main.cpp $CFLAGS $LDFLAGS -o build/main

