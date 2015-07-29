git submodule update --init

FREETYPE2="$PWD/vendor/freetype2"
BUILD="$PWD/build"

cd "$FREETYPE2"
export CFLAGS="-c -O3"
make clean 2>/dev/null
sh autogen.sh
make setup ansi
make
mkdir -p "$BUILD"
cp objs/libfreetype.a "$BUILD"

