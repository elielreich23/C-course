/* code for counting prime numbers till 10
 #include <stdio.h>

int main (){
 int  n[11];
    /*printf("Enter a number ");
     scanf("%d", &n);
    for (int i = 1; i <= n[10]; i++){
        if (i % 2  == 0)
        {
           printf("%d\n", i);
       }
     }
}*/

/* can't recall what this do
#include <stdio.h>
#define  TAM 10
int main()
{
   int idade[TAM], pos;
    for (pos = 0; pos < TAM; pos++){
        printf("%n", idade[pos]);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main(){
    double A, B, Media;

    printf("Digite uma nota");
    scanf("%lf", &A);
    printf("Digite uma ou tra nota");
    scanf("%lf", &B);
    Media = (A + B)/2;
    printf("MEDIA =  %.5lf", Media);
}*/

/*#include <stdio.h>
#include <stdlib.h>

int main (){
    int input, lenght, width, height, radius, side, base;
    float area;

    printf("_____input a digite to calculta the area of the gigure______\n");
    printf("Input 1 for to calculate for a rectangle\n");
    printf("Input 2 for to calculate for a triangle\n");
    printf("Input 3 for to calculate for a square\n");
    printf("Input 4 for to calculate for a circle\n");
    printf("Input a digite:");
    scanf("%d", &input);

    if (input == 1){
        printf("enter the two values of a rectangle: ");
        scanf("%d%d", &lenght, &width);
        area = lenght * width;
        printf("area of rectangle = %.2f\n", area);
    }else if (input == 2 ){
        printf("enter the base and height of the figure");
        scanf("%d%d", &base, &height);
        area = 0.5 * base * height;
        printf("area of triangle = %.2f\n", area);
    }else if (input == 3){
        printf("enter the sides of the square: ");
        scanf("%d", &side);
        area = side * side;
        printf("the are of a rectangle is = %.2f\n", area);
    }else if (input == 4){
        printf("enter the radius of a circle: ");
        scanf("%d", &radius);
        area = 3.142 * radius * radius;
        printf("the area of a circle is =%.2f\n", area);
    }else{
        printf("error please choose one of the 4 options for a figure");
    };

}*/

/*#include <stdio.h>
#include <stdlib.h>

int main()
{
    int input, lenght, width, height, radius, side, base;
    float area;

    printf("_____input a digite to calculta the area of the gigure______\n");
    printf("Input 1 for to calculate for a rectangle\n");
    printf("Input 2 for to calculate for a triangle\n");
    printf("Input 3 for to calculate for a square\n");
    printf("Input 4 for to calculate for a circle\n");
    printf("Input a digite:");
    scanf("%d", &input);

    switch (input)
    {
    case 1:
        printf("enter the two values of a rectangle: ");
        scanf("%d%d", &lenght, &width);
        area = lenght * width;
        printf("area of rectangle = %.2f\n", area);
        break;
    case 2:
        printf("enter the base and height of the figure");
        scanf("%d%d", &base, &height);
        area = 0.5 * base * height;
        printf("area of triangle = %.2f\n", area);
        break;
    case 3:
        printf("enter the sides of the square: ");
        scanf("%d", &side);
        area = side * side;
        printf("the are of a rectangle is = %.2f\n", area);
        break;
    case 4:
        printf("enter the radius of a circle: ");
        scanf("%d", &radius);
        area = 3.142 * radius * radius;
        printf("the area of a circle is =%.2f\n", area);

    default:
        printf("error please choose one of the 4 options for a figure");
        break;
    }
}*/

// calculate the distance of two points
/*#include <stdio.h>
#include <math.h>

int main (){

    int x1, x2, y1, y2;
    float d;

    printf("enter the two coordinates of x:\n");
    scanf("%d%d", &x1, &x2);
    printf("enter the two coordinates of y:\n");
    scanf("%d%d", &y1, &y2);
    d = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
    printf("\nthe distance between the two points is %.2f ", d);
}*/
/*
#include <stdio.h>
#include <math.h>
int main()
{
    double a,b,c;

    printf("enter the sides of your triangle\n");
    scanf("%lf%lf", &a, &b);
    c = sqrt(pow(a, 2) + (b, 2));
    printf("the third side is %lf", c);

    return 0;
}*/
/*fibonacci of nth terms
#include <stdio.h>
int main()
{
    int n1=0,n2=1,n3,num;
    printf("enter a given number:\n");
    scanf("%d", &num);
    printf("%d, %d, ", n1, n2);
    for (int i =2; i<num; i++){
        n3 = n1 +n2;
        printf("%d, ",n3);
        n1=n2;
        n2=n3;
    }
    return 0;
}*/

