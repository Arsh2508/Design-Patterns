#include "NotificationFactory.hpp"
#include <memory>

std::unique_ptr<Notification> NotificationFactory::createNotification(const std::string &type)
{
    if(type == "email")
        return std::make_unique<EmailNotification>();
    else if (type == "sms")
        return std::make_unique<SMSNotification>();
    else if(type == "push")
        return std::make_unique<PushNotification>();
    else 
        return nullptr;
}