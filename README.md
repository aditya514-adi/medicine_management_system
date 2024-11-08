# medicine_management_system
This C++ program implements a basic Pharmacy Management System that allows pharmacy staff to manage medicines by adding, viewing, billing, and checking expiration dates. Here’s a breakdown of its main features and how each function works:

Features
Add Medicine: Adds new medicines to the inventory by accepting details like the medicine's name, stock, price per unit, and expiry date.
View Medicines: Displays a list of all medicines with their name, stock, price, and expiry date in a formatted table.
Generate Bill: Allows the staff to create a bill by adding medicines and their quantities. It checks stock levels and updates inventory, calculating the total bill based on the quantity sold.
Check Expiry Dates: Compares the expiry date of each medicine with the current date to identify expired medicines.
Code Explanation
Medicine Class: Contains medicine details and functions to retrieve and display those details.

getName(), getStock(), getPrice(), and getExpiryDate(): Getters for retrieving individual medicine information.
setStock(int newStock): Updates stock levels after a sale.
displayMedicine(): Prints medicine details in a formatted table.
Pharmacy Class: Manages the medicine inventory and provides options for adding, viewing, billing, and expiry checking.

addMedicine(): Collects and stores new medicine details.
viewMedicines(): Lists all available medicines or notifies if no medicine is available.
generateBill(): Processes a sale transaction, updating stock and calculating costs.
checkExpiry(): Displays expired medicines by comparing the current date with the expiry date (using simple string comparison).
Main Function: Provides a menu-driven interface to choose operations in the pharmacy system.

Example Usage
Run the program and choose an option from the menu.
Follow prompts to enter details for adding medicines, viewing inventory, generating a bill, or checking expiry dates.
The loop continues until the user exits by selecting the “Exit” option.
Sample Output
markdown
Copy code
Pharmacy Management System
1. Add Medicine
2. View Medicines
3. Generate Bill
4. Check Expiry Dates
5. Exit
Enter your choice:
This code is a simple console application for pharmacy management, and it can be enhanced by adding features like data persistence (saving data to a file or database) and date validation for accurate expiry checking.











ChatGPT ca
