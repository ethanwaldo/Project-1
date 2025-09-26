/*
    Student: Ethan Waldo
    EMPLID: 23274836
    Project 1
    Inventory.hpp
*/

#pragma once

#include "Item.hpp"
#include <vector>
#include <stdexcept>

#include <utility>

class Inventory {
public:
    // Constructor
    Inventory(const std::vector<std::vector<Item>>& items = std::vector<std::vector<Item>>(10, std::vector<Item>(10)), Item* equipped = nullptr);

    // Big Five
    ~Inventory(); // Destructor
    Inventory(const Inventory& other); // Copy
    Inventory(Inventory&& other) noexcept; // Move
    Inventory& operator=(const Inventory& other); // Copy Assignment
    Inventory& operator=(Inventory&& other) noexcept; // Move Assignment

    // Accessors
    Item* getEquipped() const;
    std::vector<std::vector<Item>> getItems() const;
    float getWeight() const;
    size_t getCount() const;
    Item at(size_t row, size_t col) const;

    // Modifiers
    void equip(Item* itemToEquip);
    void discardEquipped();
    bool store(size_t row, size_t col, const Item& pickup);

private:
    void calculateInitialState();
    void clear();

    std::vector<std::vector<Item>> inventory_grid_;
    Item* equipped_;
    float weight_;
    size_t item_count_;
};