/*fibo series up certain number
#include <stdio.h>
int main()
{
    int n1 = 0, n2 = 1, n3 = 0, num;
    printf("enter a given number:\n");
    scanf("%d", &num);
    printf("%d, %d, ", n1, n2);
    n3 = n1 +n2;
    while (n3<=num)
    {
        printf("%d, ", n3);
        n1 = n2;
        n2 = n3;
        n3 = n1 +n2;
    }

    return 0;
}*/
// count even and odd numbers in an array
/*
#include <stdio.h>
int main()
{
    int arr[5];
    int couteven=0, countodd=0, n=0, i;
    printf("enter 5 random numbers:\n");
    scanf("%d", &n);
    for(i = 0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    for(i = 0; i<n; i++){
        if (arr[i] % 2 == 0 ){
            couteven +=1;
        }
        else{
            countodd += 1;
        }
    }
        printf("the number of even is %d and the number of odd is %d", couteven, countodd );

    return 0;
}*/

// program that seach for a element in an array of a predefined size
/*
#include <stdio.h>
int main()
{
    int arr[5];
    int n = 0, i, choice = 0, found = 0;
    printf("enter random numbers:\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("what number are you searching for: \n");
    scanf("%d", &choice);
    for (i = 0; i < n; i++)
    {
        if (arr[i] == choice)
        {
            printf("Element found\n");
            found = 1;
            break;
        }
    }
    if (found == 0)
    {
        printf("element not found");
    }
    return 0;
}*/
/*

#include <stdio.h>
#define MAX_SIZE 100
int main()
{
    int arr[MAX_SIZE];
    int size, choice, i, found;

    printf("enter the size of the array:\n");
    scanf("%d", &size);
    printf("enter the contents of the array:\n");
    for(i=0; i<size; i++){
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to seach : \n");
    scanf("%d", &choice);

    found = 0;
    for(i = 0; i<size; i++){
        if (arr[i] == choice){
            found = 1;
            break;
        }
    }
    for (i = 0; i<size; i++){
        if(arr[i] == choice){

        }
    }
    if(found == 1){
        printf("\n %d the element is found at position %d", choice, i + 1);
    }
    else{
        printf("\n %d element is not in array\n", choice);
    }

    return 0;
}*/
// program to get the number of even and odd number in an array
/*
#include <stdio.h>
#define MAX_SIZE 50
int main()
{
    // int arr[MAX_SIZE];
    int arr[MAX_SIZE];
    int size, odd, i, even;

    printf("enter the size of the array:\n");
    scanf("%d", &size);
    printf("enter the contents of the array:\n");
    for(i=0; i<size; i++){
        scanf("%d", &arr[i]);
    }
    for (i=0; i<size; i++){
        if (arr[i] % 2 == 0){
            even++;
        }
        else if (arr[i] % 2 != 0)
        {
            odd++;
        }
    }
    printf("the number of even numbers is %d and the nummber of odd numbers is %d", even, odd);

    return 0;
}*/

// program to get the smallest element of an array
// #include <stdio.h>
// #define MAX_SIZE 100
// int main()
// {
//     int arr[MAX_SIZE];
//     int size, small, i, position;

//     printf("enter the size of the array:\n");
//     scanf("%d", &size);
//     printf("enter the contents of the array:\n");
//     for(i=0; i<size; i++){
//         scanf("%d", &arr[i]);
//     }
//     small = arr[0];
//     for (i =0; i <size; i++){
//         if (small>arr[i]){
//             small = arr[i];
//             position = i;
//         }
//     }
//     printf("the smallest element is %d and is at position %d", small, position);
//     return 0;
// }

// add a number to each position of an array (array is already predefined)
/* #include <stdio.h>

int main()
{
    int number = 3;
    int arr[8] = {1, 3, 4 ,5, 6, 7, 8, 9};

    for (int i = 0; i < 8; i++)
    {
        if (arr[0] == 1)
        {
            arr[0] = arr[0] + number;
        }
        else if (arr[i] % 2 == 0)
        {
            arr[i] += number;
        }
        printf("%d ", arr[i]);
    }
} */

// same program with array defined by user
/*
#include <stdio.h>
#define MAX_SIZE 100
int main()
{
    int arr[MAX_SIZE];
    int size, small, number, i;

    printf("enter the size of the array:\n");
    scanf("%d", &size);
    printf("enter the contents of the array:\n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("enter a value to add: ");
    scanf("%d", &number);
    printf("\nthe array is: ");
    for (i = 0; i < size; i++)
    {
        arr[i] += number;
        printf("%d ", arr[i]);
    }
} */

//program that adds a number enter ed to all pair numbers of the array
 /*
#include <stdio.h>
#define MAX_SIZE 100
int main()
{
    int arr[MAX_SIZE];
    int size, small, number, i;

    printf("enter the size of the array:\n");
    scanf("%d", &size);
    printf("enter the contents of the array:\n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("enter a value to add: ");
    scanf("%d", &number);
    printf("\nthe array is: ");
    for (i = 0; i < size; i++)
    {
        if (arr[0] == 1)
        {
            arr[0] = arr[0] + number;
        }
        else if (arr[i] % 2 == 0)
        {
            arr[i] += number;
        }
        printf("%d ", arr[i]);
    }
} */


