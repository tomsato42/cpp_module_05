#include "RobotomyRequestForm.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45) {
    srand(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), target_(target) {
    if (target.empty()) {
        throw std::invalid_argument("Target cannot be empty");
    }
    srand(time(NULL));
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), target_(other.target_) {
    srand(time(NULL));
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        target_ = other.target_;
        srand(time(NULL));
    }
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    AForm::execute(executor);
    std::cout << "*drilling noises*" << std::endl;
    if (rand() % 2 == 0) {
        std::cout << "Robotomy on " << target_ << " has been successful!" << std::endl;
    } else {
        std::cout << "Robotomy on " << target_ << " has failed!" << std::endl;
    }
}
