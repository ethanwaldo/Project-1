/*
    Student: Ethan Waldo
    EMPLID: 23274836
    Project 1
    Inventory.hpp
*/
#ifndef INVENTORY_HPP
#define INVENTORY_HPP
#include <vector>
#include <cstddef>
#include <stdexcept>
#include "Item.hpp"

class Inventory {
private:
    std::vector<std::vector<Item>> inventory_grid_;
    Item* equipped_;
    float weight_;
    size_t item_count_;
    
    // Private helper functions
    void calculateInitialState();
    void clear();

public:
    // Constructor
    Inventory(const std::vector<std::vector<Item>>& items = std::vector<std::vector<Item>>(10, std::vector<Item>(10)), Item* equipped = nullptr);

    // Big Five
    Inventory(const Inventory& rhs);
    Inventory(Inventory&& rhs) noexcept;
    Inventory& operator=(const Inventory& rhs);
    Inventory& operator=(Inventory&& rhs) noexcept;
    ~Inventory();

    // Accessors
    Item* getEquipped() const;
    void equip(Item* itemToEquip);
    void discardEquipped();
    std::vector<std::vector<Item>> getItems() const;
    float getWeight() const;
    size_t getCount() const;
    Item at(size_t row, size_t col) const;
    bool store(size_t row, size_t col, const Item& pickup);
};

#endif