#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H
#include "AForm.h"

#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define RED     "\033[31m"


class RobotomyRequestForm : public AForm {
public:
    RobotomyRequestForm();

    RobotomyRequestForm(const std::string &target);

    ~RobotomyRequestForm();

    RobotomyRequestForm(const RobotomyRequestForm &);

    RobotomyRequestForm &operator=(const RobotomyRequestForm &);

    void execute(Bureaucrat const &executor) const;

    AForm *create(const std::string &target) const;

private:
    std::string target_;
};

#endif // ROBOTOMYREQUESTFORM_H
