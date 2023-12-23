#include "../Headers/DemonSlayer.hpp"

// Implementation file for header DemonSlayer

// Initializing the constructor with the inherited values
DemonSlayer::DemonSlayer(const std::string& name, const std::string& specialAbility, int strength, int constitution, int dexterity, int intelligence, int wisdom, int charisma, int holyAura, int reputation, int demonSlayerMark) : Protagonist("", "", 0, 0, 0, 0, 0, 0, 0, 0) {
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
    SetDemonSlayerMark(demonSlayerMark);
}

// Initializing the Getter for the data field
int DemonSlayer::GetDemonSlayerMark() const {
    return demonSlayerMark;
}

// Initializing the Setter for the data field
void DemonSlayer::SetDemonSlayerMark(int demonSlayerMark) {
    if (demonSlayerMark < 0) {
        this->demonSlayerMark = 0;
    } else {
        this->demonSlayerMark = demonSlayerMark;
    }
}

// Implementations for the pure virtual functions

// Implementation for Demon Slayer DPS which will use all available stats + the one specific to him
int DemonSlayer::DPS() {
    return Protagonist::DPS() + demonSlayerMark;
}

// Implementation for the Demon Slayer boost that will add an additional 1.3 times the damage
double DemonSlayer::SpecialAbility() {
    return this->DPS() * 1.6;
}

// Implementation for the Demon Slayer that will present the character's special ability
std::string DemonSlayer::SpecialAbilityName() {
    return this->GetSpecialAbility();
}
