#include "Bureaucrat.h"

Bureaucrat::Bureaucrat() : name_(std::string("Bob")) {
    grade_ = 150;
}

Bureaucrat::Bureaucrat(const std::string &name, const int grade) : name_(name) {
    if (grade < 1) {
        throw GradeTooHighException();
    }
    if (grade > 150) {
        throw GradeTooLowException();
    }
    grade_ = grade;
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name_(other.name_) {
    grade_ = other.grade_;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    if (this != &other) {
        grade_ = other.grade_;
    }
    return *this;
}

std::string Bureaucrat::getName() const {
    return name_;
}

int Bureaucrat::getGrade() const {
    return grade_;
}

void Bureaucrat::promote() {
    if (grade_ <= 1) {
        throw GradeTooHighException();
    }
    grade_--;
}

void Bureaucrat::demote() {
    if (grade_ >= 150) {
        throw GradeTooLowException();
    }
    grade_++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

std::ostream & operator<<(std::ostream &os, const Bureaucrat &b) {
    return os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
}
