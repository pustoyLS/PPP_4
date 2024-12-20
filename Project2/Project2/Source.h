#ifndef SOURCE_H
#define SOURCE_H

#include <string>
#include <vector>


enum class Direction {
    MUCHOSRANSK,  
    SYBERIA,      
    PUTINKA       
};

class Passenger {
private:
    std::string name;          
    std::string passportNumber; 

public:
    Passenger(const std::string& name, const std::string& passportNumber);
    std::string getInfo() const; 
    std::string getPassportNumber() const { return passportNumber; }
    std::string getName() const { return name; }
    
};

class Fare {
private:
    Direction direction; 
    double price;        

public:
    Fare(Direction direction, double price);
    Direction getDirection() const; 
    double getPrice() const;        
    std::string getInfo() const;    
};


class Ticket {
private:
    Passenger passenger; 
    Fare fare;           
    Direction direction; 

public:
    Ticket(const Passenger& passenger, const Fare& fare, Direction direction);
    std::string getInfo() const; 
    Direction getDirection() const; 
    double getPrice() const;        
    Passenger Ticket::getPassenger() const;
};


class TicketOffice {
private:
    std::vector<Fare> fares;   
    std::vector<Ticket> tickets; 

public:
    void addFare(const Fare& fare); 
    void sellTicket(const Passenger& passenger, Direction direction); 
    double calculateTotal() const; 
    std::vector<std::string> listPassengers(Direction direction) const;
    void TicketOffice::loadFromFile(const std::string& filename);
    void TicketOffice::saveToFile(const std::string& filename) const;
};


bool isValidName(const std::string& name); 
bool isValidPassport(const std::string& passportNumber); 

#endif // SOURCE_H
