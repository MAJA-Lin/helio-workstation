/*
    This file is part of Helio Workstation.

    Helio is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Helio is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Helio. If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

//[Headers]
class IconComponent;
#include "HighlightedComponent.h"
//[/Headers]


class TreeItemMenuButton  : public HighlightedComponent
{
public:

    TreeItemMenuButton ();

    ~TreeItemMenuButton();

    //[UserMethods]
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void parentHierarchyChanged() override;
    void mouseDown (const MouseEvent& e) override;


private:

    //[UserVariables]
    Component *createHighlighterComponent() override
    {
        return new TreeItemMenuButton();
    }
    //[/UserVariables]

    ScopedPointer<IconComponent> menuIcon;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TreeItemMenuButton)
};
