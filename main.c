#include <stdio.h>
/*Need to have 6 different function prototypes:
Need to decide on data types and arguments*/
char encryptRotation(char* message, int key);
char decryptRotation(char* message, int key);
char encryptSubstitution(char* message, char* newalphabet, char* alphabet);
char decryptSubstitution(char* message, char* newalphabet, char* alphabet);
//char decryptRotationText();
//char decryptSubstitutionText();

int main()  {
char message[100];
char newalphabet[25];
char alphabet[25]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
int key;    
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

switch (option)  {
    case 'a': encryptRotation(message, key); break; 
    case 'b': decryptRotation(message, key); break;
   // case 'c': char encryptSubstitution(); break;
   // case 'd': char decryptSubstitution(); break;
   // case 'e': char decryptRotationText(); break;
   // case 'f': char decryptSubstitutionText(); break;
    default: printf("Unknown option %c\n Please enter a, b, c or d\n");
}
  return 0;
}

/*Need to include 6 different function definitions*/
char encryptRotation(char* message, int key)  {
    /*Needs to read text from user
    Then allocate each character a different character using a rotation key
    Then the encypted message is printed*/
  char character;
	int i;
	
	printf("Enter a message to encrypt: ");
	scanf("%[^\n]*c",message);
	printf("Enter key: ");
	scanf("%d", &key);
	
	for(i = 0; message[i] != '\0'; ++i)     {
		character = message[i];
		
		if(character >= 'a' && character <= 'z')    {
			character = character + key;
			
			if(character > 'z'){
				character = character - 'z' + 'a' - 1;
			}
			
			message[i] = character;
		}
		else if(character >= 'A' && character <= 'Z')   {
			character = character + key;
			
			if(character > 'Z')      {
				character = character - 'Z' + 'A' - 1;
			}
			
			message[i] = character;
		}
	}
	
	printf("Encrypted message: %s", message);
	
	return 0;
}

char decryptRotation(char* message, int key)  {
    /*Needs to read text from user
    Then determines the allocated character of each charcter read from the user using a rotation key
    The decoded text is then printed*/ 
   	char character;
	int i;
	
	printf("Enter a message to decrypt: ");
	scanf("%[^\n]*c",message);
	printf("Enter key: ");
	scanf("%d", &key);
	
	for(i = 0; message[i] != '\0'; ++i)    {
		character = message[i];
		
		if(character >= 'a' && character <= 'z'){
			character = character - key;
			
			if(character < 'a'){
				character = character + 'z' - 'a' + 1;
			}
			
			message[i] = character;
		}
		else if(character >= 'A' && character <= 'Z'){
			character = character - key;
			
			if(character < 'A')  {
				character = character + 'Z' - 'A' + 1;
			}
			
			message[i] = character;
		}
	}
	
	printf("Decrypted message: %s", message);
	
	return 0;
}

//this function does not yet work correctly
char encryptSubstitution(char* message, char* newalphabet, char* alphabet)  {
    /* Completes the same task as case a) but uses a Substitution key */
    char character;
    int i, j;
    
    printf("Enter a message (in caps) to encrypt: \n");
    scanf("%[^\n]*c", message);
    printf("Enter the new alphabet: \n");
    scanf("%s", newalphabet);
    
    for(i = 0; message[i] != '\0'; i++)     {
		character = message[i];

	for (j=0; j<= 25 ; j++)  {
	    if (character==alphabet[j]) {
	           character=newalphabet[j];
	           message[i]= character;
	           break;
	    }
	}
    }
    printf("Encrypted message: %s", message);
	return 0;
}

char decryptSubstitution(char* message, char* newalphabet, char* alphabet)  {
    /* Completes the same task as case b) but uses a Substitution key */
      char character;
    int i, j;
    
    printf("Enter a message (in caps) to decrypt: \n");
    scanf("%[^\n]*c", message);
    printf("Enter the new alphabet: \n");
    scanf("%s", newalphabet);
    
    for(i = 0; message[i] != '\0'; i++)     {
		character = message[i];

	for (j=0; j<= 25 ; j++)  {
	    if (character==newalphabet[j]) {
	           character=alphabet[j];
	           message[i]= character;
	           break;
	    }
	}
    }
    printf("Decrypted message: %s", message);
	return 0;
}

//char decryptRotationText()  {
    /*This completes the same task as case b) but the key isn't given */ 
//}
//char decryptSubstitutionText()  {
    /*This completes the same task as case d) but the key isn't given*/
//} 
