//Name-Tasfique Enam
//Student ID- 5886429
#include <iostream>
using namespace std;

class CollegeDepartment {

    friend ostream &operator << (ostream &out, const CollegeDepartment &collegeDepartment);
    friend istream &operator >> (istream &in,  CollegeDepartment &collegeDepartment);

private:
    string departmentName;
    string deanName;
    string *courseName;
    int courseNo;
    int totalStudents;

public:
    bool operator>(CollegeDepartment);
    void operator=(CollegeDepartment);
    CollegeDepartment();
    CollegeDepartment operator+(int);

};

CollegeDepartment::CollegeDepartment() {
    departmentName = "";
    deanName = "";
    courseNo = 0;
    totalStudents = 0;
    courseName = nullptr;
}

ostream & operator << (ostream &out, const CollegeDepartment &collegeDepartment)
{
    out << "Department Name- " << collegeDepartment.departmentName << endl;
    out << "Department Dean's Name- " << collegeDepartment.deanName << endl;
    out << "Number of Courses offered by the Department- " << collegeDepartment.courseNo << endl;
    out << "Total number of student- " << collegeDepartment.totalStudents << "\n" << endl;
    out << "All Courses Names: ";
    if (collegeDepartment.courseName) {
        for (int i=0; i<collegeDepartment.courseNo-1; i++)
            out << collegeDepartment.courseName[i] << ", ";
        out << collegeDepartment.courseName[collegeDepartment.courseNo-1];
    }
    out << endl;
    return out;
}

istream & operator >> (istream &in,  CollegeDepartment &collegeDepartment)
{
    cout << "Input a department name : ";
    in >> collegeDepartment.departmentName;
    cout << "Input a dean's name : ";
    in >> collegeDepartment.deanName;
    cout << "Input the number of course: ";
    in >> collegeDepartment.courseNo;
    cout << "Input the total student: ";
    in >> collegeDepartment.totalStudents;
    collegeDepartment.courseName = new string[collegeDepartment.courseNo];

    for (int i=0; i< collegeDepartment.courseNo; i++) {
        cout << "Enter the course name " ;
        in >> collegeDepartment.courseName[i];
    }
    in.clear();
    in.ignore();
    return in;
}

CollegeDepartment CollegeDepartment::operator+(int totalStudents) {
    this->totalStudents = this->totalStudents + totalStudents;
    return *this;
}

bool CollegeDepartment::operator>(CollegeDepartment collegeDepartment) {
    if (this->courseNo > collegeDepartment.courseNo)
        return true;
    return false;
}

void CollegeDepartment::operator=(CollegeDepartment collegeDepartment) {
    this->departmentName = collegeDepartment.departmentName;
    this->deanName = collegeDepartment.deanName;
    this->courseNo = collegeDepartment.courseNo;
    this->totalStudents = collegeDepartment.totalStudents;
    if (collegeDepartment.courseName) {
        this->courseName = new string[this->courseNo];
        for (int i=0; i<this->courseNo; i++)
            this->courseName[i] = collegeDepartment.courseName[i];
    }
}

int main() {
    CollegeDepartment collegeDepartment1, collegeDepartment2;

    cin >> collegeDepartment1;
    cout << collegeDepartment1;

    cout << "Testing the object when 150 is added " << endl;
    collegeDepartment1 = collegeDepartment1 + 150;
    cout << collegeDepartment1;

    cout << "When the object is empty " << endl;
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
