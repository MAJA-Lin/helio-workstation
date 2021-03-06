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

class MidiEvent;
class MidiLayer;
class MidiRoll;

class MidiEventComponent : public Component
{
public:

    MidiEventComponent(MidiRoll &editor, const MidiEvent &event);

    const MidiEvent &getEvent() const;



    bool isActive() const;

    void setActive(bool val, bool force = false);


    virtual void updateBounds(const Rectangle<float> &b) = 0;

    virtual void setSelected(const bool selected);

    bool isSelected() const;


    float getBeat() const;

    bool belongsToLayerSet(Array<MidiLayer *> layers) const;
    
    
    //===------------------------------------------------------------------===//
    // Component
    //===------------------------------------------------------------------===//

    void mouseDown(const MouseEvent &e) override;

    static int compareElements(MidiEventComponent *first, MidiEventComponent *second);

protected:

    void activateCorrespondingLayer(bool selectOthers, bool deselectOthers);

    MidiRoll &roll;

    const MidiEvent &midiEvent;

    ComponentDragger dragger;

    bool selectedState;

    bool activeState;

    float anchorBeat;

    Colour colour;

    // сдвиг мыши от нуля компонента во время клика.
    // если его не учитывать, то ноты двигаются неестественно
    Point<int> clickOffset;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MidiEventComponent)
};
