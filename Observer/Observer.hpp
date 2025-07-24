#ifndef OBSERVER_HPP
#define OBSERVER_HPP

class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(double temperature) = 0;

};

class PhoneDisplay : public Observer {
public:
    void update(double temperature) override;
};

class LEDDisplay : public Observer {
public:
    void update(double temperature) override;
};

#endif