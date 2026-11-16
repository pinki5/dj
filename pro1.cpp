
#include <iostream>
#include <cstdlib>
using namespace std;
struct Student
{
    int id;
    char name[50];
    float cgpa;
};
int main()
{
    Student *s = NULL;
    int n = 0, searchId, i, j;
    char ch;
    do
    {
        s = (Student *)realloc(s, (n + 1) * sizeof(Student)); // grow by one
        cout << "\nEnter Student ID: ";
        cin >> s[n].id;
        cout << "Enter Name: ";
        cin.ignore();
        cin.getline(s[n].name, 50);
        cout << "Enter CGPA: ";
        cin >> s[n].cgpa;
        n++;
        cout << "Add more students? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    cout << "\nEnter Student ID to Search: ";
    cin >> searchId;

    // Linear Search
    bool found = false;
    for (i = 0; i < n; i++)
    {
        if (s[i].id == searchId)
        {
            cout << "\n[Linear Search] Student Found!" << endl;
            cout << "ID: " << s[i].id << "\nName: " << s[i].name << "\nCGPA: " << s[i].cgpa << endl;
            found = true;
            break;
        }
    }
    if (!found)
        cout << "\n[Linear Search] Student Not Found!" << endl;

    // Sort by ID (needed for Binary Search)
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (s[i].id > s[j].id)
            {
                Student temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }

    // Binary Search
    int low = 0, high = n - 1, mid;
    found = false;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (s[mid].id == searchId)
        {
            cout << "\n[Binary Search] Student Found!" << endl;
            cout << "ID: " << s[mid].id << "\nName: " << s[mid].name << "\nCGPA: " << s[mid].cgpa << endl;
            found = true;
            break;
        }
        else if (searchId < s[mid].id)
            high = mid - 1;
        else
            low = mid + 1;
    }
    if (!found)
        cout << "\n[Binary Search] Student Not Found!" << endl;

    free(s);
    return 0;
}
