#ifndef AFORM_H
#define AFORM_H
#include <string>
#include <exception>
#include <ostream>
#include "Bureaucrat.h"
class Bureaucrat;

class AForm {
public:
    AForm();

    AForm(const std::string &name, int gradeToSign, int gradeToExecute);

    void checkException() const;

    AForm(const char * &name, int gradeToSign, int gradeToExecute);

    virtual ~AForm();

    AForm(const AForm &);

    AForm &operator=(const AForm &);

    void beSigned(const Bureaucrat &bureaucrat);

    virtual void execute(Bureaucrat const &executor) const = 0;

    virtual AForm *create(const std::string &target) const = 0;

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

std::ostream &operator<<(std::ostream &os, const AForm &f);

#endif // AFORM_H
