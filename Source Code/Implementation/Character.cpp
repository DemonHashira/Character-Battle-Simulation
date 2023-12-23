#include "../Headers/Character.hpp"

// Implementation file for header Category

// Initializing the constructor
Character::Character(const std::string& name, const std::string& specialAbility, int strength, int constitution, int dexterity, int intelligence, int wisdom, int charisma) {
    SetName(name);
    SetSpecialAbility(specialAbility);
    SetStrength(strength);
    SetConstitution(constitution);
    SetDexterity(dexterity);
    SetIntelligence(intelligence);
    SetWisdom(wisdom);
    SetCharisma(charisma);
}

// Implementation for the deconstructor
Character::~Character() {}

// Initializing the Getters for the data fields
std::string Character::GetName() const {
    return name;
}

std::string Character::GetSpecialAbility() const {
    return specialAbility;
}

int Character::GetStrength() const {
    return strength;
}

int Character::GetConstitution() const {
    return constitution;
}

int Character::GetDexterity() const {
    return dexterity;
}

int Character::GetIntelligence() const {
    return intelligence;
}

int Character::GetWisdom() const {
    return wisdom;
}

int Character::GetCharisma() const {
    return charisma;
}

// Initializing the Setters for the data fields
// while also checking whether the entered name is correct
// and if the entered values are not negative
void Character::SetName(const std::string &name) {
    if (name.empty() || std::all_of(name.begin(), name.end(), isspace)) {
        this->name = "Default name";
    } else {
        this->name = name;
    }
}

void Character::SetSpecialAbility(const std::string &specialAbility) {
    if (specialAbility.empty() || std::all_of(specialAbility.begin(), specialAbility.end(), isspace)) {
        this->specialAbility = "Default Special Ability";
    } else {
        this->specialAbility = specialAbility;
    }
}

void Character::SetStrength(int strength) {
    if (strength < 0) {
        this->strength = 0;
    } else {
        this->strength = strength;
    }
}

void Character::SetConstitution(int constitution) {
    if (constitution < 0) {
        this->constitution = 0;
    } else {
        this->constitution = constitution;
    }
}

void Character::SetDexterity(int dexterity) {
    if (dexterity < 0) {
        this->dexterity = 0;
    } else {
        this->dexterity = dexterity;
    }
}

void Character::SetIntelligence(int intelligence) {
    if (intelligence < 0) {
        this->intelligence = 0;
    } else {
        this->intelligence = intelligence;
    }
}

void Character::SetWisdom(int wisdom) {
    if (wisdom < 0) {
        this->wisdom = 0;
    } else {
        this->wisdom = wisdom;
    }
}

void Character::SetCharisma(int charisma) {
    if (charisma < 0) {
        this->charisma = 0;
    } else {
        this->charisma = charisma;
    }
}
