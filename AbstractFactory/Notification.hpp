#ifndef NOTIFICATION_HPP
#define NOTIFICATION_HPP
#include <iostream>

class Notification {
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

class WindowsEmailNotification : public EmailNotification {
public:
    void notify() const override
    {
        std::cout<<"Windows: ";
        EmailNotification::notify();
    }
};

class WindowsSmsNotification : public SMSNotification {
public:
    void notify() const override
    {
        std::cout<<"Windows: ";
        SMSNotification::notify();
    }
};

class WindowsPushNotification : public PushNotification {
public:
    void notify() const override
    {
        std::cout<<"Windows: ";
        PushNotification::notify();
    }
};

class MacOSEmailNotification : public EmailNotification {
public:
    void notify() const override
    {
        std::cout<<"MacOS: ";
        EmailNotification::notify();
    }
};

class MacOSSmsNotification : public SMSNotification {
public:
    void notify() const override
    {
        std::cout<<"MacOS: ";
        SMSNotification::notify();
    }
};

class MacOSPushNotification : public PushNotification {
public:
    void notify() const override
    {
        std::cout<<"MacOS: ";
        PushNotification::notify();
    }
};

class LinuxEmailNotification : public EmailNotification {
public:
    void notify() const override
    {
        std::cout<<"Linux: ";
        EmailNotification::notify();
    }
};


class LinuxSmsNotification : public SMSNotification {
public:
    void notify() const override
    {
        std::cout<<"Linux: ";
        SMSNotification::notify();
    }
};

class LinuxPushNotification : public PushNotification {
public:
    void notify() const override
    {
        std::cout<<"Linux: ";
        PushNotification::notify();
    }
};

#endif