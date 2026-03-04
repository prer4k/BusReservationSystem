#ifndef BOOKING_H
#define BOOKING_H

class Booking {
private:
    int bookingID;
    int userID;
    int busID;
    int seatNumber;

public:
    Booking(int bID, int uID, int bus, int seat);

    int getBookingID() const;
    int getUserID() const;
    int getBusID() const;
    int getSeatNumber() const;

    void displayBooking() const;
};

#endif
