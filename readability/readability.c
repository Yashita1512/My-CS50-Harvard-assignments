#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int grade(int countl, int countw, int counts, string text);

int main(void)
{
    //taking user text input gor grading
    string text = get_string("Text: ");

    //printing grade level
    if (grade(count_letters(text), count_words(text), count_sentences(text), text) < 2)
    {
        printf("Before Grade 1\n");
    }
    else if (grade(count_letters(text), count_words(text), count_sentences(text), text) > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade(count_letters(text), count_words(text), count_sentences(text), text));
    }
}

//counting number of letters
int count_letters(string text)
{
    int countl = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        //checking for lowercase and uppercase characters fount in typed text
        if (islower(text[i]) != 0 || isupper(text[i]) != 0)
        {
            countl++;
        }
    }
    return countl;
}

//counting number of words
int count_words(string text)
{
    int countw = 1;
    //iterating over text characters to encounter spaces so as to consider that string as a word
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            countw++;
        }
    }
    return countw;
}

//counting number of sentences
int count_sentences(string text)
{
    int counts = 0;
    char ends[] = {'.', '?', '!'};

    //iterating over text characters to encounter symbols that can end a sentence 
    for (int i = 0; i < strlen(text); i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (text[i] == ends[j])
            {
                counts++;
            }
        }
    }
    return counts;
}

//Calculating Coleman-Liau index
int grade(int countl, int countw, int counts, string text)
{
    float L = (count_letters(text) * 100.0) / count_words(text) ;
    float S = (count_sentences(text) * 100.0) / count_words(text);

    float index = (0.0588 * L) - (0.296 * S) - 15.8;
    return round(index);
}
