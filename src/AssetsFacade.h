//
//  AssetsFacade.h
//  carrousel
//
//  Created by miguel on 13/10/14.
//
//

#ifndef __carrousel__AssetsFacade__
#define __carrousel__AssetsFacade__

#include <stdio.h>
#include "Assets.h"
#include "Settings.h"

using namespace std;
class AssetsFacade
{

public:
    AssetsFacade();
    ~AssetsFacade();

    Settings *settings;

    void drawIntro();
    void draw_background();
    void drawText(string t);
    

};

#endif /* defined(__carrousel__AssetsFacade__) */
