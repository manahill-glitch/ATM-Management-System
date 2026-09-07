# ATM Management System

A menu-driven C++ banking simulation designed to demonstrate core programming concepts including structures, functions, arrays, authentication, transaction management, validation, and account services.

## Overview

The ATM Management System simulates common banking operations through a console-based interface. Users can securely log in to an account and perform different banking operations through an interactive menu.

## Features

- Account authentication with PIN verification
- Three-attempt PIN protection
- Automatic account locking after failed login attempts
- Balance inquiry
- Deposit money
- Withdraw money
- Daily withdrawal limit
- Money transfer between accounts
- PIN change functionality
- Mini statement generation
- Transaction history
- Account details
- Interest calculation
- Statement clearing
- Input validation

## Technical Concepts

- C++
- Structures
- Functions
- Arrays
- Loops
- Conditional statements
- References
- Modular programming
- Basic authentication logic
- Transaction management

## Project Structure

```text
ATM-Management-System/
│
├── ATM_Management_System.cpp
└── README.md
```

## How It Works

The program initializes multiple sample accounts and provides an authentication system for account access.

After successful login, users are presented with an ATM menu containing different banking operations. Each operation is implemented through a separate function to keep the program organized and modular.

## Program Output

### ATM Login
<img width="598" height="475" alt="Screenshot (473)" src="https://github.com/user-attachments/assets/0238bf79-69b1-411e-99a0-196cdd68a6a3" />

### Check Balance
<img width="559" height="387" alt="Screenshot (474)" src="https://github.com/user-attachments/assets/e8467062-a52c-4a8c-8894-abb4c1b90114" />

### Deposit 
<img width="618" height="385" alt="Screenshot (475)" src="https://github.com/user-attachments/assets/5324d0f3-d4a7-4a3f-897b-f936c796a639" />

### Withdraw
<img width="726" height="387" alt="Screenshot (476)" src="https://github.com/user-attachments/assets/b9b8df81-6c4e-44cc-a99d-8f4a29d294a1" />

### Mini Statement
<img width="702" height="444" alt="Screenshot (477)" src="https://github.com/user-attachments/assets/576be24c-2886-4806-9ec0-10e4307cc247" />

## Security & Validation

The system includes:

- PIN-based authentication
- Limited login attempts
- Account locking after repeated incorrect PIN entries
- Balance verification before withdrawals and transfers
- Daily withdrawal limits
- Basic amount validation

## Project Purpose

This project was developed as an academic programming project to apply fundamental C++ concepts to a practical banking simulation.

Author
Manahil Rehman
BS Artificial Intelligence Student
