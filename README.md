# ✈️ Airline Reservation and Management System

A console-based C++ application simulating the core operations of an airline. Built with Modern C++ and Object-Oriented Programming (OOP) principles, this system supports multiple user roles—**Administrators**, **Booking Agents**, and **Passengers**—each with secure, role-based access to relevant functionalities.

## 🚀 Features

### 🔐 User Roles & Authentication
- Role-based login system (Administrator, Booking Agent, Passenger)
- User account management (create, update, delete)
- Secure password handling

### 🛫 Flight & Aircraft Management
- Add, update, and remove flights with schedule and aircraft details
- Aircraft tracking with specifications, maintenance status, and availability
- Crew assignment with flight hour compliance checks

### 🎫 Booking & Reservations
- Search flights by date, price, destination
- Interactive seat selection using seat maps
- Book, modify, and cancel reservations
- Simulated payment and refund processing

### 👤 Passenger Experience
- Personalized profiles with travel history
- Loyalty points system for frequent flyers

### ✅ Check-In & Boarding
- Online and airport-based check-in
- Generate boarding passes and manage boarding workflow

### 🛠 Maintenance Tracking
- Schedule and log aircraft maintenance
- Track part replacements and service records

### 📊 Reporting & Analytics
- Flight performance, booking stats, and user activity reports
- Maintenance summaries and operational insights

## 💾 Data Persistence
All data is stored in **JSON** or **CSV** file-based databases.

## 🧠 Technical Highlights
- **OOP Design**: Classes like `User`, `Flight`, `Aircraft`, `Reservation`, `Maintenance`
- **Modern C++**: Smart pointers (`std::unique_ptr`, `std::shared_ptr`), STL containers, lambda expressions
- **Filesystem**: `<filesystem>` for file handling (C++17)
- **Robust Input Validation** and **Exception Handling**
