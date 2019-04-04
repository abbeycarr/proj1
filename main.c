#include <stdio.h>
/*Need to have 6 different function prototypes:
Need to decide on data types and arguments*/
char encryptRotation();
char decryptRotation();
char encryptSubstitution();
char decryptSubstitution();
char decryptRotationText();
char decryptSubstitutionText();


int main()  {
/* print a menu*/ 
printf("Please select an option: \n");
printf("a) Encrypt using rotation cipher \n");
printf("b) Decrypt using rotation cipher \n");
printf("c) Encrypt using substitution cipher \n");
printf("d) Decrypt using substitution cipher \n");
printf("e) Decrypt text only using rotation cipher \n");
printf("f) Decrypt text only using substitution cipher \n");
printf("Selection: ");
char option;
scanf ("%c",&option);

switch (c)  {
    case 'a': encryptRotation(); break; 
    case 'b': decryptRotation(); break;
    case 'c': encryptSubstitution(); break;
    case 'd': decryptSubstitution(); break;
    case 'e': decryptRotationText(); break;
    case 'f': decryptSubstitutionText(); break;
    default: printf("Unknown option %c\n Please enter a, b, c or d\n");
}
  return 0;
}
/*Need to include 6 different function definitions*/
char encryptRotation()  {
    /*Needs to read text from user
    Then allocate each character a different character using a rotation key
    Then the encypted message is printed*/
   char text, encodedText;
   int k;
   printf("Enter text to be encrypted: \n");
   scanf("%c", text);
   printf("Enter the key integer: \n");
   scanf("%d", k);
   encodedText = (text + k)*(%26);
   printf("The encoded text is: %c\n", encodedText);
}
char decryptRotation()  {
    /*Needs to read text from user
    Then determines the allocated character of each charcter read from the user using a rotation key
    The decoded text is then printed*/ 
}
char encryptSubstitution()  {
    /* Completes the same task as case a) but uses a Substitution key */
}
char decryptSubstitution()  {
    /* Completes the same task as case b) but uses a Substitution key */
}
char decryptRotationText()  {
    /*This completes the same task as case b) but the key isn't given */ 
}
char decryptSubstitutionText()  {
    /*This completes the same task as case d) but the key isn't given*/
}
