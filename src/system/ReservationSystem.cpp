#include "ReservationSystem.h"
#include <iostream>
#include <limits>

using namespace std;

void ReservationSystem::addBus() {
    int id, seats;
    string src, dest;

    cout << "Bus ID: ";
    if(!(cin >> id)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid ID\n";
        return;
    }

    for(auto &b : buses) {
        if(b.getBusID() == id) {
            cout << "Bus ID already exists\n";
            return;
        }
    }

    cout << "Source: ";
    cin >> src;

    cout << "Destination: ";
    cin >> dest;

    cout << "Total Seats: ";
    if(!(cin >> seats) || seats <= 0) {
        cout << "Invalid seat count\n";
        return;
    }

    buses.push_back(Bus(id, src, dest, seats));
    cout << "Bus added successfully\n";
}

void ReservationSystem::viewBuses() {

    if(buses.empty()) {
        cout << "No buses available\n";
        return;
    }

    for(auto &bus : buses) {
        bus.displayBus();
        cout << endl;
    }
}

void ReservationSystem::addUser() {
    int id;
    string name;

    cout << "User ID: ";
    if(!(cin >> id)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid ID\n";
        return;
    }

    for(auto &u : users) {
        if(u.getUserID() == id) {
            cout << "User ID already exists\n";
            return;
        }
    }

    cout << "Name: ";
    cin >> name;

    users.push_back(User(id, name));

    cout << "User added successfully\n";
}

void ReservationSystem::bookSeat() {

    if(buses.empty()) {
        cout << "No buses available\n";
        return;
    }

    if(users.empty()) {
        cout << "No users registered\n";
        return;
    }

    int busID, seat, userID;

    cout << "Enter Bus ID: ";
    cin >> busID;

    Bus* foundBus = nullptr;

    for(auto &bus : buses) {
        if(bus.getBusID() == busID) {
            foundBus = &bus;
            break;
        }
    }

    if(foundBus == nullptr) {
        cout << "Bus not found\n";
        return;
    }

    foundBus->showSeats();

    cout << "Enter Seat Number: ";
    cin >> seat;

    cout << "Enter User ID: ";
    cin >> userID;

    bool userExists = false;

    for(auto &u : users) {
        if(u.getUserID() == userID) {
            userExists = true;
            break;
        }
    }

    if(!userExists) {
        cout << "User not found\n";
        return;
    }

    if(foundBus->bookSeat(seat, userID)) {

        int bookingID = bookings.size() + 1;

        bookings.push_back(
            Booking(bookingID, userID, busID, seat)
        );

        cout << "Booking Successful\n";
    }
    else {
        cout << "Seat unavailable or invalid\n";
    }
}

void ReservationSystem::cancelBooking() {

    if(buses.empty()) {
        cout << "No buses available\n";
        return;
    }

    int busID, seat;

    cout << "Bus ID: ";
    cin >> busID;

    cout << "Seat Number: ";
    cin >> seat;

    for(auto &bus : buses) {

        if(bus.getBusID() == busID) {

            bus.cancelSeat(seat);

            for(auto it = bookings.begin(); it != bookings.end(); ++it) {
                if(it->getBusID() == busID && it->getSeatNumber() == seat) {
                    bookings.erase(it);
                    break;
                }
            }

            cout << "Booking Cancelled\n";
            return;
        }
    }

    cout << "Bus not found\n";
}

void ReservationSystem::viewBookings() {

    if(bookings.empty()) {
        cout << "No bookings found\n";
        return;
    }

    for(auto &b : bookings) {
        b.displayBooking();
        cout << endl;
    }
}
