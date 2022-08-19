#include <iostream>
#include <vector>
using namespace std;

vector<int> gradingStudents(vector<int> grades)
{
    for (int i = 0; i < grades.size(); i++)
    {
        if (grades[i] >= 38)
        {
            if (grades[i] % 5 >= 3)
            {
                grades[i] += 5 - grades[i] % 5;
            }
        }
    }
    return grades;
}

int main()
{
    int n;
    cin >> n;
    vector<int> grades(n);
    for (int i = 0; i < n; i++)
    {
        cin >> grades[i];
    }
    vector<int> result = gradingStudents(grades);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}
// 4 73 67 38 33
// 75 67 40 33