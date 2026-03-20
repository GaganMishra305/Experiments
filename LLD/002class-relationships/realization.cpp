// "implements"-relationship
// fulfils a contract (ex. PaymentProcessor class)

#include <bits/stdc++.h>
using namespace std;

class Flyable {
public:
    virtual void fly() = 0;
    virtual string getFlightInfo() = 0;
    virtual ~Flyable() = default;
};

class Bird : public Flyable {
private:
    string species;
    double wingSpan;

public:
    Bird(const string& species, double wingSpan)
        : species(species), wingSpan(wingSpan) {}

    void fly() override {
        cout << species << " flaps its wings and takes off." << endl;
    }

    string getFlightInfo() override {
        return species + " (wingspan: " + to_string(wingSpan) + "m, powered by muscle)";
    }
};

class Airplane : public Flyable {
private:
    string model;
    int maxAltitude;

public:
    Airplane(const string& model, int maxAltitude)
        : model(model), maxAltitude(maxAltitude) {}

    void fly() override {
        cout << model << " engines roar as it accelerates down the runway." << endl;
    }

    string getFlightInfo() override {
        return model + " (max altitude: " + to_string(maxAltitude) + "ft, powered by jet engines)";
    }
};

class Drone : public Flyable {
private:
    int batteryLevel;
    double maxRange;

public:
    Drone(int batteryLevel, double maxRange)
        : batteryLevel(batteryLevel), maxRange(maxRange) {}

    void fly() override {
        cout << "Drone propellers spin up. Battery at " << batteryLevel << "%." << endl;
    }

    string getFlightInfo() override {
        return "Drone (range: " + to_string(maxRange) + "km, battery: " + to_string(batteryLevel) + "%)";
    }
};

int main() {
    vector<unique_ptr<Flyable>> flyingThings;
    flyingThings.push_back(make_unique<Bird>("Eagle", 2.3));
    flyingThings.push_back(make_unique<Airplane>("Boeing 737", 41000));
    flyingThings.push_back(make_unique<Drone>(85, 10.0));

    for (const auto& flyer : flyingThings) {
        cout << flyer->getFlightInfo() << endl;
        flyer->fly();
        cout << endl;
    }

    return 0;
}