/**************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

***************************/
/*
#include <stdio.h>

int main()
{
    int rows, cols,  i, j;
    printf("please enter the number of rows: \n");
    scanf("%d", &rows);
    printf("please enter the number of colums: \n");
    scanf("%d", &cols);
    
    int arr[rows][cols];
    
    printf("Enter the elements of the array:\n");

    for(i=0; i<rows; i++){
         printf("enter element at position [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        for(j=0;j<cols;j++){
            printf("enter element at position [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    
    printf("the 2d array is:\n");
     for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}*/
/*
#include <stdio.h>

#define STUDENTS 6
#define SUBJECTS 5

int main() {
    int scores[STUDENTS][SUBJECTS];

    printf("Enter the scores of the students:\n");

    // Read scores from the user and store them in the array
    for (int i = 0; i < STUDENTS; i++) {
        printf("Enter scores for student %d:\n", i + 1);
        for (int j = 0; j < SUBJECTS; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%d", &scores[i][j]);
        }
        printf("\n");
    }

    printf("\nThe scores of the students are:\n");

    // Display the scores of the students
    for (int i = 0; i < STUDENTS; i++) {
        printf("Scores for student %d:\n", i + 1);
        for (int j = 0; j < SUBJECTS; j++) {
            printf("Subject %d: %d\n", j + 1, scores[i][j]);
        }
        printf("\n");
    }

    return 0;
}

#include <stdio.h>

#define STUDENTS 5
#define SUBJECTS 5

int main() {
    int scores[STUDENTS][SUBJECTS];

    // Input scores for each student and subject
    for (int i = 0; i < STUDENTS; i++) {
        printf("Enter scores for student %d:\n", i + 1);

        printf("Mathematics: ");
        scanf("%d", &scores[i][0]);

        printf("English: ");
        scanf("%d", &scores[i][1]);

        printf("Geography: ");
        scanf("%d", &scores[i][2]);

        printf("Physics: ");
        scanf("%d", &scores[i][3]);

        printf("History: ");
        scanf("%d", &scores[i][4]);

        printf("\n");
    }

    printf("Result:\n");

    // Output the result as a 2D array
    for (int i = 0; i < STUDENTS; i++) {
        printf("Student %d: ", i + 1);
        for (int j = 0; j < SUBJECTS; j++) {
            printf("%d ", scores[i][j]);
        }
        printf("\n");
    }

    return 0;
}
#include <stdio.h>

#define STUDENTS 5
#define SUBJECTS 5

int main() {
    int scores[STUDENTS][SUBJECTS];

    // Input scores for each student and subject
    for (int i = 0; i < STUDENTS; i++) {
        printf("Enter scores for student %d:\n", i + 1);

        printf("Mathematics: ");
        scanf("%d", &scores[i][0]);

        printf("English: ");
        scanf("%d", &scores[i][1]);

        printf("Geography: ");
        scanf("%d", &scores[i][2]);

        printf("Physics: ");
        scanf("%d", &scores[i][3]);

        printf("History: ");
        scanf("%d", &scores[i][4]);

        printf("\n");
    }

    printf("Result:\n");

    // Output the result as a 2D array
    for (int i = 0; i < STUDENTS; i++) {
        printf("Student %d: ", i + 1);
        for (int j = 0; j < SUBJECTS; j++) {
            printf("%d ", scores[i][j]);
        }

        // Calculate and print the average score for each student
        int sum = 0;
        for (int j = 0; j < SUBJECTS; j++) {
            sum += scores[i][j];
        }
        float average = (float)sum / SUBJECTS;
        printf("Average: %.2f", average);

        printf("\n");
    }

    return 0;
}

#include <stdio.h>

#define STUDENTS 5
#define SUBJECTS 5

int main() {
    int scores[STUDENTS][SUBJECTS];
    int subjectTotal[SUBJECTS] = {0};  // Array to store the total scores of each subject

    // Input scores for each student and subject
    for (int i = 0; i < STUDENTS; i++) {
        printf("Enter scores for student %d:\n", i + 1);

        for (int j = 0; j < SUBJECTS; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%d", &scores[i][j]);
            subjectTotal[j] += scores[i][j];  // Update the total score for the current subject
        }

        printf("\n");
    }

    printf("Result:\n");

    // Output the result as a 2D array and calculate the average score for each student
    for (int i = 0; i < STUDENTS; i++) {
        printf("Student %d: ", i + 1);
        for (int j = 0; j < SUBJECTS; j++) {
            printf("%d ", scores[i][j]);
        }

        int sum = 0;
        for (int j = 0; j < SUBJECTS; j++) {
            sum += scores[i][j];
        }
        float average = (float)sum / SUBJECTS;
        printf("Average: %.2f", average);

        printf("\n");
    }

    printf("\n");

    // Calculate and print the average score for each subject
    for (int j = 0; j < SUBJECTS; j++) {
        float subjectAverage = (float)subjectTotal[j] / STUDENTS;
        printf("Average score for Subject %d: %.2f\n", j + 1, subjectAverage);
    }

    return 0;
}

#include <stdio.h>

#define STUDENTS 5
#define SUBJECTS 5

int main() {
    int scores[STUDENTS][SUBJECTS];
    int subjectTotal[SUBJECTS] = {0};  // Array to store the total scores of each subject
    int highestScore[SUBJECTS] = {0};  // Array to store the highest score of each subject
    int highestScoreStudent[SUBJECTS] = {0};  // Array to store the student number with the highest score for each subject

    // Input scores for each student and subject
    for (int i = 0; i < STUDENTS; i++) {
        printf("Enter scores for student %d:\n", i + 1);

        for (int j = 0; j < SUBJECTS; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%d", &scores[i][j]);
            subjectTotal[j] += scores[i][j];  // Update the total score for the current subject

            if (scores[i][j] > highestScore[j]) {
                highestScore[j] = scores[i][j];  // Update the highest score for the current subject
                highestScoreStudent[j] = i + 1;  // Update the student number with the highest score for the current subject
            }
        }

        printf("\n");
    }

    printf("Result:\n");

    // Output the result as a 2D array and calculate the average score for each student
    for (int i = 0; i < STUDENTS; i++) {
        printf("Student %d: ", i + 1);
        for (int j = 0; j < SUBJECTS; j++) {
            printf("%d ", scores[i][j]);
        }

        int sum = 0;
        for (int j = 0; j < SUBJECTS; j++) {
            sum += scores[i][j];
        }
        float average = (float)sum / SUBJECTS;
        printf("Average: %.2f", average);

        printf("\n");
    }

    printf("\n");

    // Calculate and print the average score for each subject
    for (int j = 0; j < SUBJECTS; j++) {
        float subjectAverage = (float)subjectTotal[j] / STUDENTS;
        printf("Average score for Subject %d: %.2f\n", j + 1, subjectAverage);
    }

    printf("\n");

    // Print the highest score of each subject with the student who achieved that score
    for (int j = 0; j < SUBJECTS; j++) {
        printf("Highest score for Subject %d: %d (Student %d)\n", j + 1, highestScore[j], highestScoreStudent[j]);
    }

    return 0;
}*/


