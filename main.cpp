#include <iostream>
using namespace std;

class CollegeDepartment {
    string departmentName;
    string departmentDeanName;
    int courseNum;
    int totalStudent;
    string *courseName;
public:
    CollegeDepartment();
    friend ostream &operator << (ostream &out, const CollegeDepartment &cD);
    friend istream &operator >> (istream &in,  CollegeDepartment &cD);
    CollegeDepartment operator+(int);
    bool operator>(CollegeDepartment);
    void operator=(CollegeDepartment);
};

CollegeDepartment::CollegeDepartment() {
    departmentName = "None";
    departmentDeanName = "None";
    courseNum = 0;
    totalStudent = 0;
    courseName = nullptr;
}

ostream & operator << (ostream &out, const CollegeDepartment &cD)
{
    out << "\n------------College Department Detail------------" << endl;
    out << "Department name: " << cD.departmentName << endl;
    out << "Department dean's name: " << cD.departmentDeanName << endl;
    out << "Number of course(s) the department offered: " << cD.courseNum << endl;
    out << "Total number of student: " << cD.totalStudent << endl;
    out << "List of course name: ";
    if (cD.courseName) {
        for (int i=0; i<cD.courseNum-1; i++)
            out << cD.courseName[i] << ", ";
        out << cD.courseName[cD.courseNum-1];
    }
    out << endl;
    return out;
}

istream & operator >> (istream &in,  CollegeDepartment &cD)
{
    cout << "Getting Information For College Department" << endl;
    cout << "Enter department name: ";
    getline(in,cD.departmentName);
    cout << "Enter department dean name: ";
    getline(in,cD.departmentDeanName);
    cout << "Enter the number of course: ";
    in >> cD.courseNum;
    cout << "Enter the total student: ";
    in >> cD.totalStudent;
    cD.courseName = new string[cD.courseNum];
    for (int i=0; i< cD.courseNum; i++) {
        cout << "Enter the course name " << i+1 << ": ";
        in >> cD.courseName[i];
    }
    in.clear();
    in.ignore();
    return in;
}

CollegeDepartment CollegeDepartment::operator+(int totalStudent) {
    this->totalStudent += totalStudent;
    return *this;
}

bool CollegeDepartment::operator>(CollegeDepartment cD) {
    if (this->courseNum > cD.courseNum)
        return true;
    return false;
}

void CollegeDepartment::operator=(CollegeDepartment cD) {
    this->departmentName = cD.departmentName;
    this->departmentDeanName = cD.departmentDeanName;
    this->courseNum = cD.courseNum;
    this->totalStudent = cD.totalStudent;
    if (cD.courseName) {
        this->courseName = new string[this->courseNum];
        for (int i=0; i<this->courseNum; i++)
            this->courseName[i] = cD.courseName[i];
    }
}

int main() {
    CollegeDepartment collegeDepartment1, collegeDepartment2;

    cin >> collegeDepartment1;
    cout << collegeDepartment1;


    collegeDepartment1 = collegeDepartment1 + 150;
    cout << collegeDepartment1;


    cout << collegeDepartment2;
    cin >> collegeDepartment2;
    cout << collegeDepartment2;

    if(collegeDepartment1 > collegeDepartment2)
        cout << "\nCollege department 1 has more courses offered." << endl;
    else
        cout << "\nCollege department 2 has more courses offered." << endl;

    collegeDepartment2 = collegeDepartment1;
    cout << collegeDepartment2;
    return 0;
}
