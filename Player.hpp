#pragma once

#include "Inventory.hpp"
#include <string>

class Player {
public:
    // Constructor
    Player(const std::string& name, const Inventory& inventory = Inventory());

    // Big Five
    ~Player();
    Player(const Player& other);
    Player(Player&& other);
    Player& operator=(const Player& other);
    Player& operator=(Player&& other);

    // Accessors
    std::string getName() const;
    Inventory& getInventoryRef();

private:
    Inventory inventory_;
    std::string name_;
};
