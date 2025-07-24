#include "Intern.h"

#include <iostream>

Intern::Intern() {
    formDummies[0] = new ShrubberyCreationForm("Dummy");
    formDummies[1] = new RobotomyRequestForm("Dummy");
    formDummies[2] = new PresidentialPardonForm("Dummy");

    formNames[0] = "shrubbery creation";
    formNames[1] = "robotomy request";
    formNames[2] = "presidential pardon";
}

Intern::~Intern() {
    for (unsigned int i = 0; i < numberOfForms; i++) {
        delete formDummies[i];
    }
}

Intern::Intern(const Intern &other) {
    for (int i = 0; i < numberOfForms; i++) {
        formDummies[i] = other.formDummies[i]->create("Dummy");
    }
}

Intern &Intern::operator=(const Intern &other) {
    if (this != &other) {
        for (unsigned int i = 0; i < numberOfForms; i++) {
            delete formDummies[i];
        }
        for (int i = 0; i < numberOfForms; i++) {
            formDummies[i] = other.formDummies[i]->create("Dummy");
        }
    }
    return *this;
}

AForm *Intern::makeForm(const std::string &formType, const std::string &formName) const {
    AForm *newForm = NULL;
    if (formType.empty() || formName.empty()) {
        std::cerr << "Intern cannot create a form with empty type or name." << std::endl;
        return NULL;
    }

    try {
        for (unsigned int i = 0; i < numberOfForms; i++) {
            if (formType == formNames[i]) {
                newForm = formDummies[i]->create(formName);
                break;
            }
        }
    } catch (const std::exception &e) {
        std::cerr << "Intern could not create form: " << e.what() << std::endl;
        return NULL;
    }
    if (newForm == NULL) {
        std::cout << "formType: " << formType << " is invalid." << std::endl;

    }
    else {
        std::cout << "Intern creates " << *newForm << "." << std::endl;
    }
    return newForm;
}
