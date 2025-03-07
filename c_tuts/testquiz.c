#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_QUESTIONS 100 // Increased to allow more questions
#define QUIZ_QUESTIONS 15 // Limit the number of questions per session
#define MAX_LENGTH 256
#define TIME_LIMIT 10 // Time limit per question in seconds

// Structure to hold quiz question and answers
typedef struct {
    char question[MAX_LENGTH];
    char options[4][MAX_LENGTH];
    char correct_answer;
} QuizQuestion;

void loadQuestions(QuizQuestion quiz[], int *totalQuestions);

int main() {
    QuizQuestion quiz[100];  // Assuming a max of 100 questions
    int totalQuestions = 0;

    loadQuestions(quiz, &totalQuestions);

    for (int i = 0; i < totalQuestions; i++) {
        printf("Q%d: %s\n", i+1, quiz[i].question);
        printf("%s\n", quiz[i].options[0]);
        printf("%s\n", quiz[i].options[1]);
        printf("%s\n", quiz[i].options[2]);
        printf("%s\n", quiz[i].options[3]);
        printf("Correct Answer: %c\n\n", quiz[i].correct_answer);
    }

    return 0;
}
void loadQuestions(QuizQuestion quiz[], int *totalQuestions) {
    FILE *file = fopen("questions.txt", "r");
    if (!file) {
        printf("Error: Could not open questions file.\n");
        exit(1);
    }

    while (fgets(quiz[*totalQuestions].question, MAX_LENGTH, file)) {
        // Remove trailing newline from question
        quiz[*totalQuestions].question[strcspn(quiz[*totalQuestions].question, "\n")] = '\0';
        
        for (int i = 0; i < 4; i++) {
            if (fgets(quiz[*totalQuestions].options[i], MAX_LENGTH, file)) {
                // Remove trailing newline from option
                quiz[*totalQuestions].options[i][strcspn(quiz[*totalQuestions].options[i], "\n")] = '\0';
            } else {
                printf("Error: Incomplete question set in file.\n");
                exit(1);
            }
        }

        if (fscanf(file, " %c\n", &quiz[*totalQuestions].correct_answer) != 1) {
            printf("Error: Invalid answer format in file.\n");
            exit(1);
        }
        (*totalQuestions)++;
    }

    fclose(file);
}
