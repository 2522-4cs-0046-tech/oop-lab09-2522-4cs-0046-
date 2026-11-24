#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    if (n <= 0) {
        cout << "Number of students must be greater than 0." << endl;
        return 0;
    }

    int* marks = new int[n];

    cout << "Enter " << n << " marks: ";
    for (int i = 0; i < n; i++) {
        cin >> marks[i];
    }

    int sum = 0;
    int highest = marks[0];

    for (int i = 0; i < n; i++) {
        sum += marks[i];
        if (marks[i] > highest) {
            highest = marks[i];
        }
    }

    double average = static_cast<double>(sum) / n;

    cout << "Average: " << average << endl;
    cout << "Highest mark: " << highest << endl;
    cout << "Marks above average:";
    bool anyAbove = false;
    for (int i = 0; i < n; i++) {
        if (marks[i] > average) {
            cout << " " << marks[i];
            anyAbove = true;
        }
    }
    if (!anyAbove) {
        cout << " None";
    }
    cout << endl;

    delete[] marks;
    marks = nullptr;

    return 0;
}