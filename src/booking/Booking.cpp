#include "Booking.h"
#include <iostream>

Booking::Booking(int bID, int uID, int bus, int seat) {
    bookingID = bID;
    userID = uID;
    busID = bus;
    seatNumber = seat;
}

int Booking::getBookingID() const {
    return bookingID;
}

int Booking::getUserID() const {
    return userID;
}

int Booking::getBusID() const {
    return busID;
}

int Booking::getSeatNumber() const {
    return seatNumber;
}

void Booking::displayBooking() const {
    std::cout << "Booking ID: " << bookingID << std::endl;
    std::cout << "User ID: " << userID << std::endl;
    std::cout << "Bus ID: " << busID << std::endl;
    std::cout << "Seat: " << seatNumber << std::endl;
}
