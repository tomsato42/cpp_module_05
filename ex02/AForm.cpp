#include "AForm.h"

#include <iostream>

AForm::AForm() : name_("Default AForm"), isSigned_(false), gradeToSign_(150), gradeToExecute_(150) {
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
    : name_(name), isSigned_(false), gradeToSign_(gradeToSign), gradeToExecute_(gradeToExecute) {
    checkException();
}

AForm::AForm(const char *&name, int gradeToSign, int gradeToExecute) : name_(std::string(name)), isSigned_(false),
                                                                       gradeToSign_(gradeToSign),
                                                                       gradeToExecute_(gradeToExecute) {
    checkException();
}

void AForm::checkException() const {
    if (gradeToSign_ < 1 || gradeToExecute_ < 1) {
        throw GradeTooHighException();
    }
    if (150 < gradeToSign_ || 150 < gradeToExecute_) {
        throw GradeTooLowException();
    }
}


AForm::~AForm() {
}

AForm::AForm(const AForm &other)
    : name_(other.name_), gradeToSign_(other.gradeToSign_), gradeToExecute_(other.gradeToExecute_) {
    isSigned_ = other.isSigned_;
}

AForm &AForm::operator=(const AForm &other) {
    if (this != &other) {
        isSigned_ = other.isSigned_;
    }
    return *this;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > gradeToSign_) {
        throw GradeTooLowException();
    }
    isSigned_ = true;
}

void AForm::execute(Bureaucrat const &executor) const {
    if (!isSigned_) {
        throw std::runtime_error("Form is not signed");
    }
    if (executor.getGrade() > gradeToExecute_) {
        throw GradeTooLowException();
    }
}

std::string AForm::getName() const {
    return name_;
}

bool AForm::isSigned() const {
    return isSigned_;
}

int AForm::getGradeToSign() const {
    return gradeToSign_;
}

int AForm::getGradeToExecute() const {
    return gradeToExecute_;
}

const char *AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

std::ostream &operator<<(std::ostream &os, const AForm &f) {
    return os << f.getName() << " Form, "
           << "isSigned: " << (f.isSigned() ? "yes" : "no") << ", "
           << "gradeToSign: " << f.getGradeToSign() << ", "
           << "gradeToExecute: " << f.getGradeToExecute();
}
