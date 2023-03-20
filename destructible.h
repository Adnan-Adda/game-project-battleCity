
// datum: 2022-12-26
// filnamn: destructible.h
// definition for class Destructible.

#ifndef BATTLE_CITY_PROJECT_DESTRUCTIBLE_H
#define BATTLE_CITY_PROJECT_DESTRUCTIBLE_H

/// Represent an object that can be damaged/destroyed/dead.
class Destructible{
private:
    int strength_;
public:
    /**
     * Construct object with strength, strength is object's health/life/power.
     * @param strength
     */
    explicit Destructible(int strength);
    /**
     * Decrease strength by damageSize.
     * @param damageSize
     */
    void decreaseStrength(int damageSize);
    /**
     * Get strength, minimum is 0.
     * @return
     */
    int getStrength() const;
    /**
     * Object considered dead if its strength is 0.
     * @return true if strength is 0 otherwith false
     */
    bool isDead() const;
};
#endif //BATTLE_CITY_PROJECT_DESTRUCTIBLE_H
