#pragma once

enum class ItemType {
    NONE,
    WEAPON,
    ARMOR,
    POTION
};

class Item {
public:
    Item(ItemType type = ItemType::NONE, float weight = 0.0f) : type_(type), weight_(weight) {}

    ItemType getType() const { return type_; }
    float getWeight() const { return weight_; }

private:
    ItemType type_;
    float weight_;
};
