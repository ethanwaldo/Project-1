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
    if (equipped) {
        equipped_ = new Item(*equipped);
    }
    calculateInitialState();
}

// Copy constructor
Inventory::Inventory(const Inventory& rhs)
    : inventory_grid_(rhs.inventory_grid_),
      equipped_(rhs.equipped_ ? new Item(*rhs.equipped_) : nullptr),
      weight_(rhs.weight_),
      item_count_(rhs.item_count_) {}

// Move constructor
Inventory::Inventory(Inventory&& rhs) noexcept
    : inventory_grid_(std::move(rhs.inventory_grid_)),
      equipped_(rhs.equipped_),
      weight_(rhs.weight_),
      item_count_(rhs.item_count_) {
    rhs.equipped_ = nullptr;
    rhs.weight_ = 0.0f;
    rhs.item_count_ = 0;
}

// Copy assignment
Inventory& Inventory::operator=(const Inventory& rhs) {
    if (this != &rhs) {
        clear();
        inventory_grid_ = rhs.inventory_grid_;
        equipped_ = rhs.equipped_ ? new Item(*rhs.equipped_) : nullptr;
        weight_ = rhs.weight_;
        item_count_ = rhs.item_count_;
    }
    return *this;
}

// Move assignment
Inventory& Inventory::operator=(Inventory&& rhs) noexcept {
    if (this != &rhs) {
        clear();
        inventory_grid_ = std::move(rhs.inventory_grid_);
        equipped_ = rhs.equipped_;
        weight_ = rhs.weight_;
        item_count_ = rhs.item_count_;
        rhs.equipped_ = nullptr;
        rhs.weight_ = 0.0f;
        rhs.item_count_ = 0;
    }
    return *this;
}

// Destructor
Inventory::~Inventory() {
    clear();
}

// Accessors
Item* Inventory::getEquipped() const {
    return equipped_;
}

void Inventory::equip(Item* itemToEquip) {
    // Does not deallocate the original
    equipped_ = itemToEquip;
}

void Inventory::discardEquipped() {
    delete equipped_;
    equipped_ = nullptr;
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

bool Inventory::store(size_t row, size_t col, const Item& pickup) {
    if (row >= inventory_grid_.size() || col >= inventory_grid_[0].size()) {
        throw std::out_of_range("Inventory::store() - Index out of range");
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