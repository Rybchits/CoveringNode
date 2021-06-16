#ifndef CUSTOMEXCEPTION_H
#define CUSTOMEXCEPTION_H

#include <QException>

/*! Класс собственных исключений программы. Унаследован от std::exception */
class CustomException :public std::exception{
    QString what_message;   /*!< Поле сообщения об ошибке */

public:
    //! Конструктор по сообщению исключения
    /*!
       \param[in] QString message - сообщение об исключении.
    */
    CustomException(QString message){
        what_message = message;
    }

    //! Перегрузка метода возвращающего сообщение об ошибке
    const char * what () const throw () {
          return what_message.toStdString().c_str();
       }
};

#endif // CUSTOMEXCEPTION_H
