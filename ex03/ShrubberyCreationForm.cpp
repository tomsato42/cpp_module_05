#include "ShrubberyCreationForm.h"

#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), target_("default_target") {
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), target_(target) {
    if (target.empty()) {
        throw std::invalid_argument("Target cannot be empty");
    }
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), target_(other.target_) {
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        target_ = other.target_;
    }
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    AForm::execute(executor);

    std::ofstream file(std::string(target_+"_shrubbery").c_str());
    if (!file)
        throw std::ios_base::failure("Failed to open file");

    file <<
            "                     .o00o\n"
            "                   o000000oo\n"
            "                  00000000000o\n"
            "                 00000000000000\n"
            "              oooooo  00000000  o88o\n"
            "           ooOOOOOOOoo  ```''  888888\n"
            "         OOOOOOOOOOOO'.qQQQQq. `8888'\n"
            "        oOOOOOOOOOO'.QQQQQQQQQQ/.88'\n"
            "        OOOOOOOOOO'.QQQQQQQQQQ/ /q\n"
            "         OOOOOOOOO QQQQQQQQQQ/ /QQ\n"
            "           OOOOOOOOO `QQQQQQ/ /QQ'\n"
            "             OO:F_P:O `QQQ/  /Q'\n"
            "                \\\\. \\ |  // |\n"
            "                d\\ \\\\\\|_////\n"
            "                qP| \\\\ _' `|Ob\n"
            "                   \\  / \\  \\Op\n"
            "                   |  | O| |\n"
            "           _       /\\. \\_/ /\\\n"
            "            `---__/|_\\\\   //|  __\n"
            "                  `-'  `-'`-'-'\n";

    file.close();
}
