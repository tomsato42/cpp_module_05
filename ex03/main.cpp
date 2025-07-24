#include <iostream>
#include "AForm.h"
#include "Bureaucrat.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"

int main() {
    const Bureaucrat president("President", 1);
    const Bureaucrat adam("Adam", 30);
    const Bureaucrat bob("Bob", 150);
    std::cout << "--------------------------------" << std::endl;
    // ShrubberyCreationFormのテスト
    {
        AForm *ShrubberyForm = NULL;

        // フォーム作成
        try {
            ShrubberyForm = new ShrubberyCreationForm("Home");
            std::cout << *ShrubberyForm << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "Form creation failed: " << e.what() << std::endl;
            return 1; // フォーム作成に失敗したら終了
        }

        // 実行（署名前）
        adam.executeForm(*ShrubberyForm);

        // 大統領による署名
        president.signForm(*ShrubberyForm);

        // 実行（署名後）
        adam.executeForm(*ShrubberyForm);

        delete ShrubberyForm;
    }
    std::cout << "--------------------------------" << std::endl;
    // RobotomyRequestFormのテスト
    {
        AForm *RobotomyForm = NULL;

        // フォーム作成
        try {
            RobotomyForm = new RobotomyRequestForm("Robot");
            std::cout << *RobotomyForm << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "Form creation failed: " << e.what() << std::endl;
            return 1; // フォーム作成に失敗したら終了
        }

        // 実行（署名前）
        adam.executeForm(*RobotomyForm);

        // アダムによる署名
        adam.signForm(*RobotomyForm);

        // 実行（署名後）
        std::cout << "--------------------------------" << std::endl;
        for (int i = 0; i < 4; i++) {
            adam.executeForm(*RobotomyForm);
        }

        delete RobotomyForm;
    }
    std::cout << "--------------------------------" << std::endl;
    // PresidentialPardonFormのテスト
    {
        AForm *PardonForm = NULL;

        // フォーム作成
        try {
            PardonForm = new PresidentialPardonForm("Pardon");
            std::cout << *PardonForm << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "Form creation failed: " << e.what() << std::endl;
            return 1; // フォーム作成に失敗したら終了
        }

        // 実行（署名前）
        president.executeForm(*PardonForm);

        // 大統領による署名
        president.signForm(*PardonForm);

        // 実行（署名後）
        president.executeForm(*PardonForm);

        delete PardonForm;
    }
    return 0;
}
