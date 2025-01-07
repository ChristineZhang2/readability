int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");
    int letters = 0;
    int words = 1;
    int sentences = 0;

    // Count the number of letters, words, and sentences in the text
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // Return the number of letters in text
        if (isalpha(text[i]))
        {
            letters += 1;
        }

        // Return the number of words in text
        if (isspace(text[i]) && !isspace(text[i + 1]))
        {
            words += 1;
        }

        // Return the number of sentences in text
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences += 1;
        }
    }

    // One for loop for validation in int main void

    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;

    // Compute the Coleman-Liau index
    float coleman_index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(coleman_index);
    // printf("%f\n",coleman_index);

    // Print the grade level
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", grade);
    }
    return 0;
}
