#ifndef Demon_hpp
#define Demon_hpp

#include "../Headers/Antagonist.hpp"

// Header file for the Demon class
// publicly inheriting Antagonist
class Demon : public Antagonist {
protected:
    // Additional data field specific to Demon
    int bloodDemonArt;

public:
    // Constructor with inherited values from Antagonist
    Demon(const std::string& name, const std::string& specialAbility, int strength, int constitution,
          int dexterity, int intelligence, int wisdom, int charisma, int darkAura,
          int fear, int bloodDemonArt);

    // Getter for the data field
    int GetBloodDemonArt() const;

    // Setter for the data field
    void SetBloodDemonArt(int bloodDemonArt);

    // Concrete implementation for the pure virtual functions
    int DPS() override;
    double SpecialAbility() override;
    std::string SpecialAbilityName() override;
};

#endif /* Demon_hpp */
