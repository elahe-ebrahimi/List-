#include <iostream>
#include <string>

struct Student {
    int id;
    int age;
    std::string name;
    std::string job;
    Student* next;
};

class list {
private:
    Student* head;

public:
    list() {
        head = nullptr;
    }

    void add(int id, int age, const std::string& name, const std::string& job) {
        Student* newStudent = new Student();
        newStudent->id = id;
        newStudent->age = age;
        newStudent->name = name;
        newStudent->job = job;
        newStudent->next = nullptr;

        if (head == nullptr) {
            head = newStudent;
        } else {
            Student* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newStudent;
        }
    }

    Student* find(int id) {
        Student* current = head;

        while (current != nullptr) {
            if (current->id == id) {
                return current;
            }
            current = current->next;
        }

        return nullptr;
    }

    void show() {
        Student* current = head;

        while (current != nullptr) {
            std::cout << "ID: " << current->id <<  "\nAge: " << current->age << "\nName: " << current->name << "\nJob: " << current->job << "\n\n";
            current = current->next;
        }
    }
};

int main() {
    list list;

    int id, age;
    char q;
    std::string name, job;

    do {
        std::cout << "\nEnter ID for student: ";
        std::cin >> id;
        std::cout << "Enter age for student: ";
        std::cin >> age;
        std::cout << "Enter name for student: ";
        std::cin >> name;
        std::cout << "Enter job for student: ";
        std::cin >> job;
        std::cout << "\nFor Add new student enter 'Y': ";
        std::cin >> q;

        list.add(id, age, name, job);
    } while(q == 'Y' || q == 'y');

    std::cout << "\n\nAll Students :\n\n";
    list.show();

    do{
        std::cout << "\nEnter ID to search for a student: ";
        int search;
        std::cin >> search;

        Student* student = list.find(search);
        if (student != nullptr) {
            std::cout << "\nStudent Found:\nID: " << student->id <<  "\nAge: " << student->age << "\nName: " << student->name << "\nJob: " << student->job << "\n\n";
        } else {
            std::cout << "\n4Student with ID " << search << " not found.\n\n";
        }
        
        std::cout << "for find student enter 'Y': ";
        std::cin >> q;
    }while(q == 'Y' || q == 'y');

    return 0;
}