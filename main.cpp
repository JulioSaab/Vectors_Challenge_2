#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <limits>

using namespace std;

void AddGrade(vector<double>& grades);
void DisplayGrades(const vector<double>& grades);
void CalculateAverage(const vector<double>& grades);
void FindHighestLowest(const vector<double>& grades);
void CountAboveThreshold(const vector<double>& grades);
int GetValidatedChoice();

int main() {
    vector<double> grades;
    int choice;

    do {
        // Menu
        cout << "\n=== Grade Management Menu ===\n";
        cout << "1. Add a Grade\n";
        cout << "2. Display All Grades\n";
        cout << "3. Calculate Average Grade\n";
        cout << "4. Find Highest and Lowest Grade\n";
        cout << "5. Count Grades Above Threshold\n";
        cout << "6. Quit\n";
        cout << "Enter your choice: ";

        choice = GetValidatedChoice();

        switch (choice) {
            case 1:
                AddGrade(grades);
                break;
            case 2:
                DisplayGrades(grades);
                break;
            case 3:
                CalculateAverage(grades);
                break;
            case 4:
                FindHighestLowest(grades);
                break;
            case 5:
                CountAboveThreshold(grades);
                break;
            case 6:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please select between 1 and 6.\n";
        }
    } while (choice != 6);

    return 0;
}


void AddGrade(vector<double>& grades) {
    double grade;
    cout << "Enter grade: ";
    while (!(cin >> grade)) {
        cout << "Invalid input. Please enter a numeric grade: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    grades.push_back(grade);
    cout << "Grade added successfully.\n";
}

void DisplayGrades(const vector<double>& grades) {
    if (grades.empty()) {
        cout << "No grades to display.\n";
        return;
    }
    cout << "Grades: ";
    for (double g : grades) {
        cout << g << " ";
    }
    cout << "\n";
}

void CalculateAverage(const vector<double>& grades) {
    if (grades.empty()) {
        cout << "No grades available to calculate average.\n";
        return;
    }
    double sum = accumulate(grades.begin(), grades.end(), 0.0);
    double average = sum / grades.size();
    cout << "Average grade: " << average << "\n";
}

void FindHighestLowest(const vector<double>& grades) {
    if (grades.empty()) {
        cout << "No grades available.\n";
        return;
    }
    auto minIt = min_element(grades.begin(), grades.end());
    auto maxIt = max_element(grades.begin(), grades.end());
    cout << "Lowest grade: " << *minIt << "\n";
    cout << "Highest grade: " << *maxIt << "\n";
}

void CountAboveThreshold(const vector<double>& grades) {
    if (grades.empty()) {
        cout << "No grades available.\n";
        return;
    }
    double threshold;
    cout << "Enter threshold: ";
    while (!(cin >> threshold)) {
        cout << "Invalid input. Please enter a numeric threshold: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    int count = count_if(grades.begin(), grades.end(), [threshold](double g) {
        return g > threshold;
    });
    cout << "Number of grades above " << threshold << ": " << count << "\n";
}

int GetValidatedChoice() {
    int choice;
    while (!(cin >> choice)) {
        cout << "Invalid input. Please enter a number between 1 and 6: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return choice;
}

