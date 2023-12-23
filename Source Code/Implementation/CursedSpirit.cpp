#include "../Headers/CursedSpirit.hpp"

// Implementation file for header CursedSpirit

// Initializing the constructor with the inherited values
CursedSpirit::CursedSpirit(const std::string& name, const std::string& specialAbility, int strength, int constitution, int dexterity, int intelligence, int wisdom, int charisma, int darkAura, int fear, int cursedEnergy) : Antagonist("", "", 0, 0, 0, 0, 0, 0, 0, 0) {
    SetName(name);
    SetSpecialAbility(specialAbility);
    SetStrength(strength);
    SetConstitution(constitution);
    SetDexterity(dexterity);
    SetIntelligence(intelligence);
    SetWisdom(wisdom);
    SetCharisma(charisma);
    SetDarkAura(darkAura);
    SetFear(fear);
    SetCursedEnergy(cursedEnergy);
}

// Initializing the Getter for the data field
int CursedSpirit::GetCursedEnergy() const {
    return cursedEnergy;
}

// Initializing the Setter for the data field
void CursedSpirit::SetCursedEnergy(int cursedEnergy) {
    if (cursedEnergy < 0) {
        this->cursedEnergy = 0;
    } else {
        this->cursedEnergy = cursedEnergy;
    }
}

// Implementations for the pure virtual functions

// Implementation for Cursed Spirit DPS which will use all available stats + the one specific to him
int CursedSpirit::DPS() {
    return Antagonist::DPS() + cursedEnergy;
}

// Implementation for the Cursed Spirit boost that will add an additional 1.7 times the damage
double CursedSpirit::SpecialAbility() {
    return this->DPS() * 1.7;
}

// Implementation for the Cursed Spirit that will present the character's special ability
std::string CursedSpirit::SpecialAbilityName() {
    return this->GetSpecialAbility();
}

