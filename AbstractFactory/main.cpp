#include <iostream>
#include <memory>
#include "Notification.hpp"
#include "NotificationFactory.hpp"

int main()
{
    WindowsNotificationFactory obj;

    std::unique_ptr<Notification> notif = obj.createEmailNotification();

    notif->notify();
    return 0;
}