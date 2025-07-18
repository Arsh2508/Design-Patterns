#include <iostream>
#include <string>
#include "Notification.hpp"
#include "NotificationFactory.hpp"

int main()
{
    std::unique_ptr<Notification> notification = NotificationFactory::createNotification("email");
    std::unique_ptr<Notification> Sms_notification = NotificationFactory::createNotification("sms");
    std::unique_ptr<Notification> Push_notification = NotificationFactory::createNotification("push");
    
    notification->notify();
    Sms_notification->notify();
    Push_notification->notify();
    return 0;
}