#include <stdio.h>

#define STUDENTS 5
#define SUBJECTS 5

int main() {
    int scores[STUDENTS][SUBJECTS];
    int highestScore[SUBJECTS] = {0};  // Array to store the highest score of each subject
    int studentWithHighestScore[SUBJECTS] = {0};  // Array to store the student number with the highest score for each subject
    float studentAverage[STUDENTS] = {0.0};  // Array to store the average score for each student
    float subjectAverage[SUBJECTS] = {0.0};  // Array to store the average score for each subject

    // Input scores for each student and subject
    for (int i = 0; i < STUDENTS; i++) {
        printf("Enter scores for student %d:\n", i + 1);

        for (int j = 0; j < SUBJECTS; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%d", &scores[i][j]);

            // Check if current score is higher than the previous highest score for the subject
            if (scores[i][j] > highestScore[j]) {
                highestScore[j] = scores[i][j];
                studentWithHighestScore[j] = i + 1;
            }

            // Update the average score for the current student
            studentAverage[i] += scores[i][j];

            // Update the average score for the current subject
            subjectAverage[j] += scores[i][j];
        }

        // Calculate the average score for the current student
        studentAverage[i] /= SUBJECTS;

        printf("\n");
    }

    printf("Result:\n");

    // Output the result as a 2D array
    for (int i = 0; i < STUDENTS; i++) {
        printf("Student %d: ", i + 1);
        for (int j = 0; j < SUBJECTS; j++) {
            printf("%d ", scores[i][j]);
        }
        printf("Average: %.2f\n", studentAverage[i]);
    }

    printf("\n");

    // Print the highest score of each subject with the student who achieved that score
    for (int j = 0; j < SUBJECTS; j++) {
        printf("Highest score for Subject %d: %d (Student %d)\n", j + 1, highestScore[j], studentWithHighestScore[j]);
    }

    printf("\n");

    // Calculate and print the average score for each subject
    for (int j = 0; j < SUBJECTS; j++) {
        subjectAverage[j] /= STUDENTS;
        printf("Average score for Subject %d: %.2f\n", j + 1, subjectAverage[j]);
    }

    return 0;
}