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

## How It Works

The program initializes multiple sample accounts and provides an authentication system for account access.

After successful login, users are presented with an ATM menu containing different banking operations. Each operation is implemented through a separate function to keep the program organized and modular.

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
