//Librarys included
#pragma once
#include "Entity.h"
#include <chrono>

//Child class of the Entity
class explosionEntity :
    public Entity
{
public:
    //Destructor and constructor for the explosion
    ~explosionEntity();
    explosionEntity();

    //Functions for the Explosion class
    void SetPostion(float posX, float posY) override final;
    void Update(Visualisation& m_viz, World& m_world, int deltatime) override final;
    virtual std::string getSpriteName() override final;
    std::string spritename;
    Side GetSide() const override { return Side::eNeutral; };
    void setExplosionActive(bool active, int posX, int posY) override final;

    //Functions declared for measuring time
    std::chrono::time_point<std::chrono::steady_clock> start;
    std::chrono::time_point<std::chrono::steady_clock> end;
    int frameIndexX = 0;
    int frameIndexY = 0;
    float frametime = 0.07;

    //Variable declarations for the Explosion class
    int PosX;
    int PosY;
};

