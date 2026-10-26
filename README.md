# 🧳 ROAM - Smart Trip Planner

[![Language](https://img.shields.io/badge/Language-C%2B%2B17-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B17)
[![Build Status](https://img.shields.io/badge/Build-Passing-brightgreen.svg)](https://github.com/YOUR_USERNAME/ROAM-TripPlanner)
[![Tests](https://img.shields.io/badge/Tests-13%2F13%20Passed-success.svg)](https://github.com/YOUR_USERNAME/ROAM-TripPlanner)
[![License](https://img.shields.io/badge/License-MIT-orange.svg)](LICENSE)
[![Platform](https://img.shields.io/badge/Platform-Linux%2FUnix-lightgrey.svg)](https://www.linux.org/)

## 📋 Overview

**ROAM** is a comprehensive **Smart Trip Planner** application developed in C++ to demonstrate professional Object-Oriented Programming (OOP) principles. This project showcases practical implementation of encapsulation, inheritance, polymorphism, operator overloading, and memory management through a feature-rich trip planning system.

### 🎯 Purpose

This project serves as an educational resource and portfolio piece demonstrating:
- ✅ Deep understanding of OOP concepts
- ✅ Professional C++ development practices
- ✅ Clean code architecture and design patterns
- ✅ Comprehensive testing and validation
- ✅ Real-world application development

---

## ✨ Key Features

### 1. 🏢 Trip Management
- Create and manage detailed trip information
- Store traveler details (name, age)
- Set trip dates and budgets
- Track trip duration and status

### 2. 🌍 Multiple Destination Types
- **General Destinations** - Basic location information
- **Beach Destinations** - Water sports availability tracking
- **Mountain Destinations** - Altitude tracking with cost modifiers

### 3. 💰 Budget Tracking
- Set and monitor trip budgets
- Record expenses with validation
- Prevent overspending with data protection
- Calculate remaining budget automatically

### 4. 🔄 Sorting & Organization
- Sort destinations by cost (ascending/descending)
- Sort destinations alphabetically by name
- Dynamic filtering and searching

### 5. 📊 Cost Analysis
- Calculate total trip costs per day
- Project costs for entire trip duration
- Compare with available budget
- Generate cost estimates

### 6. 🔗 Advanced Operations
- Deep copy trips for duplication
- Merge multiple trips together
- Manage complex trip scenarios

### 7. 🎓 Learning Tools
- Constructor/Destructor tracing
- Object lifecycle visualization
- Memory management demonstration
- Inheritance hierarchy display

---

---

## 🔑 OOP Concepts Demonstrated

### 1️⃣ Encapsulation
```cpp
// Data protection with controlled access
private:
    double budget, spent;
    
public:
    bool spend(double amount);  // Validated access
    double getRemaining() const;

Private member variables
Public getter/setter methods
Input validation
Data consistency protection
2️⃣ Inheritance
cpp


class Destination { /* base */ };
class BeachDestination : public Destination { /* adds water sports */ };
class MountainDestination : public Destination { /* adds altitude */ };
Single base class
Multi-level derivation
Code reuse
Specialized behavior
3️⃣ Polymorphism
cpp


virtual void display() const;          // Base class
void display() const override;         // Derived classes
Virtual functions
Runtime method resolution
Unified interface
Type-specific behavior
4️⃣ Operator Overloading



Operator	Purpose	Usage
<	Cost comparison	Sorting
==	Equality check	Searching
=	Deep copy	Assignment
+=	Add destination	trip += dest
+	Merge trips	merged = trip1 + trip2
[]	Array access	trip[0]
<<	Stream output	cout << object
5️⃣ Memory Management
Dynamic array allocation with new[]
Automatic array resizing
Deep copy in copy constructor
Proper deallocation in destructor
No memory leaks (RAII pattern)
6️⃣ Composition
Trip contains Traveler object
Trip contains Date object
Trip contains array of Destination objects
Has-a relationships (not is-a)
📁 Project Structure


ROAM-TripPlanner/
│
├── src/                          # Source code
│   ├── Trace.h                  # Debug utility for tracing
│   ├── Date.h, Date.cpp         # Date class (~120 LOC)
│   ├── Traveler.h, Traveler.cpp # Traveler class (~80 LOC)
│   ├── Destination.h, Destination.cpp  # Hierarchy (~200 LOC)
│   ├── Trip.h, Trip.cpp         # Main class (~180 LOC)
│   ├── main.cpp                 # Entry point (~220 LOC)
│   └── roam                     # Compiled executable
│
├── docs/                         # Documentation
│   ├── README.md                # Documentation
│   └── screenshots/             # Test execution screenshots
│       ├── 00_initial_setup.png
│       ├── 01_view_trip_empty.png
│       └── ... (all 13 screenshots)
│
├── .gitignore                   # Git ignore rules
├── README.md                    # This file
└── ROAM_Mid_Semester_Report.pdf # Complete project report
📊 Code Statistics



Metric	Value
Total Files	10
Lines of Code	~810
Classes	6
Methods	45+
Operator Overloads	8
Test Cases	13
Test Pass Rate	100% ✅
