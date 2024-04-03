#include"Students.h"
#include<iostream>
#include<algorithm>

using namespace std;

class University {
    private:
        Student **studentList;
        string uniName;
        int studentListCapacity;
        int studentListCounter;

    public:
        University() {
            studentList = nullptr;
            uniName = "";
            studentListCapacity = 0;
            studentListCounter = 0;
        }

        University(std::string name) {
            this->uniName = name;

            this->studentListCapacity = 5;
            this->studentListCounter = 0;
            studentList = new Student*[studentListCapacity];
        }

        ~University() {
            if(studentList) {
                for(int i = 0; i < studentListCounter; i++) {
                    delete studentList[i];
                }

                delete[] studentList;
            }

            uniName = "";
            studentListCapacity = studentListCounter = 0;

            // std::cout << "University delete completely\n";
        }

        string const getUniName() {
            return this->uniName;
        }

        void setUniName(string name) {
            this->uniName = name;
        }

        bool addStudent(Student *&student) {
            if(!studentList) return false;

            if(studentListCounter < studentListCapacity) {
                
                studentList[studentListCounter] = student;
            }
            else {
                Student **tmp = new Student*[studentListCapacity];

                for(int i = 0; i < studentListCounter; i++) tmp[i] = studentList[i];

                delete[] studentList;

                studentListCapacity *= 1.5;

                studentList = new Student*[studentListCapacity];

                for(int i = 0; i < studentListCounter; i++) studentList[i] = tmp[i];
                studentList[studentListCounter] = student;

                delete[] tmp;
            }

            studentListCounter++;
            return true;
        }

        bool deleteStudent(std::string name) {
            if(!studentListCounter || !studentList) return false;

            for(int i = 0; i < studentListCounter; i++) {
                if(studentList[i]->getName() == name) {
                    Student *tmp = studentList[i];
                    for(int j = i; j < studentListCounter-1; j++) {
                        studentList[j] = studentList[j+1];
                    }
                    delete tmp;
                    studentListCounter--;
                    return true;
                }
            }

            return false;
        }

        static bool scoreCompare(Student* A, Student* B) {
                    return (A->getScore() > B->getScore());
        }

        bool displayStudent() {
            if(!studentListCounter || !studentList) {
                cout << "Danh sach sinh vien rong\n";
                return false;
            }
            
            sort(studentList, studentList + studentListCounter, University::scoreCompare);

            cout << "Cac sinh vien co ten trong danh sach la\n";

            for(int i = 0; i < studentListCounter; i++) cout << i+1 << ". " << studentList[i]->getName() << " " << studentList[i]->getScore() << " " << studentList[i]->getType() <<endl; 

            return true;
        }

        bool bestStudents() {
            if(!studentListCounter || !studentList) return false;

            int max = INT_MIN;
            int order = 1;

            for(int i = 0; i < studentListCounter; i++) 
                if(max < studentList[i]->getScore()) max = studentList[i]->getScore();

                cout << "Cac sinh vien co thanh tich tot nhat la:\n";

            for(int i = 0; i < studentListCounter; i++) {
                if(studentList[i]->getScore() == max) cout << order++ << ". " << studentList[i]->getName() << " " << studentList[i]->getScore() << endl;
            }  

            return true;
        }

        void DoAssignmentsForAllStudents() {
            cout << "Doing assignments for all students:\n";
            for (int i = 0; i < studentListCounter; ++i) {
                studentList[i]->DoAssignment();
            }
        }

        void TakeTestsForAllStudents() {
            cout << "Taking tests for all students:\n";
            for (int i = 0; i < studentListCounter; ++i) {
                studentList[i]->TakeTest();
            }
        }

        void TakeExamsForAllStudents() {
            cout << "Taking exams for all students:\n";
            for (int i = 0; i < studentListCounter; ++i) {
                studentList[i]->TakeExam();
            }
        }
};