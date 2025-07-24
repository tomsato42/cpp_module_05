#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H
#include "AForm.h"

class RobotomyRequestForm : public AForm {
public:
    RobotomyRequestForm();

    RobotomyRequestForm(const std::string &target);

    ~RobotomyRequestForm();

    RobotomyRequestForm(const RobotomyRequestForm &);

    RobotomyRequestForm &operator=(const RobotomyRequestForm &);

    void execute(Bureaucrat const &executor) const;

private:
    std::string target_;
};

#endif // ROBOTOMYREQUESTFORM_H
