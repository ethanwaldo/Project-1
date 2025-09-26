/*
    Student: Ethan Waldo
    EMPLID: 23274836
    Project 1
    Player.cpp
*/

#include "Player.hpp"

// Constructor
Player::Player(const std::string& name, const Inventory& inventory)
    : inventory_(inventory), name_(name) {}

// Copy Constructor
Player::Player(const Player& other)
    : inventory_(other.inventory_), name_(other.name_) {}

// Move Constructor
Player::Player(Player&& other) noexcept
    : inventory_(std::move(other.inventory_)), name_(std::move(other.name_)) {}

// Copy Assignment
Player& Player::operator=(const Player& other) {
    if (this != &other) {
        inventory_ = other.inventory_;
        name_ = other.name_;
    }
    return *this;
}

// Move Assignment
Player& Player::operator=(Player&& other) noexcept {
    if (this != &other) {
        inventory_ = std::move(other.inventory_);
        name_ = std::move(other.name_);
    }
    return *this;
}

// --- Accessors ---
const std::string& Player::getName() const {
    return name_;
}

Inventory& Player::getInventoryRef() {
    return inventory_;
}

const Inventory& Player::getInventoryRef() const {
    return inventory_;
}
