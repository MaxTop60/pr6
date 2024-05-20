#include <iostream>
#include <list>
#include <string>

// Структура для хранения информации о заявке
struct TicketRequest {
    std::string destination;
    int flightNumber;
    std::string passengerName;
    std::string departureDate;

    // Конструктор для удобного создания объектов
    TicketRequest(const std::string& dest, int number, const std::string& name, const std::string& date)
        : destination(dest), flightNumber(number), passengerName(name), departureDate(date) {}
};

// Функция для добавления заявки в список
void addTicketRequest(std::list<TicketRequest>& requests) {
    std::string dest, name, date;
    int flightNumber;

    std::cout << "Enter destination: ";
    std::cin >> dest;

    std::cout << "Enter flight number: ";
    std::cin >> flightNumber;

    std::cout << "Enter passenger name: ";
    std::cin >> name;

    std::cout << "Enter departure date: ";
    std::cin >> date;

    requests.push_back(TicketRequest(dest, flightNumber, name, date));
}

// Функция для удаления заявки из списка
void removeTicketRequest(std::list<TicketRequest>& requests) {
    if (!requests.empty()) {
        std::string name;
        std::cout << "Enter passenger name to remove: ";
        std::cin >> name;

        // Ищем заявку по имени пассажира и удаляем её, если найдена
        auto it = std::find_if(requests.begin(), requests.end(), [&](const TicketRequest& request) {
            return request.passengerName == name;
            });

        if (it != requests.end()) {
            requests.erase(it);
            std::cout << "Ticket request for passenger " << name << " has been removed.\n";
        }
        else {
            std::cout << "Ticket request for passenger " << name << " not found.\n";
        }
    }
    else {
        std::cout << "No ticket requests to remove.\n";
    }
}

// Функция для вывода заявок по заданному номеру рейса и дате вылета
void printTicketRequests(std::list<TicketRequest>& requests) {
    if (!requests.empty()) {
        int flightNumber;
        std::string date;

        std::cout << "Enter flight number: ";
        std::cin >> flightNumber;

        std::cout << "Enter departure date: ";
        std::cin >> date;

        // Выводим заявки с заданным номером рейса и датой вылета
        std::cout << "Ticket requests for flight " << flightNumber << " on " << date << ":\n";
        for (const auto& request : requests) {
            if (request.flightNumber == flightNumber && request.departureDate == date) {
                std::cout << "Destination: " << request.destination << ", Passenger: " << request.passengerName << std::endl;
            }
        }
    }
    else {
        std::cout << "No ticket requests available.\n";
    }
}

// Функция для вывода всех заявок
void printAllTicketRequests(std::list<TicketRequest>& requests) {
    if (!requests.empty()) {
        std::cout << "All ticket requests:\n";
        for (const auto& request : requests) {
            std::cout << "Destination: " << request.destination << ", Flight: " << request.flightNumber
                << ", Passenger: " << request.passengerName << ", Departure Date: " << request.departureDate << std::endl;
        }
    }
    else {
        std::cout << "No ticket requests available.\n";
    }
}

int main() {
    std::list<TicketRequest> ticketRequests;

    int choice;
    do {
        // Выводим меню
        std::cout << "\nMenu:\n";
        std::cout << "1. Add ticket request\n";
        std::cout << "2. Remove ticket request\n";
        std::cout << "3. Print ticket requests by flight number and departure date\n";
        std::cout << "4. Print all ticket requests\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Обработка выбора пользователя
        switch (choice) {
        case 1:
            addTicketRequest(ticketRequests);
            break;
        case 2:
            removeTicketRequest(ticketRequests);
            break;
        case 3:
            printTicketRequests(ticketRequests);
            break;
        case 4:
            printAllTicketRequests(ticketRequests);
            break;
        case 5:
            std::cout << "Exiting program.\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}