#ifndef BUS_H
#define BUS_H

#include <string>
#include <vector>

class Bus {
private:
    int busID;
    std::string source;
    std::string destination;
    int totalSeats;
    std::vector<int> seats;

public:
    Bus(int id, std::string src, std::string dest, int seatsCount);

    int getBusID() const;
    int getTotalSeats() const;

    void displayBus() const;

    void showSeats() const;
    bool bookSeat(int seatNumber, int userID);
    bool cancelSeat(int seatNumber);
};

#endif
