#include <iomanip>
#include <iostream>

#include "Bureaucrat.h"

int main() { {
        std::cout << "--------------------------------" << std::endl; {
            const Bureaucrat tmp = Bureaucrat();
            std::cout << tmp << std::endl;
        }
        std::cout << "--------------------------------" << std::endl;
        try {
            std::cout << "grade:" << std::setw(3) << 1 << " ->";
            Bureaucrat tmp = Bureaucrat(std::string("Adam"), 1);
            std::cout << "OK" << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "NG: " << e.what() << std::endl;
        }
    } {
        try {
            std::cout << "grade:" << std::setw(3) << 0 << " ->";
            Bureaucrat tmp = Bureaucrat(std::string("Adam"), 0); // This should throw an exception
            std::cout << "OK" << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "NG: " << e.what() << std::endl;
        }
    } {
        try {
            std::cout << "grade:" << std::setw(3) << 150 << " ->";
            Bureaucrat tmp = Bureaucrat(std::string("Adam"), 150); // This should throw an exception
            std::cout << "OK" << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "NG: " << e.what() << std::endl;
        }
    } {
        try {
            std::cout << "grade:" << std::setw(3) << 151 << " ->";
            Bureaucrat tmp = Bureaucrat(std::string("Adam"), 151); // This should throw an exception
            std::cout << "OK" << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "NG: " << e.what() << std::endl;
        }
    } {
        Bureaucrat tmp = Bureaucrat(std::string("Adam"), 100);
        std::cout << "grade:" << std::setw(3) << tmp.getGrade() << " ->";
        try {
            tmp.promote();
            std::cout << "OK" << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "NG: " << e.what() << std::endl;
        }
    } {
        Bureaucrat tmp = Bureaucrat(std::string("Adam"), 1);
        std::cout << "grade:" << std::setw(3) << tmp.getGrade() << " ->";
        try {
            tmp.promote();
            std::cout << "OK" << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "NG: " << e.what() << std::endl;
        }
    } {
        Bureaucrat tmp = Bureaucrat(std::string("Adam"), 150);
        std::cout << "grade:" << std::setw(3) << tmp.getGrade() << " ->";
        try {
            tmp.demote();
            std::cout << "OK" << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "NG: " << e.what() << std::endl;
        }
    }
    std::cout << "--------------------------------" << std::endl; {
        Bureaucrat tmp = Bureaucrat(std::string("Adam"), 149);
        std::cout << "grade:" << std::setw(3) << tmp.getGrade() << " ->";
        try {
            tmp.demote();
            std::cout << "OK: " << "grade:" << std::setw(3) << tmp.getGrade() << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "NG: " << "grade:" << std::setw(3) << tmp.getGrade() << " " << e.what() << std::endl;
        }
        std::cout << "grade:" << std::setw(3) << tmp.getGrade() << " ->";
        try {
            tmp.demote();
            std::cout << "OK: " << "grade:" << std::setw(3) << tmp.getGrade() << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "NG: " << "grade:" << std::setw(3) << tmp.getGrade() << " " << e.what() << std::endl;
        }
    } {
        Bureaucrat tmp = Bureaucrat(std::string("Adam"), 2);
        std::cout << "grade:" << std::setw(3) << tmp.getGrade() << " ->";
        try {
            tmp.promote();
            std::cout << "OK: " << "grade:" << std::setw(3) << tmp.getGrade() << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "NG: " << "grade:" << std::setw(3) << tmp.getGrade() << " " << e.what() << std::endl;
        }
        std::cout << "grade:" << std::setw(3) << tmp.getGrade() << " ->";
        try {
            tmp.promote();
            std::cout << "OK: " << "grade:" << std::setw(3) << tmp.getGrade() << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "NG: " << "grade:" << std::setw(3) << tmp.getGrade() << " " << e.what() << std::endl;
        }
    }
}
