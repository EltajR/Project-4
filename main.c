#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct tuple {
    int letter_counter;
    int word_counter;
    int sentence_counter;
} tuple;

char *read_input(void);
int determine_type_of_char(char c);
tuple counter (char *user_input);
int determine_readability (int w_per_100_l , int s_per_100_l);
void output_grade (int readability_level);




int main(void){

    char *user_input = read_input();
    tuple container = counter(user_input);
    printf("%s: %i\n", "Letter count", container.letter_counter);
    printf("%s: %i\n", "Word count", container.word_counter);
    printf("%s: %i\n", "Sentence count", container.sentence_counter);
}

char *read_input(void){
    char *user_input = malloc(512 * sizeof(char));
    scanf(" %[^\n]",user_input);
    return user_input;
}

// What if there is one word and no space around it? -- Possible Error!
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

