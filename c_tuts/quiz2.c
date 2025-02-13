#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_QUESTIONS 100
#define MAX_LENGTH 256
#define TIME_LIMIT 10 // Time limit per question in seconds

typedef struct {
    char question[MAX_LENGTH];
    char options[4][MAX_LENGTH];
    char correct_answer;
} QuizQuestion;

typedef struct {
    char name[MAX_LENGTH];
    int score;
    int totalQuestions;
} PlayerResult;

void loadQuestions(QuizQuestion quiz[], int *totalQuestions);
void shuffleQuestions(QuizQuestion quiz[], int totalQuestions);
int askQuestions(QuizQuestion quiz[], int totalQuestions, char correctAnswers[]);
void saveResults(PlayerResult player);
void displayCorrectAnswers(QuizQuestion quiz[], int totalQuestions, char correctAnswers[]);

int main() {
    QuizQuestion quiz[MAX_QUESTIONS];
    int totalQuestions = 0;
    char name[MAX_LENGTH];
    char correctAnswers[MAX_QUESTIONS];

    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline

    loadQuestions(quiz, &totalQuestions);
    shuffleQuestions(quiz, totalQuestions);
    int score = askQuestions(quiz, totalQuestions, correctAnswers);

    PlayerResult player;
    strcpy(player.name, name);
    player.score = score;
    player.totalQuestions = totalQuestions;
    saveResults(player);

    printf("\nQuiz complete! %s, your score is %d/%d.\n", name, score, totalQuestions);
    displayCorrectAnswers(quiz, totalQuestions, correctAnswers);
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

void shuffleQuestions(QuizQuestion quiz[], int totalQuestions) {
    srand(time(NULL));
    for (int i = totalQuestions - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        QuizQuestion temp = quiz[i];
        quiz[i] = quiz[j];
        quiz[j] = temp;
    }
}

int askQuestions(QuizQuestion quiz[], int totalQuestions, char correctAnswers[]) {
    int score = 0;
    char answer;
    time_t start, end;
    
    for (int i = 0; i < totalQuestions; i++) {
        correctAnswers[i] = quiz[i].correct_answer;
        printf("\nQ%d: %s", i + 1, quiz[i].question);
        for (int j = 0; j < 4; j++) {
            printf("%s", quiz[i].options[j]);
        }

        printf("Your answer (A, B, C, D): ");
        start = time(NULL);
        scanf(" %c", &answer);
        end = time(NULL);
        getchar(); // Consume newline

        if (difftime(end, start) > TIME_LIMIT) {
            printf("Time's up! No points for this question.\n");
            continue;
        }

        if (toupper(answer) == quiz[i].correct_answer) {
            score++;
            printf("Correct!\n");
        } else {
            printf("Wrong! The correct answer was %c.\n", quiz[i].correct_answer);
        }
    }
    return score;
}

void saveResults(PlayerResult player) {
    FILE *file = fopen("results.txt", "a");
    if (!file) {
        printf("Error: Could not open results file.\n");
        return;
    }
    fprintf(file, "%s: %d/%d\n", player.name, player.score, player.totalQuestions);
    fclose(file);
}

void displayCorrectAnswers(QuizQuestion quiz[], int totalQuestions, char correctAnswers[]) {
    printf("\nCorrect Answers:\n");
    for (int i = 0; i < totalQuestions; i++) {
        printf("Q%d: %c\n", i + 1, correctAnswers[i]);
    }
}
