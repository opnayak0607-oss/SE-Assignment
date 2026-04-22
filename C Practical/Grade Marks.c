#include <stdio.h>

int main() {
    int marks;

    printf("Enter marks: ");
    scanf("%d", &marks);

    if (marks >= 90 && marks <= 100) {
        printf("Grade: A");
    }
    else if (marks >= 75) {
        printf("Grade: B");
    }
    else if (marks >= 60) {
        printf("Grade: C");
    }
    else if (marks >= 50) {
        printf("Grade: D");
    }
    else if (marks >= 0) {
        printf("Grade: F");
    }
    else {
        printf("Invalid marks");
    }

    return 0;
}