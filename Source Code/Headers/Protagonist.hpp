#ifndef Protagonist_hpp
#define Protagonist_hpp

#include "../Headers/Character.hpp"

// Header file for the Protagonist class
// publicly inheriting Character
class Protagonist : public Character {
protected:
    // Additional data fields specific to Protagonist
    int holyAura;
    int reputation;

public:
    // Constructor with inherited values from Character
    Protagonist(const std::string& name, const std::string& specialAbility, int strength, int constitution,
                int dexterity, int intelligence, int wisdom, int charisma, int holyAura, int reputation);

    // Getters for the additional data fields
    int GetHolyAura() const;
    int GetReputation() const;

    // Setters for the additional data fields
    void SetHolyAura(int holyAura);
    void SetReputation(int reputation);

    // Concrete implementations for the pure virtual functions
    int DPS() override;
    double SpecialAbility() override;
    std::string SpecialAbilityName() override;

};

#endif /* Protagonist_hpp */
