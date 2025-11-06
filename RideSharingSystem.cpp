// File: RideSharingSystem.cpp
// I implemented a Ride Sharing System in C++ to demonstrate encapsulation, inheritance, and polymorphism.
// I start by defining a base class Ride that encapsulates core ride details and enforces a virtual fare calculation.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Base Ride class: I encapsulated rideID, pickup/dropoff locations, and distance as protected members.
class Ride {
protected:
    int rideID;
    string pickupLocation;
    string dropoffLocation;
    double distance;

public:
    // I initialize each ride with its ID, start/end locations, and distance.
    Ride(int id, const string& pick, const string& drop, double dist)
      : rideID(id), pickupLocation(pick), dropoffLocation(drop), distance(dist) {
        // I could validate inputs here if needed.
    }

    // I expose getters and setters to maintain encapsulation.
    int getRideID() const { return rideID; }
    void setDistance(double d) { distance = d; }
    double getDistance() const     { return distance; }

    // I declare calculateFare as pure virtual to force subclasses to implement it.
    virtual double calculateFare() const = 0;

    // I provide a default rideDetails method to display ride info uniformly.
    virtual void rideDetails() const {
        cout << "Ride " << rideID
             << ": from " << pickupLocation
             << " to " << dropoffLocation
             << ", distance=" << distance << " km"
             << ", fare=" << calculateFare()
             << endl;
    }

    virtual ~Ride() {}
};

// StandardRide subclass: I override calculateFare with my chosen rate.
class StandardRide : public Ride {
public:
    StandardRide(int id, const string& pick, const string& drop, double dist)
      : Ride(id, pick, drop, dist) {}

    double calculateFare() const override {
        // I apply a per-km rate of 1.50 for standard rides.
        return distance * 1.50;
    }
};

// PremiumRide subclass: I add a fixed premium charge and rate.
class PremiumRide : public Ride {
public:
    PremiumRide(int id, const string& pick, const string& drop, double dist)
      : Ride(id, pick, drop, dist) {}

    double calculateFare() const override {
        // I charge 2.50 per km plus a flat premium fee of 5.00.
        return (distance * 2.50) + 5.00;
    }
};

// Driver class: I keep driver details private and manage rides via a vector.
class Driver {
private:
    int driverID;
    string name;
    double rating;
    vector<Ride*> assignedRides;

public:
    // I initialize a driver with ID, name, and rating.
    Driver(int id, const string& n, double r)
      : driverID(id), name(n), rating(r) {}

    // I encapsulate ride assignment behind this method.
    void addRide(Ride* r) {
        assignedRides.push_back(r);
    }

    // I display driver info, including number of completed rides.
    void getDriverInfo() const {
        cout << "Driver " << name
             << " (ID: " << driverID << ")"
             << " Rating: " << rating
             << " | Rides completed: "
             << assignedRides.size()
             << endl;
    }
};

// Rider class: I model a rider's ride requests privately.
class Rider {
private:
    int riderID;
    string name;
    vector<Ride*> requestedRides;

public:
    Rider(int id, const string& n)
      : riderID(id), name(n) {}

    // I allow riders to request rides, which I store internally.
    void requestRide(Ride* r) {
        requestedRides.push_back(r);
    }

    // I let riders view their ride history using polymorphic details.
    void viewRides() const {
        for (auto r : requestedRides) {
            r->rideDetails();
        }
    }
};

// Main function: I demonstrate polymorphism and class interactions.
int main() {
    // I create standard and premium rides.
    vector<Ride*> rides;
    rides.push_back(new StandardRide(101, "Downtown", "Airport", 10));
    rides.push_back(new PremiumRide(102, "Mall", "Hotel", 5));

    // I show polymorphic fare calculations.
    cout << "-- Ride Details --" << endl;
    for (auto r : rides) {
        r->rideDetails();
    }

    // I set up a driver and assign rides to them.
    Driver alice(1, "Alice", 4.9);
    alice.addRide(rides[0]);
    alice.addRide(rides[1]);
    cout << endl;
    alice.getDriverInfo();

    // I set up a rider and record their requested rides.
    Rider bob(501, "Bob");
    bob.requestRide(rides[0]);
    bob.requestRide(rides[1]);
    cout << endl << "-- Bob's Ride History --" << endl;
    bob.viewRides();

    // I clean up allocated memory.
    for (auto r : rides) {
        delete r;
    }

    return 0;
}
