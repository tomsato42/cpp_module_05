#include "PresidentialPardonForm.h"

#include <iostream>

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5), target_("default_target") {
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", 25, 5), target_(target) {
    if (target.empty()) {
        throw std::invalid_argument("Target cannot be empty");
    }
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
    : AForm(other), target_(other.target_) {
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        target_ = other.target_;
    }
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    AForm::execute(executor);
    std::cout << "*info : " << target_ << " has been graciously pardoned by the magnificent Zaphod Beeblebrox." <<
            std::endl;
}

AForm *PresidentialPardonForm::create(const std::string &target) const {
    return new PresidentialPardonForm(target);
}
