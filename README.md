# 🌿Plant Shop Management System
A simple console-based project that simulates a basic **plant shop** experience. Users can log in, browse plants, make payments, access plant care guides, and view purchase history.

---

## 🌟 Features

- 🔐 User Sign In / Log In  
- 🛒 Browse Indoor & Outdoor Plants  
- 💳 Payment Options (Cash / Online)  
- 📘 Plant Care Instructions  
- 📂 Customer Purchase History  

---

## 🧩 Key Components

### 👤 User Authentication  
**Class:** `Enter`  
Prompts users for name, email, and password (no actual validation).

### 🎉 Welcome Screen  
**Class:** `Welcome`  
Provides a main menu with options to:
- A: View Plant Catalog  
- B: View Customer Record  
- C: Access Plant Care Guide  

### 🪴 Plant Catalog  
**Classes:** `Plant_Catalog`, `Outdoor_plants`, `Indoor_plants`, etc.  
- **Outdoor Plants:** 🌸 Flowering, 🌿 Medicinal, 🍊 Fruiting  
- Shows plant details, price, and quantity

### 💰 Payment System  
**Class:** `payment` (inherits from all plant types)  
- Supports **cash** or **online** methods  
- Calculates total and logs to `record.txt`  
- Online: Accepts ATM number and PIN (no validation)

### 📘 Plant Care Guide  
**Class:** `Plant_Guide`  
Search plant names for care instructions

### 📂 Customer Record  
Displays purchase records by reading from `record.txt`

---

## 🔄 Program Flow

1. **User Sign-In / Log-In**  
2. **Choose Menu Option:**  
   - View Catalog  
   - View Past Records  
   - Plant Care Guide  
3. **Select Plant & Quantity**  
4. **Choose Payment Method**  
5. **View/Save Purchase History** or **Get Plant Care Tips**

---

## 🛠 Tech Stack

- 💻 Language: C++  
- 🗃 File I/O: `fstream` used for transaction records  
- 🧱 Concepts: OOP (Classes, Inheritance), Console Interaction  

---

## 📁 File Summary

- `project.cpp` – Full program logic  
- `record.txt` – Stores transaction history  
- No external libraries used

---


