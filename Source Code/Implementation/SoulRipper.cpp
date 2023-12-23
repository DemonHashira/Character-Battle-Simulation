#include "../Headers/SoulRipper.hpp"

// Implementation file for header SoulRipper

// Initializing the constructor with the inherited values
SoulRipper::SoulRipper(const std::string& name, const std::string& specialAbility, int strength, int constitution,
                       int dexterity, int intelligence, int wisdom, int charisma, int holyAura,
                       int reputation, int spiritualPower)
    : Protagonist("", "", 0, 0, 0, 0, 0, 0, 0, 0) {
    SetName(name);
    SetSpecialAbility(specialAbility);
    SetStrength(strength);
    SetConstitution(constitution);
    SetDexterity(dexterity);
    SetIntelligence(intelligence);
    SetWisdom(wisdom);
    SetCharisma(charisma);
    SetHolyAura(holyAura);
    SetReputation(reputation);
    SetSpiritualPower(spiritualPower);
}

// Initializing the Getter for the data field
int SoulRipper::GetSpiritualPower() const {
    return spiritualPower;
}

// Initializing the Setter for the data field
void SoulRipper::SetSpiritualPower(int spiritualPower) {
    if (spiritualPower < 0) {
        this->spiritualPower = 0;
    } else {
        this->spiritualPower = spiritualPower;
    }
}

// Implementations for the pure virtual functions

// Implementation for Soul Ripper DPS which will use all available stats + the one specific to him
int SoulRipper::DPS() {
    return Protagonist::DPS() + spiritualPower;
}

// Implementation for the Soul Ripper boost that will add an additional 1.2 times the damage
double SoulRipper::SpecialAbility() {
    return this->DPS() * 1.7;
}

// Implementation for the Soul Ripper that will present the character's special ability
std::string SoulRipper::SpecialAbilityName() {
    return this->GetSpecialAbility();
}
