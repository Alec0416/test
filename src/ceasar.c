// feel free to use the functions that you made in Part1
#include "../include/global.h" 


int encrypt(const char *plaintext, char *ciphertext, int key){
    int encoded = 0;
    char *cipherOriginal = ciphertext;
    if(plaintext==NULL || ciphertext==NULL){  //checks to see if both characters are null, if not then continues
        return -2;
    }
    while(*plaintext!= '\0' && *ciphertext!= '\0'){ //loops until either address contents are null character
        if(plaintext==NULL || ciphertext==NULL){  //checks to see if both characters are null, if not then continues
            return -2;
        }
        if(isupper(*plaintext)){ //encrypts them and increments depending on type of character
            *ciphertext =  ((*plaintext+key-'A')%26)+'A';
            encoded++;
            ciphertext++;
        }
        else if(islower(*plaintext)){
            *ciphertext = ((*plaintext+key-'a')%26)+'a';
            encoded++;
            ciphertext++;
        }
        else if (*plaintext>='0' && *plaintext<='9'){
            *ciphertext = ((*plaintext+key-'0')%10)+'0';
            encoded++;
            ciphertext++;
        }
        else { // if it is not alphanumeric, do not encrypt
            *ciphertext = *plaintext;
            ciphertext++;
        }
        plaintext++;
    }
    if(encoded == 0){ //returns 0 if no characters are encoded
        strgCopy("undefined__EOM__",cipherOriginal);
        return 0;
    }
    if(strgLen(ciphertext)<7){ //returns -1 and attempts to copy the rest of the EOM marker if there is no space for the EOM marker
        strgCopy("__EOM__",ciphertext);
        return -1;
    }
    strgCopy("__EOM__",ciphertext); //copies the EOM marker
    return encoded; //returns encoded characters
}
int decrypt(const char *ciphertext, char *plaintext, int key){
    const char *eom = ciphertext;
    int decoded = 0;
    if(plaintext==NULL || ciphertext==NULL){  //checks to see if both characters are null, if not then continues
        return -2;
    }
    if(*eom == '\0'){
        return -1; //returns -1 if ciphertext is empty 
    } 
    while(*eom!='\0'){ //iterates through ciphertext to find EOM marker
        if(*eom == '\0'|| *(eom+1) == '\0' || *(eom+2) == '\0'|| *(eom+3) == '\0'|| *(eom+4) == '\0'|| *(eom+5) == '\0'|| *(eom+6) == '\0'){
            return -1; //returns -1 if null character is reached before EOM marker
        }
        else if(*eom == '_'&& *(eom+1) == '_' && *(eom+2) == 'E'&& *(eom+3) == 'O'&& *(eom+4) == 'M'&& *(eom+5) == '_'&& *(eom+6) == '_'){
            break; //saves EOM address in *eom if found
        }
        eom++;
    }
    while(ciphertext!=eom){ //iterates until address of ciphertext is equal to eom address
        if(*plaintext == '\0'){ //breaks if plaintext cannot fit message
            break;
        }
        if(isupper(*ciphertext)){ //decrypts them and increments depending on type of character
            *plaintext = (*ciphertext-key-'A'+26)%26+'A'; 
            decoded++;
            plaintext++;
        }
        else if(islower(*ciphertext)){
            *plaintext = (*ciphertext-key-'a'+26)%26+'a'; 
            decoded++;
            plaintext++;
        }
        else if (*ciphertext>='0' && *ciphertext<='9'){
            *plaintext = (*ciphertext-key-'0'+10)%10+'0'; 
            decoded++;
            plaintext++;
        }
        else { // if it is not alphanumeric, do not decrypt
            *plaintext = *ciphertext;
            plaintext++;
        }
        ciphertext++;
    }
    *plaintext = '\0';
    return decoded;
}
