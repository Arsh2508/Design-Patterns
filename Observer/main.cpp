#include <iostream>
#include "WeatherStation.hpp"
#include "Observer.hpp"

int main()
{
    WeatherStation* station = new ConcreteWeatherStation(10);

    Observer *phone = new PhoneDisplay();
    Observer *led = new LEDDisplay();

    station->addObserver(phone);
    
    station->ChangeTemperature(28.5);

    station->addObserver(led);
    station->notifyObservers();
    station->removeObserver(phone);
    station->ChangeTemperature(31.5);

    delete station;
    delete phone;
    delete led;

    return 0;
}