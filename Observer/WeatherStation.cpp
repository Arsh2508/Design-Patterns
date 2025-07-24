#include "WeatherStation.hpp"
#include "Observer.hpp"

ConcreteWeatherStation::ConcreteWeatherStation(double temp)
    : WeatherStation(temp)
{
}

WeatherStation::WeatherStation(double temp)
    :temperature{temp}
{
}

void ConcreteWeatherStation::addObserver(Observer *ob)
{
    observers.insert(ob);
}

void ConcreteWeatherStation::removeObserver(Observer *ob)
{
    observers.erase(ob);    
}

void ConcreteWeatherStation::notifyObservers()
{
    for(auto it = observers.begin(); it != observers.end(); ++it) {
        (*it)->update(temperature);
    }
}

void ConcreteWeatherStation::ChangeTemperature(double temp)
{
    temperature = temp;
    notifyObservers();
}
