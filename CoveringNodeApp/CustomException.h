#ifndef CUSTOMEXCEPTION_H
#define CUSTOMEXCEPTION_H

#include <QException>

class CustomException :public std::exception{
    QString what_message;

public:
    CustomException(QString message){
        what_message = message;
    }

    const char * what () const throw () {
          return what_message.toStdString().c_str();
       }
};

#endif // CUSTOMEXCEPTION_H
