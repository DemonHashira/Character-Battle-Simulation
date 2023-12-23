#include "../Headers/Sorcerer.hpp"

// Implementation for the header file Sorcerer

// Initializing the constructor with the inherited values
Sorcerer::Sorcerer(const std::string& name, const std::string& specialAbility, int strength, int constitution, int dexterity, int intelligence, int wisdom, int charisma, int holyAura, int reputation, int innateTechnique) : Protagonist("", "", 0, 0, 0, 0, 0, 0, 0, 0) {
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
    SetInnateTechnique(innateTechnique);
}

// Initializing the Getter for the data field
int Sorcerer::GetInnateTechnique() const {
    return innateTechnique;
}

// Initializing the Setter for the data field
void Sorcerer::SetInnateTechnique(int innateTechnique) {
    if (innateTechnique < 0) {
        this->innateTechnique = 0;
    } else {
        this->innateTechnique = innateTechnique;
    }
}

// Implementations for the pure virtual functions

// Implementation for Sorcerer DPS which will use all available stats + the one specific to him
int Sorcerer::DPS() {
    return Protagonist::DPS() + innateTechnique;
}

// Implementation for the Sorcerer boost that will add an additional 1.8 times the damage
double Sorcerer::SpecialAbility() {
    return this->DPS() * 1.8;
}

// Implementation for the Sorcerer that will present the character's special ability
std::string Sorcerer::SpecialAbilityName() {
    return this->GetSpecialAbility();
}
