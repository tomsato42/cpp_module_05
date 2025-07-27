#ifndef FORM_H
#define FORM_H
#include <string>
#include <exception>
#include <ostream>
#include "Bureaucrat.h"
class Bureaucrat;
class Form {
public:
    Form();

    Form(const std::string &name, int gradeToSign, int gradeToExecute);

    void checkException() const;

    Form(const char* &name, int gradeToSign, int gradeToExecute);

    ~Form();

    Form(const Form &);

    Form &operator=(const Form &);

    void beSigned(const Bureaucrat &bureaucrat);

    std::string getName() const;

    bool isSigned() const;

    int getGradeToSign() const;

    int getGradeToExecute() const;

    class GradeTooHighException : public std::exception {
    public:
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char *what() const throw();
    };

private:
    const std::string name_;
    bool isSigned_;
    const int gradeToSign_;
    const int gradeToExecute_;
};

std::ostream &operator<<(std::ostream &os, const Form &f);

#endif // FORM_H
