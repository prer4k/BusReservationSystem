#include "Bus.h"
#include <iostream>

Bus::Bus(int id, std::string src, std::string dest, int seatsCount) {
    busID = id;
    source = src;
    destination = dest;
    totalSeats = seatsCount;

    seats.resize(totalSeats, 0);
}

int Bus::getBusID() const {
    return busID;
}

int Bus::getTotalSeats() const {
    return totalSeats;
}

void Bus::displayBus() const {
    std::cout << "Bus ID: " << busID << std::endl;
    std::cout << "Route: " << source << " -> " << destination << std::endl;
    std::cout << "Total Seats: " << totalSeats << std::endl;
}

void Bus::showSeats() const {

    std::cout << "\nSeat Layout (X = booked)\n\n";

    for(int i = 0; i < totalSeats; i++) {

        if(seats[i] == 0)
            std::cout << "[" << i+1 << "]\t";
        else
            std::cout << "[X]\t";

        if((i + 1) % 4 == 0)
            std::cout << std::endl;
    }

    std::cout << std::endl;
}
bool Bus::bookSeat(int seatNumber, int userID) {

    if(seatNumber < 1 || seatNumber > totalSeats) {
        std::cout << "Invalid seat number\n";
        return false;
    }

    if(userID <= 0) {
        std::cout << "Invalid user ID\n";
        return false;
    }

    if(seats[seatNumber - 1] != 0) {
        std::cout << "Seat already booked\n";
        return false;
    }

    seats[seatNumber - 1] = userID;
    return true;
}

bool Bus::cancelSeat(int seatNumber) {

    if(seatNumber < 1 || seatNumber > totalSeats) {
        std::cout << "Invalid seat number\n";
        return false;
    }

    if(seats[seatNumber - 1] == 0) {
        std::cout << "Seat already empty\n";
        return false;
    }

    seats[seatNumber - 1] = 0;
    return true;
}
