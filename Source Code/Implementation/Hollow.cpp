#include "../Headers/Hollow.hpp"

// Implementation file for Header Hollow

// Initializing the constructor with inherited values
Hollow::Hollow(const std::string& name, const std::string& specialAbility, int strength, int constitution,
               int dexterity, int intelligence, int wisdom, int charisma, int darkAura,
               int fear, int hollowFlash) : Antagonist("", "", 0, 0, 0, 0, 0, 0, 0, 0) {
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
    SetHollowFlash(hollowFlash);
}

// Initializing the Getter for the data field
int Hollow::GetHollowFlash() const {
    return hollowFlash;
}

// Initializing the Setter for the data field
void Hollow::SetHollowFlash(int hollowFlash) {
    if (hollowFlash < 0) {
        this->hollowFlash = 0;
    } else {
        this->hollowFlash = hollowFlash;
    }
}

// Implementations for the pure virtual functions

// Implementation for Hollow DPS which will use all available stats + the one specific to him
int Hollow::DPS() {
    return Antagonist::DPS() + hollowFlash;
}

// Implementation for the Hollow boost that will add an additional 1.8 times the damage
double Hollow::SpecialAbility() {
    return this->DPS() * 1.8;
}

// Implementation for the Hollow that will present the character's special ability
std::string Hollow::SpecialAbilityName() {
    return this->GetSpecialAbility();
}
