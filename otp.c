/* 
*  OTP  (one time pad ) is an encryption technique where a string of key is modularly added to plain ascii text to create the cipher text 
*  Decryption is done using the modular subtraction of the key from the cipher text at the other end.
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main ()
{
  unsigned char text[] = "hello World";
  unsigned char key[]  = "snsvnvlsckn";
  unsigned char *cipher = calloc (1, strlen(text));  
  unsigned char *decryptText = calloc (1, strlen(text));
  unsigned char result ;

  unsigned int i ;
  for (i=0; i < strlen (text); i++)
  {
    result = ((text[i] - 'a') + (key[i] - 'a'));
    cipher [i] = result;
  }
  printf ("cipher : %s\n", cipher);
  
  for (i=0;i<strlen(cipher);i++)
  {
    result = ((cipher[i] - 'a') - (key[i] - 'a'));
    if (result < 0)
      result+=26;
  
    decryptText [i] = result; 
  }
  printf ("Decrypt text: %s\n", decryptText);
}

