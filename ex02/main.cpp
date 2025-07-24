#include <iostream>
#include "AForm.h"
#include "Bureaucrat.h"
#include "ShrubberyCreationForm.h"

int main() {
    const Bureaucrat president("President", 1);
    const Bureaucrat adam("Adam", 30);
    const Bureaucrat bob("Bob", 150); {
        AForm *ShrubberyForm = nullptr;

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
    return 0;
}
