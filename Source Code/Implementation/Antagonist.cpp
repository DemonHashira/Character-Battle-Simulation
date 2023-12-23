#include "../Headers/Antagonist.hpp"

// Implementation file for header Antagonist

// Initializing the constructor with the inherited values
Antagonist::Antagonist(const std::string& name, const std::string& specialAbility, int strength, int constitution, int dexterity, int intelligence, int wisdom, int charisma, int darkAura, int fear) : Character("", "", 0, 0, 0, 0, 0, 0) {
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
}

// Initializing the Getters for the data fields
int Antagonist::GetFear() const {
    return fear;
}

int Antagonist::GetDarkAura() const {
    return darkAura;
}

// Initializing the Setters for the data fields
void Antagonist::SetFear(int fear) {
    if (fear < 0) {
        this->fear = 0;
    } else {
        this->fear = fear;
    }
}

void Antagonist::SetDarkAura(int darkAura) {
    if (darkAura < 0) {
        this->darkAura = 0;
    } else {
        this->darkAura = darkAura;
    }
}

// Implementations for the pure virtual functions

// Implementation for the default Antagonist DPS which will use all available stats
int Antagonist::DPS() {
    return strength + constitution + dexterity + intelligence + wisdom + charisma
    + darkAura + fear;
}

// Implementation for the default Antagonist boost that will add 1.5 times the damage
double Antagonist::SpecialAbility() {
    return this->DPS() * 1.5;
}

// Implementation for the default Antagonist that will present the character's special ability
std::string Antagonist::SpecialAbilityName() {
    return this->GetSpecialAbility();
}
