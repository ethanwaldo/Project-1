/*
    Student: Ethan Waldo
    EMPLID: 23274836
    Project 1
    Player.hpp
*/

#pragma once

#include "Inventory.hpp"

#include <string>
#include <utility>

class Player {
public:
    // Constructor
    Player(const std::string& name, const Inventory& inventory = Inventory());

    // Big Five
    ~Player() = default;
    Player(const Player& other);
    Player(Player&& other) noexcept;
    Player& operator=(const Player& other);
    Player& operator=(Player&& other) noexcept;

    // Accessors
    const std::string& getName() const;
    Inventory& getInventoryRef();

private:
    Inventory inventory_;
    std::string name_;
};
