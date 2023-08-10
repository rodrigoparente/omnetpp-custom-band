//
// Copyright (C) 2014 OpenSim Ltd.
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program; if not, see <http://www.gnu.org/licenses/>.
//

#include "inet/physicallayer/ieee80211/mode/Ieee80211Band.h"

namespace inet {

namespace physicallayer {

Ieee80211BandBase::Ieee80211BandBase(const char *name) :
    name(name)
{
}

Ieee80211EnumeratedBand::Ieee80211EnumeratedBand(const char *name, const std::vector<Hz> centers) :
    Ieee80211BandBase(name),
    centers(centers)
{
}

Hz Ieee80211EnumeratedBand::getCenterFrequency(int channelNumber) const
{
    if (channelNumber < 0 || channelNumber >= (int)centers.size())
        throw cRuntimeError("Invalid channel number: %d", channelNumber);
    return centers[channelNumber];
}

Ieee80211ArithmeticalBand::Ieee80211ArithmeticalBand(const char *name, Hz start, Hz spacing, int numChannels) :
    Ieee80211BandBase(name),
    start(start),
    spacing(spacing),
    numChannels(numChannels)
{
}

Hz Ieee80211ArithmeticalBand::getCenterFrequency(int channelNumber) const
{
    if (channelNumber < 0 || channelNumber >= numChannels)
        throw cRuntimeError("Invalid channel number: %d", channelNumber);
    return start + spacing * channelNumber;
}

const Ieee80211EnumeratedBand Ieee80211CompliantBands::band2_4GHz("2.4 GHz",
{
    GHz(2.412),    // 1
    GHz(2.417),    // 2
    GHz(2.422),    // 3
    GHz(2.427),    // 4
    GHz(2.432),    // 5
    GHz(2.437),    // 6
    GHz(2.442),    // 7
    GHz(2.447),    // 8
    GHz(2.452),    // 9
    GHz(2.457),    // 10
    GHz(2.462),    // 11
    GHz(2.467),    // 12
    GHz(2.472),    // 13
    GHz(2.484),    // 14, this channel is intentionally further away from the previous than the others, see 802.11 specification
});

const Ieee80211EnumeratedBand Ieee80211CompliantBands::bandZigbee("ZigbeeBand",
{
    GHz(2.405),    // 1
    GHz(2.405),    // 2
    GHz(2.405),    // 3
    GHz(2.405),    // 4
    GHz(2.405),    // 5
    GHz(2.405),    // 6
    GHz(2.405),    // 7
    GHz(2.405),    // 8
    GHz(2.405),    // 9
    GHz(2.405),    // 10
    GHz(2.405),    // 11
    GHz(2.410),    // 12
    GHz(2.415),    // 13
    GHz(2.420),    // 14
    GHz(2.425),    // 15
    GHz(2.430),    // 16
    GHz(2.435),    // 17
    GHz(2.440),    // 18
    GHz(2.445),    // 19
    GHz(2.450),    // 20
    GHz(2.455),    // 21
    GHz(2.460),    // 22
    GHz(2.465),    // 23
    GHz(2.470),    // 24
    GHz(2.475),    // 25
    GHz(2.480),    // 26
});

const Ieee80211EnumeratedBand Ieee80211CompliantBands::bandBluetooth("BluetoothBand",
{
    GHz(2.404),    // 0
    GHz(2.406),    // 1
    GHz(2.408),    // 2
    GHz(2.410),    // 3
    GHz(2.412),    // 4
    GHz(2.414),    // 5
    GHz(2.416),    // 6
    GHz(2.418),    // 7
    GHz(2.420),    // 8
    GHz(2.422),    // 9
    GHz(2.424),    // 10
    GHz(2.428),    // 11
    GHz(2.430),    // 12
    GHz(2.432),    // 13
    GHz(2.434),    // 14
    GHz(2.436),    // 15
    GHz(2.438),    // 16
    GHz(2.440),    // 17
    GHz(2.442),    // 18
    GHz(2.444),    // 19
    GHz(2.446),    // 20
    GHz(2.448),    // 21
    GHz(2.450),    // 22
    GHz(2.452),    // 23
    GHz(2.454),    // 24
    GHz(2.456),    // 25
    GHz(2.458),    // 26
    GHz(2.460),    // 27
    GHz(2.462),    // 28
    GHz(2.464),    // 29
    GHz(2.466),    // 30
    GHz(2.468),    // 31
    GHz(2.470),    // 32
    GHz(2.472),    // 33
    GHz(2.474),    // 34
    GHz(2.476),    // 35
    GHz(2.478),    // 36
    GHz(2.402),    // 37
    GHz(2.426),    // 38
    GHz(2.480),    // 39
});

const Ieee80211ArithmeticalBand Ieee80211CompliantBands::band5GHz("5 GHz", GHz(5), MHz(5), 200);

const Ieee80211ArithmeticalBand Ieee80211CompliantBands::band5_9GHz("5.9 GHz", GHz(5.86), MHz(10), 7);

const std::vector<const IIeee80211Band *> Ieee80211CompliantBands::bands = {&band2_4GHz, &band5GHz, &band5_9GHz, &bandZigbee, &bandBluetooth};

const IIeee80211Band *Ieee80211CompliantBands::findBand(const char *name)
{
    for (auto & band : bands)
        if (!strcmp(band->getName(), name))
            return band;
    return nullptr;
}

const IIeee80211Band *Ieee80211CompliantBands::getBand(const char *name)
{
    const IIeee80211Band *band = findBand(name);
    if (band == nullptr)
        throw cRuntimeError("Unknown 802.11 band: '%c'", name);
    else
        return band;
}

} // namespace physicallayer

} // namespace inet

