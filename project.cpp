/*=========================================================================
	GROUP PROJECT: SIMPLE STUDENT MANAGEMENT SYSTEM IN C++
	The system allows the user to add, view, and manage student 
	information. The information include student's name, age, 
	and grades.
	
============================================================================*/

#include <iostream>
#include <string>
using namespace std;




//This structure used to stores individual student data (name, age, grade)
struct Student{
	//struct members to store student name, age,grade.
	
    string name;
    int age;
    float grade;
};
//end of structure definition.




// Global variables
Student students[100]; // Array to store up to 100 students
int studentCount = 0;




// Function prototypes
void add_student();
void display_student();
void calculate_average();
void show_menu();




int main() {
	//calling the menu function
    show_menu();
    return 0;
}




/*
this function provides a menu interface for the user to navigate through the system

*/
void show_menu() {
    int choice;
    do {
        cout << "\n=== Student Management System ===\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Calculate Average Grade\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                display_student();
                break;
            case 3:
                calculate_average();
                break;
            case 4:
                cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);
}



//This function allows the input of multiple students' data
void add_student() {
    if (studentCount < 100) {
        cout << "\nEnter Student Name: ";
        cin.ignore();
        getline(cin, students[studentCount].name);
        cout << "Enter Age: ";
        cin >> students[studentCount].age;
        cout << "Enter Grade: ";
        cin >> students[studentCount].grade;

        studentCount++;
        cout << "Student added successfully.\n";
    } else {
        cout << "Maximum student capacity reached.\n";
    }
}





/**
this function loops through the students[] array and display the stored details

**/
// Function to display all students using pointer iteration
void display_student() {
    if (studentCount == 0) {
        cout << "No students to display.\n";
        return;
    }

    cout << "\n--- Student Details ---\n";
    Student* ptr = students; // Pointer to the start of the array
    for (int i = 0; i < studentCount; i++) {
        cout << "Student " << i + 1 << ":\n";
        cout << "Name: " << ptr[i].name << "\n";
        cout << "Age: " << ptr[i].age << "\n";
        cout << "Grade: " << ptr[i].grade << "\n";
    }
}





// Function to calculate the average grade using pointer iteration
/*
This function calculates the average grade of all students in the students array.
It adds up the grades of all students and divides by the total number of students.
*/

void calculate_average() {
    if (studentCount == 0) {
        cout << "No students available to calculate the average grade.\n";
        return;
    }

    float totalGrade = 0;
    Student* ptr = students; // Pointer to the start of the array
    for (int i = 0; i < studentCount; i++) {
        totalGrade += ptr[i].grade;
    }
    cout << "The average grade is: " << totalGrade / studentCount << "\n";
}
