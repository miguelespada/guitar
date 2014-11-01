//
//  Team.h
//  heinneken
//
//  Created by miguel on 01/11/14.
//
//

#ifndef __heinneken__Team__
#define __heinneken__Team__

class Team
{
public:
    Team();
    Team(int team_number);
    virtual ~Team();
    int getTeamNumber();
    bool isLeftPainted();
protected:
private:
    int id;
};


#endif /* defined(__heinneken__Team__) */
