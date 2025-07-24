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
        try {
            ShrubberyForm->execute(adam);
        } catch (const std::exception &e) {
            std::cerr << "Execute failed: " << e.what() << std::endl;
        }

        // 大統領による署名
        try {
            ShrubberyForm->beSigned(president);
            std::cout << "Signed by president: " << *ShrubberyForm << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "President signing failed: " << e.what() << std::endl;
        }

        // 実行（署名後）
        try {
            ShrubberyForm->execute(adam);
            std::cout << "Executed successfully" << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "Execute after signing failed: " << e.what() << std::endl;
        }

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
        try {
            RobotomyForm->execute(adam);
        } catch (const std::exception &e) {
            std::cerr << "Execute failed: " << e.what() << std::endl;
        }

        // アダムによる署名
        try {
            RobotomyForm->beSigned(adam);
            std::cout << "Signed by Adam: " << *RobotomyForm << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "Adam signing failed: " << e.what() << std::endl;
        }

        // 実行（署名後）
        std::cout << "--------------------------------" << std::endl;
        for (int i = 0; i < 4; i++) {
            try {
                RobotomyForm->execute(adam);
                std::cout << "Executed successfully" << std::endl;
            } catch (const std::exception &e) {
                std::cerr << "Execute after signing failed: " << e.what() << std::endl;
            }
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
        try {
            PardonForm->execute(bob);
        } catch (const std::exception &e) {
            std::cerr << "Execute failed: " << e.what() << std::endl;
        }

        // 大統領による署名
        try {
            PardonForm->beSigned(president);
            std::cout << "Signed by president: " << *PardonForm << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "President signing failed: " << e.what() << std::endl;
        }

        // 実行（署名後）
        try {
            PardonForm->execute(president);
            std::cout << "Executed successfully" << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "Execute after signing failed: " << e.what() << std::endl;
        }

        delete PardonForm;
    }
    return 0;
}
