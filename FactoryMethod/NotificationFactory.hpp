#ifndef NOTIFICATION_FACTORY_HPP
#define NOTIFICATION_FACTORY_HPP
#include "Notification.hpp"
#include <memory>
#include <string>

class NotificationFactory {
public:
    static std::unique_ptr<Notification> createNotification(const std::string& type);
};

 

#endif
