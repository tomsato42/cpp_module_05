#include <iostream>

#include "Bureaucrat.h"

int main() {
    std::cout << "--------------------------------" << std::endl; {
        Bureaucrat bob;
        std::cout << bob << std::endl;

        Form formA("formA", 150, 150);
        std::cout << formA << std::endl;
        bob.signForm(formA);
        std::cout << formA << std::endl;

        Form formB("formB", 149, 149);
        std::cout << formB << std::endl;
        bob.signForm(formB);
        std::cout << formB << std::endl;
    }
    std::cout << "--------------------------------" << std::endl; {
        {
            try {
                Form(std::string("too high grade to sign"), 0, 150);
            } catch (const std::exception &e) {
                std::cerr << "Exception: " << e.what() << std::endl;
            }
        } {
            try {
                Form(std::string("too high grade to execute"), 150, 0);
            } catch (const std::exception &e) {
                std::cerr << "Exception: " << e.what() << std::endl;
            }
        } {
            try {
                Form(std::string("too low grade to sign"), 151, 150);
            } catch (const std::exception &e) {
                std::cerr << "Exception: " << e.what() << std::endl;
            }
        } {
            try {
                Form(std::string("too low grade to execute"), 150, 151);
            } catch (const std::exception &e) {
                std::cerr << "Exception: " << e.what() << std::endl;
            }
        } {
            try {
                Form(std::string("invalid form"), 0, 151);
            } catch (const std::exception &e) {
                std::cerr << "Exception: " << e.what() << std::endl;
            }
        } {
            try {
                Form form = Form(std::string("valid form"), 150, 150);
                std::cout << "Form created successfully." << std::endl;
            } catch (const std::exception &e) {
                std::cerr << "Exception: " << e.what() << std::endl;
            }
        }
    }

    return 0;
}
