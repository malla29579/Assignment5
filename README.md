# Ride Sharing System

I’ve implemented a class‑based **Ride Sharing System** in both **C++** and **Smalltalk**, demonstrating encapsulation, inheritance, and polymorphism.

---

## Repository Structure

* **RideSharingSystem.cpp**
  My C++ implementation of the `Ride`, `StandardRide`, `PremiumRide`, `Driver`, and `Rider` classes, with first‑person comments explaining each design choice.

* **RideSharingSystem.st**
  My Smalltalk script containing all class definitions and a demo usage block. Load it in a Pharo/Squeak Playground.

* **README.md**
  This file, written in the first person.

---

## How I Mapped Requirements

1. **Ride Class**

   * I encapsulated `rideID`, `pickupLocation`, `dropoffLocation`, and `distance` as protected/private fields.
   * I defined a virtual `calculateFare()` method in C++, and a `calculateFare` selector in Smalltalk.
   * I provided a uniform `rideDetails()` (or `rideDetails` in Smalltalk) method to display ride info.

2. **Specific Ride Subclasses**

   * I created `StandardRide` and `PremiumRide` that override the fare calculation with different rates and fees.
   * I demonstrated polymorphism by storing both types in a common collection and calling `rideDetails` or `calculateFare` dynamically.

3. **Driver Class**

   * I encapsulated `driverID`, `name`, `rating`, and a private list of assigned rides.
   * I wrote an `addRide(...)` method to update the driver’s list and a `getDriverInfo()` (or equivalent) method to print the summary.

4. **Rider Class**

   * I encapsulated `riderID`, `name`, and a private list of requested rides.
   * I wrote `requestRide(...)` and `viewRides()` to let riders request and review their trips.

5. **System Functionality**

   * In both languages, I demonstrate polymorphism in the `main` (C++) or demo block (Smalltalk) by iterating over a mixed list of rides, then exercising the driver and rider classes.

---

## C++ Usage

1. **Compile**

   ```bash
   g++ RideSharingSystem.cpp -o RideShare
   ```
2. **Run**

   ```bash
   ./RideShare
   ```

I’ll see output showing ride details, driver info, and rider history.

---

## Smalltalk Usage

1. Open Pharo or Squeak.
2. Create or open a Playground.
3. Paste `RideSharingSystem.st` into the Playground.
4. Evaluate the class definitions first, then the demo usage block.
5. Watch the Transcript for ride, driver, and rider messages.

---


