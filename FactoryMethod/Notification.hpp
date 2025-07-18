#ifndef NOTIFICATION_HPP
#define NOTIFICATION_HPP
#include <iostream>

class Notification{
public:
    virtual void notify() const = 0;

    virtual ~Notification() = default; 
};

class EmailNotification : public Notification {
public:
    void notify() const override
    {
        std::cout<<"Sending Email Notification"<<std::endl;
    } 
};

class SMSNotification : public Notification {
public:
    void notify() const override 
    {
        std::cout<< "Sending SMS Notification"<< std::endl;
    }
};

class PushNotification : public Notification {
public:
    void notify() const override 
    {
        std::cout << "Sending Push Notification" <<std::endl;
    }
};

#endif