/*
    Student: Ethan Waldo
    EMPLID: 23274836
    Project 1
    Inventory.cpp
*/
#include "Inventory.hpp"
#include <numeric>

// Constructor
Inventory::Inventory(const std::vector<std::vector<Item>>& items, Item* equipped)
    : inventory_grid_(items), equipped_(equipped), weight_(0.0f), item_count_(0) {
    calculateInitialState();
}

// Destructor
Inventory::~Inventory() {
    clear();
}

// Copy Constructor
Inventory::Inventory(const Inventory& other)
    : inventory_grid_(other.inventory_grid_),
      equipped_(other.equipped_ ? new Item(*other.equipped_) : nullptr),
      weight_(other.weight_),
      item_count_(other.item_count_) {}

// Move Constructor
Inventory::Inventory(Inventory&& other) noexcept
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
        clear();
        inventory_grid_ = other.inventory_grid_;
        equipped_ = other.equipped_ ? new Item(*other.equipped_) : nullptr;
        weight_ = other.weight_;
        item_count_ = other.item_count_;
    }
    return *this;
}

// Move Assignment
Inventory& Inventory::operator=(Inventory&& other) noexcept {
    if (this != &other) {
        clear();
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

// --- Accessors ---
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
        throw std::out_of_range("Inventory::at() - Index out of range");
    }
    return inventory_grid_[row][col];
}

// --- Modifiers ---
void Inventory::equip(Item* itemToEquip) {
    // Does not deallocate the original
    equipped_ = itemToEquip;
}

void Inventory::discardEquipped() {
    delete equipped_;
    equipped_ = nullptr;
}

bool Inventory::store(size_t row, size_t col, const Item& pickup) {
    if (row >= inventory_grid_.size() || col >= inventory_grid_[0].size()) {
        throw std::out_of_range("Row or column index is out of bounds");
    }
    Item& current_item = inventory_grid_[row][col];
    if (current_item.getType() != ItemType::NONE) {
        return false;
    }
    current_item = pickup;
    if (pickup.getType() != ItemType::NONE) {
        weight_ += pickup.getWeight();
        item_count_++;
    }
    return true;
}

// --- Private Helper Functions ---
void Inventory::calculateInitialState() {
    weight_ = 0.0f;
    item_count_ = 0;
    for (const auto& row : inventory_grid_) {
        for (const auto& item : row) {
            if (item.getType() != ItemType::NONE) {
                weight_ += item.getWeight();
                item_count_++;
            }
        }
    }
}

void Inventory::clear() {
    delete equipped_;
    equipped_ = nullptr;
}