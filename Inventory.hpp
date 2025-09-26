/*
    Student: Ethan Waldo
    EMPLID: 23274836
    Project 1
    Inventory.hpp
*/

#pragma once

// #include "Item.hpp"
#include <vector>
#include <stdexcept>

class Inventory {
public:
    // Constructor
    Inventory(const std::vector<std::vector<Item>>& items = std::vector<std::vector<Item>>(10, std::vector<Item>(10)), Item* equipped = nullptr);

    // Big Five
    ~Inventory(); 
    Inventory(const Inventory& other); 
    Inventory(Inventory&& other); 
    Inventory& operator=(const Inventory& other); 
    Inventory& operator=(Inventory&& other); 

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
    std::vector<std::vector<Item>> inventory_grid_;
    Item* equipped_;
    float weight_;
    size_t item_count_;
};