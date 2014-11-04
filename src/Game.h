

#ifndef game_Game_h
#define game_Game_h

#include "ofMain.h"
#include "Observer.h"
#include "Commandable.h"
#include "State.h"
#include "Action.h"
#include "SongManager.h"


class Game: public Observer, public Commandable
{
    
public:
    Game();    
    ~Game();
    class State *current_state;
    class AssetsFacade *assetsFacade;
    class Settings *settings;
    
    void setCurrent(State *s);
    void setAssetsFacade(AssetsFacade *a);
    void notify(Action *action);
    
    void next();
    void jump();
    void draw();
    void update();
    void setSongManager(SongManager *s);
    
    SongManager *songManager;
};

#endif
