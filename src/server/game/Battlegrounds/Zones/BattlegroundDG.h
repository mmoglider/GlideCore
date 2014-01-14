/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __BATTLEGROUNDDG_H
#define __BATTLEGROUNDDG_H

#include "Battleground.h"

class BattlegroundDGScore : public BattlegroundScore
{
    public:
        BattlegroundDGScore() : CartsCaptures(0), CartsReturned(0), MinesAssaulted(0), MinesDefended(0)  {};
        virtual ~BattlegroundDGScore() {};

        uint32 CartsCaptures;
        uint32 CartsReturned;
        uint32 MinesAssaulted;
        uint32 MinesDefended;
};

class BattlegroundDG : public Battleground
{
    public:
        BattlegroundDG();
        ~BattlegroundDG();
};

#endif
