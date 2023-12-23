#include "../Headers/Protagonist.hpp"

// Implementation file for header Protagonist

// Initializing the constructor with the inherited values
Protagonist::Protagonist(const std::string& name, const std::string& specialAbility, int strength, int constitution, int dexterity, int intelligence, int wisdom, int charisma, int holyAura, int reputation) : Character("", "", 0, 0, 0, 0, 0, 0) {
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
}

// Initializing the Getters for the data fields
int Protagonist::GetHolyAura() const {
    return holyAura;
}

int Protagonist::GetReputation() const {
    return reputation;
}

// Intilializing the Setters for the data fields
void Protagonist::SetHolyAura(int holyAura) {
    if (holyAura < 0) {
        this->holyAura = 0;
    } else {
        this->holyAura = holyAura;
    }
}

void Protagonist::SetReputation(int reputation) {
    if (reputation < 0) {
        this->reputation = 0;
    } else {
        this->reputation = reputation;
    }
}

// Implementations for the pure virtual functions

// Implementation for the default Protagonist DPS which will use all available stats
int Protagonist::DPS() {
    return strength + constitution + dexterity + intelligence + wisdom + charisma
    + holyAura + reputation;
}

// Implementation for the default Protagonist boost that will add 1.5 times the damage
double Protagonist::SpecialAbility() {
    return this->DPS() * 1.5;
}

// Implementation for the default Protagonist that will present the character's special ability
std::string Protagonist::SpecialAbilityName() {
    return this->GetSpecialAbility();
}
