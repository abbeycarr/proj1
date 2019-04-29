#include <stdio.h>

/*The following 6 lines of code are function prototpes. 
Each function completes one of the six required tasks for this project*/

int encryptRotation(char* message,char character, int key, int i);
int decryptRotation(char* message, char character, int key, int i);
int encryptSubstitution(char* message, char* newalphabet, char* alphabet, char character, int i, int j);
int decryptSubstitution(char* message, char* newalphabet, char* alphabet, char character, int i, int j);
int decryptRotationNoKey(char* message, char character, int key, int i);
int decryptSubstitutionNoKey(char* message, char character, int i);

int main()  {
/* The following 4 lines of code are declarations of the arguments used in the 6 functions.
'message', 'alphabet' and 'newalphabet' are all arrays of type char which allows letters to be converted into numbers.
'character' is a single char variable.
'key' is an integer variable.
'i' and 'j' are integer varaibles that are used to represent array index/elements*/

char message[500]; //if the message to be encrypted/decrypted is longer than 500 characters then the array length must be altered
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
printf("f) Decrypt using substitution cipher without known key\n");
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
    case 'f': decryptSubstitutionNoKey(message, character, i); break;
    default: printf("Unknown option: '%c'\nPlease enter a, b, c, d, e or f\n", option);
}
  return 0;
}

/*The rest of the code includes the 6 function definitions, i.e what each task does */

/* The following function completes the first task of the project,
which involves encrypting text via a rotation cipher with a given key.
The 4 inputs are: message and key (read from the terminal) and character and int i
This function returns the integer 0.
This function reads text from the terminal and stores it in the message array.
Each character of this array is then assigned a different character dependent on the key.
The new encrypted message is then printed to the terminal.
Limitations: the message to be encrypted must have a maximum of 500 characters */

int encryptRotation(char* message, char character, int key, int i)     {
	
	printf("Enter a message to encrypt: ");
	scanf(" %[^\n]*c",message); //reads text (includig the space key) from terminal and stores it in message[500]
    printf("Enter key: ");
	scanf("%d", &key);//reads integer from terminal and stores it in key
	
	for(i = 0; message[i] != '\0'; ++i)     {
		character = message[i]; // a single element from the array message[500] is assigned to the variable character
		
		if(character >= 'a' && character <= 'z')    {
			character = character-32;
		} //if the character is a lowercase letter it is converted to an uppercase letter
		
		if(character >= 'A' && character <= 'Z')   {
			character = character + key; //assigns new character dependent on the key integer
			
			if(character > 'Z')      {
				character = character - 'Z' + 'A' - 1;
			} //this loops the end letters of the alphabet back to the start, e.g. if the key is 1 then 'z' would be shifted to the 'a' position
			
			message[i] = character; //the new characters become the elements in the array message[500]
		}
	}
	
	printf("Encrypted message: %s", message); //the encrypted text is printed
	
	return 0;
}

/*The following function completes the 2nd task of the project,
which involves reading encrypted text from the terminal and decrypting it using a rotation cipher with a given key.
The 4 inputs are: message, character, key and i.
The function returns the integer 0.
The encrypted text is read from the terminal and stored in message[500]
Each character of this array is then assigned its original character dependent on the key.
The decrypted message is then printed to the terminal.
Limitations: the message must be less than 500 characters */ 

int decryptRotation(char* message, char character, int key, int i)     {
	
	printf("Enter a message to decrypt: ");
	scanf(" %[^\n]*c",message); //reads encrypted text from the teminal (including space key) and stores it in the message array
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
This function has 6 inputs: message, alphabet, newalphabet, character, i and j.
The function returns the integer 0.
The new alphabet order is read from the terminal and stored in the array newalphabet[26]
A message is also read from the terminal and stored in the message array.
Each letter of the message is assigned a new letter dependent on the new alphabet order and the encrypted message is printed.
Limitations: the message must be 500 charcters or less */

int encryptSubstitution(char* message, char* newalphabet, char* alphabet, char character, int i, int j)    {
    
    printf("Enter a message to encrypt: ");
    scanf(" %[^\n]*c", message);//reads text from terminal and stores it in message[500]
    printf("Enter the new alphabet (IN CAPS): ");
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
The 6 inputs are: message, alphabet, newalphabet, character, i and j.
This function returns the integer 0.
Encrypted text is read from terminal and stored in message [500].
The new alphabet order is read from the terminal and stored in newalphabet[26].
Each letter of the message is assigned its orginal letter dependent on the new order of the alphabet 
and the decrypted message is printed to the terminal.
Limitations: the message must be 500 charcters or less.*/

int decryptSubstitution(char* message, char* newalphabet, char* alphabet, char character, int i, int j)    {
    
    printf("Enter a message to decrypt: ");
    scanf(" %[^\n]*c", message); //reads encrypted text from terminal and stores it in message[500]
    printf("Enter the new alphabet (IN CAPS): ");
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
The inputs are: message, character, key and i.
This function returns the integr 0.
An encrypted message is read from the terminal and stored into the array message[500].
The message is then decrypted using a brute force attack where every possible key value is tested (1-26).
The decrypted message with its corresponding key is printed to the terminal.
LImitations: the message must be 500 characters or less.*/ 

int decryptRotationNoKey(char* message, char character, int key, int i)    {
	
	printf("Enter a message to decrypt: ");
	scanf(" %[^\n]*c", message); //encrypted text is read from the terminal and stored in the array message[500]
	
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
	        printf("Key: %d Decrypted message: %s\n\n",key, message); //the decrypted message and corresponding key are printed to the terminal each iteration of the loop, i.e. 26 different messages will be printed on a new line
    }
        printf("Scroll through the 25 keys to find the decrypted message\n");
        return 0;
}

/*This function completes part of task 6 of the project: takes the first day encrypted message and partially decrypts it.
It has 3 inputs: message, character and i.
The function returns the integer zero.
This function basically invloves a switch-case statement that replaces the encrypted letter with the decrypted letters.
These decrypted letters where chosen by recognising common 1 letter, 2 letter and 3 letter words and entering them via trial and error.
*/

int decryptSubstitutionNoKey(char* message, char character, int i)    {
    
    printf("Enter the first day message to decrypt: \n");
    scanf(" %[^\n]*c", message);
    
    for(i=0; message[i]!='\0'; i++)     {
        character=message[i]; //each element of the message becomes 'character'
        
        switch(character)   { //this loop replaces the letters in the message with new letters 
            case 'F': character='T'; break;
            case 'B': character='E'; break;
            case 'N': character='A'; break;
            case 'R': character='D'; break;
            case 'C': character='I'; break;
            case 'J': character='S'; break;
            case 'P': character='H'; break;
            case 'K': character='N'; break;
            case 'Y': character='O'; break;
            case 'T': character='U'; break;
            case 'Z': character='L'; break;
            case 'I': character='P'; break;
            case 'Q': character='G'; break;
            case 'V': character='Y'; break;
            case 'X': character='R'; break;
            case 'E': character='U'; break;
            case 'G': character='V'; break;
            case 'M': character='N'; break;
            case 'D': character='J'; break;
            case 'O': character='M'; break;
        }
        
        message[i]=character; //the new letters become elements in the new decrypted message
    }
    printf("Partially decrypted message: %s", message);
    return 0;
}
