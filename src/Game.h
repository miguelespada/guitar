

#ifndef game_Game_h
#define game_Game_h

#include "ofMain.h"
#include "Observer.h"
#include "Commandable.h"
#include "State.h"
#include "Action.h"


class Game: public Observer, public Commandable
{
    
public:
    Game();    
    class State *current;
    class AssetsFacade *assetsFacade;
    class Settings *settings;
    
    void setCurrent(State *s);
    void setAssetsFacade(AssetsFacade *a);
    
    void setSettings(Settings *s);
    void notify(Action *action);
    
    void next();
    void jump();
    void draw();
};

#endif
