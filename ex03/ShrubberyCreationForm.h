#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H
#include "AForm.h"

class ShrubberyCreationForm : public AForm {
public:
    ShrubberyCreationForm();

    ShrubberyCreationForm(const std::string &target);

    ~ShrubberyCreationForm();

    ShrubberyCreationForm(const ShrubberyCreationForm &);

    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &);

    void execute(Bureaucrat const &executor) const;

    AForm *create(const std::string &target) const;

private:
    std::string target_;
};

#endif // SHRUBBERYCREATIONFORM_H
