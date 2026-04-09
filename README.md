# NTU Hotel Room Reservation System

A C console application for managing hotel room assignments. Built as part of the NTU C Programming assignment (AY2022/23 Semester 1).

---

## Overview

This program simulates a simple hotel room management system with 5 rooms. Users can assign rooms to customers, remove them, search for a guest by name, and view all currently occupied rooms — all through an interactive menu-driven interface.

---

## Features

- **List occupied rooms** — displays all rooms currently in use along with the guest's name
- **Assign a room** — books a specified room for a named customer, with validation for occupied rooms and a full hotel
- **Remove a room** — checks out a guest and frees up the room, with validation for empty rooms
- **Find a customer** — searches for a guest by name (case-insensitive) and returns their room details

---

## Program Structure

The entire program is contained in a single file (`assignment.c`) with nested functions defined inside `main()`:

- `listOccupiedRooms()` — iterates through all rooms and prints occupied ones
- `prompt_user_input()` — handles and validates room ID input (1–5) recursively
- `assignRoom()` — assigns a room to a customer with full-hotel and occupied-room checks
- `removeRoom()` — removes a customer from a room with empty-room checks
- `findCustomer()` — performs a case-insensitive linear search across all customer names

---

## Setup & Running

### Prerequisites
- GCC or any C compiler supporting C99 or later (nested functions require GCC with GNU extensions)

### Compile
```bash
gcc assignment.c -o hotel
```

### Run
```bash
./hotel
```

---

## Usage

On launch, the program displays a menu:

```
NTU HOTEL ROOM RESERVATION PROGRAM:
1: listOccupiedRooms()
2: assignRoom()
3: removeRoom()
4: findCustomer()
5: quit
```

Enter the corresponding number to select an option. Enter `5` to exit the program.

---

## Notes

- The system supports exactly 5 rooms (IDs 1–5)
- Room and customer data is stored in-memory only — no persistence between runs
- Customer name search is case-insensitive

---

## Author

Choo Yi Ken — NTU AY2022/23 Semester 1
