#include "Player.hpp"

Player::Player(const std::string&, const Inventory&) {}
Player::~Player() {}
Player::Player(const Player&) {}
Player::Player(Player&&) {}
Player& Player::operator=(const Player&) { return *this; }
Player& Player::operator=(Player&&) { return *this; }

std::string Player::getName() const { return ""; }
Inventory& Player::getInventoryRef() { return inventory_; }
