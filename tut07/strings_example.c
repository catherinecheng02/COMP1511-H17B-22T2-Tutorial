#include <stdio.h>

// Manually prints out a string, one character at a time.
// Should behave like printf("%s\n");
void print_string(char *string) {
    int i = 0;
    while (string[i] != '\0') {
        printf("%c", string[i]);
        i++;
    }
    printf("\n");
}

//int is_lowercase(char c)；
//int count_lowercase(char *string);

//Provided char functions

// Returns : 1 if `c` is a lowercase letter
//         : 0 otherwise.
int is_lowercase(char c) {

    return 'a' <= c && c <= 'z';
}

// Returns : 1 if `c` is an uppercase letter
//         : 0 otherwise.
int is_uppercase(char c) {

    return 'A' <= c && c <= 'Z';
}

// Returns : 1 if `c` is a letter
//         : 0 otherwise.
int is_letter(char c) {

    return is_lowercase(c) || is_uppercase(c);
}

// Returns : `c` converted to lowercase, if it was an uppercase letter
//         : `c` unmodified, otherwise
char to_lowercase(char c) {
    if (is_uppercase(c)){
        return c - 'A' + 'a';
    }

    return c;
}

// Returns : `c` converted to uppercase, if it was a lowercase letter
//         : `c` unmodified, otherwise
char to_uppercase(char c) {
    if (is_lowercase(c)) {
        return c - 'a' + 'A';
    }

    return c;
}

// Returns : 1 if `c` is an uppercase or lowercase vowel
//         : 0 otherwise.
int is_vowel(char c) {
    char lower_c = to_lowercase(c);

    return lower_c == 'a' 
        || lower_c == 'e'
        || lower_c == 'i' 
        || lower_c == 'o' 
        || lower_c == 'u';
}

// Functions to implement:

// 1.
// returns the number of lowercase letters in `char *string`
int count_lowercase(char *string) {
    int i = 0;
    int num_of_lowercase = 0;
    while (string[i] != '\0') {
        
        num_of_lowercase = num_of_lowercase + is_lowercase(string[i]);

        i++;
    }
  return num_of_lowercase;
    
}
// modifies `char *string` by converting all its vowels to uppercase
void make_vowels_uppercase(char *string) {
  int i = 0;
  while (string[i] != '\0') {
    if (is_vowel(string[i])) {
      string[i] = to_uppercase(string[i]);
    }
    i++;
  }
 
}

// 3..
// shortens a string so that it ends after the first word
// e.g. "This is a sentence" should turn into:
//      "This"
// is_letter
// (hint. what defines when a string ends?)
void delete_following_words(char *string){
    int i = 0;
    //while (is_letter(string[i])) {
    //    if (is_letter(string[i]) == 1) {
    //        string[i] = string [i];
    //    } else {
    //        ;
    //    }
   // }

    while(string[i] != '\0') {
      if (!is_letter(string[i])) {
        string[i] = '\0';
      }
      i++;
    }
}

int main(void) {
    char my_string[] =  "The quick brown FOX jumped over the lazy Dog."; 
    int lowercase_characters;
    print_string(my_string);
    lowercase_characters = count_lowercase(my_string);
    printf("number of lowercase letters: %d\n", lowercase_characters);
    make_vowels_uppercase(my_string);  
    print_string(my_string);
    delete_following_words(my_string);
    print_string(my_string);
    return 0;
}
