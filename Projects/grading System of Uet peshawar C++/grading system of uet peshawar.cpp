#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

const int MAX_RECORDS = 500;
const int MAX_PAPERS = 10;

struct Student
{
    string rollNo;
    string name;
};

struct PaperRecord
{
    Student student;

    string paperName;
    int creditHours;

    float marks;

    string grade;
    float gpa;
};

PaperRecord records[MAX_RECORDS];

string paperNames[MAX_PAPERS];

int totalRecords = 0;
int totalPapers = 0;

// ================= PAPER CHECK =================

bool paperExists(string paper)
{
    for (int i = 0; i < totalPapers; i++)
    {
        if (paperNames[i] == paper)
        {
            return true;
        }
    }

    return false;
}

void addPaper(string paper)
{
    if (!paperExists(paper))
    {
        paperNames[totalPapers] = paper;
        totalPapers++;
    }
}

// ================= DUPLICATE CHECK =================

bool duplicateRecord(string rollNo, string paper)
{
    for (int i = 0; i < totalRecords; i++)
    {
        if (records[i].student.rollNo == rollNo &&
            records[i].paperName == paper)
        {
            return true;
        }
    }

    return false;
}

// ================= RELATIVE GRADING SYSTEM =================

void assignGrades(string paper)
{
    int indexes[200];
    int count = 0;

    // STORE INDEXES OF SAME PAPER

    for (int i = 0; i < totalRecords; i++)
    {
        if (records[i].paperName == paper)
        {
            indexes[count] = i;
            count++;
        }
    }

    // SORT BY MARKS (DESCENDING)

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (records[indexes[j]].marks >
                records[indexes[i]].marks)
            {
                int temp = indexes[i];
                indexes[i] = indexes[j];
                indexes[j] = temp;
            }
        }
    }

    // ASSIGN RELATIVE GRADES

    for (int i = 0; i < count; i++)
    {
        // TOP 10

        if (i < 10)
        {
            records[indexes[i]].grade = "A";
            records[indexes[i]].gpa = 4.0;
        }

        // NEXT 5

        else if (i < 15)
        {
            records[indexes[i]].grade = "A-";
            records[indexes[i]].gpa = 3.7;
        }

        // NEXT 5

        else if (i < 20)
        {
            records[indexes[i]].grade = "B+";
            records[indexes[i]].gpa = 3.3;
        }

        // NEXT 5

        else if (i < 25)
        {
            records[indexes[i]].grade = "B";
            records[indexes[i]].gpa = 3.0;
        }

        // NEXT 5

        else if (i < 30)
        {
            records[indexes[i]].grade = "B-";
            records[indexes[i]].gpa = 2.7;
        }

        // NEXT 5

        else if (i < 35)
        {
            records[indexes[i]].grade = "C+";
            records[indexes[i]].gpa = 2.3;
        }

        // NEXT 5

        else if (i < 40)
        {
            records[indexes[i]].grade = "C";
            records[indexes[i]].gpa = 2.0;
        }

        // NEXT 5

        else if (i < 45)
        {
            records[indexes[i]].grade = "D";
            records[indexes[i]].gpa = 1.0;
        }

        // REMAINING

        else
        {
            records[indexes[i]].grade = "F";
            records[indexes[i]].gpa = 0.0;
        }
    }
}

// ================= TOPPER =================

void showTopper(string paper)
{
    float highest = -1;
    int index = -1;

    for (int i = 0; i < totalRecords; i++)
    {
        if (records[i].paperName == paper)
        {
            if (records[i].marks > highest)
            {
                highest = records[i].marks;
                index = i;
            }
        }
    }

    if (index != -1)
    {
        cout << "\n=========== TOPPER ===========" << endl;

        cout << "Paper : " << paper << endl;
        cout << "Name  : " << records[index].student.name << endl;
        cout << "Marks : " << records[index].marks << endl;
    }
}

// ================= ENTER DETAILS =================

void enterDetails()
{
    string paper;
    int creditHours;
    int students;

    cout << "\nEnter Paper Name: ";
    cin >> paper;

    addPaper(paper);

    cout << "Enter Credit Hours: ";
    cin >> creditHours;

    cout << "Enter Total Students: ";
    cin >> students;

    for (int i = 0; i < students; i++)
    {
        PaperRecord temp;

        cout << "\nStudent " << i + 1 << endl;

        cout << "Enter Roll No: ";
        cin >> temp.student.rollNo;

        if (duplicateRecord(temp.student.rollNo, paper))
        {
            cout << "\nERROR: Record already exists for this paper.\n";
            continue;
        }

        cout << "Enter Name: ";
        cin >> temp.student.name;

        cout << "Enter Marks: ";
        cin >> temp.marks;

        while (temp.marks < 0 || temp.marks > 100)
        {
            cout << "Invalid Marks. Enter Again: ";
            cin >> temp.marks;
        }

        temp.paperName = paper;
        temp.creditHours = creditHours;

        records[totalRecords] = temp;

        totalRecords++;
    }

    assignGrades(paper);

    cout << "\nPaper Record Added Successfully.\n";
}

// ================= UPDATE DETAILS =================

