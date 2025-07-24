#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H
#include "AForm.h"

class PresidentialPardonForm : public AForm {
public:
    PresidentialPardonForm();

    PresidentialPardonForm(const std::string &target);

    ~PresidentialPardonForm();

    PresidentialPardonForm(const PresidentialPardonForm &);

    PresidentialPardonForm &operator=(const PresidentialPardonForm &);

    void execute(Bureaucrat const &executor) const;

private:
    std::string target_;
};

#endif // PRESIDENTIALPARDONFORM_H
