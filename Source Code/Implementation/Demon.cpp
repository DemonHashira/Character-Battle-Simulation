#include "../Headers/Demon.hpp"

// Implementation file for header Demon

//Initializing the constructor with the inherited values
Demon::Demon(const std::string& name, const std::string& specialAbility, int strength, int constitution, int dexterity, int intelligence, int wisdom, int charisma, int darkAura, int fear, int bloodDemonArt) : Antagonist("", "", 0, 0, 0, 0, 0, 0, 0, 0) {
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
    SetBloodDemonArt(bloodDemonArt);
}

// Initializing the Getter for the data field
int Demon::GetBloodDemonArt() const {
    return bloodDemonArt;
}

// Initializing the Setter for the data field
void Demon::SetBloodDemonArt(int bloodDemonArt) {
    if (bloodDemonArt < 0) {
        this->bloodDemonArt = 0;
    } else {
        this->bloodDemonArt = bloodDemonArt;
    }
}

// Implementations for the pure virtual functions

// Implementation for Demon DPS which will use all available stats + the one specific to him
int Demon::DPS() {
    return Antagonist::DPS() + bloodDemonArt;
}

// Implementation for the Demon boost that will add an additional 1.6 times the damage
double Demon::SpecialAbility() {
    return this->DPS() * 1.6;
}

// Implementation for the Demon that will present the character's special ability
std::string Demon::SpecialAbilityName() {
    return this->GetSpecialAbility();
}
