#ifndef Antagonist_hpp
#define Antagonist_hpp

#include "../Headers/Character.hpp"

// Header file for the Antagonist class
// publicly inheriting Character
class Antagonist : public Character {
protected:
    // Additional data fields specific to Antagonist
    int darkAura;
    int fear;

public:
    // Constructor with inherited values from Character
    Antagonist(const std::string& name, const std::string& specialAbility, int strength, int constitution,
               int dexterity, int intelligence, int wisdom, int charisma, int darkAura, int fear);

    // Getters for the additional data fields
    int GetDarkAura() const;
    int GetFear() const;

    // Setters for the additional data fields
    void SetDarkAura(int darkAura);
    void SetFear(int fear);

    // Concrete implementations for the pure virtual functions
    int DPS() override;
    double SpecialAbility() override;
    std::string SpecialAbilityName() override;

};

#endif /* Antagonist_hpp */
