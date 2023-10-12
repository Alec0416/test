#include "global.h"

int strgLen(char *s){
    // TO BE IMPLEMENTED
    int len = 0;
    while(*s!= '\0'){ //checks if the address contents is null character
        len++; // adds one to length 
        s++; // proceeds to next character in string
    }
    return len;
}
void strgCopy(char *s,char *d ){
    // TO BE IMPLEMENTED
    if(d!=NULL || s!=NULL){ //checks to see if both characters are null, if not then continues
    while(*s!= '\0' && *d!= '\0'){ //checks if either address contents are null character
        *d = *s; //puts s contents in d
        s++; //increments s
        d++; //increments d
    }
    *d = '\0'; //ends d with the null character once s is finished copying
    }
}
void strgChangeCase(char *s){
    // TO BE IMPLEMENTED
    while(*s!='\0'){ //iterates through string until null character
        if(islower(*s)){ //sets lower to upper
            *s = toupper(*s);
        }
        else if(isupper(*s)){ //sets upper ot lower 
            *s = tolower(*s);
        }
        s++; 
    }

}
int strgDiff(char *s1,char *s2 ){
    // TO BE IMPLEMENTED
    if(s1==NULL || s2 == NULL || *s1 == '\0' || *s2 == '\0'){ //returns -2 if either character is null or empty string
        return -2;
    }
    int index = 0;
    while(*s1!='\0' && *s2!='\0'){// iterates until end of either string
        if(*s1!=*s2){ //returns index if character is different
            return index;
        }
        index++; 
        s1++;
        s2++;
    }
    return -1; //if no character is different, return -1

}
void strgInterleave(char *s1, char *s2, char *d ){
    // TO BE IMPLEMENTED
    if(s1==NULL || s2 == NULL || d == NULL){ // returns if any address is NULL
        return;
    }
    while(*s1!='\0' && *s2!='\0' && *d!='\0'){ //iterates until end of either string or until d has no space
        *d = *s1; //puts s1 contents in d
        d++;
        if(*d=='\0'){
            break; //breaks if d has no space after incrementing d once
        }
        *d = *s2; //puts s2 contents in d after increment
        d++; 
        s1++; //increment all three 
        s2++;
    }
    if(*s1=='\0' && *s2!='\0'){ //if end of one string is reached but not the other, copy rest of other string to d
        strgCopy(s2,d);
    }
    else if(*s2=='\0' && *s1!='\0'){
        strgCopy(s1,d);
    }
    else{ // only if s1 and s2 are the same length or are both empty, the contents of d are set to null character
        *d = '\0';
    }

}
