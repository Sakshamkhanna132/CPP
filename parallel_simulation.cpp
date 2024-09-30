#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>
#include <random>
#include <algorithm>
#include "Human.h"
#include "SuperHuman.h"

// Mutex for thread-safe console output
std::mutex cout_mutex;

// Function to simulate human activities
void simulateHuman(Human& human, int iterations) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);

    for (int i = 0; i < iterations; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(dis(gen)));
        int action = dis(gen) % 3;
        
        std::lock_guard<std::mutex> lock(cout_mutex);
        switch (action) {
            case 0:
                std::cout << human.getName() << " is eating." << std::endl;
                break;
            case 1:
                std::cout << human.getName() << " is sleeping." << std::endl;
                break;
            case 2:
                std::cout << human.getName() << " is working." << std::endl;
                break;
        }
    }
}

// Function to simulate superhuman activities
void simulateSuperhuman(SuperHuman& superhuman, int iterations) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);

    for (int i = 0; i < iterations; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(dis(gen)));
        int action = dis(gen) % 3;
        
        std::lock_guard<std::mutex> lock(cout_mutex);
        switch (action) {
            case 0:
                std::cout << superhuman.getName() << " is using " << superhuman.getSpecialAbility() << "." << std::endl;
                break;
            case 1:
                std::cout << superhuman.getName() << " is saving " << superhuman.getPlanet() << "." << std::endl;
                break;
            case 2:
                std::cout << superhuman.getName() << " is training to increase power level." << std::endl;
                superhuman.setSuperPowerLevel(superhuman.getSuperPowerLevel() + 1);
                break;
        }
    }
}

int main() {
    // Create a vector of Humans
    std::vector<Human> humans = {
        Human("Alice", 25, 1.65),
        Human("Bob", 30, 1.80),
        Human("Charlie", 22, 1.70)
    };

    // Create a vector of SuperHumans
    std::vector<SuperHuman> superhumans = {
        SuperHuman("Wonder Woman", 5000, 1.75, "Earth", "Urban", 95, "Super Strength"),
        SuperHuman("Superman", 35, 1.90, "Krypton", "Various", 100, "Flight"),
        SuperHuman("Black Widow", 35, 1.70, "Earth", "Urban", 80, "Espionage")
    };

    // Create threads for simulating humans
    std::vector<std::thread> human_threads;
    for (auto& human : humans) {
        human_threads.emplace_back(simulateHuman, std::ref(human), 10);
    }

    // Create threads for simulating superhumans
    std::vector<std::thread> superhuman_threads;
    for (auto& superhuman : superhumans) {
        superhuman_threads.emplace_back(simulateSuperhuman, std::ref(superhuman), 10);
    }

    // Join all threads
    for (auto& thread : human_threads) {
        thread.join();
    }
    for (auto& thread : superhuman_threads) {
        thread.join();
    }

    // Display final information
    std::cout << "\nFinal Information:\n";
    for (const auto& human : humans) {
        human.displayInfo();
    }
    for (const auto& superhuman : superhumans) {
        superhuman.displayInfo();
    }

    // Find the superhuman with the highest power level
    auto max_power_superhuman = std::max_element(superhumans.begin(), superhumans.end(),
        [](const SuperHuman& a, const SuperHuman& b) {
            return a.getSuperPowerLevel() < b.getSuperPowerLevel();
        });

    std::cout << "\nSuperhuman with the highest power level: " << max_power_superhuman->getName()
              << " (Power Level: " << max_power_superhuman->getSuperPowerLevel() << ")" << std::endl;

    return 0;
}