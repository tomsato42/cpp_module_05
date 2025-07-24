#ifndef INTERN_H
#define INTERN_H

#include "AForm.h"
#include "Bureaucrat.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"
#include <stdexcept>

typedef AForm *(*FormCreator)(const std::string &target);

class Intern {
public:
    Intern();

    ~Intern();

    Intern(const Intern &);

    Intern &operator=(const Intern &);

    AForm *makeForm(const std::string &formType, const std::string &formName) const;

private:
    static const int numberOfForms = 3;
    std::string formNames[numberOfForms];
    AForm *formDummies[numberOfForms];
};

#endif // INTERN_H
