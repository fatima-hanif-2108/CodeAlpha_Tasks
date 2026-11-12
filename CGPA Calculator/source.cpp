#include <iostream>
using namespace std;

int main() {
    int n;
    double grade, credit;
    double totalCredits = 0, totalPoints = 0;

    cout << "Enter number of courses: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << "\nCourse " << i << endl;
        cout << "Enter grade point (0 to 4): ";
        cin >> grade;
        cout << "Enter credit hours: ";
        cin >> credit;

        cout << "Course " << i << " -> Grade: " << grade
            << ", Credits: " << credit
            << ", Points: " << grade * credit << endl;

        totalCredits = totalCredits + credit;
        totalPoints = totalPoints + grade * credit;
    }

    double gpa = totalPoints / totalCredits;

    double oldCredits, oldCGPA;
    cout << "\nEnter previous total credits (0 if first semester): ";
    cin >> oldCredits;
    cout << "Enter previous CGPA (0 if first semester): ";
    cin >> oldCGPA;

    double cgpa = (oldCGPA * oldCredits + totalPoints) / (oldCredits + totalCredits);

    cout << "\nTotal Credits: " << totalCredits << endl;
    cout << "Total Points: " << totalPoints << endl;
    cout << "Semester GPA: " << gpa << endl;
    cout << "Overall CGPA: " << cgpa << endl;

    return 0;
}