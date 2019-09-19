
## Maps

* Tileset must be defined on the top of the file like:
            tileset = "tileset.png"
  where tileset.png is an existing file in the tilesets folder.

* Resources must be defined on the top of the file like:
            resources = "resources.res"
  where tileset.png is an existing file in the tilesets folder.

* The map must have at least one layer, but there is no maximum limit.

* Layers are separated with {} signs.

* Layers will be placed down in the opposite order
  as they are placed in the map file.

* tileWidth and tileHeight must be defined before the tileset.

## Resources

* Resource objects are defined in the 
            "resources = {"
  block.
  
* Each resource have:
    - a name  (This will be the in game name too)
    - tiles  (Which tiles can represent this resource?)
    - types  (must be one from the acceptable types)
    - properties  (see the acceptable properties)

### Acceptable types

food
liquid
stone
wood

### Possible properties


