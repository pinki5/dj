#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
struct Student
{
int id;
char name[50];
float cgpa;
};
bool after(Student a, Student b, int choice)
{
if (choice == 1) return strcmp(a.name, b.name) > 0; 
if (choice == 2) return a.cgpa > b.cgpa;            
return a.cgpa < b.cgpa;                             
}
int main()
{
Student *s = NULL;
int n = 0, choice;
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
cout << "\n1. Sort by Name (Alphabetical)";
cout << "\n2. Sort by CGPA (Ascending)";
cout << "\n3. Sort by CGPA (Descending)";
cout << "\nEnter your choice: ";
cin >> choice;
for (int i = 1; i < n; i++)
{
Student key = s[i];
int j = i - 1;
while (j >= 0 && after(s[j], key, choice))
{
s[j + 1] = s[j];
j--;
}
s[j + 1] = key;
}
cout << "\nSorted Student Records:\n";
cout << "\nID\tName\tCGPA\n";
for (int i = 0; i < n; i++)
cout << s[i].id << "\t" << s[i].name << "\t" << s[i].cgpa << endl;
free(s);
return 0;
}
