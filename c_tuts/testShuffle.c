#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 256
#define MAX_QUESTIONS 100

typedef struct {
    char question[MAX_LENGTH];
    char options[4][MAX_LENGTH];
    char correct_answer;
} QuizQuestion;

void shuffleQuestions(QuizQuestion quiz[], int totalQuestions);

int main() {
    QuizQuestion quiz[MAX_QUESTIONS] = {
        {"What is the capital of France?", {"Paris", "London", "Berlin", "Rome"}, 'A'},
        {"Which planet is known as the Red Planet?", {"Earth", "Mars", "Jupiter", "Saturn"}, 'B'},
        {"Who wrote 'Hamlet'?", {"Shakespeare", "Dickens", "Hemingway", "Twain"}, 'A'}
    };
    int totalQuestions = 3;

    printf("Before Shuffle:\n");
    for (int i = 0; i < totalQuestions; i++) {
        printf("Q%d: %s\n", i + 1, quiz[i].question);
    }

    shuffleQuestions(quiz, totalQuestions);

    printf("\nAfter Shuffle:\n");
    for (int i = 0; i < totalQuestions; i++) {
        printf("Q%d: %s\n", i + 1, quiz[i].question);
    }

    return 0;
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
