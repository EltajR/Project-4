#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


typedef struct tuple {
    int letter_counter;
    int word_counter;
    int sentence_counter;
} tuple;

char *read_input(char *output_to_user);
int determine_type_of_char(char c);
tuple counter (char *user_input);
int determine_readability (float l_per_100_words , float s_per_100_words);
float per_100_words (int sentences_or_letters, int words);
void output_grade (int grade);

int main(void){
    while (1){
    char *user_input = read_input("Text:");
    tuple container = counter(user_input);
    float letters_per_100_words = per_100_words(container.letter_counter, container.word_counter);
    float sentences_per_100_words = per_100_words(container.sentence_counter, container.word_counter);
    int grade = determine_readability(letters_per_100_words, sentences_per_100_words);
    output_grade(grade);
    }
}

char *read_input(char *output_to_user){
    printf("%s", output_to_user);
    char *user_input = malloc(512 * sizeof(char));
    scanf(" %[^\n]",user_input);
    return user_input;
}

tuple counter(char *user_input){
    tuple counter_tuple;
    counter_tuple.letter_counter = 0;
    counter_tuple.word_counter = 0;
    counter_tuple.sentence_counter = 0;
    if(user_input == NULL) return counter_tuple;
    else {
        for (int len = strlen(user_input), i = 0; i < len; i++)
        {
            int bool = determine_type_of_char(user_input[i]);
            if(bool == 1) counter_tuple.letter_counter++;
            else if (bool == 2) counter_tuple.word_counter++;
            else if (bool == 3) counter_tuple.sentence_counter++;
        }
    }
    // The number of words is always 1 more than the number of spaces, so -->
    counter_tuple.word_counter++;
    return counter_tuple;
}

int determine_type_of_char(char c){
    // if it is a letter, return 1;
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) return 1;
    // if it is a space return 2;
    else if (c == ' ') return 2;
    // if it is a point, question, or exclamation mark, return 3
    else if ((c == '.') || (c == '?') || (c == '!')) return 3;
    // if it is anything else, return 0 -- not interested in that!
    else return 0;
}

float per_100_words(int sentences_or_letters, int words){ return sentences_or_letters/(float)words * 100; }

int determine_readability (float l_per_100_words , float s_per_100_words){
    float grade = 0.0588 * l_per_100_words - 0.296 * s_per_100_words - 15.8;
    return (int)roundf(grade);
}

void output_grade (int grade){
    if(grade >= 1 && grade < 16) printf("%s %i\n", "Grade", grade);
    else if(grade < 1) printf("%s\n", "Before grade 1");
    else printf("%s\n", "Grade 16+");
}

