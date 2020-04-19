#include <stdio.h>
#include <stdlib.h>

int max(int x1, int x2){
  if ( x1> x2 ){
    return x1;
  }
    return x2;
}


/* check1
 * Determines if coord is in range between
 * offset (INCLUSIVE) and offset + size (EXCLUSIVE)
 */

int isInRange(int coord, int offset, int size) {
  // if coord is in range, return 1
  // else, return 0
  return ( offset <= coord && coord < offset+size);
  }



/*
 * Determines if coord is at border of offset or
 * offset + size
 */
int isAtBorder(int coord, int offset, int size) {
  // if coord is equal to offest or offset + size
  // return 1, else return 0
  return  coord == offset || coord == offset+size-1;
 }

// if case main contruct function
int caseBound ( int x, int y, int x_offset, int y_offset, int size){
  return isInRange(x, x_offset, size) && isAtBorder(y, y_offset, size);
}

// this function will be used in else-if condition in main
int caseBound1 ( int x, int y, int size_1){
  return caseBound(x, y, 0, 0, size_1) || caseBound(y, x, 0, 0, size_1);
}

// this function will be used in if condition in main
int caseBound2 ( int x, int y, int x_offset, int y_offset, int size_2){
  return caseBound(x, y, x_offset, y_offset, size_2) || caseBound(y, x, y_offset, x_offset, size_2);
}

  

void squares(int size1, int x_offset, int y_offset, int size2) {
  //compute the max of size1 and (x_offset + size2).  Call this w
  int w = max(size1, x_offset + size2);
  //compute the max of size1 and (y_offset + size2).  Call this h
  int h = max(size1, y_offset + size2);
  //count from 0 to h. Call the number you count with y
  for (int y=0; y<h ; y++){
      //count from 0 to w. Call the number you count with x
    for (int x=0; x<w; x++){
      //check if  EITHER 
      //    ((x is between x_offset  and x_offset +size2) AND 
      //     y is equal to either y_offset OR y_offset + size2 - 1 )
      //  OR
      //    ((y is between y_offset and y_offset + size2) AND
      //     x is equal to either x_offset OR x_offset + size2 -1)
      // if so, print a *
      if ( caseBound2(x, y, x_offset, y_offset, size2) ){
	
	printf("*");
      }
      //if not,
      else if (caseBound1(x, y, size1)) {
      // check if EITHER.update
      //    x is less than size1 AND (y is either 0 or size1-1)
      // OR
      //    y is less than size1 AND (x is either 0 or size1-1)
      //if so, print a #
       
	printf("#");
      }

      
      //else print a space
      else{
	printf(" ");
      }
    } // small for
    //when you finish counting x from 0 to w, 
    //print a newline
    printf("\n");
  } // big for
} //main
