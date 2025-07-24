#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <string>
#include <exception>
#include "AForm.h"

// ANSI エスケープシーケンスの定義
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

// 官僚クラス
class AForm;

class Bureaucrat {
public:
    Bureaucrat();

    Bureaucrat(const std::string &name, int grade);

    ~Bureaucrat();

    Bureaucrat(const Bureaucrat &);

    Bureaucrat &operator=(const Bureaucrat &);

    std::string getName() const;

    int getGrade() const;

    void promote(); // 昇格

    void demote(); // 降格

    void signForm(AForm &f) const;

    void executeForm(AForm const &form) const;

    class GradeTooHighException : public std::exception {
    public:
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char *what() const throw();
    };

private:
    const std::string name_; // 名前
    int grade_; // グレード（1が最高、150が最低）
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif // BUREAUCRAT_H
