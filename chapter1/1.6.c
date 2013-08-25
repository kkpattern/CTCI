// Rotate the image by 90 degrees.
#include <assert.h>
#include <stdlib.h>
#include <string.h>

// Allocate an image represented by N*N pixels.
// @in n: The dimension of the image.
// @in l: The length of the bytes used to present a pixel.
char ***image_alloc(int n, int l) {
  char ***image = (char ***) malloc(sizeof(char **) * n);
  for (int i = 0; i < n; ++i) {
    image[i] = (char **) malloc(sizeof(char*) *n);
    for (int j = 0; j < n; ++j) {
      image[i][j] = (char *) malloc(sizeof(char) * l);
    }
  }
  return image;
}

// Free an image.
// @in n: The dimension of the image.
void image_free(char ***image, int n) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      free(image[i][j]);
    }
    free(image[i]);
  }
  free(image);
}

// Copy a pixel.
// @in dest: Copy the pixel to.
// @in source: The soure pixel.
// @in l: The length of the bytes used to present a pixel.
void pixel_copy(char *dest, const char *source, int l) {
  strncpy(dest, source, l);
}

// Rotate an image by 90 degree.
// @in n: The dimension of the image.
// @in l: The length of the bytes used to present a pixel.
void image_rotate(char ***image, int n, int l) {
  char *source = (char *) malloc(sizeof(char)*l);
  char *buffer = (char *) malloc(sizeof(char)*l);
  for (int i = 0; i < (n+1)/2; ++i) {
    for (int j = 0; j < (n+1)/2; ++j) {
      int next_i = j;
      int next_j = n-i-1;
      pixel_copy(source, image[i][j], l);
      while (next_i != i && next_j != j) {
        pixel_copy(buffer, image[next_i][next_j], l);
        pixel_copy(image[next_i][next_j], source, l);
        pixel_copy(source, buffer, l);
        next_i = next_j;
        next_j = n-next_i-1;
      }
    }
  }
  free(buffer);
  free(source);
}

int main() {
  int n = 3;
  char ***image = image_alloc(n, 4);
  image_rotate(image, n, 4);
  image_free(image, n);
  return 0;
}
