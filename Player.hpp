#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include "Inventory.hpp"

class Player {
private:
    Inventory inventory_;
    std::string name_;

public:
    // Constructor
    Player(const std::string& name = "", const Inventory& inventory = Inventory());

    // Big Five
    Player(const Player& rhs);
    Player(Player&& rhs) noexcept;
    Player& operator=(const Player& rhs);
    Player& operator=(Player&& rhs) noexcept;
    ~Player() = default;

    // Accessors
    std::string getName() const;
    Inventory& getInventoryRef();
};

#endif
