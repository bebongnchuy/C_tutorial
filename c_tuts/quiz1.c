#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_LENGTH 256

typedef struct {
    char question[MAX_LENGTH];
    char options[4][MAX_LENGTH];
    char correct_answer;
} QuizQuestion;

void loadQuestions(QuizQuestion quiz[], int *totalQuestions);
int askQuestions(QuizQuestion quiz[], int totalQuestions);
void saveResults(const char *name, int score, int totalQuestions);

int main() {
    QuizQuestion quiz[MAX_QUESTIONS];
    int totalQuestions = 0;
    char name[MAX_LENGTH];

    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline

    loadQuestions(quiz, &totalQuestions);
    int score = askQuestions(quiz, totalQuestions);
    saveResults(name, score, totalQuestions);

    printf("\nQuiz complete! %s, your score is %d/%d.\n", name, score, totalQuestions);
    return 0;
}

void loadQuestions(QuizQuestion quiz[], int *totalQuestions) {
    FILE *file = fopen("questions.txt", "r");
    if (!file) {
        printf("Error: Could not open questions file.\n");
        exit(1);
    }

    while (fgets(quiz[*totalQuestions].question, MAX_LENGTH, file)) {
        for (int i = 0; i < 4; i++) {
            fgets(quiz[*totalQuestions].options[i], MAX_LENGTH, file);
        }
        fscanf(file, " %c\n", &quiz[*totalQuestions].correct_answer);
        (*totalQuestions)++;
    }
    fclose(file);
}

int askQuestions(QuizQuestion quiz[], int totalQuestions) {
    int score = 0;
    char answer;

    for (int i = 0; i < totalQuestions; i++) {
        printf("\nQ%d: %s", i + 1, quiz[i].question);
        for (int j = 0; j < 4; j++) {
            printf("%s", quiz[i].options[j]);
        }

        printf("Your answer (A, B, C, D): ");
        scanf(" %c", &answer);
        getchar(); // Consume newline

        if (toupper(answer) == quiz[i].correct_answer) {
            score++;
        }
    }
    return score;
}

void saveResults(const char *name, int score, int totalQuestions) {
    FILE *file = fopen("results.txt", "a");
    if (!file) {
        printf("Error: Could not open results file.\n");
        return;
    }
    fprintf(file, "%s: %d/%d\n", name, score, totalQuestions);
    fclose(file);
}
