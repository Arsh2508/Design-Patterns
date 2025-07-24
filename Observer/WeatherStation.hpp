#ifndef WEATHER_STATION_HPP
#define WEATHER_STATION_HPP
#include <unordered_set>

class Observer;

class WeatherStation {
public:
    WeatherStation(double temp);
    virtual void addObserver(Observer* ) = 0;
    virtual void removeObserver(Observer*) = 0;
    virtual void notifyObservers() = 0;

    virtual void ChangeTemperature(double temp) = 0;
    
    virtual ~WeatherStation() = default;

protected:
    std::unordered_set<Observer*> observers;
    double temperature;
};

class ConcreteWeatherStation : public WeatherStation {
public:
    ConcreteWeatherStation(double temp);
    virtual void addObserver(Observer *ob) override;
    virtual void removeObserver(Observer* ob) override;
    virtual void notifyObservers();

    void ChangeTemperature(double temp) override;
};

#endif