void updateDetails()
{
    string rollNo;
    string paper;

    cout << "\nEnter Roll No: ";
    cin >> rollNo;

    cout << "Enter Paper Name: ";
    cin >> paper;

    bool found = false;

    for (int i = 0; i < totalRecords; i++)
    {
        if (records[i].student.rollNo == rollNo &&
            records[i].paperName == paper)
        {
            found = true;

            int choice;

            cout << "\nRecord Found\n";

            cout << "1. Update Name\n";
            cout << "2. Update Marks\n";
            cout << "3. Update Roll No\n";

            cout << "Enter Choice: ";
            cin >> choice;

            if (choice == 1)
            {
                cout << "Enter New Name: ";
                cin >> records[i].student.name;
            }
            else if (choice == 2)
            {
                cout << "Enter New Marks: ";
                cin >> records[i].marks;

                assignGrades(paper);
            }
            else if (choice == 3)
            {
                cout << "Enter New Roll No: ";
                cin >> records[i].student.rollNo;
            }

            cout << "\nRecord Updated Successfully.\n";
        }
    }

    if (!found)
    {
        cout << "\nRecord Not Found.\n";
    }
}

// ================= PAPER DETAILS MENU =================

void paperDetailsMenu()
{
    int choice;

    cout << "\n===== PAPER DETAILS =====\n";

    cout << "1. Enter Details\n";
    cout << "2. Update Details\n";

    cout << "Enter Choice: ";
    cin >> choice;

    if (choice == 1)
    {
        enterDetails();
    }
    else if (choice == 2)
    {
        updateDetails();
    }
    else
    {
        cout << "Invalid Choice.\n";
    }
}

// ================= SEE PAPER RESULTS =================

void seePaperResults()
{
    if (totalPapers == 0)
    {
        cout << "\nNo Papers Available.\n";
        return;
    }

    cout << "\n===== PAPER RESULTS =====\n";

    for (int i = 0; i < totalPapers; i++)
    {
        cout << i + 1 << ". " << paperNames[i] << endl;
    }

    int choice;

    cout << "Choose Paper: ";
    cin >> choice;

    if (choice < 1 || choice > totalPapers)
    {
        cout << "Invalid Choice.\n";
        return;
    }

    string selectedPaper = paperNames[choice - 1];

    cout << "\n========== " << selectedPaper << " RESULT ==========\n";

    cout << left
         << setw(15) << "Roll No"
         << setw(15) << "Name"
         << setw(10) << "Marks"
         << setw(10) << "Grade"
         << setw(10) << "GPA"
         << endl;

    for (int i = 0; i < totalRecords; i++)
    {
        if (records[i].paperName == selectedPaper)
        {
            cout << left
                 << setw(15) << records[i].student.rollNo
                 << setw(15) << records[i].student.name
                 << setw(10) << records[i].marks
                 << setw(10) << records[i].grade
                 << setw(10) << records[i].gpa
                 << endl;
        }
    }

    showTopper(selectedPaper);
}

// ================= SHOW DMC =================

void showDMC()
{
    if (totalRecords == 0)
    {
        cout << "\nNo Records Available.\n";
        return;
    }

    string uniqueStudents[200];
    string uniqueRolls[200];

    int totalStudents = 0;

    // UNIQUE STUDENT LIST

    for (int i = 0; i < totalRecords; i++)
    {
        bool exists = false;

        for (int j = 0; j < totalStudents; j++)
        {
            if (uniqueRolls[j] == records[i].student.rollNo)
            {
                exists = true;
                break;
            }
        }

        if (!exists)
        {
            uniqueStudents[totalStudents] = records[i].student.name;
            uniqueRolls[totalStudents] = records[i].student.rollNo;

            totalStudents++;
        }
    }

    cout << "\n===== DMC TRANSCRIPT =====\n";

    for (int i = 0; i < totalStudents; i++)
    {
        cout << i + 1 << ". " << uniqueStudents[i] << endl;
    }

    int choice;

    cout << "Choose Student: ";
    cin >> choice;

    if (choice < 1 || choice > totalStudents)
    {
        cout << "Invalid Choice.\n";
        return;
    }

    string selectedRoll = uniqueRolls[choice - 1];
    string selectedName = uniqueStudents[choice - 1];

    cout << "\n============== DMC ==============\n";

    cout << "Name    : " << selectedName << endl;
    cout << "Roll No : " << selectedRoll << endl;

    cout << "\n";

    cout << left
         << setw(15) << "Subject"
         << setw(10) << "CH"
         << setw(10) << "Marks"
         << setw(10) << "Grade"
         << setw(10) << "GPA"
         << endl;

    float totalPoints = 0;
    int totalCH = 0;

    for (int i = 0; i < totalRecords; i++)
    {
        if (records[i].student.rollNo == selectedRoll)
        {
            cout << left
                 << setw(15) << records[i].paperName
                 << setw(10) << records[i].creditHours
                 << setw(10) << records[i].marks
                 << setw(10) << records[i].grade
                 << setw(10) << records[i].gpa
                 << endl;

            totalPoints +=
                records[i].gpa * records[i].creditHours;

            totalCH += records[i].creditHours;
        }
    }

    float cgpa = totalPoints / totalCH;

    cout << "\nTotal Credit Hours: " << totalCH << endl;

    cout << fixed << setprecision(2);

    cout << "CGPA: " << cgpa << endl;
}

// ================= MAIN =================

int main()
{
    int choice;

    do
    {
        cout << "\n=====================================\n";
        cout << "     RELATIVE GRADING SYSTEM\n";
        cout << "=====================================\n";

        cout << "1. Enter Paper Details\n";
        cout << "2. See Each Paper Results\n";
        cout << "3. See DMC Transcript\n";
        cout << "4. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            paperDetailsMenu();
            break;

        case 2:
            seePaperResults();
            break;

        case 3:
            showDMC();
            break;

        case 4:
            cout << "\nProgram Exited.\n";
            break;

        default:
            cout << "\nInvalid Choice.\n";
        }

    } while (choice != 4);

    return 0;
}
