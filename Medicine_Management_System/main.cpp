#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

class Medicine {
private:
    std::string name;
    int stock;
    double price;
    std::string expiryDate;

public:
    Medicine(std::string n, int s, double p, std::string e)
        : name(n), stock(s), price(p), expiryDate(e) {}

    std::string getName() const { return name; }
    int getStock() const { return stock; }
    double getPrice() const { return price; }
    std::string getExpiryDate() const { return expiryDate; }

    void setStock(int newStock) { stock = newStock; }

    void displayMedicine() const {
        std::cout << std::setw(15) << name << std::setw(10) << stock
                  << std::setw(10) << price << std::setw(15) << expiryDate << "\n";
    }
};

class Pharmacy {
private:
    std::vector<Medicine> medicines;

public:
    void addMedicine() {
        std::string name, expiryDate;
        int stock;
        double price;

        std::cout << "Enter Medicine Name: ";
        std::cin >> name;
        std::cout << "Enter Stock Quantity: ";
        std::cin >> stock;
        std::cout << "Enter Price per Unit: ";
        std::cin >> price;
        std::cout << "Enter Expiry Date (dd-mm-yyyy): ";
        std::cin >> expiryDate;

        Medicine newMedicine(name, stock, price, expiryDate);
        medicines.push_back(newMedicine);
        std::cout << "Medicine added successfully!\n";
    }

    void viewMedicines() const {
        if (medicines.empty()) {
            std::cout << "No medicines available.\n";
            return;
        }
        std::cout << "\nAvailable Medicines:\n";
        std::cout << std::setw(15) << "Name" << std::setw(10) << "Stock"
                  << std::setw(10) << "Price" << std::setw(15) << "Expiry Date\n";
        std::cout << "---------------------------------------------------------\n";
        for (const auto& medicine : medicines) {
            medicine.displayMedicine();
        }
    }

    void generateBill() {
        std::string medName;
        int quantity;
        double totalBill = 0;

        while (true) {
            std::cout << "Enter Medicine Name (or type 'done' to finish): ";
            std::cin >> medName;
            if (medName == "done") break;

            bool found = false;
            for (auto& medicine : medicines) {
                if (medicine.getName() == medName) {
                    found = true;
                    std::cout << "Enter Quantity: ";
                    std::cin >> quantity;
                    if (quantity <= medicine.getStock()) {
                        double cost = quantity * medicine.getPrice();
                        totalBill += cost;
                        medicine.setStock(medicine.getStock() - quantity);
                        std::cout << "Added to bill: " << medName << " x" << quantity
                                  << " = $" << cost << "\n";
                    } else {
                        std::cout << "Insufficient stock for " << medName << ".\n";
                    }
                    break;
                }
            }
            if (!found) {
                std::cout << "Medicine not found.\n";
            }
        }
        std::cout << "Total Bill: $" << totalBill << "\n";
    }

    void checkExpiry() const {
        std::string date;
        std::cout << "Enter current date (dd-mm-yyyy): ";
        std::cin >> date;

        std::cout << "Medicines past expiry:\n";
        bool expired = false;
        for (const auto& medicine : medicines) {
            if (medicine.getExpiryDate() < date) {  // Simple string comparison for date
                expired = true;
                medicine.displayMedicine();
            }
        }
        if (!expired) {
            std::cout << "No expired medicines.\n";
        }
    }
};

int main() {
    Pharmacy pharmacy;
    int choice;

    do {
        std::cout << "\nPharmacy Management System\n";
        std::cout << "1. Add Medicine\n";
        std::cout << "2. View Medicines\n";
        std::cout << "3. Generate Bill\n";
        std::cout << "4. Check Expiry Dates\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                pharmacy.addMedicine();
                break;
            case 2:
                pharmacy.viewMedicines();
                break;
            case 3:
                pharmacy.generateBill();
                break;
            case 4:
                pharmacy.checkExpiry();
                break;
            case 5:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
