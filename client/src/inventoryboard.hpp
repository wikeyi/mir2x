/*
 * =====================================================================================
 *
 *       Filename: inventoryboard.hpp
 *        Created: 10/08/2017 19:06:52
 *    Description: inventory class
 *                 server won't store the item place
 *                 it only stores the item weight in total
 *
 *                 client can use different strategy to store them
 *                 player has max weight to hold only
 *
 *        Version: 1.0
 *       Revision: none
 *       Compiler: gcc
 *
 *         Author: ANHONG
 *          Email: anhonghe@gmail.com
 *   Organization: USTC
 *
 * =====================================================================================
 */

#pragma once
#include "widget.hpp"
#include "labelboard.hpp"
#include "tritexbutton.hpp"

class ProcessRun;
class InventoryBoard: public Widget
{
    private:
        LabelBoard m_goldBoard;
        LabelBoard m_opNameBoard;
        WMDAniBoard m_wmdAniBoard;

    private:
        TritexButton m_closeButton;

    private:
        ProcessRun *m_processRun;

    public:
        InventoryBoard(int, int, ProcessRun *, Widget * = nullptr, bool = false);

    private:
        void drawItem(int, int, const PackBin &);

    public:
        void update(double) override;
        void drawEx(int, int, int, int, int, int) override;
        bool processEvent(const SDL_Event &, bool) override;

    private:
        std::string getGoldStr() const;
};
