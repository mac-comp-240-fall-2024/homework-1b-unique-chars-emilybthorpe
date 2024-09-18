/*
 * hasUniqueChars.c
 * 
 * Homework 1B: Given a string of characters, which are encoded in ascii,
 * determine if the string contains all unique characters.
 *
 * File contains functions for this goal.
 * 
 * Author: Emily Thorpe
 */

#include <stdio.h>  // fprintf, printf
#include <stdlib.h> // exit() defined here
#include <string.h> // useful string operations
#include <ctype.h>  //useful character operations
#include <stdbool.h>  // to define a boolean type and true, false
                      // see https://en.wikibooks.org/wiki/C_Programming/stdbool.h

#include "binary_convert.h"


/*
 * This function is for debugging by printing out the value
 * of an input insigned long as a binary string.
 */
void seeBits(unsigned long value, char *debug_text) {
  
  // string to represent binary value of variable value
  char *bin_str;

  bin_str = ulong_to_bin_str(value);
  printf("%s%s\n", debug_text, bin_str);
  free(bin_str);
  
}


/*
 * Given an input string of chars, check for any non-printing
 * characters and print an error and exit if the string has any.
 */
void checkInvalid(char * inputStr) {
  char nextChar;
  int i;
  
  for(i = 0; i < strlen(inputStr); i++) {
    nextChar = inputStr[i];

    // if nextChar is invalid (31 or less or 127 as an ascii char code), then bail out
    if ((nextChar <= 31 ) || (nextChar == 127)) {
      fprintf(stderr, "invalid character in string\n");
      exit(EXIT_FAILURE);
    }
  }
}


/*
 * Given an input string of chars, check if all chars are unique
 * Returns true if all unique, false if there are duplicates
 *
 * Error conditions: 
 *    - Invalid characters in input string
 */
bool hasUniqueChars(char * inputStr) {
  // bail out quickly if any invalid characters
  checkInvalid(inputStr);
  
  int i;   // loop counter
  
  // unsigned long can handle 64 different chars in a string
  // if a bit at a position is 1, then we have seen that character
  unsigned long checkBitsA_z = 0;   // for checking A through z and {|}~
  unsigned long checkBitsexcl_amp =0;  // for checking ! though @ 

  char nextChar;         // next character in string to check

  for(i = 0; i < strlen(inputStr); i++) {
    nextChar = inputStr[i];

    // Dont count spaces
    if (nextChar == 32)
    {
      continue;
    }

    // Check if char is in first or second checker
    if (nextChar < 64) {      
      unsigned long checkBitCurrentChar = 1UL << (63 - nextChar);

      // Check if character has been seen
      if((checkBitsexcl_amp & checkBitCurrentChar) != 0)
      {
        // Character has been seen before, therefore not unique
        return false;
      }

      // Mark char as  seen
      checkBitsexcl_amp |= checkBitCurrentChar;
    } else {
      unsigned long checkBitCurrentChar = 1UL << (127 - nextChar);

      // Check if character has been seen
      if((checkBitsA_z & checkBitCurrentChar) != 0)
      {
        // Character has been seen before, therefore not unique
        return false;
      }

      // Mark char as  seen
      checkBitsA_z |= checkBitCurrentChar;
    }

  }

  // if through all the characters, then no duplicates found
  return true;
}
