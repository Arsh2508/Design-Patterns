#ifndef NOTIFICATION_FACTORY_HPP
#define NOTIFICATION_FACTORY_HPP

#include "Notification.hpp"
#include <memory>

class NotificationFactory {
public:
    virtual std::unique_ptr<Notification> createEmailNotification() const = 0;
    virtual std::unique_ptr<Notification> createSMSNotification() const = 0;
    virtual std::unique_ptr<Notification> createPushNotification() const = 0;
    virtual ~NotificationFactory() = default;
};

class WindowsNotificationFactory : public NotificationFactory{
public:
    std::unique_ptr<Notification> createEmailNotification() const override
    {
        return std::make_unique<WindowsEmailNotification>();
    }
    std::unique_ptr<Notification> createSMSNotification() const override 
    {
        return std::make_unique<WindowsSmsNotification>();
    }
    std::unique_ptr<Notification> createPushNotification() const override
    {
        return std::make_unique<WindowsPushNotification>();
    }
};

class MacOSNotificationFactory : public NotificationFactory{
public:
    std::unique_ptr<Notification> createEmailNotification() const override
    {
        return std::make_unique<MacOSEmailNotification>();
    }
    std::unique_ptr<Notification> createSMSNotification() const override 
    {
        return std::make_unique<MacOSSmsNotification>();
    }
    std::unique_ptr<Notification> createPushNotification() const override
    {
        return std::make_unique<MacOSPushNotification>();
    }
};

class LinuxNotificationFactory : public NotificationFactory{
public:
    std::unique_ptr<Notification> createEmailNotification() const override
    {
        return std::make_unique<LinuxEmailNotification>();
    }
    std::unique_ptr<Notification> createSMSNotification() const override 
    {
        return std::make_unique<LinuxSmsNotification>();
    }
    std::unique_ptr<Notification> createPushNotification() const override
    {
        return std::make_unique<LinuxPushNotification>();
    }
};

#endif