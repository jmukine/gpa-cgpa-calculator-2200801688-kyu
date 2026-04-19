/*
Name: Your Name MUKINE JOEL
Registration Number: 22/U/BIO/1688/PD
*/

#in#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void getGradeAndPoint(float score, char *grade, int *point) {
    if (score >= 80) { *grade = 'A'; *point = 5; }
    else if (score >= 70) { *grade = 'B'; *point = 4; }
    else if (score >= 60) { *grade = 'C'; *point = 3; }
    else if (score >= 50) { *grade = 'D'; *point = 2; }
    else { *grade = 'F'; *point = 0; }
}

void getClassification(float cgpa, char *classification) {
    if (cgpa >= 4.40) strcpy(classification, "First Class");
    else if (cgpa >= 3.60) strcpy(classification, "Second Class Upper");
    else if (cgpa >= 2.80) strcpy(classification, "Second Class Lower");
    else if (cgpa >= 2.00) strcpy(classification, "Pass");
    else strcpy(classification, "Fail");
}

int main() {
    char *sem1_code[] = {"TEMB 1101","TEMB 1102","TEMB 1103","TEMB 1104",
                         "TEMB 1105","TEMB 1106","TEMB 1107","TEMB 1108"};
    int sem1_credit[] = {4,3,3,3,3,3,2,3};

    char *sem2_code[] = {"TEMB 1201","TEMB 1202","TEMB 1203","TEMB 1204",
                         "TEMB 1205","TEMB 1206","TEMB 1207","TEMB 1208"};
    int sem2_credit[] = {4,3,3,3,3,3,3,3};

    float sem1_score[8], sem2_score[8];
    char sem1_grade[8], sem2_grade[8];
    int sem1_point[8], sem2_point[8];
    int sem1_weighted[8], sem2_weighted[8];

    float sem1_tw = 0, sem2_tw = 0;
    int sem1_tc = 0, sem2_tc = 0;

    // Input scores with indicators
    printf("SEMESTER 1\n");
    for (int i = 0; i < 8; i++) {
        printf("%s (%d credits): ", sem1_code[i], sem1_credit[i]);
        scanf("%f", &sem1_score[i]);
        if (sem1_score[i] < 0 || sem1_score[i] > 100) {
            printf("invalid score entered\n");
            return 0;
        }
        getGradeAndPoint(sem1_score[i], &sem1_grade[i], &sem1_point[i]);
        sem1_weighted[i] = sem1_point[i] * sem1_credit[i];
        sem1_tw += sem1_weighted[i];
        sem1_tc += sem1_credit[i];
    }

    printf("\nSEMESTER 2\n");
    for (int i = 0; i < 8; i++) {
        printf("%s (%d credits): ", sem2_code[i], sem2_credit[i]);
        scanf("%f", &sem2_score[i]);
        if (sem2_score[i] < 0 || sem2_score[i] > 100) {
            printf("invalid score entered\n");
            return 0;
        }
        getGradeAndPoint(sem2_score[i], &sem2_grade[i], &sem2_point[i]);
        sem2_weighted[i] = sem2_point[i] * sem2_credit[i];
        sem2_tw += sem2_weighted[i];
        sem2_tc += sem2_credit[i];
    }

    float sem1_gpa = sem1_tw / sem1_tc;
    float sem2_gpa = sem2_tw / sem2_tc;
    float cgpa = (sem1_tw + sem2_tw) / (sem1_tc + sem2_tc);

    char classification[25];
    getClassification(cgpa, classification);

    system("cls"); // clears the input prompts & indicators

    printf("=== FULL ACADEMIC REPORT ===\n\n");

    printf("SEMESTER I\n");
    printf("%-12s %-6s %-6s %-12s %-12s %-20s\n", "Course code", "Score", "Grade", "Grade point", "Credit unit", "Weighted contribution");
    printf("----------------------------------------------------------------------------------------\n");
    for (int i = 0; i < 8; i++) {
        printf("%-12s %-6.1f %-6c %-12d %-12d %-20d\n", sem1_code[i], sem1_score[i], sem1_grade[i], sem1_point[i], sem1_credit[i], sem1_weighted[i]);
    }
    printf("CGPA: %.2f\n", sem1_gpa);

    printf("\nSEMESTER II\n");
    printf("%-12s %-6s %-6s %-12s %-12s %-20s\n", "Course code", "Score", "Grade", "Grade point", "Credit unit", "Weighted contribution");
    printf("----------------------------------------------------------------------------------------\n");
    for (int i = 0; i < 8; i++) {
        printf("%-12s %-6.1f %-6c %-12d %-12d %-20d\n", sem2_code[i], sem2_score[i], sem2_grade[i], sem2_point[i], sem2_credit[i], sem2_weighted[i]);
    }

    printf("\nSemester I GPA: %.2f\n", sem1_gpa);
    printf("Semester II GPA: %.2f\n", sem2_gpa);
    printf("CGPA: %.2f\n", cgpa);
    printf("Classification: %s\n", classification);

    return 0;
}
}
