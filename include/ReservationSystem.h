#ifndef RESERVATIONSYSTEM_H
#define RESERVATIONSYSTEM_H

#include <vector>
#include "Bus.h"
#include "User.h"
#include "Booking.h"

class ReservationSystem {
private:
    std::vector<Bus> buses;
    std::vector<User> users;
    std::vector<Booking> bookings;

public:
    ReservationSystem() = default;

    void addBus();
    void viewBuses();

    void addUser();

    void bookSeat();
    void cancelBooking();
    void viewBookings();
};

#endif
