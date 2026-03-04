#include <iostream>
#include <limits>
#include "ReservationSystem.h"

using namespace std;

int main() {

    ReservationSystem system;
    int choice;

    while(true) {

        cout << "\n--- Bus Reservation System ---\n";
        cout << "1 Add Bus\n";
        cout << "2 View Buses\n";
        cout << "3 Add User\n";
        cout << "4 Book Seat\n";
        cout << "5 Cancel Booking\n";
        cout << "6 View Bookings\n";
        cout << "7 Exit\n";
        cout << "Enter choice: ";

        if(!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";

            cin.clear();  
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch(choice) {

            case 1:
                system.addBus();
                break;

            case 2:
                system.viewBuses();
                break;

            case 3:
                system.addUser();
                break;

            case 4:
                system.bookSeat();
                break;

            case 5:
                system.cancelBooking();
                break;

            case 6:
                system.viewBookings();
                break;

            case 7:
                cout << "Exiting program...\n";
                return 0;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}
