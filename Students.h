#include<string>
#include <iostream>

using namespace std;

struct Semesters {
    int assignments;
    int tests;
    int exams;
};

class Student {
    protected:
        std::string name;
        std::string birth;
        std::string schoolName;
        std::string courseName;
        std::string type;
        Semesters *semesters;
        int score;
    public:
        Student(std::string name = "", std::string birth = "", std::string schoolName = "", std::string courseName = "", Semesters *semester = nullptr, int score = 0) {
            this->name = name;
            this->birth = birth;
            this->schoolName = schoolName;
            this->courseName = courseName;
            this->semesters = semester;
            this->score = score;
        }
        ~Student() {
            // std::cout << "Deleted " << this->name << " " << this->score << std::endl;
            this->name = "";
        };

        std::string getName() const {
            return this->name;
        }

        std::string getBirth() const {
            return this->birth;
        }

        std::string getSchoolName() const {
            return this->schoolName;
        }
        
        std::string getCourseName() const {
            return this->courseName;
        }

        int getScore() const {
            return this->score;
        }

        std::string getType() const {
            return this->type;
        }

        void setName(std::string name) {
            this->name = name;
        }

        void setBirth(std::string birth) {
            this->birth = birth;
        }
        
        void setSchoolName(std::string schoolName) {
            this->schoolName = schoolName;
        }

        void setCourseName(std::string courseName) {
            this->courseName = courseName;
        }

        void setScore(int score) {
            this->score = score;
        }
        virtual void DoAssignment() = 0;
        virtual void TakeTest() = 0;
        virtual void TakeExam() = 0;
};

class UniStudents : public Student {
    public:
        UniStudents(std::string name = "", std::string birth = "", std::string schoolName = "", std::string courseName = "", int score = 0) {
            this->name = name;
            this->birth = birth;
            this->schoolName = schoolName;
            this->courseName = courseName;
            this->score = score;
            this->type = "Uni Student";
            semesters = new Semesters[8];
            for(int i = 0; i < 8; i++) {
                semesters[i].assignments = 3;
                semesters[i].tests = 2;
                semesters[i].exams = 1;
            }
        }

        ~UniStudents() {
            delete[] semesters;
        }
        void DoAssignment() override {
            // Gán điểm ngẫu nhiên cho bài tập cho sinh viên đại học
            srand(time(NULL));
            int randomScore = rand() % 101; // Điểm từ 0 đến 100
            cout << "UniStudent " << name << " - Assignment Score: " << randomScore << endl;
        }

        void TakeTest() override {
            // Gán điểm ngẫu nhiên cho bài kiểm tra cho sinh viên đại học
            srand(time(NULL));
            int randomScore = rand() % 101; // Điểm từ 0 đến 100
            cout << "UniStudent " << name << " - Test Score: " << randomScore << endl;
        }

        void TakeExam() override {
            // Gán điểm ngẫu nhiên cho kỳ thi cho sinh viên đại học
            srand(time(NULL));
            int randomScore = rand() % 101; // Điểm từ 0 đến 100
            cout << "UniStudent " << name << " - Exam Score: " << randomScore << endl;
        }
};


class CollegeStudents : public Student {
    public:
        CollegeStudents(std::string name = "", std::string birth = "", std::string schoolName = "", std::string courseName = "", int score = 0) {
            this->name = name;
            this->birth = birth;
            this->schoolName = schoolName;
            this->courseName = courseName;
            this->score = score;
            this->type = "College Student";
            semesters = new Semesters[8];
            for(int i = 0; i < 8; i++) {
                semesters[i].assignments = 1;
                semesters[i].tests = 1;
                semesters[i].exams = 1;
            }
        }

        ~CollegeStudents() {
            delete[] semesters;
        }
        void DoAssignment() override {
            // Gán điểm ngẫu nhiên cho bài tập cho sinh viên cao đẳng
            srand(time(NULL));
            int randomScore = rand() % 101; // Điểm từ 0 đến 100
            cout << "CollegeStudent " << name << " - Assignment Score: " << randomScore << endl;
        }

        void TakeTest() override {
            // Gán điểm ngẫu nhiên cho bài kiểm tra cho sinh viên cao đẳng
            srand(time(NULL));
            int randomScore = rand() % 101; // Điểm từ 0 đến 100
            cout << "CollegeStudent " << name << " - Test Score: " << randomScore << endl;
        }

        void TakeExam() override {
            // Gán điểm ngẫu nhiên cho kỳ thi cho sinh viên cao đẳng
            srand(time(NULL));
            int randomScore = rand() % 101; // Điểm từ 0 đến 100
            cout << "CollegeStudent " << name << " - Exam Score: " << randomScore << endl;
        }
};