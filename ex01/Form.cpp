#include "Form.h"

#include <iostream>

Form::Form() : name_("Default Form"), isSigned_(false), gradeToSign_(150), gradeToExecute_(150) {
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : name_(name), isSigned_(false), gradeToSign_(gradeToSign), gradeToExecute_(gradeToExecute) {
    checkException();
}
Form::Form(const char *&name, int gradeToSign, int gradeToExecute) : name_(std::string(name)), isSigned_(false), gradeToSign_(gradeToSign), gradeToExecute_(gradeToExecute) {
    checkException();
}

void Form::checkException() const {
    if (gradeToSign_ < 1 || gradeToExecute_ < 1) {
        throw GradeTooHighException();
    }
    if (150 < gradeToSign_ || 150 < gradeToExecute_) {
        throw GradeTooLowException();
    }
}


Form::~Form() {
}

Form::Form(const Form &other)
    : name_(other.name_), gradeToSign_(other.gradeToSign_), gradeToExecute_(other.gradeToExecute_) {
    isSigned_ = other.isSigned_;
}

Form &Form::operator=(const Form &other) {
    if (this != &other) {
        this->~Form();
        new(this) Form(other.name_, other.gradeToSign_, other.gradeToExecute_);
        isSigned_ = other.isSigned_;
    }
    return *this;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > gradeToSign_) {
        throw GradeTooLowException();
    }
    isSigned_ = true;
}

std::string Form::getName() const {
    return name_;
}

bool Form::isSigned() const {
    return isSigned_;
}

int Form::getGradeToSign() const {
    return gradeToSign_;
}

int Form::getGradeToExecute() const {
    return gradeToExecute_;
}

const char *Form::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

std::ostream &operator<<(std::ostream &os, const Form &f) {
    return os << f.getName() << " Form, "
           << "isSigned: " << (f.isSigned() ? "yes" : "no") << ", "
           << "gradeToSign: " << f.getGradeToSign() << ", "
           << "gradeToExecute: " << f.getGradeToExecute();
}
