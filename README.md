# Catan - Digital and 3D

## Reserach

### Games

**Base Game:** [[rules]](https://www.catan.com/sites/default/files/2021-06/catan_base_rules_2020_200707.pdf)

- 19x land tiles:
  | wood | wool | brick | ore | grain | desert |
  | --- | --- | --- | --- | --- | --- |
  | 4x | 4x | 4x | 4x | 4x | 1x |

- 9x harbors:
  | 3:1 | wood | wool | brick | ore | grain |
  | --- | --- | --- | --- | --- | --- |
  | 4x | 1x | 1x | 1x | 1x | 1x |

- 18x numbers:
  | 2 | 3 | 4 | 5 | 6 | 8 | 9 | 10 | 11 | 12 |
  | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
  | 1x | 2x | 2x | 2x | 2x | 2x | 2x | 2x | 2x | 1x |

- 95x different resources:
  | wood | wool | brick | ore | grain |
  | --- | --- | --- | --- | --- |
  | 19x | 19x | 19x | 19x | 19x |

- 25x development cards:
  | knights | progress | victory points |
  | --- | --- | --- |
  | 14x | 6x | 5x |

- 5x settlements each
- 4x cities each
- 15x roads each
- 1x robber

- longest roal
- biggest knight army

**Base Game - 5&6 players:** [[rules]](https://s3.eu-central-1.amazonaws.com/kosmos.de/media/pdf/80/d7/50/682699_Cat_Basis56_Manual_220125_web.pdf)

- 11x land tiles:
  | wood | wool | brick | ore | grain | desert |
  | --- | --- | --- | --- | --- | --- |
  | 2x | 2x | 2x | 2x | 2x | 1x |

- 2x harbors:
  | 3:1 | wool |
  | --- | --- |
  | 1x | 1x |

- 10x numbers:
  | 2 | 3 | 4 | 5 | 6 | 8 | 9 | 10 | 11 | 12 |
  | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
  | 1x | 1x | 1x | 1x | 1x | 1x | 1x | 1x | 1x | 1x |

- 25x different resources
  | wood | wool | brick | ore | grain |
  | --- | --- | --- | --- | --- |
  | 5x | 5x | 5x | 5x | 5x |

- 9x development cards
  | knights | progress |
  | --- | --- |
  | 6x | 6x |

- 5x settlements each
- 4x cities each
- 15x roads each

**Variation: Towers and Lighthouses:** [[source]](https://www.thingiverse.com/thing:2289838)

> Allows each player to place two lighthouses / towers
>
> - cost: 1x brick, 1x wood, 1x ore
> - no minimum distance to other buildings
> - lighthouse: way to go from land to water
> - prevents robber/pirate from entering adjacent hex
> - breaks up other player's longest road

- 2x tower each

**Variation: Peasants and Plagues:** [[source]](https://www.thingiverse.com/thing:2289886)

> Gives each player nine peasants that can be placed on hex fields and their amout per hex is used in the same way as the number on the chip.
>
> - cost: 1x wheat per peasant
> - min two peasants per hex
> - plague blocks the peasants on a hex
> - plague is moved on a seven _in additon_ to the robber or pirate
> - plague is not blocked by a lighthouse / knight etc
> - can plague and robber be on the same field? (probably not)

- 9x peasants each (touch interface?)
- 1x plague

**Variation: Catan for two:** [[source]](https://www.thingiverse.com/thing:2289938)

> todo

**Variant: Castles of Catan:** [[source]](https://www.thingiverse.com/thing:1831239)

> A castle is a piece that is applied to a hex, which prevents the robber/plague from moving to that hex.
>
> - cost: invest two knight cards at once (they are put back into the supply)

- there is one for each player, but they are common to use for everyone

**Variant: The magic 7** [[source]](https://www.thingiverse.com/thing:1417913)

> Rather than producing a resource, the citadel hex produces development cards. As with resources, whenever a citadel produces resources, players earn one development card for each adjacent settlement, and two for each
adjacent city.
>
> - Cities & Knights: progress cards are used instead
> - the robber / plague can not be placed there
> - happens before the normal 7 action happens

**Variant: Factories of Catan:** [[source]](https://www.thingiverse.com/thing:1410226)

> Factories are placed as settlements and allow the player to get resources from adjacent hex
>
> - cost: one of each
> - not worth any victory points
> - placed as settlements and therefore adhere to the distance rule
> - produce one resource, player may choose a resource from any of the adjacent hex fields
> - alternate hex may not be chosen if robber or plague is placed on it

- one factory per player

**Variant: Powerty is No Shame & Revenge is Sweet:**

> - a player receives a marker each time they get no resources on a dice throw
> - every time a 7 is thrown, every player but those at the citadel receive a marker
> - three markers allow a player to move the robber / plague
> - as many markers as a player has victory points allow the player to modify the dice throw

**Scenarios:**

- The Colonies [[source]](https://www.thingiverse.com/thing:1395407)
- Atoll [[source]](https://www.thingiverse.com/thing:1410218)
- The Explorers [[source]](https://www.thingiverse.com/thing:1410221)
- [!] The Bermuda Triangle [[source]](https://www.thingiverse.com/thing:1430341)
- [!] El Dorado [[source]](https://www.thingiverse.com/thing:1485518)
- The Fleets [[source]](https://www.thingiverse.com/thing:1430346)
- The Great Race [[source]](https://www.thingiverse.com/thing:1485509)
- Treasure Hunters [[source]](https://www.thingiverse.com/thing:1417797)
- [!] The Storm Tides [[source]](https://www.thingiverse.com/thing:1485448)
- Desert Ogres [[source]](https://www.thingiverse.com/thing:1430387)

## Hardware Ideas

### Hex Communication

- each of the six sides of the tile has 5 connections
  - VCC / GND
  - RX / TX
  - data busy (if a slave wants to transmit data, it checks if busy is low before pulling it high and transmitting the data after that)
- each hex has its own MCU
- when the hexgrid loses power, the grid has to be rebuit
  - the master first pulls the data busy line high
  - the slaves then know that they can't transmit data and wait until the master requested their state one by one

### Placement Detection

- there are three placement positions
  - corners
  - edges
  - center
- the first two are a bit more complicated because there can be many things there and the placed items can be upgraded as well
- placed parts can be detected by their resistance
  - there are 6 colors
  - there are less than 10 possible buildings
- parts can have upgrades / subparts that are measured by a separate pin
  - there are probably less than 10 upgrades
- some parts have a status LED, so there should be a pin to feed through the LED
