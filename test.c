/*
 * Homework 1B - Check if a string has unique chars
 * This file includes the main function which tests the hasUniqueChars() method
 *
 * Author: Emily Thorpe
 */

#include <stdio.h>    // printf
#include <stdbool.h>  // to define a boolean type and true, false
#include <string.h>   // strcpy  to copy a string
#include <assert.h>


// declaration of function from hasUniqueChars.c
bool hasUniqueChars(char * inputStr);


int main() {

  // ------------------------------------------------------------
  // Examples of declaring string constants
  /* Example 1 */
  char string1[] = "A string declared as an array.\n";

  /* Example 2 */
  char *string2 = "A string declared as a pointer.\n";

  /* Example 3 */
  char string3[128];   // can copy in up to 127 characters
                       // chose 128 because it is a multiple of 8 bytes
  strcpy(string3, "A string constant copied in.\n");

  // -------------------------------------------------------------
  // Thorough and exhaustive tests of hasUniqueChars()  
  bool ok;    // holds the result of hasUniqueChars(); used in asserts
  
  // Test 1: a test case that should return false because characters are duplicated
  strcpy(string3, "This should fail (l and s and i and h)");
  ok = hasUniqueChars(string3);
  assert(!(ok));
  
  // Test 2: This should be true and not fail, but won't work until you
  // complete the hasUniqueChars() function
  strcpy(string3, "abcdefghij");
  ok = hasUniqueChars(string3);
  assert(ok);
  
  // Test 3: String with all ascii characters
  strcpy(string3, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~");
  ok = hasUniqueChars(string3);
  assert(ok);

  // Test 4: String with duplicate characters
  strcpy(string3, "This should fail (l and s and i and h)");
  ok = hasUniqueChars(string3);
  assert(!ok);

  // Test 5: String with multiple spaces
  strcpy(string3, "a b c d e f g");
  ok = hasUniqueChars(string3);
  assert(ok);

  // Test 6: Edge case at the end of the first range (ASCII 63)
  strcpy(string3, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789?");
  ok = hasUniqueChars(string3);
  assert(ok);

  // Test 7: Edge case at the start of the second range (ASCII 64)
  strcpy(string3, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789@");
  ok = hasUniqueChars(string3);
  assert(ok);

  // Test 8: Mix of printable, non-printable, and edge cases
  strcpy(string3, "abc\1\2\3def\x7F");  // \x7F is DELETE (ASCII 127)
  ok = hasUniqueChars(string3);
  assert(ok);

  // Test 9: Empty string (edge case)
  strcpy(string3, "");
  ok = hasUniqueChars(string3);
  assert(ok);

  // Test 10: Non-printing characters
  strcpy(string3, "\1\2\3\0");
  ok = hasUniqueChars(string3);
  printf("%d ", ok);

  // Test 11: More non-printing characters
  strcpy(string3, "a b cc\n");
  ok = hasUniqueChars(string3);

  return 0;
}