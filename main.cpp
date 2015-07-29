#include <stdio.h>

#include <cassert>

#include <ft2build.h>
#include FT_FREETYPE_H

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("usage: ./build/main math-font\n");
    return 1;
  }

  char* fontPath = argv[1];

  FT_Library lib;
  assert(FT_Init_FreeType(&lib) == 0);

  FT_Face face;
  assert(FT_New_Face(lib, fontPath, 0, &face) == 0);

  assert(FT_Set_Char_Size(face, (16 << 6), 0, 72*2, 72*2) == 0);

  printf("Loading A\n");
  FT_Load_Char(face, 'A', FT_LOAD_RENDER);
  auto &bitmap = face->glyph->bitmap;
  printf("Bitmap size: %dx%d\n", bitmap.width, bitmap.rows);
  printf("X advance=%d\n", (face->glyph->advance.x >> 6));

  for (int y = 0; y < bitmap.rows; y++) {
    for (int x = 0; x < bitmap.width; x++) {
      auto value = bitmap.buffer[y*bitmap.width + x];
      if (value > 0) {
        printf("oo");
      } else {
        printf("  ");
      }
    }
    printf("\n");
  }

  return 0;
}

