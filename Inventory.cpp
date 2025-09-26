/*
    Student: Ethan Waldo
    EMPLID: 23274836
    Project 1
    Inventory.cpp
*/
#include "Inventory.hpp"

// Constructor
Inventory::Inventory(const std::vector<std::vector<Item>>& items, Item* equipped)
    : inventory_grid_(items), equipped_(equipped), weight_(0.0f), item_count_(0) {
    // Calculate initial weight and count
    for (const auto& row : inventory_grid_) {
        for (const auto& item : row) {
            if (item.getType() != ItemType::NONE) {
                weight_ += item.getWeight();
                item_count_++;
            }
        }
    }
}

// Destructor
Inventory::~Inventory() {
    delete equipped_;
}

// Copy Constructor
Inventory::Inventory(const Inventory& other)
    : inventory_grid_(other.inventory_grid_),
      equipped_(nullptr),
      weight_(other.weight_),
      item_count_(other.item_count_) {
    if (other.equipped_ != nullptr) {
        equipped_ = new Item(*other.equipped_);
    }
}

// Move Constructor
Inventory::Inventory(Inventory&& other)
    : inventory_grid_(std::move(other.inventory_grid_)),
      equipped_(other.equipped_),
      weight_(other.weight_),
      item_count_(other.item_count_) {
    other.equipped_ = nullptr;
    other.weight_ = 0.0f;
    other.item_count_ = 0;
}

// Copy Assignment
Inventory& Inventory::operator=(const Inventory& other) {
    if (this != &other) {
        delete equipped_;
        inventory_grid_ = other.inventory_grid_;
        equipped_ = (other.equipped_ != nullptr) ? new Item(*other.equipped_) : nullptr;
        weight_ = other.weight_;
        item_count_ = other.item_count_;
    }
    return *this;
}

// Move Assignment
Inventory& Inventory::operator=(Inventory&& other) {
    if (this != &other) {
        delete equipped_;
        inventory_grid_ = std::move(other.inventory_grid_);
        equipped_ = other.equipped_;
        weight_ = other.weight_;
        item_count_ = other.item_count_;
        other.equipped_ = nullptr;
        other.weight_ = 0.0f;
        other.item_count_ = 0;
    }
    return *this;
}

// Accessors
Item* Inventory::getEquipped() const {
    return equipped_;
}

std::vector<std::vector<Item>> Inventory::getItems() const {
    return inventory_grid_;
}

float Inventory::getWeight() const {
    return weight_;
}

size_t Inventory::getCount() const {
    return item_count_;
}

Item Inventory::at(size_t row, size_t col) const {
    if (row >= inventory_grid_.size() || col >= inventory_grid_[0].size()) {
        throw std::out_of_range("Row or column index is out of bounds");
    }
    return inventory_grid_[row][col];
}

// Modifiers
void Inventory::equip(Item* itemToEquip) {
    equipped_ = itemToEquip;
}

void Inventory::discardEquipped() {
    if (equipped_ != nullptr) {
        delete equipped_;
        equipped_ = nullptr;
    }
}

bool Inventory::store(size_t row, size_t col, const Item& pickup) {
    if (row >= inventory_grid_.size() || col >= inventory_grid_[0].size()) {
        throw std::out_of_range("Row or column index is out of bounds");
    }
    
    if (inventory_grid_[row][col].getType() != ItemType::NONE) {
        return false;
    }
    
    inventory_grid_[row][col] = pickup;
    
    if (pickup.getType() != ItemType::NONE) {
        weight_ += pickup.getWeight();
        item_count_++;
    }
    
    return true;
}