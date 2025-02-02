#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NUM_ASSIGNMENTS 5

struct Student {
    char name[50];
    int studentID;
    float grades[NUM_ASSIGNMENTS];
    float avgGrade;
    char lettergrade;
};

struct Course {
    int courseNum;
    char courseName[50];
    struct Student *roster;
};

void createClassRoster(struct Course *course);
void inputStudentData(struct Course *course, int numStudents);
void calculateGrades(struct Course *course, int numStudents);
void displayStudentGrades(struct Course *course, int numStudents);

int main() {
    struct Course course;
    course.courseNum = 101;
    strcpy(course.courseName, "Introduction to Programming");

    createClassRoster(&course);

    int numStudents;
    printf("Enter the number of students in the class: ");
    scanf("%d", &numStudents);

    inputStudentData(&course, numStudents);
    calculateGrades(&course, numStudents);
    displayStudentGrades(&course, numStudents);

    free(course.roster);

    return 0;
}

void createClassRoster(struct Course *course) {
    course->roster = (struct Student *)malloc(MAX_STUDENTS * sizeof(struct Student));
    if (course->roster == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
}

void inputStudentData(struct Course *course, int numStudents) {
    for (int i = 0; i < numStudents; ++i) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]", course->roster[i].name);
        printf("Student ID: ");
        scanf("%d", &course->roster[i].studentID);

        printf("Enter grades for %d assignments:\n", NUM_ASSIGNMENTS);
        for (int j = 0; j < NUM_ASSIGNMENTS; ++j) {
            do {
                printf("Assignment %d grade: ", j + 1);
                scanf("%f", &course->roster[i].grades[j]);
                if (course->roster[i].grades[j] < 0 || course->roster[i].grades[j] > 100) {
                    printf("Invalid grade. Please enter a grade between 0 and 100.\n");
                }
            } while (course->roster[i].grades[j] < 0 || course->roster[i].grades[j] > 100);
        }
    }
}

void calculateGrades(struct Course *course, int numStudents) {
    float totalGrade;

    for (int i = 0; i < numStudents; ++i) {
        totalGrade = 0.0;
        for (int j = 0; j < NUM_ASSIGNMENTS; ++j) {
            totalGrade += course->roster[i].grades[j];
        }
        course->roster[i].avgGrade = totalGrade / NUM_ASSIGNMENTS;

        if (course->roster[i].avgGrade >= 90) {
            course->roster[i].lettergrade = 'A';
        } else if (course->roster[i].avgGrade >= 80) {
            course->roster[i].lettergrade = 'B';
        } else if (course->roster[i].avgGrade >= 70) {
            course->roster[i].lettergrade = 'C';
        } else if (course->roster[i].avgGrade >= 60) {
            course->roster[i].lettergrade = 'D';
        } else {
            course->roster[i].lettergrade = 'F';
        }
    }
}

void displayStudentGrades(struct Course *course, int numStudents) {
    printf("\nClass Roster for %s (Course Number: %d)\n", course->courseName, course->courseNum);
    printf("%-20s %-10s %-15s %-15s %-15s %-15s %-15s %-15s %-10s\n", "Name", "Student ID", "Assignment 1", "Assignment 2", "Assignment 3", "Assignment 4", "Assignment 5", "Avg Grade", "Letter Grade");

    for (int i = 0; i < numStudents; ++i) {
        printf("%-20s %-10d ", course->roster[i].name, course->roster[i].studentID);
        for (int j = 0; j < NUM_ASSIGNMENTS; ++j) {
            printf("%-15.2f", course->roster[i].grades[j]);
        }
        printf("%-15.2f %-10c\n", course->roster[i].avgGrade, course->roster[i].lettergrade);
    }
}
