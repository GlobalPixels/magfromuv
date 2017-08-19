#include <cstdio>
#include <string.h>
#include <stdlib.h>

#include "Grid.h"
#include "TifGrid.h"

int main(int argc, char *argv[]) {
  
  if (argc < 3) {
    printf("Bad command\n");
    return 1;
  }
  
  char *argOutput = argv[1];
  char *argUFile = argv[2];
  char *argVFile = argv[3];
  bool outside = false;
  FloatGrid *uGrid = ReadFloatTifGrid(argUFile, 90.0, -90.0, -180.0, 180.0, &outside);
  if (!uGrid) {
    printf("Failed to open uGrid %s\n", argUFile);
    return 2;
  }

  FloatGrid *vGrid = ReadFloatTifGrid(argVFile, 90.0, -90.0, -180.0, 180.0, &outside);
  if (!vGrid) {
    printf("Failed to open vGrid %s\n", argVFile);
    return 2;
  }
  
  for (int y = 0; y < uGrid->numRows; y++) {
    for (int x = 0; x < uGrid->numCols; x++) {
	uGrid->data[y][x] = sqrtf(powf(uGrid->data[y][x], 2.0) + powf(vGrid->data[y][x], 2.0));
    }
  }
  
  WriteFloatTifGrid(argOutput, uGrid); 
  
  return 0;
}

