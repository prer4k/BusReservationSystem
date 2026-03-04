# Bus Reservation System

A simple C++ terminal based Bus Reservation System built using OOP concepts.

## Build 
```bash
cmake -S . -B build
cmake --build build
```

## Run
```bash
./build/bus
```

## Project Structure

```
BusReservationSystem/
├── include/                  # Header files
│   ├── Booking.h
│   ├── Bus.h
│   ├── ReservationSystem.h
│   └── User.h
│
├── src/                      # Source files
│   ├── booking/
│   │   └── Booking.cpp
│   ├── bus/
│   │   └── Bus.cpp
│   ├── system/
│   │   └── ReservationSystem.cpp
│   ├── user/
│   │   └── User.cpp
│   └── main.cpp
│
├── CMakeLists.txt
└── README.md
```
