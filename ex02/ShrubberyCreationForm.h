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

private:
    std::string target_;
};

#endif // SHRUBBERYCREATIONFORM_H
