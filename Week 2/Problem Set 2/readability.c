#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Gets the number of letters in the text
int count_letters(string text);

// Gets the number of words in the text
int count_words(string text);

// Gets the number of sentences in the text
int count_sentences(string text);

// Prints the index of the grade reading level
void get_grade_level(string text);

int main(void)
{
    string text = get_string("Text: ");

    printf("%d\n", count_letters(text));
    printf("%d\n", count_words(text));
    printf("%d\n", count_sentences(text));

    get_grade_level(text);

}

// Returns the number of letters in the text
int count_letters(string text)
{
    int letters = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]) != 0)
        {
            letters++;
        }
    }
    return letters;
}

// Returns the number of words in the text
int count_words(string text)
{
    int words = 0;

    for (int i = 0, n = strlen(text); i < n + 1; i++)
    {
        if (isspace(text[i]) != 0 || text[i] == '\0')
        {
            words++;
        }
    }
    return words;
}

int count_sentences(string text)
{
    int sentences = 0;

    for (int i = 0, n = strlen(text); i < n + 1; i++)
    {
        if (text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            sentences++;
        }
    }
    return sentences;
}

// Calculates the index of the grade reading level
void get_grade_level(string text)
{
    // Average of letters per 100 words in the text
    double L = ((double) count_letters(text) / (double)count_words(text)) * 100;

    // Average of sentences per 100 words in the text
    double S = ((double) count_sentences(text) / (double) count_words(text)) * 100;

    // Coleman-Liau Formula
    int grade_level = round(0.0588 * L - 0.296 * S - 15.8);

    if (grade_level <= 16 && grade_level >= 0)
    {
        printf("Grade %d\n", grade_level);
    }

    else if (grade_level < 0)
    {
        printf("Before Grade 1\n");
    }

    else
    {
        printf("Grade 16+\n");
    }
}
