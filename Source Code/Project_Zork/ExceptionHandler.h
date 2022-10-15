#ifndef EXCEPTIONHANDLER_H
#define EXCEPTIONHANDLER_H
#include <exception>

class ExceptionHandler : public std::exception
{
public:
    const char* what()const throw();
};

#endif // EXCEPTIONHANDLER_H
