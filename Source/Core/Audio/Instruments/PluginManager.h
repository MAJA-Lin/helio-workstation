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

#include "Serializable.h"

class PluginManager :
    public Serializable,
    public Thread,
    public WaitableEvent, // засыпает после поиска
    public ChangeBroadcaster // оповещает о том, что найден новый плагин
{
public:

    PluginManager();

    ~PluginManager() override;

    
    bool isWorkingNow() const;

    void removeListItem(int index);

    const KnownPluginList &getList();

    void sortList(KnownPluginList::SortMethod sortMethod, bool forward);

    StringArray getFilesToScan() const;

    void runInitialScan();

    void scanFolderAndAddResults(const File &dir);


    //===------------------------------------------------------------------===//
    // Thread
    //===------------------------------------------------------------------===//

    void run() override;


    //===------------------------------------------------------------------===//
    // Serializable
    //===------------------------------------------------------------------===//

    XmlElement *serialize() const override;

    void deserialize(const XmlElement &xml) override;

    void reset() override;

private:

    ReadWriteLock pluginsListLock;

    KnownPluginList pluginsList;


    ReadWriteLock filesListLock;

    StringArray filesToScan;

    
    ReadWriteLock workingFlagLock;
    
    bool isWorking;
    

    FileSearchPath getTypicalFolders();

    void scanPossibleSubfolders(const StringArray &possibleSubfolders,
                                const File &currentSystemFolder,
                                FileSearchPath &foldersOut);

};
