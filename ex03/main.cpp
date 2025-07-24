#include <iomanip>
#include <iostream>
#include "AForm.h"
#include "Bureaucrat.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"
#include "Intern.h"

int main() {
    const Bureaucrat president("President", 1);
    const Bureaucrat adam("Adam", 30);
    const Bureaucrat bob("Bob", 150);
    Intern intern = Intern();
    std::cout << "--------------------------------" << std::endl;
    // internによるフォーム作成のテスト
    {
        {
            std::cout << std::right << BOLD << CYAN << std::setw(10) << "Intern" << RESET << ": ";
            const AForm *form = intern.makeForm("shrubbery creation", "HOME");
            if (form != NULL) {
                delete form;
            }
        } {
            std::cout << std::right << BOLD << CYAN << std::setw(10) << "Intern" << RESET << ": ";
            const AForm *form = intern.makeForm("no exist form type", "Home");
            if (form != NULL) {
                delete form;
            }
        } {
            std::cout << std::right << BOLD << CYAN << std::setw(10) << "Intern" << RESET << ": ";
            const AForm *form = intern.makeForm("shrubbery creation", "");
            if (form != NULL) {
                delete form;
            }
        }
    }
    std::cout << "--------------------------------" << std::endl;
    // ShrubberyCreationFormのテスト
    {
        AForm *ShrubberyForm = NULL;

        // フォーム作成
        std::cout << std::right << BOLD << CYAN << std::setw(10) << "Intern" << RESET << ": ";
        ShrubberyForm = intern.makeForm("shrubbery creation", "Home");
        if (ShrubberyForm == NULL) {
            return 1;
        }
        // 実行（署名前）
        std::cout << std::right << BOLD << RED << std::setw(10) << "Fail" << RESET << ": ";
        adam.executeForm(*ShrubberyForm);

        // 大統領による署名
        std::cout << std::right << BOLD << GREEN << std::setw(10) << "Sign" << RESET << ": ";
        president.signForm(*ShrubberyForm);

        // 実行（署名後）
        std::cout << std::right << BOLD << BLUE << std::setw(10) << "Execute" << RESET << ": ";
        adam.executeForm(*ShrubberyForm);

        delete ShrubberyForm;
    }
    std::cout << "--------------------------------" << std::endl;
    // RobotomyRequestFormのテスト
    {
        AForm *RobotomyForm = NULL;

        // フォーム作成
        std::cout << std::right << BOLD << CYAN << std::setw(10) << "Intern" << RESET << ": ";
        RobotomyForm = intern.makeForm("robotomy request", "Robot");
        if (RobotomyForm == NULL) {
            return 1;
        }

        // 実行（署名前）
        std::cout << std::right << BOLD << RED << std::setw(10) << "Fail" << RESET << ": ";
        adam.executeForm(*RobotomyForm);

        // アダムによる署名
        std::cout << std::right << BOLD << GREEN << std::setw(10) << "Sign" << RESET << ": ";
        adam.signForm(*RobotomyForm);

        // 実行（署名後）
        std::cout << "--------------------------------" << std::endl;
        for (int i = 0; i < 4; i++) {
            std::cout << std::right << BOLD << BLUE << std::setw(10) << "Execute" << RESET << ": ";
            adam.executeForm(*RobotomyForm);
        }

        delete RobotomyForm;
    }
    std::cout << "--------------------------------" << std::endl;
    // PresidentialPardonFormのテスト
    {
        AForm *PardonForm = NULL;

        // フォーム作成
        std::cout << std::right << BOLD << CYAN << std::setw(10) << "Intern" << RESET << ": ";
        PardonForm = intern.makeForm("presidential pardon", "Bob");
        if (PardonForm == NULL) {
            return 1;
        }

        // 実行（署名前）
        std::cout << std::right << BOLD << RED << std::setw(10) << "Fail" << RESET << ": ";
        president.executeForm(*PardonForm);

        // 大統領による署名
        std::cout << std::right << BOLD << GREEN << std::setw(10) << "Sign" << RESET << ": ";
        president.signForm(*PardonForm);

        // 実行（署名後）
        std::cout << std::right << BOLD << BLUE << std::setw(10) << "Execute" << RESET << ": ";
        president.executeForm(*PardonForm);

        delete PardonForm;
    }
    return 0;
}
