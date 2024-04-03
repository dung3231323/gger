#include"University.h"
#include <limits>

#ifdef _WIN32
    #define CLEAR_SCREEN "cls"
#else 
    #define CLEAR_SCREEN "clear"
#endif

University *university = nullptr;

int main() {
    std::string choice = "";
    
    std::cout << "Vui long nhap ten truong: ";
    std::getline(std::cin, choice);

    university = new University(choice);
    choice = "";

    while(1) {
        std::cout << "  Chuong trinh quan ly ten sinh vien " << university->getUniName() << "\n";
        std::cout << "|  1. Them sinh vien                      |\n";
        std::cout << "|  2. Xoa sinh vien                       |\n";
        std::cout << "|  3. Hien thi danh sach cac sinh vien    |\n";
        std::cout << "|  4. Hien thi danh sach (cac) sinh vien  |\n|     co thanh tich tot nhat              |\n";
        std::cout << "|  5. Thoat chuong trinh                  |\n";

        std::cout << "Vui long nhap vao lua chon muon thuc hien: "; std::cin >> choice;
        system(CLEAR_SCREEN);
        
        // std::cout << std::endl;

        if(choice == "1") {
            std::string name = "";
            std::string birth = "";
            std::string course = "";
            int type;
            int score = 0;
            
            while(1) {
                // std::cin.ignore(32767, '\n');
                
                std::cout << "Chon loai sinh vien muon nhap\n";
                std::cout << "0. Thoat\t1. UniStudent\t2. CollegeStudent\n";
                std::cin >> type;

                if(type == 0) {
                    system(CLEAR_SCREEN);
                    break;
                }

                std::cout << "Nhap \"#\" de thoat\n";
                
                std::cin.ignore(32767, '\n');
                nameInput: std::cout << "Vui long nhap ten sinh vien muon them vao: "; std::getline(std::cin, name);

                if(name == "#") {
                    system(CLEAR_SCREEN);
                    break;
                }

                if(name == "") {
                    std::cout << "Ten khong hop le\n\n";
                    goto nameInput;
                }

                scoreInput: std::cout << "Vui long nhap diem cua " << name << ": "; 

                while(!(std::cin >> score)) {
                    std::cout << "\nGia tri khong hop le. Vui long nhap vao mot so nguyen: ";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }

                if(score < 0) {
                    std::cout << "Diem khong hop le\n\n";
                    goto scoreInput;
                }

                std::cin.ignore(32767, '\n');
                std::cout << "Vui long nhap ngay sinh: "; std::getline(std::cin, birth);

                std::cout << "Vui long nhap ten khoa hoc: "; std::getline(std::cin, course);
                
                Student *newStudent;

                if(type == 2) newStudent = new CollegeStudents(name, birth, university->getUniName(), course, score);
                else newStudent = new UniStudents(name, birth, university->getUniName(), course, score);

                system(CLEAR_SCREEN);

                if(university->addStudent(newStudent)) std::cout << "Them sinh vien thanh cong\n\n";
            }
        }
        else if(choice == "2") {
            if(!university->displayStudent()) {
                std::cout << std::endl;
                continue;
            }
            std::string name = "";

            std::cin.ignore(32767, '\n');
            std::cout << "Vui long nhap ten sinh vien muon xoa: "; std::getline(std::cin, name);

            if(university->deleteStudent(name)) std::cout << "Xoa sinh vien thanh cong\n";
            else std::cout << "Ten sinh vien khong hop le\n";

        }
        else if(choice == "3") {
            university->displayStudent();
        }
    
        else if(choice == "4") {
            if(!university->bestStudents()) {
                university->displayStudent();
            }
        }
        else if(choice == "5") {
            break;
        }
        else {
            std::cout << "Lua chon khong hop le. Vui long nhap lai\n";
        }

        std::cout << std::endl;
    }

    delete university;

    return 0;
}