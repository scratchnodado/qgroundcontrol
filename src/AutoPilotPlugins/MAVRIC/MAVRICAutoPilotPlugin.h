/*=====================================================================
 
 QGroundControl Open Source Ground Control Station
 
 (c) 2009 - 2014 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 
 This file is part of the QGROUNDCONTROL project
 
 QGROUNDCONTROL is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 QGROUNDCONTROL is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with QGROUNDCONTROL. If not, see <http://www.gnu.org/licenses/>.
 
 ======================================================================*/

#ifndef MAVRICAUTOPILOT_H
#define MAVRICAUTOPILOT_H

#include "AutoPilotPlugin.h"
#include "AutoPilotPluginManager.h"
#include "UASInterface.h"
#include "../Generic/GenericParameterFacts.h"

/// @file
///     @brief This is the MAV'RIC specific implementation of the AutoPilot class.
///     @author Nicolas Dousse <nic.dousse@gmail.com>

class MAVRICAutoPilotPlugin : public AutoPilotPlugin
{
    Q_OBJECT

public:
    MAVRICAutoPilotPlugin(UASInterface* uas, QObject* parent = NULL);
    ~MAVRICAutoPilotPlugin();

	// Overrides from AutoPilotPlugin
    virtual const QVariantList& vehicleComponents(void);
    virtual ParameterLoader* getParameterLoader(void) { return _parameterFacts; }

    static QList<AutoPilotPluginManager::FullMode_t> getModes(void);
    static QString getShortModeText(uint8_t baseMode, uint32_t customMode);
    static void clearStaticData(void);

private slots:
    void _parametersReady(void);

private:
    UASInterface*       _uas;
    GenericParameterFacts*  _parameterFacts;
};

#endif