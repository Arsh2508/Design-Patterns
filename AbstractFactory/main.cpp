#include <iostream>
#include <memory>
#include "Notification.hpp"
#include "NotificationFactory.hpp"

int main()
{
    WindowsNotificationFactory obj1;
    MacOSNotificationFactory obj2;
    LinuxNotificationFactory obj3;

    std::unique_ptr<Notification> WindEmail = obj1.createEmailNotification();
    std::unique_ptr<Notification> MacOsSMS = obj2.createSMSNotification();
    std::unique_ptr<Notification> LinuxPush = obj3.createPushNotification();

    WindEmail->notify();
    MacOsSMS->notify();
    LinuxPush->notify();
    return 0;
}