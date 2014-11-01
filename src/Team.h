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
    void setTeamNumber(int value);
    bool isLeftPainted();
protected:
private:
    int team_number;
    bool left_painted;
};


#endif /* defined(__heinneken__Team__) */
