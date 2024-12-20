#include "Source.h"
#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <cctype>
#include <fstream>
#include <sstream>


using namespace std;


Passenger::Passenger(const string& name, const string& passportNumber)
    : name(name), passportNumber(passportNumber) {
}

string Passenger::getInfo() const {
    return "Passenger: " + name + ", Passport: " + passportNumber;
}
Passenger Ticket::getPassenger() const {
    return passenger;
}
Fare::Fare(Direction direction, double price)
    : direction(direction), price(price) {
}

Direction Fare::getDirection() const {
    return direction;
}

double Fare::getPrice() const {
    return price;
}

string Fare::getInfo() const {
    string dir;
    switch (direction) {
    case Direction::MUCHOSRANSK: dir = "Muchosransk"; break;
    case Direction::SYBERIA: dir = "Syberia"; break;
    case Direction::PUTINKA: dir = "Putinka"; break;
    }
    return "Fare to " + dir + ": $" + to_string(price);
}

Ticket::Ticket(const Passenger& passenger, const Fare& fare, Direction direction)
    : passenger(passenger), fare(fare), direction(direction) {
}

string Ticket::getInfo() const {
    return passenger.getInfo() + ", " + fare.getInfo();
}

Direction Ticket::getDirection() const {
    return direction;
}

double Ticket::getPrice() const {
    return fare.getPrice();
}

void TicketOffice::addFare(const Fare& fare) {
    fares.push_back(fare);
}

void TicketOffice::sellTicket(const Passenger& passenger, Direction direction) {
    for (const auto& fare : fares) {
        if (fare.getDirection() == direction) {
            tickets.emplace_back(passenger, fare, direction);
            cout << "Ticket sold: " << tickets.back().getInfo() << endl;
            return;
        }
    }
    cout << "No fare available for this direction." << endl;
}

double TicketOffice::calculateTotal() const {
    double total = 0;
    for (const auto& ticket : tickets) {
        total += ticket.getPrice();
    }
    return total;
}

std::vector<std::string> TicketOffice::listPassengers(Direction direction) const {
    std::vector<std::string> passengerList;
    string directionStr;
    switch (direction) {
    case Direction::MUCHOSRANSK:
        directionStr = "Muchosransk";
        break;
    case Direction::SYBERIA:
        directionStr = "Syberia";
        break;
    case Direction::PUTINKA:
        directionStr = "Putinka";
        break;
    }
    passengerList.push_back("Passengers for direction: " + directionStr);
    for (const auto& ticket : tickets) {
        if (ticket.getDirection() == direction) {
            passengerList.push_back(ticket.getInfo());
        }
    }
    return passengerList;
}

bool isValidName(const string& name) {
    if (name.empty() || name.length() > 50) return false; // Длина не должна превышать 50
    for (char c : name) {
        if (!isalpha(c) && c != ' ') return false; // Только буквы и пробелы
    }
    return true;
}

bool isValidPassport(const string& passportNumber) {
    if (passportNumber.empty() || passportNumber.length() > 10) return false; // Длина не должна превышать 10
    for (char c : passportNumber) {
        if (!isdigit(c)) return false; // Только цифры
    }
    return true;
}
void TicketOffice::saveToFile(const std::string& filename) const {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cerr << "Error: Unable to open file for saving." << endl;
        return;
    }

    outFile << "Tickets\n";
    for (const auto& ticket : tickets) {
        outFile << ticket.getPassenger().getName() << " "
            << ticket.getPassenger().getPassportNumber() << " "
            << static_cast<int>(ticket.getDirection()) << " "
            << ticket.getPrice() << "\n";
    }

    outFile.close();
    cout << "Data saved successfully to " << filename << endl;
}
void TicketOffice::loadFromFile(const std::string& filename) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << "Error: Unable to open file for loading." << endl;
        return;
    }

    fares.clear();
    tickets.clear();

    string line;
    getline(inFile, line);
    if (line == "Fares") {
        while (getline(inFile, line) && !line.empty() && line != "Tickets") {
            int dir;
            double price;
            istringstream iss(line);
            iss >> dir >> price;
            fares.emplace_back(static_cast<Direction>(dir), price);
        }
    }

    if (line == "Tickets") {
        while (getline(inFile, line) && !line.empty()) {
            string name, passport;
            int dir;
            double price;
            istringstream iss(line);
            iss >> name >> passport >> dir >> price;
            Passenger passenger(name, passport);
            Fare fare(static_cast<Direction>(dir), price);
            tickets.emplace_back(passenger, fare, static_cast<Direction>(dir));
        }
    }

    inFile.close();
    cout << "Data loaded successfully from " << filename << endl;
}