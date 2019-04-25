#include <stdio.h>

/*The following 6 lines of code are function prototpes. 
Each function completes one of the six required tasks for this project
*/
char encryptRotation(char* message,char character, int key, int i);
char decryptRotation(char* message, char character, int key, int i);
char encryptSubstitution(char* message, char* newalphabet, char* alphabet, char character, int i, int j);
char decryptSubstitution(char* message, char* newalphabet, char* alphabet, char character, int i, int j);
char decryptRotationNoKey(char* message, char character, int key, int i);
//char decryptSubstitutionNoKey();

int main()  {
/* The following 4 lines of code are declarations of the arguments used in the 6 functions.
'message', 'alphabet' and 'newalphabet' are all arrays of type char which allows letters to be converted into numbers.
'character' is a single char variable.
'key' is an integer variable.
'i' and 'j' are integer varaibles that are used to represent array index/elements*/

char message[100]; //if the message to be encrypted/decrypted is longer than 100 characters then the array length must be altered
char newalphabet[26];
char alphabet[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char character=0;
int key=0; 
int i=0, j=0;

/* The following 10 lines of code prints a user friendly menu to the terminal 
and reads which option is chosen by a single letter*/ 
printf("Please select an option: \n");
printf("a) Encrypt using rotation cipher \n");
printf("b) Decrypt using rotation cipher \n");
printf("c) Encrypt using substitution cipher \n");
printf("d) Decrypt using substitution cipher \n");
printf("e) Decrypt using rotation cipher without known key\n");
//printf("f) Decrypt using substitution cipher without known key\n");
printf("Selection: ");
char option;
scanf ("%c",&option);

/* The following switch-case statements allocates each of the 6 functions to the letter option*/
switch (option)  {
    case 'a': encryptRotation(message, character, key, i); break;
    case 'b': decryptRotation(message, character, key, i); break;
    case 'c': encryptSubstitution(message, newalphabet, alphabet, character, i, j); break;
    case 'd': decryptSubstitution(message, newalphabet, alphabet, character, i, j); break;
    case 'e': decryptRotationNoKey(message, character, key, i); break;
    //case 'f': char decryptSubstitutionNoKey(); break;
    default: printf("Unknown option %c\n Please enter a, b, c or d\n", option);
}
  return 0;
}

/*The rest of the code includes the 6 function definitions, i.e what each task does */

/* The following function completes the first task of the project,
which involves encrypting text via a rotation cipher with a given key.
This function reads text from the terminal and stores it in the message array.
Each character of this array is then assigned a different character dependent on the key.
The new encrypted message is then printed to the terminal */

char encryptRotation(char* message, char character, int key, int i)     {
	
	printf("Enter a message to encrypt: ");
	scanf("%[^\n]*c",message); //reads text (includig the space key) from terminal and stores it in message[100]
	printf("Enter key: ");
	scanf("%d", &key);//reads integer from terminal and stores it in key
	
	for(i = 0; message[i] != '\0'; ++i)     {
		character = message[i]; // a single element from the array message[100] is assigned to the variable character
		
		if(character >= 'a' && character <= 'z')    {
			character = character-32;
		} //if the character is a lowercase letter it is converted to an uppercase letter
		
		if(character >= 'A' && character <= 'Z')   {
			character = character + key; //assigns new character dependent on the key integer
			
			if(character > 'Z')      {
				character = character - 'Z' + 'A' - 1;
			} //this loops the end letters of the alphabet back to the start, e.g. if the key is 1 then 'z' would be shifted to the 'a' position
			
			message[i] = character; //the new characters become the elements in the array message[100]
		}
	}
	
	printf("Encrypted message: %s", message); //the encrypted text is printed
	
	return 0;
}

/*The followng function completes the 2nd task of the project,
which involves reading encrypted text from the terminal and decrypting it using a rotation cipher with a given key.
The encrypted text is read from the terminal and stored in message[100]
Each character of this array is then assigned its original character dependent on the key.
The decrypted message is then printed to the terminal */ 

char decryptRotation(char* message, char character, int key, int i)     {
	
	printf("Enter a message to decrypt: ");
	scanf("%[^\n]*c",message); //reads encrypted text from the teminal (including space key) and stores it in the message array
	printf("Enter key: ");
	scanf("%d", &key); //reads integer from terminal and stores it in key
	
	for(i = 0; message[i] != '\0'; ++i)     {
		character = message[i]; //each element of the array is assigned to the variable character
		
		if(character >= 'a' && character <= 'z')    {
			character = character-32; //this converts lowercase letters to uppercase letters
		}
		
		if(character >= 'A' && character <= 'Z')   {
			character = character - key; //this assigns the original letter to character dependent on the key
			
			 if(character < 'A')  {
				    character = character + 'Z' - 'A' + 1; //this loops the start letters of the encrypted alphabet back to the end
			 }
			 
			message[i] = character; //the original letters become element in the array
		}
	}
	
	printf("Decrypted message: %s", message); //the decrypted message is printed
	
	return 0;
}

/* This function completes task 3 of the project, 
which involves encrypting text using a substitution cipher with the given new alphabet order.
The new alphabet order is read from the terminal and stored in the array newalphabet[26]
A message is also read from the terminal and stored in the message array.
Each letter of the message is assigned a new letter dependent on the new alphabet order and the encrypted message is printed.*/

char encryptSubstitution(char* message, char* newalphabet, char* alphabet, char character, int i, int j)    {
    
    printf("Enter a message to encrypt: \n");
    scanf("%[^\n]*c", message);//reads text from terminal and stores it in message[100]
    printf("Enter the new alphabet (IN CAPS): \n");
    scanf("%s", newalphabet);//reads text from terminal and stores it in newalphabet[26]
    
    for(i = 0; message[i] != '\0'; i++)     {
		character = message[i]; //each element of the message array is assigned to the varaiable character
		
        if(character>='a' && character<='z')    {
            character=character-32; //lowercase letters are converted to uppercase letters
        }
        
    	for (j=0; j<= 25 ; j++)     { //this loop allows each element of the alphabet array to be tested 
    	    if (character==alphabet[j])     { //if the character is an element in the alphabet array then the loop is executed
    	        character=newalphabet[j]; //character is assigned a new letter.This new character is the letter of the new alphabet that corresponds with the letter of the orginal alphabet 
	            message[i]= character; //the new letter become elements in the message array
	            break; //the loop exits once it reaches this line
	        }
	    }
    }
    printf("Encrypted message: %s", message); //the encrypted message is printed
    
	return 0;
}

/* This function completes task 4 of the project, 
which involves decrypting text with a given new order alphabet.
Encrypted text is read from terminal and stored in message [100].
The new alphabet order is read from the terminal and stored in newalphabet[26].
Each letter of the message is assigned its orginal letter dependent on the new order of the alphabet 
and the decrypted message is printed to the terminal.*/

char decryptSubstitution(char* message, char* newalphabet, char* alphabet, char character, int i, int j)    {
    
    printf("Enter a message to decrypt: \n");
    scanf("%[^\n]*c", message); //reads encrypted text from terminal and stores it in message[100]
    printf("Enter the new alphabet (IN CAPS): \n");
    scanf("%s", newalphabet); //reads string of letters from terminal and stores it in newalphabet[26]
    
    for(i = 0; message[i] != '\0'; i++)     {
		character = message[i]; //each element of the message array is assigned to the variable 'character'

        if(character>='a' && character<='z')    {
            character=character-32; //lowercase letters are converted to uppercase letters
        }
        
        for (j=0; j<= 25 ; j++)     { //this loops allows each element of the newalphabet array to be tested
	          if (character==newalphabet[j])     { //if the character is an element in the new alphabet then the loop is executed
	              character=alphabet[j]; //the character is assigned a letter in the alphabet that corresponds to the element in the new alphabet
	              message[i]= character; //the characters become elements in the message array
	              break; //the loop exits once it reaches this line
	          }
        }
    }
    printf("Decrypted message: %s", message); //the decrypted message is printed to the terminal
    
	return 0;
}

/* This function completes task 5 of the project, 
which involves decrypting text using a rotation cipher without knowing the key.
An encrypted message is read from the terminal and stored into the array message[100].
The message is then decrypted using a brute force attack where every possible key value is tested (1-26).
The decrypted message with its corresponding key is printed to the terminal.*/ 

char decryptRotationNoKey(char* message, char character, int key, int i)    {
	
	printf("Enter a message to decrypt: ");
	scanf("%[^\n]*c", message); //encrypted text is read from the terminal and stored in the array message[100]
	
	for(key =1; key<27; key++)  { //this loops allows every key from 1-26 to be tested
    	for(i = 0; message[i] != '\0'; ++i)    {
	    	character = message[i]; //each element of the array is assigned to character
	    	
	        if(character >= 'a' && character <= 'z')    {
			    character = character-32; //lowercase letters are converted to uppercase letters
		    }
		
		    if(character >= 'A' && character <= 'Z')   {
			character = character-1; //the character value is rotated "backwards" by 1 each time the loop is iterated, i.e. 'M' becomes 'L' then 'K' etc.
			
		        if(character < 'A')  {
				    character = character + 'Z' - 'A' + 1;
			    } //letters at start of alphabet are moved to the end each iteration, i.e. 'A' moves to 'Z'
			    
			message[i] = character; //each new character becomes an elememt in the message array
		    }
    	}   
	        printf("Key: %d Decrypted message: %s\n",key, message); //the decrypted message and corresponding key are printed to the terminal each iteration of the loop, i.e. 26 different messages will be printed on a new line
    }
    	return 0;
}

//char decryptSubstitutionNoKey()  {
    /*This completes the same task as case d) but the key isn't given*/
//} 
