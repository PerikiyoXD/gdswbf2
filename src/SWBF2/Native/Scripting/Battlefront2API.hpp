// Battlefront2API.h

#ifndef BATTLEFRONT2API_H
#define BATTLEFRONT2API_H

#include <string>
#include <vector>
#include <tuple>
#include <functional>

namespace Battlefront2API {

/**
 * Sets the sound stream to play for the specified team when the other specified team has started/stopped bleeding.
 * 
 * @param playerTeam         Player's team number
 * @param bleedTeam          The team that's started/stopped bleeding
 * @param streamSoundName    Stream sound to play when the local player is playerTeam and bleedTeam has started/stopped bleeding
 * @param bleeding           Set to 1 to assign a started bleeding sound, set to 0 to assign a stopped bleeding sound
 */
void SetBleedingVoiceOver(int playerTeam, int bleedTeam, const std::string& streamSoundName, int bleeding);

/**
 * Sets the bleeding sound stream repeat time.
 * 
 * @param repeatTime         Time between each repetition of the started bleeding voice over
 */
void SetBleedingRepeatTime(float repeatTime);

/**
 * Sets the voice over to play for the specified bonus.
 * 
 * @param playerTeam         Player's team number
 * @param bonusNum           The number of the bonus to be set.
 *                            `0` - medical regen bonus (played on level load, heard by player's team)
 *                            `1` - surplus supplies bonus (played on level load, heard by player's team)
 *                            `2` - sensor boost bonus (played on level load, heard by player's team)
 *                            `3` - hero is on the battlefield (played on level load, heard by both teams)
 *                            `4` - our team just got the reserves bonus (played when it happens, heard by player's team)
 *                            `5` - the other team just got reserves bonus (played when it happens, heard by other team)
 * @param streamSoundName    Stream sound to play when the bonus occurs (or at level load if the bonus is ongoing)
 */
void SetPlanetaryBonusVoiceOver(int playerTeam, int bonusNum, const std::string& streamSoundName);

/**
 * Sets the sound effect to play for the specified sound event.
 * 
 * @param soundEventType     Type of event. Can be any of the following...
 *                            `BirdScatter` - Played when birds are spawned
 *                            `Bird` - Attached to each bird
 *                            `LeafFall` - Played when a falling leaf is spawned
 *                            `ScopeDisplayAmbient` - Played when scope display is active
 *                            `ScopeDisplayZoomIn` - When scope display zooms in
 *                            `ScopeDisplayZoomOut` - When scope display zooms out
 *                            `WeaponUnableSelect` - When the weapon change button is pressed but another weapon is not available
 *                            `WeaponModeUnableSelect` - When the weapon mode change button is pressed but another mode is not available
 *                            `SpawnDisplayUnitChange` - When unit is changed in spawn display
 *                            `SpawnDisplayUnitAccept` - When unit is selected in spawn display
 *                            `SpawnDisplaySpawnPointChange` - When spawn point is changed in spawn display
 *                            `SpawnDisplaySpawnPointAccept` - When spawn point is selected in spawn display
 *                            `SpawnDisplayBack` - When user presses the back button and returns from the map to the unit select screen in
 *                                                 the spawn display
 *                            `LockOn` - Played when player locks onto someone using the targeting display
 *                            `HeroesUnlocked` - When heroes are unlocked in multiplayer
 *                            `HeroSpawned` - When a player on Team `teamIndex` spawns in as the hero
 *                            `HeroDefeated` - When a player on Team `teamIndex` dies in as the hero
 * @param soundPropertyName  Name of a SoundProperty assigned to the event
 * @param teamIndex          Only required if `soundEventType` == `"HeroSpawned"` or `"HeroDefeated"`. Index of team that player is on
 */
void SetSoundEffect(const std::string& soundEventType, const std::string& soundPropertyName, int teamIndex = -1);

/**
 * Sets the voice over for when the specified team has low reinforcements.
 * 
 * @param playerTeam               Player's team number
 * @param lowReinforcementTeam     Team which has low reinforcements
 * @param streamSoundName          Sound stream to play when the local player is `playerTeam` and `lowReinforcementTeam`'s reinforcements
 *                                 have dropped below `numReinforcements`
 * @param numReinforcements        Number of reinforcements which triggers the low reinforcement stream
 * @param isPercentage             Optional argument which when set to 1 treats `numReinforcements` as a fraction (`0.0..1.0`) of maximum reinforcements
 */
void SetLowReinforcementsVoiceOver(int playerTeam, int lowReinforcementTeam, const std::string& streamSoundName, int numReinforcements, int isPercentage = 0);

/**
 * Sets the out-of-bounds voice over to play for the specified team.
 * 
 * @param playerTeam         Player's team number
 * @param streamSoundName    Name of the stream to play when the player goes out of bounds
 */
void SetOutOfBoundsVoiceOver(int playerTeam, const std::string& streamSoundName);

/**
 * Sets the ambient music to play for players on the specified team.
 * 
 * @param playerTeam         Player's team number
 * @param reinforcementCount Reinforcement count of the player's team which triggers the specified music
 * @param musicName          Name of the music configuration
 * @param gameStage          Value from 0 to 2, where 0 = beginning, 1 = middle, and 2 = end
 * @param isPercentage       Optional argument which when set to 1 treats reinforcementCount as a fraction (`0.0..1.0`) of maximum reinforcements
 */
void SetAmbientMusic(int playerTeam, int reinforcementCount, const std::string& musicName, int gameStage, int isPercentage = 0);

/**
 * Sets which music and voice overs are heard when in two-player (only?) splitscreen.
 * 
 * @param teamIndex          Index of the attacking team
 */
void SetAttackingTeam(int teamIndex);

/**
 * Sets the music to play for players on the specified team when their team is victorious.
 * 
 * @param teamIndex          Index of player's team
 * @param soundStreamID      ID of sound stream properties to play
 */
void SetVictoryMusic(int teamIndex, const std::string& soundStreamID);

/**
 * Sets the music to play for players on the specified team when their team is defeated.
 * 
 * @param teamIndex          Index of player's team
 * @param soundStreamID      ID of sound stream properties to play
 */
void SetDefeatMusic(int teamIndex, const std::string& soundStreamID);

/**
 * Plays the specified sound stream segment.
 * 
 * @param streamFilename    File containing the audio stream
 * @param streamID          ID of sound stream properties containing `segmentID`
 * @param segmentID         ID of segment within the `streamID` to play
 * @param gain              Initial gain of the stream
 * @param busName           Bus stream is assigned to (default = "Root")
 * @param streamIndex       Index of the open stream to play, `streamFilename` can be "" if this is specified.  (NOTE : This is an optional argument)
 * @return                  ID of the opened stream, `streamIndex` if it was specified or 0 if the function fails
 */
int PlayAudioStream(const std::string& streamFilename, const std::string& streamID, const std::string& segmentID, float gain, const std::string& busName = "Root", int streamIndex = -1);

/**
 * Plays the specified sound stream with the specified properties.
 * 
 * @param streamFilename    File containing the audio stream specified in the sound stream properties
 * @param soundStreamID     ID of the sound stream properties to play
 * @param noOpen            Set to 1 to play using a previously opened stream. (NOTE : This is an optional argument)
 * @return                  ID of the opened stream (this may not be the stream that's playing)
 */
int PlayAudioStreamUsingProperties(const std::string& streamFilename, const std::string& soundStreamID, int noOpen = 0);

/**
 * Stops and optionally closes the specified sound stream.
 * 
 * @param streamIndex       Index of the audio stream to stop
 * @param close             Optional argument.  Set to 1 to close the stream, 0 to leave the stream open
 */
void StopAudioStream(int streamIndex, int close = 0);

/**
 * Opens the specified sound stream.
 * 
 * @param streamFilename    File containing the audio stream
 * @param streamID          ID of stream within the file
 * @return                  ID of the opened stream or 0 if the function fails
 */
int OpenAudioStream(const std::string& streamFilename, const std::string& streamID);

/**
 * Appends the specified sound stream to another stream. Just like how only one segment in an open audio stream can be 
 * played at a time, only one segment in a group of appended segments can be played at a time.  
 * 
 * NOTE: This can ONLY be used with streams that are stored inside the same lvl file!
 * 
 * @param streamFilename    File containing the stream to append to the currently open stream
 * @param streamID          ID of the stream within the file
 * @param streamIndex       Number returned from `OpenAudioStream()` which is the index of the stream to append segments to
 * @return                  ID of the opened stream or 0 if the function fails
 */
int AudioStreamAppendSegments(const std::string& streamFilename, const std::string& streamID, int streamIndex);

/**
 * Returns whether or not a sound stream is currently playing.
 * 
 * @param streamID          ID of the stream to query
 * @return                  1 if the stream has stopped, 0 otherwise
 */
int AudioStreamComplete(const std::string& streamID);

/**
 * Plays the specified sound properties.
 * 
 * @param soundID           ID of sound properties to play
 */
void ScriptCB_SndPlaySound(const std::string& soundID);

/**
 * Fades the specified sound bus.
 * 
 * @param busName           Name of the bus to fade
 * @param endGain           Final gain of the bus
 * @param fadeTime          Time to fade the bus
 * @param startGain         Start gain of the bus (NOTE : this is an optional argument)
 */
void ScriptCB_SndBusFade(const std::string& busName, float endGain, float fadeTime, float startGain = 0.0f);

/**
 * Scales the specified parameter for the specified sound group.
 * 
 * @param groupID           Identifies the group which contains sounds that are changed
 * @param parameter         Parameter to scale on each sound within the group.  Can be one of the following...
 *                           `Gain`
 *                           `GainDev`
 *                           `Pitch`
 *                           `PitchDev`
 *                           `PlayProbability`
 *                           `PlayInterval`
 *                           `PlayIntervalDev`
 *                           `ReverbGain`
 *                           `Pan`
 *                           `MinDistance`
 *                           `MuteDistance`
 *                           `MaxDistance`
 *                           `RollOff`
 *                           `RollIn`
 *                           `RollInDistance`
 * @param scale             Scale factor for the parameter
 */
void ScaleSoundParameter(const std::string& groupID, const std::string& parameter, float scale);

/**
 * Sets the bus that controls movie audio volume.
 * 
 * @param busID             ID of bus which controls the movie audio volume
 */
void ScriptCB_SetMovieAudioBus(const std::string& busID);

/**
 * Exaggerates or reduces doppler effects.
 * 
 * @param dopplerFactor     Default value is 1.0.  To reduce doppler effects use values
 *                          less than 1.0, to exaggerate use values greater than 1.0
 */
void ScriptCB_SetDopplerFactor(float dopplerFactor);

/**
 * Plays the specified music.
 * 
 * @param musicID           ID of the music to play in game
 */
void ScriptCB_PlayInGameMusic(const std::string& musicID);

/**
 * Stops the music previously played using `ScriptCB_PlayInGameMusic()`.
 */
void ScriptCB_StopInGameMusic();

/**
 * Enables or disables command post voice overs.
 * 
 * @param enabled           Set to 1 to enable command post VO, 0 to disable command post VO
 */
void ScriptCB_EnableCommandPostVO(int enabled);

/**
 * Enables or disables hero music.
 * 
 * @param enabled           Set to 1 to enable hero music, 0 to disable hero music
 */
void ScriptCB_EnableHeroMusic(int enabled);

/**
 * Enables or disables hero voice overs.
 * 
 * @param enabled           Set to 1 to enable hero voice overs, 0 to disable hero voice overs
 */
void ScriptCB_EnableHeroVO(int enabled);

/**
 * Sets the gain of the ingame bus when the spawn display is visible.
 * 
 * @param gain              0..1 - Gain of the ingame bus when the spawn display is visible (default = 0.2)
 * @param fadeTime          Time, in seconds, to fade the ingame bus (default = 3.0)
 */
void ScriptCB_SetSpawnDisplayGain(float gain = 0.2f, float fadeTime = 3.0f);

/**
 * Enables or disables the specified trigger sound region.
 * 
 * @param groupName         Name of the trigger sound region group to enable/disable
 * @param enabled           1 to enable, 0 to disable.  (default = 1)
 */
void ScriptCB_TriggerSoundRegionEnable(const std::string& groupName, int enabled = 1);

/**
 * Returns the entity class of the specified class name.
 * 
 * @param entityClassName   Name of the entity class
 * @return                  Entity class
 */
void* FindEntityClass(const std::string& entityClassName);

/**
 * Sets the amount of extra(?) model memory to allocate for the map on the PS2.
 * 
 * @param bytes             Bytes to allocate
 */
void SetPS2ModelMemory(int bytes);

/**
 * For CollisionManager and TreeGrid sizes...  
 * 
 * `SetWorldExtents` and `ScriptPreInit` go hand in hand. When building a Space level, you may notice that when you exit 
 *  your ship you instantly die. You also might find that running around certain parts of your ship you will die 
 *  without taking damage. That’s what `SetWorldExtents` is for. If you have this set to 2500, but you’re still finding 
 *  that the world is killing you (and you’re not walking into a death region) then bump it up to enlarge the soldier 
 *  based playable space.
 * 
 * Might have to go in `ScriptPreInit`.
 * 
 * @param amount            New world extents in meters(?)
 */
void SetWorldExtents(int amount);

/**
 * Sets the amount of memory to take from the artist memory pools and reallocate. (Where to, though?)
 * 
 * @param bytes             Bytes to reallocate
 */
void StealArtistHeap(int bytes);

/**
 * Loads the specified lvl file. Sub-lvls contained in the lvl file can be loaded in subsequent arguments like so:
 *  `ReadDataFile("dc:SIDE\\rep.lvl", "rep_inf_ep3_trooper", "rep_inf_ep3_engineer", "rep_hero_anakin")`
 * 
 *  You can also load a sub-lvl with a semicolon in the `sourceFilename` argument like so:
 *  `ReadDataFile("dc:Sound\\abc.lvl;ABCg")`
 * 
 * @param sourceFilename    Path of the lvl file to load, a single sub-lvl can be loaded by appending a semicolon followed by the name of the sub-lvl to this
 * @param ...               Optional. Any additional sub-lvls to load
 */
void ReadDataFile(const std::string& sourceFilename, ...);

/**
 * Loads the specified lvl file during run-time (I think?). Sub-lvls contained in the lvl file can be loaded in subsequent arguments like so:
 *  `ReadDataFile("dc:SIDE\\rep.lvl", "rep_inf_ep3_trooper", "rep_inf_ep3_engineer", "rep_hero_anakin")`
 * 
 *  You can also load a sub-lvl with a semicolon in the `sourceFilename` argument like so:
 *  `ReadDataFile("dc:Sound\\abc.lvl;ABCg")`
 * 
 * @param sourceFilename    Path of the lvl file to load, a single sub-lvl can be loaded by appending a semicolon followed by the name of the sub-lvl
 * @param ...               Optional. Any additional sub-lvls to load
 */
void ReadDataFileInGame(const std::string& sourceFilename, ...);

/**
 * Sets the amount of memory to allocate to a temporary pool.  Used in galactic conquest. (What for specifically, though?)
 * 
 * @param bytes             Bytes to allocate
 */
void SetupTempHeap(int bytes);

/**
 * Clears the temporary memory pool created with `SetupTempHeap`.
 */
void ClearTempHeap();

/**
 * Adds a shot to the map's set of camera shots. These are the different camera angles that you cycle 
 * through while in spectator mode when there's no players to spectate.
 * Use the `DumpCamera` console command to print new ones to the debug log.
 * 
 * @param quatW        Quaternion's W value for camera rotation
 * @param quatX        Quaternion's X value for camera rotation
 * @param quatY        Quaternion's Y value for camera rotation
 * @param quatZ        Quaternion's Z value for camera rotation
 * @param posX         Value of camera's X position
 * @param posY         Value of camera's Y position
 * @param posZ         Value of camera's Z position
 */
void AddCameraShot(float quatW, float quatX, float quatY, float quatZ, float posX, float posY, float posZ);

/**
 * Sets the camera's rotation (in quaternions). Note that the camera is immediately reset if the player is controlling a 
 * Controllable entity.
 * 
 * @param quatW        Quaternion's W value for camera rotation
 * @param quatX        Quaternion's X value for camera rotation
 * @param quatY        Quaternion's Y value for camera rotation
 * @param quatZ        Quaternion's Z value for camera rotation
 */
void SetCameraRotation(float quatW, float quatX, float quatY, float quatZ);

/**
 * Sets the camera's position. Note that the camera is immediately reset if the player is controlling a Controllable entity.
 *  
 * @param posX         Value of camera's X position
 * @param posY         Value of camera's Y position
 * @param posZ         Value of camera's Z position
 */
void SetCameraPosition(float posX, float posY, float posZ);

/**
 * Moves the camera to the specified entity. Used in galactic conquest.
 *  
 * @param entity       Entity to move camera to
 */
void MoveCameraToEntity(void* entity);

/**
 * Sets the map camera's position. Used in galactic conquest.
 *  
 * @param posX         X position
 * @param posY         Y position
 * @param posZ         Z position
 */
void SetMapCameraPosition(int posX, int posY, int posZ);

/**
 * Returns the map camera's position values. Used in galactic conquest.
 *  
 * @return             X position
 * @return             Y position
 * @return             Z position
 */
std::tuple<int, int, int> GetMapCameraPosition();

/**
 * Sets the map camera's position offset for the specified level of zoom. Used in galactic conquest.
 *  
 * @param zoom         Level of zoom for which to set camera offset (0 = wide, 1 = normal, 2 = focus)
 * @param posX         X position offset
 * @param posY         Y position offset
 * @param posZ         Z position offset
 */
void SetMapCameraOffset(int zoom, int posX, int posY, int posZ);

/**
 * Sets the map camera's pitch for the specified level of zoom. Used in galactic conquest.
 *  
 * @param zoom         Level of zoom for which to set camera pitch
 * @param pitch        Amount to pitch camera by
 */
void SetMapCameraPitch(int zoom, float pitch);

/**
 * Sets the map camera's zoom level. Used in galactic conquest.
 *  
 * @param zoom         Level of zoom (0 = wide, 1 = normal, 2 = focus)
 * @param dir          Optional argument. Direction of zoom (1 = zoom in, 0 = zoom out)
 * @param ratio        Optional argument. Ratio of the shortest and longest ranges of the zoom lens. For example, 
 *                     an 18-55 mm lens has a ratio of 0.33, or about 1:3, while a 75-300 mm lens ratio is 0.25, 
 *                     or 1:4. Note that the zoom ratios have no connection to field of view, but merely express 
 *                     the range between short and long
 */
void SetMapCameraZoom(int zoom, int dir = 0, float ratio = 1.0f);

/**
 * Returns the map camera's current zoom values. Used in galactic conquest.
 *  
 * @return             Level of zoom (0 = wide, 1 = normal, 2 = focus)
 * @return             Direction of zoom (1 = zoom in, 0 = zoom out)
 * @return             Ratio of the shortest and longest ranges of the zoom lens. For example, an 18-55 mm lens 
 *                     has a ratio of 0.33, or about 1:3, while a 75-300 mm lens ratio is 0.25, or 1:4. Note 
 *                     that the zoom ratios have no connection to field of view, but merely express the range 
 *                     between short and long
 */
std::tuple<int, int, float> GetMapCameraZoom();

/**
 * Snaps the map camera in place. Used in galactic conquest.
 */
void SnapMapCamera();

/**
 * Restarts the shell.
 * 
 * @param state        Set to "State"
 */
void SetState(const std::string& state);

/**
 * Sets the mission as historical, might be related to Galactic Conquest? Obsolete, used in SWBF1.
 */
void SetHistorical();

/**
 * Sets the name of the specified team. The names "neutral", "neu", "alliance", "all", "empire", "imp", "republic", "rep", 
 * and "cis" map to pre-defined team identifiers; anything else maps to locals. (Yes, this is not very general.)
 * 
 * @param teamIndex    Index of team
 * @param key          Localization key (not the full path) of the team name, which must be located in the 
 *                     scope `"level.ABC."` (replacing `ABC` with the map's ID)
 */
void SetTeamName(int teamIndex, const std::string& key);

/**
 * Sets the aggressiveness of the AI on the specified team.
 * 
 * @param teamIndex        Index of team
 * @param aggressiveness   Aggressiveness value, higher means more aggressive (`0.0..1.0`)
 */
void SetTeamAggressiveness(int teamIndex, float aggressiveness);

/**
 * Controls how far downwards from the center of the world the AI can fly. These are used on ground based maps to limit 
 * the jet classes and jedi, but is also used to keep flyers from getting too far below the space battlefield. To find 
 * an appropriate height, use `PrintPlayerPos` in the console, fly to your desired min height, and punch those numbers 
 * in. It’s best to keep the MinFlyHeight and the MinPlayerFlyHeight in line with each other to avoid AI doing things 
 * that players can’t.
 * 
 * @param height        Height in meters(?)
 */
void SetMinFlyHeight(int height);

/**
 * Controls how far upwards from the center of the world the AI can fly. These are used on ground based maps to limit 
 * the jet classes and jedi, but is also used to keep flyers from getting too far above the space battlefield. To find 
 * an appropriate height, use `PrintPlayerPos` in the console, fly to your desired max height, and punch those numbers 
 * in. It’s best to keep the MaxFlyHeight and the MaxPlayerFlyHeight in line with each other to avoid AI doing things 
 * that players can’t.
 * 
 * @param height        Height in meters(?)
 */
void SetMaxFlyHeight(int height);

/**
 * Controls how far downwards from the center of the world the player can fly. These are used on ground based maps to 
 * limit the jet classes and jedi, but is also used to keep flyers from getting too far below the space battlefield. To 
 * find an appropriate height, use `PrintPlayerPos` in the console, fly to your desired min height, and punch those 
 * numbers in. It’s best to keep the MinFlyHeight and the MinPlayerFlyHeight in line with each other to avoid AI doing 
 * things that players can’t.
 * 
 * @param height        Height in meters(?)
 */
void SetMinPlayerFlyHeight(int height);

/**
 * Controls how far upwards from the center of the world the player can fly. These are used on ground based maps to 
 * limit the jet classes and jedi, but is also used to keep flyers from getting too far above the space battlefield. To 
 * find an appropriate height, use `PrintPlayerPos` in the console, fly to your desired min height, and punch those 
 * numbers in. It’s best to keep the MaxFlyHeight and the MaxPlayerFlyHeight in line with each other to avoid AI doing 
 * things that players can’t.
 * 
 * @param height        Height in meters(?)
 */
void SetMaxPlayerFlyHeight(int height);

/**
 * Enables uber mode, which allows more than 32 units per team.
 * 
 * @param enabled       Set to 1 to enable, or 0 to disable
 */
void SetUberMode(int enabled);

/**
 * Exact functionality unknown, but likely allows AI units to jetjump at will instead of restricting them to JetJump hint nodes. Used in Kamino.
 * 
 * @param allow         Set to 1 to allow, or 0 to disallow (default = 1)
 */
void SetAllowBlindJetJumps(int allow = 1);

/**
 * Unused, exact functionality unknown. Might be related to AI planning requests.
 * 
 * @param time          Wait time in seconds
 */
void SetStationaryWaitTime(float time);

/**
 * Sets the icon of the specified team to the specified texture. Not sure where exactly this is used.
 * 
 * @param teamIndex     Index of team
 * @param icon          Name of icon texture
 */
void SetTeamIcon(int teamIndex, const std::string& icon);

/**
 * Makes the specified `team` regard the `other` team as an enemy. It does not affect how the `other` team regards the specified `team`!
 * 
 * @param team          Index of team to set views of
 * @param other         Index of team that's being viewed as enemy
 */
void SetTeamAsEnemy(int team, int other);

/**
 * Makes the specified `team` regard the `other` team as a neutral. It does not affect how the `other` team regards the specified `team`!
 * 
 * @param team          Index of team to set views of
 * @param other         Index of team that's being viewed as neutral
 */
void SetTeamAsNeutral(int team, int other);

/**
 * Makes the specified `team` regard the `other` team as an ally. It does not affect how the `other` team regards the specified `team`!
 * 
 * @param team          Index of team to set views of
 * @param other         Index of team that's being viewed as ally
 */
void SetTeamAsFriend(int team, int other);

/**
 * Sets the number of units the specified team has.
 * 
 * @param teamIndex     Index of team
 * @param count         Number of units
 */
void SetUnitCount(int teamIndex, int count);

/**
 * Returns the number of units the specified team has.
 * 
 * @param teamIndex     Index of team
 * @return              Team's unit count
 */
int GetUnitCount(int teamIndex);

/**
 * Sets the specified team's ticket count.
 * 
 * @param teamIndex     Index of team
 * @param tickets       Number of tickets to set to
 */
void SetReinforcementCount(int teamIndex, int tickets);

/**
 * Returns the specified team's current ticket count.
 * 
 * @param teamIndex     Index of team
 * @return              Number of tickets
 */
int GetReinforcementCount(int teamIndex);

/**
 * Adds the specified number of tickets to the specified team's ticket count.
 * 
 * @param teamIndex     Index of team
 * @param tickets       Number of tickets to add, use negative value to subtract tickets
 */
void AddReinforcements(int teamIndex, int tickets);

/**
 * Sets the specified team's point count.
 * 
 * @param teamIndex     Index of team
 * @param points        Number of points to set to
 */
void SetTeamPoints(int teamIndex, int points);

/**
 * Returns the specified team's current point count.
 * 
 * @param teamIndex     Index of team
 * @return              Number of points
 */
int GetTeamPoints(int teamIndex);

/**
 * Adds the specified number of points to the specified team's point count.
 * 
 * @param teamIndex     Index of team
 * @param points        Number of points to add, use negative value to subtract points
 */
void AddTeamPoints(int teamIndex, int points);

/**
 * Gives the specified character unit flag capture points.
 * 
 * @param integerChrIdx   Integer index of character unit
 */
void AddFlagCapturePoints(int integerChrIdx);

/**
 * Gives the specified character unit assault destroy points.
 * 
 * @param integerChrIdx   Integer index of character unit
 */
void AddAssaultDestroyPoints(int integerChrIdx);

/**
 * Gives the specified character unit space assault destroy points for the specified object.
 * 
 * @param integerChrIdx   Integer index of character unit
 * @param object          ID of object
 */
void AddSpaceAssaultDestroyPoints(int integerChrIdx, const std::string& object);

/**
 * Returns the faction ID of the specified team. Not sure what this is used for.
 * 
 * @param teamIndex       Index of team
 * @return                Team's faction ID
 */
std::string GetTeamFactionId(int teamIndex);

/**
 * Adds the specified unit class to the specified team.
 * 
 * @param teamIndex       Index of team
 * @param unitClass       Name of unit class (example: `"imp_inf_trooper"`)
 * @param minUnits        Minimum number of AI units that can spawn as this class
 * @param maxUnits        Optional argument. Maximum number of AI units that can spawn as this class. If the unit class has 
 *                        a `PointsToUnlock` value specified in its ODF, this argument acts as the maximum number of AI and 
 *                        player units that can spawn as this class.
 */
void AddUnitClass(int teamIndex, const std::string& unitClass, int minUnits, int maxUnits = 0);

/**
 * Sets the hero class for the specified team.
 * 
 * @param teamIndex       Index of team
 * @param heroClass       Name of hero class (example: `"imp_hero_vader"`)
 */
void SetHeroClass(int teamIndex, const std::string& heroClass);

/**
 * Turns on the hero rules for the game. This should be present in every multiplayer script, unless you do not actually want heroes 
 * in your map. Simply omit this line, and you will never get heroes in your game.
 */
void EnableSPHeroRules();

/**
 * Turns on the campaign hero rules for the game. This should be present in every campaign script for missions that include heroes.
 */
void EnableSPScriptedHeroes();

/**
 * Unused. Sets the rule by which the hero is unlocked.
 * 
 * @param rule            Unlock rule to use, possible options are unknown
 */
void SetHeroUnlockRule(const std::string& rule);

/**
 * Unused. Sets the hero player rule (whatever that means).
 * 
 * @param rule            Team rule to use, possible options are unknown
 */
void SetHeroTeamRule(const std::string& rule);

/**
 * Unused. Sets the hero player rule (whatever that means).
 * 
 * @param rule            Player rule to use, possible options are unknown
 */
void SetHeroPlayerRule(const std::string& rule);

/**
 * Unused. Sets the rule by which the hero respawns.
 * 
 * @param rule            Respawn rule to use, possible options are unknown
 */
void SetHeroRespawnRule(const std::string& rule);

/**
 * Unlocks the hero for the specified team.
 * 
 * @param teamIndex       Index of team
 */
void UnlockHeroForTeam(int teamIndex);

/**
 * Forces the specified character unit to accept the unlocked hero, automatically bringing them to the spawn screen.
 * 
 * @param integerChrIdx   Character unit index returned by GetCharacterUnit
 */
void AcceptHero(int integerChrIdx);

/**
 * Shows all units on the minimap if enabled.
 * 
 * @param enabled         Set to 1 to show all units, or 0 to put back to normal
 */
void ShowAllUnitsOnMinimap(int enabled);

/**
 * Shows or hides the CTF points for the specified team.
 * 
 * @param teamIndex       Index of team
 * @param enabled         Set to 1 to show points, or 0 to hide
 */
void ShowTeamPoints(int teamIndex, int enabled);

/**
 * Activates a bonus for the specified team.
 * 
 * @param teamIndex       Index of team to activate bonus for
 * @param bonus           Bonus to activate. Allowed values:
 *                         `MEDICAL_SUPPLIES`
 *                         `SURPLUS_SUPPLIES`
 *                         `SENSOR_BOOST`
 *                         `HERO`
 *                         `RESERVES`
 *                         `SABOTAGE`
 *                         `SNEAK_ATTACK`
 *                         `TRAINING`
 */
void ActivateBonus(int teamIndex, const std::string& bonus);

/**
 * Sets the specified team's ticket bleed rate.
 * 
 * @param teamIndex       Index of team
 * @param rate            Bleed rate to set to
 */
void SetBleedRate(int teamIndex, float rate);

/**
 * Returns the specified team's current ticket bleed rate.
 * 
 * @param teamIndex       Index of team
 * @return                Team's bleed rate
 */
float GetBleedRate(int teamIndex);

/**
 * Obsolete, from SWBF1. Sets the carrier class for the specified team.
 * 
 * @param teamIndex       Index of team
 * @param class           Name of carrier class (example: `"rep_fly_vtrans"`)
 */
void SetCarrierClass(int teamIndex, const std::string& classString);

/**
 * Specifies an initial spawn delay. All levels use this call. You should never have to modify the values.
 * 
 * @param num1            Unknown, always set to `10.0`
 * @param num2            Unknown, always set to `0.25`
 */
void SetSpawnDelay(float num1, float num2);

/**
 * Specifies an initial spawn delay for the specified team. All levels use this call. You should never have to modify the values.
 * 
 * @param num1            Unknown, always set to `10.0`
 * @param num2            Unknown, always set to `0.25`
 * @param teamIndex       Index of team
 */
void SetSpawnDelayTeam(float num1, float num2, int teamIndex);

/**
 * Sets a switch in the code that controls a number of AI behaviors. If this were a very foggy map, with a short view distance, 
 * you would set this to "true" which would make the AI see a shorter distance, and other various things to make the AI act 
 * more appropriately in an environment with limited visibility.  
 * 
 * Synonymous with `SetUrbanEnvironment()`.
 * 
 * @param enabled         Set to "true" to enable, or "false" to disable
 */
void SetDenseEnvironment(const std::string& enabled);

/**
 * Sets the distance from which AI scout units can snipe when using 'attack' snipe hint nodes.
 * 
 * @param distance        Average distance in meters from which AI can snipe
 */
void SetAttackerSnipeRange(int distance);

/**
 * Sets the distance from which AI scout units can snipe when using 'defend' snipe hint nodes.
 * 
 * @param distance        Average distance in meters from which AI can snipe
 */
void SetDefenderSnipeRange(int distance);

/**
 * Makes AI units stay in turrets, but under what conditions, no one knows... Found on Endor.
 * 
 * @param enabled         Set to 1 to enable, or 0 to disable
 */
void SetStayInTurrets(int enabled);

/**
 * Sets the maximum collision distance for asteroids. What this does exactly is unclear.
 * 
 * @param distance        Maximum collision distance (likely in meters)
 */
void SetMaxCollisionDistance(int distance);

/**
 * Sets the particle LOD bias (probably correlates to particle view distance). Needed for particles in space 
 * to work properly, don’t delete it!
 * 
 * @param bias            LOD bias value, is set to `15000` in stock space maps
 */
void SetParticleLODBias(int bias);

/**
 * Sets the size of the specified memory pool.
 * 
 * @param memoryPool      Memory pool to set size of. Possible values:
 *                         `AcklayData`
 *                         `ActiveRegion`
 *                         `Aimer`
 *                         `AmmoCounter`
 *                         `Asteroid`
 *                         `BaseHint`
 *                         `ClothData` - need 1 per cloth object in the level
 *                         `Combo` - should be ~ 2x number of jedi classes
 *                         `Combo::Attack` - should be ~8-12x #Combo
 *                         `Combo::Condition` - should be a bit bigger than #Combo::State
 *                         `Combo::DamageSample` - should be ~8-12x #Combo::Attack
 *                         `Combo::Deflect` - should be ~1x #combo
 *                         `Combo::State` - should be ~12x #Combo
 *                         `Combo::Transition` - should be a bit bigger than #Combo::State
 *                         `CommandFlyer`
 *                         `CommandHover`
 *                         `CommandWalker`
 *                         `ConnectivityGraphFollower`
 *                         `EnergyBar`
 *                         `EntityBuildingArmedDynamic`
 *                         `EntityCarrier`
 *                         `EntityCloth`
 *                         `EntityDefenseGridTurret`
 *                         `EntityDroid`
 *                         `EntityDroideka`
 *                         `EntityFlyer` - need 1 per flyer in the level
 *                         `EntityHover`
 *                         `EntityLight`
 *                         `EntityMine`
 *                         `EntityPortableTurret`
 *                         `EntityRemoteTerminal`
 *                         `EntitySoldier`
 *                         `EntitySoundStatic`
 *                         `EntitySoundStream`
 *                         `EntityTauntaun` - need 1 per tauntaun in the level
 *                         `EntityWalker` - need 1 per walker in the level
 *                         `FlagItem` - need 1 per flag in the level
 *                         `FLEffectObject::OffsetMatrix`
 *                         `LightFlash`
 *                         `MountedTurret`
 *                         `Music`
 *                         `Navigator`
 *                         `Obstacle`
 *                         `Ordnance`
 *                         `OrdnanceTowCable`
 *                         `ParticleEmitter`
 *                         `ParticleEmitterInfoData`
 *                         `ParticleEmitterObject`
 *                         `ParticleTransformer::ColorTrans` - must go before the stock `ingame.lvl` is loaded
 *                         `ParticleTransformer::PositionTr` - must go before the stock `ingame.lvl` is loaded
 *                         `ParticleTransformer::SizeTransf` - must go before the stock `ingame.lvl` is loaded
 *                         `PassengerSlot`
 *                         `PathFollower`
 *                         `PathNode`
 *                         `PathRequest`
 *                         `PowerupItem`
 *                         `RedOmniLight`
 *                         `ShieldEffect`
 *                         `SoldierAnimation`
 *                         `SoundSpaceRegion`
 *                         `TentacleSimulator`
 *                         `Timer`
 *                         `TreeGridStack`
 *                         `UnitAgent`
 *                         `UnitController`
 *                         `Weapon`
 * @param size            Size of memory pool
 */
void SetMemoryPoolSize(const std::string& memoryPool, int size);

/**
 * Sets how many types of birds there are in the level.
 * 
 * @param types          Number of bird types
 */
void SetNumBirdTypes(int types);

/**
 * Declares a new bird type.
 * 
 * @param disable        Exact functionality unknown, seems to disable birds of this type when set to 1
 * @param size           Size of birds of this type
 * @param texture        Name of bird texture
 */
void SetBirdType(int disable, float size, const std::string& texture);

/**
 * Sets the lowest height at which flocks of birds can fly.
 * 
 * @param height         Minimum flying height
 */
void SetBirdFlockMinHeight(int height);

/**
 * Sets how many types of fish there are in the level.
 * 
 * @param types          Number of fish types
 */
void SetNumFishTypes(int types);

/**
 * Declares a new fish type.
 * 
 * @param disable        Exact functionality unknown, seems to disable fish of this type when set to 1
 * @param size           Size of fish of this type
 * @param texture        Name of fish texture
 */
void SetFishType(int disable, float size, const std::string& texture);

/**
 * Fills the specified region with asteroids. Each asteroid will move in the X, Y, and Z directions at a random velocity within the range 
 * of each `minSpeed` and `maxSpeed` argument. Asteroid velocity is probably measured in meters per second. This randomized velocity is 
 * different for each asteroid.  
 * 
 * NOTE: Asteroids won't appear unless the "Asteroid" memory pool is filled >= the total number of asteroids that 
 * are in the level!
 * 
 * @param region         ID of region class
 * @param class          Name of asteroid class (example: `"spa1_prop_asteroid_03"`)
 * @param count          Number of asteroids to fill the region with
 * @param maxSpeedX      Maximum asteroid drift speed in X direction (default = 0)
 * @param maxSpeedY      Maximum asteroid drift speed in Y direction (default = 0)
 * @param maxSpeedZ      Maximum asteroid drift speed in Z direction (default = 0)
 * @param minSpeedX      Minimum asteroid drift speed in X direction (default = 0)
 * @param minSpeedY      Minimum asteroid drift speed in Y direction (default = 0)
 * @param minSpeedZ      Minimum asteroid drift speed in Z direction (default = 0)
 */
void FillAsteroidRegion(const std::string& region, const std::string& classString, int count, float maxSpeedX = 0.0f, float maxSpeedY = 0.0f, float maxSpeedZ = 0.0f, float minSpeedX = 0.0f, float minSpeedY = 0.0f, float minSpeedZ = 0.0f);

/**
 * Fills the specified path with asteroids. The distribution of the asteroids along the path's spline is more-or-less even. However, the 
 * position of each asteroid is also offset in a random direction. The distance of this offset is a random value between 0 and `maxOffset`. 
 * This randomized offset is different for each asteroid.  
 * 
 * Each asteroid will move in the X, Y, and Z directions at a random velocity within the range of each `minSpeed` and `maxSpeed` 
 * argument. Asteroid velocity is probably measured in meters per second. This randomized velocity is different for each asteroid.  
 * 
 * NOTE: Asteroids won't appear unless the "Asteroid" memory pool is filled >= the total number of asteroids that 
 * are in the level!
 * 
 * @param path           ID of path
 * @param maxOffset      Maximum distance (probably in meters) to offset each asteroid's position by (default = 0)
 * @param class          Name of asteroid class (example: `"spa1_prop_asteroid_03"`)
 * @param count          Number of asteroids to fill the path with
 * @param maxSpeedX      Maximum asteroid drift speed in X direction (default = 0)
 * @param maxSpeedY      Maximum asteroid drift speed in Y direction (default = 0)
 * @param maxSpeedZ      Maximum asteroid drift speed in Z direction (default = 0)
 * @param minSpeedX      Minimum asteroid drift speed in X direction (default = 0)
 * @param minSpeedY      Minimum asteroid drift speed in Y direction (default = 0)
 * @param minSpeedZ      Minimum asteroid drift speed in Z direction (default = 0)
 */
void FillAsteroidPath(const std::string& path, float maxOffset, const std::string& classString, int count, float maxSpeedX = 0.0f, float maxSpeedY = 0.0f, float maxSpeedZ = 0.0f, float minSpeedX = 0.0f, float minSpeedY = 0.0f, float minSpeedZ = 0.0f);

/**
 * Registers the specified region class as a death region. Entities that enter this region will be immediately killed.
 * 
 * @param regionClass    ID of region class
 */
void AddDeathRegion(const std::string& regionClass);

/**
 * Registers the specified region class as a landing region. Flyers will be able to land when inside of this region.
 * 
 * @param regionClass    ID of region class
 */
void AddLandingRegion(const std::string& regionClass);

/**
 * Removes the specified region class. Death regions and landing regions removed by RemoveRegion can be re-added 
 * with AddDeathRegion or AddLandingRegion.
 * 
 * @param regionClass    ID of region class
 */
void RemoveRegion(const std::string& regionClass);

/**
 * Returns whether or not the specified character is in the specified region.
 * 
 * @param integerChrIdx  Integer index of character
 * @param region         ID of region class
 * @return               1 if character is in region, 0 if not
 */
int IsCharacterInRegion(int integerChrIdx, const std::string& region);

/**
 * Returns the name of the specified region class.
 * 
 * @param region         ID of region class
 * @return               Name of region
 */
std::string GetRegionName(const std::string& region);

/**
 * Returns the class of the specified region.
 * 
 * @param region         Name of region
 * @return               ID of region class
 */
std::string GetRegion(const std::string& region);

/**
 * Wipes out any allocations that may have been done automatically for walkers. You’ll need to have this line in, 
 * and uncommented if you want to have walkers in your level.
 */
void ClearWalkers();

/**
 * Adds walkers to your level.  
 * 
 * The first number inside the parenthesis (numPairs) specifies how many leg pairs the walker type has. 
 * Droidekas are set up as a special case, with 0 leg pairs. So as you can see below, we have AddWalkerType(0,4), this 
 * specifies that we will have 4 walkers with 0 leg pairs (droidekas). 1 leg pair would specify a walker with one pair 
 * of legs, an ATST for example, or a one-man ATST from the Clone Wars era. So for 2 ATSTs, we would have a line that 
 * says AddWalkerType(1, 2). 2 leg pairs would be a unit like the CIS spider walker, or an ATAT, and 3 leg pairs would 
 * be the 6-legged walker from the Clone Wars era.  
 * 
 * **Examples:**  
 * 
 * `AddWalkerType(0, 4) -- special -> droidekas, 0x4 (4 droidekas)`  
 * `AddWalkerType(1, 2) -- 1x2 (2 walkers with 1 pair of legs)`  
 * `AddWalkerType(2, 4) -- 2x4 (4 walkers with 2 pairs of legs)`  
 * `AddWalkerType(3, 1) -- 3x1 (1 walker with 3 pairs of legs)`
 * 
 * @param numPairs       How many leg pairs the walker type has
 * @param count          Max number of walkers of this type that can exist simultaneously in the level
 */
void AddWalkerType(int numPairs, int count);

/**
 * Sets the distance around a waiting vehicle from which AI can be lured in.
 * 
 * @param radius         Notify radius in meters (probably)
 */
void SetAIVehicleNotifyRadius(int radius);

/**
 * Sets the overall view distance for AI.
 * 
 * @param visibility     Multiplier for how far AI can see
 */
void SetAIViewMultiplier(float visibility);

/**
 * Sets the distance from which AI scout units can snipe.
 * 
 * @param distance       Average distance in meters from which AI can snipe
 */
void AISnipeSuitabilityDist(int distance);

/**
 * When enabled, makes it so AI flyers are spatially aware of the ground, thus reducing/eliminating the chances of them crashing into it.
 * 
 * @param enabled        Set to 1 to enable, set to 0 to disable (default = 0)
 */
void SetGroundFlyerMap(int enabled);

/**
 * Turns on AutoBalancing. This will work for Conquest/Assault/CTF games. Not campaign. Basically 
 * if the score gets too far in one teams favor (+/- 40 conquest, 60 assault, 1 ctf) it will make 
 * the losing team better and the

 winning team worse until things get back to close again.
 */
void EnableAIAutoBalance();

/**
 * Turns off AutoBalancing. It is on by default so you should use this for your campaign mode scripts.
 */
void DisableAIAutoBalance();

/**
 * Sets the current difficulty modifier. This can be called from any point within a mission. So if you 
 * want the bad guys to be more difficult on just one objective, call this with say (0,2) in the OnStart 
 * function, then call it again with (0,0) to reset it in the OnComplete function.
 * 
 * @param player         Modifier for player team, positive value = team is better, negative value = team is worse (default = 0)
 * @param enemy          Modifier for enemy team, positive value = team is better, negative value = team is worse (default = 0)
 * @param difficulty     Optional argument. Sets the player and enemy difficulty only for this profile difficulty mode ("easy", "medium", or "hard")
 */
void SetAIDifficulty(int player = 0, int enemy = 0, const std::string& difficulty = "");

/**
 * Notifies the C++ code that the specified objective (uniquely identified in `text` parameter) exists for the specified team.  
 * Optionally specifies the text to show in a popup once the objective is activated.
 * 
 * @param teamIndex      Index of team to add the objective to
 * @param text           Path to localized text to display in the objective list once the objective is activated 
 *                       (example: `"level.ABC.objectives.1"`)
 * @param popupText      Optional argument. Path to localized text to display in a popup once the objective is 
 *                       activated (example: `"level.ABC.objectives.1_popup"`)
 */
void AddMissionObjective(int teamIndex, const std::string& text, const std::string& popupText = "");

/**
 * Tells the C++ code to activate the specified objective.
 * 
 * @param text           Path to localized text of the objective to activate (example: `"level.ABC.objectives.1"`)
 */
void ActivateObjective(const std::string& text);

/**
 * Tells the C++ code to complete the specified objective.
 * 
 * @param text           Path to localized text of the objective to complete (example: `"level.ABC.objectives.1"`)
 */
void CompleteObjective(const std::string& text);

/**
 * Adds the specified hint to the list of hints for the level.
 * 
 * @param hintText       Path to localized text of the hint (example: `"level.ABC.hints.1"`)
 */
void AddMissionHint(const std::string& hintText);

/**
 * Sets the flag gameplay type for the level.
 * 
 * @param type           Flag gameplay type. Possible values:
 *                        `none`
 *                        `1flag`
 *                        `2flag`
 *                        `campaign`
 */
void SetFlagGameplayType(const std::string& type);

/**
 * Notifies C++ that we're running space assault now so it can do team scoring with critical systems and whatnot.
 * 
 * @param enabled        Set to true to enable, or false to disable (default = false)
 */
void SpaceAssaultEnable(bool enabled = false);

/**
 * Adds a critical system to be destroyed in space assault.
 * 
 * @param name               Name of the object in the level
 * @param pointValue         How many points the object is worth when it's destroyed
 * @param hudPosX            X coordinate for placing the hud health indicator for the critical system (`0.0..1.0`)
 * @param hudPosY            Y coordinate for placing the hud health indicator for the critical system (`0.0..1.0`)
 * @param displayHUDMarker   Optional argument. Set to true to display the HUD marker, or false to not display it (default = true)
 */
void SpaceAssaultAddCriticalSystem(const std::string& name, int pointValue, float hudPosX, float hudPosY, bool displayHUDMarker = true);

/**
 * Links together all of the critical system objects (the names of which are stored in the specified table) as one marker in space assault.
 * 
 * @param objects        Table containing the names of critical system objects to link together
 */
void SpaceAssaultLinkCriticalSystems(const std::vector<std::string>& objects);

/**
 * Unused. Exact functionality unknown.
 * 
 * @param unknown        Unknown argument
 */
void SpaceAssaultSetupTeamNumbers(int unknown);

/**
 * Sets up the HUD bitmaps for each team's capital ship, systems, etc.
 * 
 * @param shipBitmapATT      Name of texture to use for ATT team's ship
 * @param shipBitmapDEF      Name of texture to use for DEF team's ship
 * @param shieldBitmapATT    Name of texture to use for ATT team's shields
 * @param shieldBitmapDEF    Name of texture to use for DEF team's shields
 * @param critSysBitmapATT   Name of texture to use for each of ATT team's critical systems
 * @param critSysBitmapDEF   Name of texture to use for each of DEF team's critical systems
 */
void SpaceAssaultSetupBitmaps(const std::string& shipBitmapATT, const std::string& shipBitmapDEF, const std::string& shieldBitmapATT, const std::string& shieldBitmapDEF, const std::string& critSysBitmapATT, const std::string& critSysBitmapDEF);

/**
 * Returns the score limit for space assault.
 * 
 * @return                Score limit that each team must reach to win
 */
int SpaceAssaultGetScoreLimit();

/**
 * Returns whether or not the current mission is a multiplayer match.
 * 
 * @return                1 if multiplayer match, 0 if not
 */
int ScriptCB_InMultiplayer();

/**
 * Returns whether or not the current mission is using campaign rules.
 * 
 * @return                1 if using campaign rules, 0 if using non-campaign rules
 */
int IsCampaign();

/**
 * Returns the name of the first wld file that was loaded in the map. For example, if the stock hot1.lvl 
 * file is loaded, this function will return *hoth*, since the wld file in hot1 is called *hoth.wld*.
 * 
 * @return                Name of the first-loaded wld file
 */
std::string GetWorldFilename();

/**
 * Prints the specified localized key in the message box in the player's HUD. For example, printing the key 
 * "level.cor1.objectives.campaign.1" would print "Capture the Jedi Council Chamber".
 * 
 * @param keyPath         Full path of localized key to show (example: "level.cor1.objectives.campaign.1")
 * @param teamIndex       Optional argument. Index of team to show message to if specified, or shows to players on both teams if unspecified
 */
void ShowMessageText(const std::string& keyPath, int teamIndex = -1);

/**
 * DEPRECATED, DOESN'T WORK.
 * 
 * @param keyPath         Full path of localized key to show (example: "level.cor1.objectives.campaign.1")
 */
void ShowPopup(const std::string& keyPath);

/**
 * DEPRECATED, DOESN'T WORK.
 * 
 * @param keyPath         Full path of localized key to show (example: "level.cor1.objectives.campaign.1")
 */
void ShowObjectiveTextPopup(const std::string& keyPath);

/**
 * Shows or hides the specified Timer.
 * 
 * @param timer           ID (or handler returned from CreateTimer) of the Timer to show. Set to nil (or leave blank) to hide all Timers
 */
void ShowTimer(const std::string& timer = "");

/**
 * Shows the specified localized text in a selection popup. Used in spa2c_c for choosing control layout making but not for PC?!
 * 
 * @param text            Path to localized text to show (example: `"level.spa2.objectives.popup.selectConfig"`)
 */
void ShowSelectionTextPopup(const std::string& text);

/**
 * Plays the specified sound stream for all players, or optionally only for players on the specified team.
 * 
 * @param streamID        ID of sound stream properties to play
 * @param teamIndex       Optional argument. If set, plays the sound stream properties only for players on this team
 */
void BroadcastVoiceOver(const std::string& streamID, int teamIndex = -1);

/**
 * Kills the player of the specified HUD viewport.
 * 
 * @param viewport        Viewport of the player to kill
 */
void ScriptCB_PlayerSuicide(int viewport);

/**
 * Attaches a map marker to the specified region class.
 * 
 * @param region          ID of region class to attach marker to
 * @param markerClass     Name of marker icon texture to use (the only value that seems to work is `"hud_objective_icon_circle"`)
 * @param size            Icon size multiplier
 * @param teamIndex       Index of team that should be able to see the marker
 * @param color           Icon color. Possible values:  
 *                         `RED`  
 *                         `GREEN`  
 *                         `BLUE`  
 *                         `CYAN`  
 *                         `MAGENTA`  
 *                         `YELLOW`  
 *                         `ORANGE`  
 *                         `WHITE`  
 *                         `BLACK`  
 * @param showOnHUD       Optional argument. Set to true to also show the marker on the player's HUD, or false to only show it on the map. NOTE: Doesn't seem to 
 *                        work with this particular marker function (default = true)
 * @param pulseOpacity    Optional argument. Set to true to linearly interpolate marker opacity from `(alpha*1.0)`

 to `(alpha*0.0)` 
 *                        once per second, or false to keep opacity static (default = true)
 * @param pulseSize       Optional argument. Set to true to linearly interpolate marker size from `(size*0.5)` to `(size*1.5)` once 
 *                        per second, or false to keep size static (default = true)
 */
void MapAddRegionMarker(const std::string& region, const std::string& markerClass, float size, int teamIndex, const std::string& color, bool showOnHUD = true, bool pulseOpacity = true, bool pulseSize = true);

/**
 * Removes any map markers attached to the specified region class.
 * 
 * @param region          ID of region class to remove markers from
 */
void MapRemoveRegionMarker(const std::string& region);

/**
 * Attaches a map marker to the specified entity.
 * 
 * @param entity          ID of entity to attach marker to
 * @param markerClass     Name of marker icon texture to use (the only value that seems to work is `"hud_objective_icon_circle"`)
 * @param size            Icon size multiplier
 * @param teamIndex       Index of team that should be able to see the marker
 * @param color           Icon color. Possible values:  
 *                         `RED`  
 *                         `GREEN`  
 *                         `BLUE`  
 *                         `CYAN`  
 *                         `MAGENTA`  
 *                         `YELLOW`  
 *                         `ORANGE`  
 *                         `WHITE`  
 *                         `BLACK`  
 * @param showOnHUD       Optional argument. Set to true to also show the marker on the player's HUD, or false to only show it on the map (default = true)
 * @param pulseOpacity    Optional argument. Set to true to linearly interpolate marker opacity from `(alpha*1.0)` to `(alpha*0.0)` 
 *                        once per second, or false to keep opacity static (default = true)
 * @param pulseSize       Optional argument. Set to true to linearly interpolate marker size from `(size*0.5)` to `(size*1.5)` once 
 *                        per second, or false to keep size static (default = true)
 */
void MapAddEntityMarker(const std::string& entity, const std::string& markerClass, float size, int teamIndex, const std::string& color, bool showOnHUD = true, bool pulseOpacity = true, bool pulseSize = true);

/**
 * Removes any map markers attached to the specified entity.
 * 
 * @param entity          ID of entity to remove markers from
 */
void MapRemoveEntityMarker(const std::string& entity);

/**
 * Attaches a map marker to all instances of the specified entity class.
 * 
 * @param class          Name of entity class to attach markers to (example: `"imp_inf_trooper"`)
 * @param markerClass    Name of marker icon texture to use (the only value that seems to work is `"hud_objective_icon"`)
 * @param size           Icon size multiplier
 * @param teamIndex      Index of team that should be able to see the marker
 * @param color          Icon color. Possible values:  
 *                        `RED`  
 *                        `GREEN`  
 *                        `BLUE`  
 *                        `CYAN`  
 *                        `MAGENTA`  
 *                        `YELLOW`  
 *                        `ORANGE`  
 *                        `WHITE`  
 *                        `BLACK`  
 * @param showOnHUD      Optional argument. Set to true to also show the marker on the player's HUD, or false to only show it on the map (default = true)
 * @param pulseOpacity   Optional argument. Set to true to linearly interpolate marker opacity from `(alpha*1.0)` to `(alpha*0.0)` 
 *                       once per second, or false to keep opacity static (default = true)
 * @param pulseSize      Optional argument. Set to true to linearly interpolate marker size from `(size*0.5)` to `(size*1.5)` once 
 *                       per second, or false to keep size static (default = true)
 */
void MapAddClassMarker(const std::string& className, const std::string& markerClass, float size, int teamIndex, const std::string& color, bool showOnHUD = true, bool pulseOpacity = true, bool pulseSize = true);

/**
 * Removes any map markers attached to the specified entity class.
 * 
 * @param class          Name of entity class to remove markers from
 */
void MapRemoveClassMarker(const std::string& className);

/**
 * Hides all command post markers from the minimap and radar.
 */
void MapHideCommandPosts();

/**
 * Sets whether or not the specified object can be locked onto by weapons.
 * 
 * @param objectName     ID of object
 * @param enabled        Set to 1 to enable locking on, or 0 to disable
 */
void EnableBuildingLockOn(const std::string& objectName, int enabled);

/**
 * Checks whether or not a timer exists.
 * 
 * @param timer          ID (or handler returned from `CreateTimer`) of the timer to find
 */
bool FindTimer(const std::string& timer);

/**
 * Creates a new Timer with the specified name and returns it.
 * 
 * @param name           Name to give the Timer
 * @return               Timer's handler
 */
std::string CreateTimer(const std::string& name);

/**
 * Deletes the specified Timer. Do not use the timer after destroying it!
 * 
 * @param timer          ID (or handler returned from CreateTimer) of the Timer
 */
void DestroyTimer(const std::string& timer);

/**
 * Activates the specified Timer.
 * 
 * @param timer          ID (or handler returned from CreateTimer) of the Timer
 */
void StartTimer(const std::string& timer);

/**
 * Deactivates the specified Timer.
 * 
 * @param timer          ID (or handler returned from CreateTimer) of the Timer
 */
void StopTimer(const std::string& timer);

/**
 * Sets the value of the specified Timer.
 * 
 * @param timer          ID (or handler returned from CreateTimer) of the Timer
 * @param value          Timer's duration in seconds
 */
void SetTimerValue(const std::string& timer, float value);

/**
 * Returns the value of the specified Timer.
 * 
 * @param timer          ID (or handler returned from CreateTimer) of the Timer
 * @return               The Timer's value
 */
float GetTimerValue(const std::string& timer);

/**
 * Sets the rate of the specified Timer.
 * 
 * @param timer          ID (or handler returned from CreateTimer) of the Timer
 * @param rate           Multiplier for Timer's elapse speed (default = 1.0)
 */
void SetTimerRate(const std::string& timer, float rate);

/**
 * Returns the rate of the specified Timer.
 * 
 * @param timer          ID (or handler returned from CreateTimer) of the Timer
 * @return               The Timer's rate
 */
float GetTimerRate(const std::string& timer);

/**
 * Shows or hides the timer.
 * 
 * @param timer          ID (or handler returned from CreateTimer) of the Timer
 */
void ShowTimer(const std::string& timer);

/**
 * Tell the C++ code about the defeat timer (which will display it on the HUD).
 * 
 * @param timer          ID (or handler returned from CreateTimer) of the Timer to pair with the defeat timer
 * @param teamIndex      Index of team to associate with the defeat timer
 */
void SetDefeatTimer(const std::string& timer, int teamIndex);

/**
 * Tell the C++ code about the victory timer (which will display it on the HUD).
 * 
 * @param timer          ID (or handler returned from CreateTimer) of the Timer to pair with the victory timer. Set to nil (or leave blank) to hide it
 * @param teamIndex      Index of team to associate with the victory timer
 */
void SetVictoryTimer(const std::string& timer, int teamIndex);

/**
 * UNUSED. Tell the C++ code about the mission timer (which will display it on the HUD).
 * 
 * @param timer          ID (or handler returned from CreateTimer) of the Timer to pair with the mission timer. Set to nil (or leave blank) to hide it
 */
void SetMissionTimer(const std::string& timer);

/**
 * Returns the object pointer of the specified object.
 * 
 * @param objectName     ID of object to get pointer of
 * @return               The object's pointer
 */
void* GetObjectPtr(const std::string& objectName);

/**
 * Activates the specified object.
 * 
 * @param objectName     ID of object to activate
 */
void ActivateObject(const std::string& objectName);

/**
 * Deactivates the specified object.
 * 
 * @param objectName     ID of object to deactivate
 */
void DeactivateObject(const std::string& objectName);

/**
 * Assigns the specified object to the specified team.
 * 
 * @param objectName     ID of object to set the team of
 * @param teamIndex      Index of the team to assign to the object
 */
void SetObjectTeam(const std::string& objectName, int teamIndex);

/**
 * Returns the team index of the specified object.
 * 
 * @param objectName     ID of object to get the team of
 * @return               Index of the team the object belongs to
 */
int GetObjectTeam(const std::string& objectName);

/**
 * Returns whether or not the specified object is alive.
 * 
 * @param objectName     ID of object to check
 * @return               1 if object is alive, 0 if object is not alive
 */
int IsObjectAlive(const std::string& objectName);

/**
 * Returns the current health value of the specified object.
 * 
 * @param objectName     ID of object to get the current health value of
 * @return               Object's CurHealth value
 * @return               Object's MaxHealth value
 * @return               Object's AddHealth value
 */
std::tuple<float, float, float> GetObjectHealth(const std::string& objectName);

/**
 * Returns the current shield value of the specified object.
 * 
 * @param objectName     ID of object to get the current shield value of
 * @return               Object's CurShield value
 * @return               Object's MaxShield value
 * @return               Object's AddShield value
 */
std::tuple<float, float, float> GetObjectShield(const std::string& objectName);

/**
 * Returns the name of the most recent weapon that the specified object was hit by.
 * 
 * @param objectName     ID of object to check
 * @return               Weapon class name
 */
std::string GetObjectLastHitWeaponClass(const std::string& objectName);

/**
 * Kills the specified object.
 * 
 * @param objectName     ID of object to destroy
 */
void KillObject(const std::string& objectName);

/**
 * Respawns the specified object.
 * 
 * @param objectName     ID of object to respawn
 */
void RespawnObject(const std::string& objectName);

/**
 * Returns the entity pointer of the specified object or character unit index.
 * 
 * @param object         ID of object or character unit index
 * @return               Entity pointer of object or character
 */
void* GetEntityPtr(const std::string& object);

/**
 * Returns the name of the specified entity.
 * 
 * @param entity         ID of entity
 * @return               Entity name
 */
std::string GetEntityName(void* entity);

/**
 * Returns the class of the specified entity. Can be used with FindEntityClass to check whether or not an entity is a certain class.
 * 
 * @param entity         ID of entity
 * @return               Entity class
 */
void* GetEntityClass(void* entity);

/**
 * Returns the class name of the specified entity.
 * 
 * @param entity         ID of entity
 * @return               Entity class name
 */
std::string GetEntityClassName(void* entity);

/**
 * Sets the matrix of the specified entity.
 * 
 * @param entity         ID of entity
 * @param matrix         Entity matrix to apply to entity
 */
void SetEntityMatrix(void* entity, const std::string& matrix);

/**
 * Returns the

 matrix of the specified entity.
 * 
 * @param entity         ID of entity
 * @return               Entity matrix
 */
std::string GetEntityMatrix(void* entity);

/**
 * Sets the value of a property for the specified object.
 * 
 * @param objectName     ID of object or character unit index
 * @param property       ID of the property to set
 * @param value          Value to set the property to
 */
void SetProperty(const std::string& objectName, const std::string& property, const std::string& value);

/**
 * Creates a new instance of the specified entity and returns it.
 * 
 * @param class          Name of the entity class to instantiate
 * @param matrix         Matrix or path point to create the entity at
 * @param name           Name to assign to the entity
 * @return               Entity instance
 */
void* CreateEntity(const std::string& className, const std::string& matrix, const std::string& name);

/**
 * Deletes the specified entity.
 * 
 * @param entity         ID of entity
 */
void DeleteEntity(void* entity);

/**
 * Returns the entity class pointer of the specified entity.
 * 
 * @param entity         ID of entity
 * @return               Entity class pointer
 */
void* GetEntityClassPtr(void* entity);

/**
 * Sets the value of a property for the specified object class.
 * 
 * @param objectClass    ID of object class
 * @param property       ID of the property to set
 * @param value          Property's value to set
 */
void SetClassProperty(void* objectClass, const std::string& property, const std::string& value);

/**
 * Forces the specified flyer to perform a take-off.
 * 
 * @param flyer         ID of flyer object or flyer vehicle spawn object
 */
void EntityFlyerTakeOff(const std::string& flyer);

/**
 * Forces the specified flyer to perform a landing.
 * 
 * @param flyer         ID of flyer object or flyer vehicle spawn object
 */
void EntityFlyerLand(const std::string& flyer);

/**
 * Initializes the specified flyer as flying.
 * 
 * @param flyer         ID of flyer object or flyer vehicle spawn object
 */
void EntityFlyerInitAsFlying(const std::string& flyer);

/**
 * Initializes the specified flyer as landed.
 * 
 * @param flyer         ID of flyer object or flyer vehicle spawn object
 */
void EntityFlyerInitAsLanded(const std::string& flyer);

/**
 * Forces the specified entity into the specified vehicle.
 * 
 * @param entity        Entity or character unit index to force into vehicle
 * @param vehicle       ID of the vehicle class
 */
void EnterVehicle(void* entity, const std::string& vehicle);

/**
 * Forces the specified entity out of whatever vehicle it's currently in.
 * 
 * @param entity        Entity or character unit index to force out of vehicle
 */
void ExitVehicle(void* entity);

/**
 * Enables or disables the specified flyer path.
 * 
 * @param pathID        ID of flyer spline path to enable
 * @param enable        Set to 1 to enable the path, or set to 0 to disable the path
 */
void EnableFlyerPath(int pathID, int enable);

/**
 * Returns the path point based on the specified path node.
 * 
 * @param pathName      ID of path
 * @param nodeIdx       Numeric ID of path node
 * @return              Path point
 */
std::string GetPathPoint(const std::string& pathName, int nodeIdx);

/**
 * Returns the number of units that are currently alive in the specified team.
 * 
 * @param teamIndex     Index of team
 * @return              Number of units currently alive in team
 */
int GetNumTeamMembersAlive(int teamIndex);

/**
 * Creates a new matrix based on an existing one.
 * 
 * @param rad           Rotation angle in radians around chosen axes or X axis if none chosen
 * @param rotX          Rotation around x axis if rotX != 0
 * @param rotY          Rotation around y axis if rotY != 0
 * @param rotZ          Rotation around z axis if rotZ != 0
 * @param posX          Translates unit on X axis
 * @param posY          Translates unit on Y axis
 * @param posZ          Translates unit on Z axis
 * @param matrix        Starting point for matrix changes
 * @return              Newly created matrix
 */
std::string CreateMatrix(float rad, float rotX, float rotY, float rotZ, float posX, float posY, float posZ, const std::string& matrix);

/**
 * Returns the current screen position relative to what seems to be the entity camera or 
 * entity origin point (otherwise known as pivot point or center of geometry (COG)).
 * 
 * @param entity        Entity, or integer character index (returned by GetCharacterUnit) to check
 * @return              X position
 * @return              Y position
 * @return              Z position (so it seems, anyway)
 */
std::tuple<float, float, float> GetScreenPosition(void* entity);

/**
 * Resumes playing of animation group from whichever time it was at last.
 * 
 * @param animationGroupName     ID of animation group to resume
 */
void PlayAnimation(const std::string& animationGroupName);

/**
 * Pauses animation group's playback - objects remain where they are currently.
 * 
 * @param animationGroupName     ID of animation group to pause
 */
void PauseAnimation(const std::string& animationGroupName);

/**
 * Instantly rewinds the animation group to the beginning. Can be called while the group is playing. 
 * If called while the group is stopped, play will resume from the beginning when Play is called.
 * 
 * @param animationGroupName     ID of animation group to rewind
 */
void RewindAnimation(const std::string& animationGroupName);

/**
 * Takes the current positions of the objects referenced by the group, and uses those positions 
 * as the new start point for when that object is next animated.
 * 
 * @param animationGroupName     ID of animation group to affect
 */
void SetAnimationStartPoint(const std::string& animationGroupName);

/**
 * Plays the indicated animation group from beginTime to endTime. So for a 10-second animation, 
 * playing from 0 to 5 plays the first half, and playing from 5 to 10 plays the second half.
 * 
 * @param animationGroupName     ID of animation group to play
 * @param beginTime              Start point of animation in seconds
 * @param endTime                End point of animation in seconds
 */
void PlayAnimationFromTo(const std::string& animationGroupName, float beginTime, float endTime);

/**
 * Returns the total number of units (living or dead) on the specified team.
 * 
 * @param teamIndex     Index of team to get size of
 * @return              Size of team
 */
int GetTeamSize(int teamIndex);

/**
 * Returns the integer character index of the specified unit index from the specified team.
 * 
 * @param teamIndex     Index of team
 * @param unitIndex     Index of unit to get integer character index of
 * @return              Integer character index
 */
int GetTeamMember(int teamIndex, int unitIndex);

/**
 * Returns the team index of the specified character.
 * 
 * @param characterIndex     Index of character to get team of
 * @return                   Index of team the character belongs to
 */
int GetCharacterTeam(int characterIndex);

/**
 * Selects the specified team for the specified character (as if you were doing so manually via the spawn screen).
 * 
 * @param character      Character unit
 * @param teamIndex      Index of team to select
 */
void SelectCharacterTeam(int character, int teamIndex);

/**
 * Returns whether the specified character is a human player or an AI.
 * 
 * @param characterIndex     Index of character to check "humanity" of
 * @return                   1 if character is human, 0 if character is not human
 */
int IsCharacterHuman(int characterIndex);

/**
 * Selects the specified class for the specified character (as if you were doing so manually via the spawn screen).
 * 
 * @param character      Character unit
 * @param className      Name of class to select
 */
void SelectCharacterClass(int character, const std::string& className);

/**
 * Returns the numeric index of the specified character's class (starting at 0). If you think of a team's list of 
 * classes as a table (with the hero being the last class in the list), the first class's index would be 0, the 
 * second class's index would be 1, etc.
 * 
 * @param integerChrIdx      Integer character index returned by GetCharacterUnit
 * @return                   Numeric index of character's class
 */
int GetCharacterClass(int integerChrIdx);

/**
 * Moves specified number of units from the source team to the destination team. No, you can't specify which units 
 * are moved. All this function does is iterate through the list of units on the source team and move each unit to 
 * the source team until the iterator max limit, `numUnits`, has been reached. Think of it as a for loop where 
 * the `min` is `1` and the `max` is `numUnits`, and inside the loop is a function that moves the unit index (shifted 
 * up by 1, so the player's index is going to be 1) matching the loop's `cur` value to the destination team.  
 * 
 * Also worth noting is when an alive unit is moved with this function, the function will not automatically kill the 
 * unit, so you must kill the unit through some other means if you don't want the unit to remain spawned their current 
 * class. One way you might do this (and this is untested) is by looping through `destTeam`'s units and killing them 
 * (and only loop through as many as you plan on moving to the other team), and then call `BatchChangeTeams` immediately 
 * after the loop has finished. Here's what this might look like:  
 * 
 * `unitsToMove = 5`  
 * 
 * `for unit=0,unitsToMove-1 do`  
 * `    KillObject(GetCharacterUnit(GetTeamMember(ATT, unit)))`  
 * `end`  
 * 
 * `BatchChangeTeams(ATT, DEF, unitsToMove)`
 * 
 * @param sourceTeam     Index of source team, where units are moved from
 * @param destTeam       Index of destination team, where units are moved to
 * @param numUnits       Number of units to move
 */
void BatchChangeTeams(int sourceTeam, int destTeam, int numUnits);

/**
 * Prevents or allows spawning of AI units from the specified team.
 * 
 * @param teamIndex      Index of team to affect
 * @param canSpawn       Set to 1 to allow AI units on this team to spawn, or 0 to prevent them from spawning
 */
void AllowAISpawn(int teamIndex, int canSpawn);

/**
 * Spawns the specified character unit index at the specified path point.
 * 
 * @param integerChrIdx  Unit returned from GetCharacterUnit
 * @param pathPoint      Path point returned from GetPathPoint
 */
void SpawnCharacter(int integerChrIdx, const std::string& pathPoint);

/**
 * Returns the integer character index from the specified entity or team member index.
 * 
 * @param entity         Character entity, or character index returned from GetTeamMember
 * @return               Character unit index
 */
int GetCharacterUnit(void* entity);

/**
 * Returns the integer vehicle index from the specified vehicle entity.
 * 
 * @param entity         Vehicle entity
 * @return               Vehicle index
 */
int GetCharacterVehicle(void* entity);

/**
 * Returns the integer index from the specified RemoteTerminal entity. See BF2EntityRemoteTerminalClassReference for more information. 
 * http://www.secretsociety.com/forum/downloads/BF2Docs/ClassReference/BF2EntityRemoteTerminalClassReference.jpg
 * 
 * @param entity         RemoteTerminal entity
 * @return               RemoteTerminal entity index
 */
int GetCharacterRemote(void* entity);

/**
 * Returns the integer vehicle index from the specified Controllable entity. See BF2ControllableClassReference for more information. 
 * http://www.secretsociety.com/forum/downloads/BF2Docs/ClassReference/BF2ControllableClassReference.jpg
 * 
 * @param entity         Vehicle entity
 * @return               Controllable entity index
 */
int GetCharacterControllable(void* entity);

/**
 * Returns a command post's capture region.
 * 
 * @param postID         ID of command post
 * @return               ID of command post's capture region
 */
std::string GetCommandPostCaptureRegion(const std::string& postID);

/**
 * Returns a command post's bleed value.
 * 
 * @param postID         ID of command post
 * @return               Command post's bleed value
 */
int GetCommandPostBleedValue(const std::string& postID);

/**
 * Returns a command post's owning team.
 * 
 * @param postID         ID of command post
 * @return               Index of owning team
 */
int GetCommandPostTeam(const std::string& postID);

/**
 * Initiates a victory for the specified team.
 * 
 * @param teamIndex      Index of team to declare victory for
 */
void MissionVictory(int teamIndex);

/**
 * Initiates a defeat for the specified team.
 * 
 * @param teamIndex      Index of team to declare defeat for
 */
void MissionDefeat(int teamIndex);

/**
 * Sets the movie to play once the mission has ended.
 * 
 * @param sourceFilename     File containing the movie
 * @param movieID            ID of the movie properties to play
 */
void SetMissionEndMovie(const std::string& sourceFilename, const std::string& movieID);

/**
 * Removes all previous AI goals for this team. You should call this before you set the 
 * first goals for a team, since teams 1, 2, and 3 start out with a default Conquest goal.
 * 
 * @param teamIndex     Index of team to clear goals of
 */
void ClearAIGoals(int teamIndex);

/**
 * Removes the specified goal.
 * 
 * @param goalHandle    Handle returned by AddAIGoal
 */
void DeleteAIGoal(int goalHandle);

/**
 * Adds an AI goal for this team.
 * 
 * @param teamIndex     Index of team to add goal to
 * @param goalType      Goal's type. Can be one of the following...  
 *                       `Conquest` - capture enemy team's CPs while preventing own from being captured.  
 *                       `Deathmatch` - just kill everyone.  
 *                       `Destroy` - destroy the target (a gameobject pointer, or a character index) (set in target1).  
 *                       `Defend` - defend the target (a gameobject pointer, or a character index) (set in target1).  
 *                       `CTFOffense` - try to get the specified flag (set in `target2`) and bring it back to the specified region (set in target1).  
 *                       `CTFDefense` - protect the specified flag (set in `target1`), and hunt down and return it when its stolen.  
 *                       `Follow` - follow around the target (like defend, but uses a tight follow) (set in `target1`).
 * @param weight        Weight is a relative weight for this goal. Since you can specify more than one goal for a 
 *                       team at a time, this specifies how the guys are divided. A goal with weight 2 will get 
 *                       twice as many guys as the goal with weight 1. The size of the numbers doesn't matter and 
 *                       they don't have to add up to 100 or anything.
 * @param target1       If `goalType` is:  
 *                       `Destroy` - this is a gameobject pointer or a character index.  
 *                       `Defend` - this is a gameobject pointer or a character index.  
 *                       `CTFOffense` - this is a region name.  
 *                       `CTFDefense` - this is a flag pointer.  
 *                       `Follow` - this is a gameobject pointer. 
 * @param target2       If `goalType` is:  
 *                       `CTFOffense` - this is a flag pointer.
 * @return              Goal's handle.
 */
int AddAIGoal(int teamIndex, const std::string& goalType, int weight, void* target1, void* target2);

/**
 * Blocks the given dynamic connection/group if it is currently unblocked, or unblocks it if it is currently blocked.
 * 
 * @param connection    ID of dynamic connection or planning group to toggle
 */
void TogglePlanningGraphArcs(int connection);

/**
 * Blocks the given dynamic connection/group.
 * 
 * @param connection    ID of dynamic connection or planning group to block
 */
void BlockPlanningGraphArcs(int connection);

/**
 * Unblocks the given dynamic connection/group.
 * 
 * @param connection    ID of dynamic connection or planning group to unblock
 */
void UnblockPlanningGraphArcs(int connection);

/**
 * Disables the given barrier if it is currently enabled, or enables it if it is currently disabled.
 * 
 * @param barrierID      ID of barrier to toggle
 */
void ToggleBarriers(int barrierID);

/**
 * Enables the given barrier.
 * 
 * @param barrierID      ID of barrier to enable
 */
void EnableBarriers(int barrierID);

/**
 * Disables the given barrier.
 * 
 * @param barrierID      ID of barrier to disable
 */
void DisableBarriers(int barrierID);

/**
 * Prevents all AI or AI on a specified team from using any vehicle. When this 
 * is called, AI currently in a vehicle will be forced out of it.
 * 
 * @param teamIndex      Index of team to force out of vehicles
 * @param enabled        True to prevent AI from entering vehicles, false to allow them to do so
 */
void ForceAIOutOfVehicles(int teamIndex, bool enabled);

/**
 * Prevents or allows AI to capture the specified command post.
 * 
 * @param postID         ID of command post
 * @param teamIndex      Index of team whose AI to affect
 * @param canCapture     Set to 1 to allow AI from teamIndex to capture postID, set to 0 to prevent them from capturing it
 */
void AICanCaptureCP(const std::string& postID, int teamIndex, int canCapture);

/**
 * Sets the threshold at which AI units can no longer damage the specified 
 * object or entity. For example, if threshold is 0.5, AI will not be able 
 * to damage the object or entity if its health percentage is <= 50%.
 * 
 * @param object         Object or entity to affect
 * @param threshold      Lowest health percentage that object can be brought to by AI
 */
void SetAIDamageThreshold(void* object, float threshold);

/**
 * Translates AI command IDs to strings.
 * 
 * @param command_id     command_id returned by CharacterIssueAICommand event
 * @return               Depending on command_id, will be one of the following: "getintovehicle", 
 *                        "getoutofvehicle", "waitforpickup", "followchr", or "stopfollowchr"
 */
std::string TranslateAICommand(int command_id);

/**
 * Adds the specified amount to the specified entity's MaxShields. NOTE: This does not affect the entity's CurShields value.
 * 
 * @param entity         Entity, or integer index returned by GetCharacterUnit, GetCharacterVehicle, etc.
 * @param shields        Amount of shields to add
 */
void AddShieldStrength(void* entity, int shields);

/**
 * Sets the north angle on the minimap.
 * 
 * @param angle          New minimap rotation angle in degrees (clockwise)
 * @param number         Unknown, seemingly optional, doesn't appear to do anything. Some stock mission scripts have this set to 1, some don't include it at all
 */
void SetMapNorthAngle(int angle, int number = 1);

/**
 * Forces all non-AI players to join team 1.
 */
void ForceHumansOntoTeam1();

/**
 * Returns whether or not the specified character can interact with flags.
 * 
 * @param integerChrIdx  Character unit index to check for flag interactibility
 * @return               1 if character can interact with flag, 0 if not
 */
int CanCharacterInteractWithFlag(int integerChrIdx);

/**
 * Returns the character unit carrying the specified flag.
 * 
 * @param flag           Name of the flag in the level
 * @return               Character unit index of flag carrier
 */
int GetFlagCarrier(const std::string& flag);

/**
 * Sets the map overall range (whatever that means). My guess is it's related to unit scan/transmit 
 * radar reporting. Either way, it doesn't appear to actually do anything.
 * 
 * @param range          Range in meters? (or maybe units in relation to minimap size)
 */
void SetMapRangeOverall(int range);

/**
 * Sets the map shooting range (whatever that means). My guess is it's related to unit scan/transmit 
 * radar reporting. Either way, it doesn't appear to actually do anything.
 * 
 * @param range          Range in meters? (or maybe units in relation to minimap size)
 */
void SetMapRangeShooting(int range);

/**
 * Sets the map range view cone (whatever that means). My guess is it's related to unit scan/transmit 
 * radar reporting. Either way, it doesn't appear to actually do anything.
 * 
 * @param range          Cone range in meters? (or maybe units in relation to minimap size)
 */
void SetMapRangeViewCone(int range);

/**
 * Sets the map view cone angle (whatever that means). My guess is it's related to unit scan/transmit 
 * radar reporting. Either way, it doesn't appear to actually do anything.
 * 
 * @param angle          Cone angle in degrees?
 */
void SetMapViewConeAngle(int angle);

/**
 * Removes the small minimap from the HUD.
 */
void DisableSmallMapMiniMap();

/**
 * Spawns a new instance of the specified particle effect and returns it.
 * 
 * @param effectFilename   Name of particle effect to instantiate
 * @return                 Particle effect instance
 */
void* CreateEffect(const std::string& effectFilename);

/**
 * Deletes the specified particle effect instance.
 * 
 * @param effect           Particle effect instance returned by CreateEffect
 */
void RemoveEffect(void* effect);

/**
 * Attaches the specified particle effect instance to the specified object.
 * 
 * @param effect           Particle effect instance returned by CreateEffect
 * @param object           ID of object to attach effect to
 */
void AttachEffectToObject(void* effect, const std::string& object);

/**
 * Attaches the specified particle effect instance to the specified matrix.
 * 
 * @param effect           Particle effect instance returned by CreateEffect
 * @param matrix           Matrix to attach effect to
 */
void AttachEffectToMatrix(void* effect, const std::string& matrix);

/**
 * Returns the matrix of the specified particle effect instance.
 * 
 * @param effect           Particle effect instance returned by CreateEffect
 * @return                 Effect matrix
 */
std::string GetEffectMatrix(void* effect);

/**
 * Sets the matrix of the specified particle effect instance.
 * 
 * @param effect           Particle effect instance returned by CreateEffect
 * @param matrix           Matrix to set for the effect
 */
void SetEffectMatrix(void* effect, const std::string& matrix);

/**
 * Returns whether or not the specified particle effect is active.
 * 
 * @param effect           Particle effect instance returned by CreateEffect
 * @return                 1 if effect is active, 0 if effect is inactive 
 */
int IsEffectActive(void* effect);

/**
 * Sets the state of the specified particle effect.
 * 
 * @param effect           Particle effect instance returned by CreateEffect
 * @param active           Set to 1 to activate effect, set to 0 to deactivate effect
 */
void SetEffectActive(void* effect, int active);

/**
 * Deregisters the specified event callback handler. 
 * 
 * For example, if you assign an event callback to a variable via 'playerDeathHandler = OnCharacterDeath(<...>)', 
 * calling 'ReleaseCharacterDeath(playerDeathHandler)' would stop the contents of whatever is in '<...>' from executing 
 * because the event callback's handler will have been removed from the list of event callbacks that should be executed 
 * when 'OnCharacterDeath' (or any one of its filter equivalents, such as 'OnCharacterDeathTeam', etc.) is triggered. 
 * 
 * When this is used, generally it's good practice to also dispose of the event handler by setting its variable to nil 
 * (e.g., 'playerDeathHandler = nil'). 
 * 
 * @param eventHandler     Event callback handler to deregister. NOTE: This must not be a local variable.
 */
void ReleaseCharacterDeath(void* eventHandler);

/**
 * This event occurs whenever a character (human or AI) dies.
 * 
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `player, killer`
 * @return                 Unique event callback handler
 */
void* OnCharacterDeath(const std::function<void(int player, int killer)>& callback);

/**
 * This event occurs whenever a character (human or AI) of the specified name dies.
 * 
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `player, killer`
 * @param nameStr          Character name
 * @return                 Unique event callback handler
 */
void* OnCharacterDeathName(const std::function<void(int player, int killer)>& callback, const std::string& nameStr);

/**
 * This event occurs whenever a character (human or AI) of the specified team dies.
 * 
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `player, killer`
 * @param teamIndex        Character team
 * @return                 Unique event callback handler
 */
void* OnCharacterDeathTeam(const std::function<void(int player, int killer)>& callback, int teamIndex);

/**
 * This event occurs whenever a character (human or AI) of the specified class dies.
 * 
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `player, killer`
 * @param configStr        Character class
 * @return                 Unique event callback handler
 */
void* OnCharacterDeathConfig(const std::function<void(int player, int killer)>& callback, const std::string& configStr);

/**
 * Deregisters the specified event callback handler. 
 * 
 * For example, if you assign an event callback to a variable via 'playerDeathHandler = OnCharacterDeath(<...>)', 
 * calling 'ReleaseCharacterDeath(playerDeathHandler)' would stop the contents of whatever is in '<...>' from executing 
 * because the event callback's handler will have been removed from the list of event callbacks that should be executed 
 * when 'OnCharacterDeath' (or any one of its filter equivalents, such as 'OnCharacterDeathTeam', etc.) is triggered. 
 * 
 * When this is used, generally it's good practice to also dispose of the event handler by setting its variable to nil 
 * (e.g., 'playerDeathHandler = nil'). 
 * 
 * @param eventHandler     Event callback handler to deregister. NOTE: This must not be a local variable.
 */
void ReleaseCharacterSpawn(void* eventHandler);

/**
 * This event occurs whenever a character (human or AI) spawns.
 * 
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `player`
 * @return                 Unique event callback handler
 */
void* OnCharacterSpawn(const std::function<void(int player)>& callback);

/**
 * This event occurs whenever a character (human or AI) of the specified name spawns.
 * 
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `player`
 * @param nameStr          Character name
 * @return                 Unique event callback handler
 */
void* OnCharacterSpawnName(const std::function<void(int player)>& callback, const std::string& nameStr);

/**
 * This event occurs whenever a character (human or AI) of the specified team spawns.
 * 
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `player`
 * @param teamIndex        Character team
 * @return                 Unique event callback handler
 */
void* OnCharacterSpawnTeam(const std::function<void(int player)>& callback, int teamIndex);

/**
 * This event occurs whenever a character (human or AI) of the specified class spawns.
 * 
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `player`
 * @param configStr        Character class
 * @return                 Unique event callback handler
 */
void* OnCharacterSpawnConfig(const std::function<void(int player)>& callback, const std::string& configStr);

/**
 * Deregisters the specified event callback handler. 
 * 
 * For example, if you assign an event callback to a variable via 'playerDeathHandler = OnCharacterDeath(<...>)', 
 * calling 'ReleaseCharacterDeath(playerDeathHandler)' would stop the contents of whatever is in '<...>' from executing 
 * because the event callback's handler will have been removed from the list of event callbacks that should be executed 
 * when 'OnCharacterDeath' (or any one of its filter equivalents, such as 'OnCharacterDeathTeam', etc.) is triggered. 
 * 
 * When this is used, generally it's good practice to also dispose of the event handler by setting its variable to nil 
 * (e.g., 'playerDeathHandler = nil'). 
 * 
 * @param eventHandler     Event callback handler to deregister. NOTE: This must not be a local variable.
 */
void ReleaseCharacterDispensePowerup(void* eventHandler);

/**
 * This event occurs whenever a character drops a health/ammo pickup.
 * 
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `player, powerup`
 * @return                 Unique event callback handler
 */
void* OnCharacterDispensePowerup(const std::function<void(int player, int powerup)>& callback);

/**
 * This event occurs whenever a character of the specified name drops a health/ammo pickup.
 * 
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `player, powerup`
 * @param nameStr          Character name
 * @return                 Unique event callback handler
 */
void* OnCharacterDispensePowerupName(const std::function<void(int player, int powerup)>& callback, const std::string& nameStr);

/**
 * This event occurs whenever a character of the specified team drops a health/ammo pickup.
 * 
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `player, powerup`
 * @param teamIndex        Character team
 * @return                 Unique event callback handler
 */
void* OnCharacterDispensePowerupTeam(const std::function<void(int player, int powerup)>& callback, int teamIndex);

/**
 * This event occurs whenever a character of the specified class drops a health/ammo pickup.
 * 
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `player, powerup`
 * @param configStr        Character class
 * @return                 Unique event callback handler
 */
void* OnCharacterDispensePowerupConfig(const std::function<void(int player, int powerup)>& callback, const std::string& configStr);

/**
 * Deregisters the specified event callback handler.
 *
 * For example, if you assign an event callback to a variable via 'playerDeathHandler = OnCharacterDeath(<...>)',
 * calling 'ReleaseCharacterDeath(playerDeathHandler)' would stop the contents of whatever is in '<...>' from
 * executing because the event callback's handler will have been removed from the list of event callbacks that
 * should be executed when 'OnCharacterDeath' (or any one of its filter equivalents, such as 'OnCharacterDeathTeam', etc.)
 * is triggered.
 *
 * When this is used, generally it's good practice to also dispose of the event handler by setting its variable to nil
 * (e.g., 'playerDeathHandler = nil').
 *
 * @param eventHandler     Event callback handler to deregister. NOTE: This must not be a local variable.
 */
void ReleaseCharacterDispenseControllable(void* eventHandler);

/**
 * This event occurs whenever a character drops a controllable item (such as a remote droid or a mini-turret).
 *
 * If you want to check exactly what kind of controllable was dropped, use 'GetEntityClassName(controllable)'.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `player, controllable`
 * @return                 Unique event callback handler
 */
void* OnCharacterDispenseControllable(const std::function<void(int player, int controllable)>& callback);

/**
 * This event occurs whenever a character of the specified name drops a controllable item (such as a remote droid or a mini-turret).
 *
 * If you want to check exactly what kind of controllable was dropped, use 'GetEntityClassName(controllable)'.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `player, controllable`
 * @param nameStr          Character name
 * @return                 Unique event callback handler
 */
void* OnCharacterDispenseControllableName(const std::function<void(int player, int controllable)>& callback, const std::string& nameStr);

/**
 * This event occurs whenever a character of the specified team drops a controllable item (such as a remote droid or a mini-turret).
 *
 * If you want to check exactly what kind of controllable was dropped, use 'GetEntityClassName(controllable)'.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `player, controllable`
 * @param teamIndex        Character team
 * @return                 Unique event callback handler
 */
void* OnCharacterDispenseControllableTeam(const std::function<void(int player, int controllable)>& callback, int teamIndex);

/**
 * This event occurs whenever a character of the specified class drops a controllable item (such as a remote droid or a mini-turret).
 *
 * If you want to check exactly what kind of controllable was dropped, use 'GetEntityClassName(controllable)'.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `player, controllable`
 * @param configStr        Character class
 * @return                 Unique event callback handler
 */
void* OnCharacterDispenseControllableConfig(const std::function<void(int player, int controllable)>& callback, const std::string& configStr);

/**
 * Deregisters the specified event callback handler.
 *
 * For example, if you assign an event callback to a variable via 'playerDeathHandler = OnCharacterDeath(<...>)',
 * calling 'ReleaseCharacterDeath(playerDeathHandler)' would stop the contents of whatever is in '<...>' from
 * executing because the event callback's handler will have been removed from the list of event callbacks that
 * should be executed when 'OnCharacterDeath' (or any one of its filter equivalents, such as 'OnCharacterDeathTeam', etc.)
 * is triggered.
 *
 * When this is used, generally it's good practice to also dispose of the event handler by setting its variable to nil
 * (e.g., 'playerDeathHandler = nil').
 *
 * @param eventHandler     Event callback handler to deregister. NOTE: This must not be a local variable.
 */
void ReleaseCharacterLandedFlyer(void* eventHandler);

/**
 * This event occurs whenever a character lands a flyer.
 *
 * If you wanted to check if the player landed within a region, use 'IsCharacterInRegion(player, "regionName")'.
 *
 * If you want to check if the flyer matches a particular type of flyer, use this:
 * `if GetEntityClass(flyer) == FindEntityClass("flyerClassName") then`
 * `    <blah blah insert code here>`
 * `end`
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `player, flyer`
 * @return                 Unique event callback handler
 */
void* OnCharacterLandedFlyer(const std::function<void(int player, int flyer)>& callback);

/**
 * This event occurs whenever a character of the specified name lands a flyer.
 *
 * If you wanted to check if the player landed within a region, use 'IsCharacterInRegion(player, "regionName")'.
 *
 * If you want to check if the flyer matches a particular type of flyer, use this:
 * `if GetEntityClass(flyer) == FindEntityClass("flyerClassName") then`
 * `    <blah blah insert code here>`
 * `end`
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `player, flyer`
 * @param nameStr          Character name
 * @return                 Unique event callback handler
 */
void* OnCharacterLandedFlyerName(const std::function<void(int player, int flyer)>& callback, const std::string& nameStr);

/**
 * This event occurs whenever a character of the specified team lands a flyer.
 *
 * If you wanted to check if the player landed within a region, use 'IsCharacterInRegion(player, "regionName")'.
 *
 * If you want to check if the flyer matches a particular type of flyer, use this:
 * `if GetEntityClass(flyer) == FindEntityClass("flyerClassName") then`
 * `    <blah blah insert code here>`
 * `end`
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `player, flyer`
 * @param teamIndex        Character team
 * @return                 Unique event callback handler
 */
void* OnCharacterLandedFlyerTeam(const std::function<void(int player, int flyer)>& callback, int teamIndex);

/**
 * This event occurs whenever a character of the specified class lands a flyer.
 *
 * If you wanted to check if the player landed within a region, use 'IsCharacterInRegion(player, "regionName")'.
 *
 * If you want to check if the flyer matches a particular type of flyer, use this:
 * `if GetEntityClass(flyer) == FindEntityClass("flyerClassName") then`
 * `    <blah blah insert code here>`
 * `end`
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `player, flyer`
 * @param configStr        Character class
 * @return                 Unique event callback handler
 */
void* OnCharacterLandedFlyerConfig(const std::function<void(int player, int flyer)>& callback, const std::string& configStr);

/**
 * Deregisters the specified event callback handler.
 *
 * For example, if you assign an event callback to a variable via 'playerDeathHandler = OnCharacterDeath(<...>)',
 * calling 'ReleaseCharacterDeath(playerDeathHandler)' would stop the contents of whatever is in '<...>' from
 * executing because the event callback's handler will have been removed from the list of event callbacks that
 * should be executed when 'OnCharacterDeath' (or any one of its filter equivalents, such as 'OnCharacterDeathTeam', etc.)
 * is triggered.
 *
 * When this is used, generally it's good practice to also dispose of the event handler by setting its variable to nil
 * (e.g., 'playerDeathHandler = nil').
 *
 * @param eventHandler     Event callback handler to deregister. NOTE: This must not be a local variable.
 */
void ReleaseCharacterEnterVehicle(void* eventHandler);

/**
 * This event occurs whenever a character enters a vehicle. It also works for turrets!
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `player, vehicle`
 * @return                 Unique event callback handler
 */
void* OnCharacterEnterVehicle(const std::function<void(int player, int vehicle)>& callback);

/**
 * This event occurs whenever a character of the specified name enters a vehicle. It also works for turrets!
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `player, vehicle`
 * @param nameStr          Character name
 * @return                 Unique event callback handler
 */
void* OnCharacterEnterVehicleName(const std::function<void(int player, int vehicle)>& callback, const std::string& nameStr);

/**
 * This event occurs whenever a character of the specified team enters a vehicle. It also works for turrets!
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `player, vehicle`
 * @param teamIndex        Character team
 * @return                 Unique event callback handler
 */
void* OnCharacterEnterVehicleTeam(const std::function<void(int player, int vehicle)>& callback, int teamIndex);

/**
 * This event occurs whenever a character of the specified class enters a vehicle. It also works for turrets!
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `player, vehicle`
 * @param configStr        Character class
 * @return                 Unique event callback handler
 */
void* OnCharacterEnterVehicleConfig(const std::function<void(int player, int vehicle)>& callback, const std::string& configStr);

/**
 * Deregisters the specified event callback handler.
 *
 * For example, if you assign an event callback to a variable via 'playerDeathHandler = OnCharacterDeath(<...>)',
 * calling 'ReleaseCharacterDeath(playerDeathHandler)' would stop the contents of whatever is in '<...>' from
 * executing because the event callback's handler will have been removed from the list of event callbacks that
 * should be executed when 'OnCharacterDeath' (or any one of its filter equivalents, such as 'OnCharacterDeathTeam', etc.)
 * is triggered.
 *
 * When this is used, generally it's good practice to also dispose of the event handler by setting its variable to nil
 * (e.g., 'playerDeathHandler = nil').
 *
 * @param eventHandler     Event callback handler to deregister. NOTE: This must not be a local variable.
 */
void ReleaseCharacterChangeClass(void* eventHandler);

/**
 * This event occurs whenever the player presses the OK button in the spawn display. It is not intended to be a robust thing
 * that can be used in either multiplayer or to check when the AI change classes.
 *
 * If you need to get the player's class, use 'GetCharacterClass(player)', which will return a class index.
 *
 * If you need the class name, you can use 'GetEntityClassName(GetCharacterUnit(player))'.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `player`
 * @return                 Unique event callback handler
 */
void* OnCharacterChangeClass(const std::function<void(int player)>& callback);

/**
 * This event occurs whenever the player of the specified name presses the OK button in the spawn display. It is not intended to be a robust thing
 * that can be used in either multiplayer or to check when the AI change classes.
 *
 * If you need to get the player's class, use 'GetCharacterClass(player)', which will return a class index.
 *
 * If you need the class name, you can use 'GetEntityClassName(GetCharacterUnit(player))'.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `player`
 * @param nameStr          Character name
 * @return                 Unique event callback handler
 */
void* OnCharacterChangeClassName(const std::function<void(int player)>& callback, const std::string& nameStr);

/**
 * This event occurs whenever the player of the specified team presses the OK button in the spawn display. It is not intended to be a robust thing
 * that can be used in either multiplayer or to check when the AI change classes.
 *
 * If you need to get the player's class, use 'GetCharacterClass(player)', which will return a class index.
 *
 * If you need the class name, you can use 'GetEntityClassName(GetCharacterUnit(player))'.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `player`
 * @param teamIndex        Character team
 * @return                 Unique event callback handler
 */
void* OnCharacterChangeClassTeam(const std::function<void(int player)>& callback, int teamIndex);

/**
 * This event occurs whenever the player of the specified class presses the OK button in the spawn display. It is not intended to be a robust thing
 * that can be used in either multiplayer or to check when the AI change classes.
 *
 * If you need to get the player's class, use 'GetCharacterClass(player)', which will return a class index.
 *
 * If you need the class name, you can use 'GetEntityClassName(GetCharacterUnit(player))'.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `player`
 * @param configStr        Character class
 * @return                 Unique event callback handler
 */
void* OnCharacterChangeClassConfig(const std::function<void(int player)>& callback, const std::string& configStr);

/**
 * Deregisters the specified event callback handler.
 *
 * For example, if you assign an event callback to a variable via 'playerDeathHandler = OnCharacterDeath(<...>)',
 * calling 'ReleaseCharacterDeath(playerDeathHandler)' would stop the contents of whatever is in '<...>' from
 * executing because the event callback's handler will have been removed from the list of event callbacks that
 * should be executed when 'OnCharacterDeath' (or any one of its filter equivalents, such as 'OnCharacterDeathTeam', etc.)
 * is triggered.
 *
 * When this is used, generally it's good practice to also dispose of the event handler by setting its variable to nil
 * (e.g., 'playerDeathHandler = nil').
 *
 * @param eventHandler     Event callback handler to deregister. NOTE: This must not be a local variable.
 */
void ReleaseCharacterIssueAICommand(void* eventHandler);

/**
 * This event occurs whenever a player issues a command to the AI. The command ID that is passed in must be translated into a string by
 * calling 'TranslateAICommand(command_id)'. This function will return one of the following strings:
 *
 *  'getintovehicle'
 *  'getoutofvehicle'
 *  'waitforpickup'
 *  'followchr'
 *  'stopfollowchr'
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `player, command_id`
 * @return                 Unique event callback handler
 */
void* OnCharacterIssueAICommand(const std::function<void(int player, int command_id)>& callback);

/**
 * This event occurs whenever a player of the specified name issues a command to the AI. The command ID that is passed in must be translated into a string by
 * calling 'TranslateAICommand(command_id)'. This function will return one of the following strings:
 *
 *  'getintovehicle'
 *  'getoutofvehicle'
 *  'waitforpickup'
 *  'followchr'
 *  'stopfollowchr'
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `player, command_id`
 * @param nameStr          Character name
 * @return                 Unique event callback handler
 */
void* OnCharacterIssueAICommandName(const std::function<void(int player, int command_id)>& callback, const std::string& nameStr);

/**
 * This event occurs whenever a player of the specified team issues a command to the AI. The command ID that is passed in must be translated into a string by
 * calling 'TranslateAICommand(command_id)'. This function will return one of the following strings:
 *
 *  'getintovehicle'
 *  'getoutofvehicle'
 *  'waitforpickup'
 *  'followchr'
 *  'stopfollowchr'
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `player, command_id`
 * @param teamIndex        Character team
 * @return                 Unique event callback handler
 */
void* OnCharacterIssueAICommandTeam(const std::function<void(int player, int command_id)>& callback, int teamIndex);

/**
 * This event occurs whenever a player of the specified class issues a command to the AI. The command ID that is passed in must be translated into a string by
 * calling 'TranslateAICommand(command_id)'. This function will return one of the following strings:
 *
 *  'getintovehicle'
 *  'getoutofvehicle'
 *  'waitforpickup'
 *  'followchr'
 *  'stopfollowchr'
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `player, command_id`
 * @param configStr        Character class
 * @return                 Unique event callback handler
 */
void* OnCharacterIssueAICommandConfig(const std::function<void(int player, int command_id)>& callback, const std::string& configStr);

// EVENT CALLBACKS :: Command Post

// BeginNeutralize

/**
 * Deregisters the specified event callback handler.
 *
 * For example, if you assign an event callback to a variable via 'playerDeathHandler = OnCharacterDeath(<...>)',
 * calling 'ReleaseCharacterDeath(playerDeathHandler)' would stop the contents of whatever is in '<...>' from
 * executing because the event callback's handler will have been removed from the list of event callbacks that
 * should be executed when 'OnCharacterDeath' (or any one of its filter equivalents, such as 'OnCharacterDeathTeam', etc.)
 * is triggered.
 *
 * When this is used, generally it's good practice to also dispose of the event handler by setting its variable to nil
 * (e.g., 'playerDeathHandler = nil').
 *
 * @param eventHandler     Event callback handler to deregister. NOTE: This must not be a local variable.
 */
void ReleaseBeginNeutralize(void* eventHandler);

/**
 * Actor: post
 * Context: holding (table of characters)
 *
 * This Event occurs when an enemy unit begins neutralizing a Command Post.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `post, holding`
 * @return                 Unique event callback handler
 */
void* OnBeginNeutralize(const std::function<void(int post, const std::vector<int>& holding)>& callback);

/**
 * Actor: post
 * Context: holding (table of characters)
 *
 * This Event occurs when an enemy unit begins neutralizing a Command Post of the specified name.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `post, holding`
 * @param nameStr          Command Post name
 * @return                 Unique event callback handler
 */
void* OnBeginNeutralizeName(const std::function<void(int post, const std::vector<int>& holding)>& callback, const std::string& nameStr);

/**
 * Actor: post
 * Context: holding (table of characters)
 *
 * This Event occurs when an enemy unit begins neutralizing a Command Post of the specified team.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `post, holding`
 * @param teamIndex        Command Post team
 * @return                 Unique event callback handler
 */
void* OnBeginNeutralizeTeam(const std::function<void(int post, const std::vector<int>& holding)>& callback, int teamIndex);

// AbortNeutralize

/**
 * Deregisters the specified event callback handler.
 *
 * For example, if you assign an event callback to a variable via 'playerDeathHandler = OnCharacterDeath(<...>)',
 * calling 'ReleaseCharacterDeath(playerDeathHandler)' would stop the contents of whatever is in '<...>' from
 * executing because the event callback's handler will have been removed from the list of event callbacks that
 * should be executed when 'OnCharacterDeath' (or any one of its filter equivalents, such as 'OnCharacterDeathTeam', etc.)
 * is triggered.
 *
 * When this is used, generally it's good practice to also dispose of the event handler by setting its variable to nil
 * (e.g., 'playerDeathHandler = nil').
 *
 * @param eventHandler     Event callback handler to deregister. NOTE: This must not be a local variable.
 */
void ReleaseAbortNeutralize(void* eventHandler);

/**
 * Actor: post
 * Context: holding (table of characters)
 *
 * This Event occurs when an enemy unit stops neutralizing a Command Post.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `post, holding`
 * @return                 Unique event callback handler
 */
void* OnAbortNeutralize(const std::function<void(int post, const std::vector<int>& holding)>& callback);

/**
 * Actor: post
 * Context: holding (table of characters)
 *
 * This Event occurs when an enemy unit stops neutralizing a Command Post of the specified name.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `post, holding`
 * @param nameStr          Command Post name
 * @return                 Unique event callback handler
 */
void* OnAbortNeutralizeName(const std::function<void(int post, const std::vector<int>& holding)>& callback, const std::string& nameStr);

/**
 * Actor: post
 * Context: holding (table of characters)
 *
 * This Event occurs when an enemy unit stops neutralizing a Command Post of the specified team.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `post, holding`
 * @param teamIndex        Command Post team
 * @return                 Unique event callback handler
 */
void* OnAbortNeutralizeTeam(const std::function<void(int post, const std::vector<int>& holding)>& callback, int teamIndex);

// FinishNeutralize

/**
 * Deregisters the specified event callback handler.
 *
 * For example, if you assign an event callback to a variable via 'playerDeathHandler = OnCharacterDeath(<...>)',
 * calling 'ReleaseCharacterDeath(playerDeathHandler)' would stop the contents of whatever is in '<...>' from
 * executing because the event callback's handler will have been removed from the list of event callbacks that
 * should be executed when 'OnCharacterDeath' (or any one of its filter equivalents, such as 'OnCharacterDeathTeam', etc.)
 * is triggered.
 *
 * When this is used, generally it's good practice to also dispose of the event handler by setting its variable to nil
 * (e.g., 'playerDeathHandler = nil').
 *
 * @param eventHandler     Event callback handler to deregister. NOTE: This must not be a local variable.
 */
void ReleaseFinishNeutralize(void* eventHandler);

/**
 * Actor: post
 * Context: holding (table of characters)
 *
 * This Event occurs when an enemy unit finishes neutralizing a Command Post.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `post, holding`
 * @return                 Unique event callback handler
 */
void* OnFinishNeutralize(const std::function<void(int post, const std::vector<int>& holding)>& callback);

/**
 * Actor: post
 * Context: holding (table of characters)
 *
 * This Event occurs when an enemy unit finishes neutralizing a Command Post of the specified name.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `post, holding`
 * @param nameStr          Command Post name
 * @return                 Unique event callback handler
 */
void* OnFinishNeutralizeName(const std::function<void(int post, const std::vector<int>& holding)>& callback, const std::string& nameStr);

/**
 * Actor: post
 * Context: holding (table of characters)
 *
 * This Event occurs when an enemy unit finishes neutralizing a Command Post of the specified team.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `post, holding`
 * @param teamIndex        Command Post team
 * @return                 Unique event callback handler
 */
void* OnFinishNeutralizeTeam(const std::function<void(int post, const std::vector<int>& holding)>& callback, int teamIndex);

// BeginCapture

/**
 * Deregisters the specified event callback handler.
 *
 * For example, if you assign an event callback to a variable via 'playerDeathHandler = OnCharacterDeath(<...>)',
 * calling 'ReleaseCharacterDeath(playerDeathHandler)' would stop the contents of whatever is in '<...>' from
 * executing because the event callback's handler will have been removed from the list of event callbacks that
 * should be executed when 'OnCharacterDeath' (or any one of its filter equivalents, such as 'OnCharacterDeathTeam', etc.)
 * is triggered.
 *
 * When this is used, generally it's good practice to also dispose of the event handler by setting its variable to nil
 * (e.g., 'playerDeathHandler = nil').
 *
 * @param eventHandler     Event callback handler to deregister. NOTE: This must not be a local variable.
 */
void ReleaseBeginCapture(void* eventHandler);

/**
 * Actor: post
 * Context: holding (table of characters)
 *
 * This Event occurs when a unit begins capturing a neutral Command Post.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `post, holding`
 * @return                 Unique event callback handler
 */
void* OnBeginCapture(const std::function<void(int post, const std::vector<int>& holding)>& callback);

/**
 * Actor: post
 * Context: holding (table of characters)
 *
 * This Event occurs when a unit begins capturing a neutral Command Post of the specified name.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `post, holding`
 * @param nameStr          Command Post name
 * @return                 Unique event callback handler
 */
void* OnBeginCaptureName(const std::function<void(int post, const std::vector<int>& holding)>& callback, const std::string& nameStr);

/**
 * Actor: post
 * Context: holding (table of characters)
 *
 * This Event occurs when a unit begins capturing a neutral Command Post of the specified team.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `post, holding`
 * @param teamIndex        Command Post team
 * @return                 Unique event callback handler
 */
void* OnBeginCaptureTeam(const std::function<void(int post, const std::vector<int>& holding)>& callback, int teamIndex);

// EVENT CALLBACKS :: Command Post

// AbortCapture

/**
 * Deregisters the specified event callback handler.
 *
 * For example, if you assign an event callback to a variable via 'playerDeathHandler = OnCharacterDeath(<...>)',
 * calling 'ReleaseCharacterDeath(playerDeathHandler)' would stop the contents of whatever is in '<...>' from
 * executing because the event callback's handler will have been removed from the list of event callbacks that
 * should be executed when 'OnCharacterDeath' (or any one of its filter equivalents, such as 'OnCharacterDeathTeam', etc.)
 * is triggered.
 *
 * When this is used, generally it's good practice to also dispose of the event handler by setting its variable to nil
 * (e.g., 'playerDeathHandler = nil').
 *
 * @param eventHandler     Event callback handler to deregister. NOTE: This must not be a local variable.
 */
void ReleaseAbortCapture(void* eventHandler);

/**
 * Actor: post
 * Context: holding (table of characters)
 *
 * This Event occurs when a unit stops capturing a neutral Command Post.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `post, holding`
 * @return                 Unique event callback handler
 */
void* OnAbortCapture(const std::function<void(int post, const std::vector<int>& holding)>& callback);

/**
 * Actor: post
 * Context: holding (table of characters)
 *
 * This Event occurs when a unit stops capturing a neutral Command Post of the specified name.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `post, holding`
 * @param nameStr          Command Post name
 * @return                 Unique event callback handler
 */
void* OnAbortCaptureName(const std::function<void(int post, const std::vector<int>& holding)>& callback, const std::string& nameStr);

/**
 * Actor: post
 * Context: holding (table of characters)
 *
 * This Event occurs when a unit stops capturing a neutral Command Post of the specified team.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `post, holding`
 * @param teamIndex        Command Post team
 * @return                 Unique event callback handler
 */
void* OnAbortCaptureTeam(const std::function<void(int post, const std::vector<int>& holding)>& callback, int teamIndex);

// FinishCapture

/**
 * Deregisters the specified event callback handler.
 *
 * For example, if you assign an event callback to a variable via 'playerDeathHandler = OnCharacterDeath(<...>)',
 * calling 'ReleaseCharacterDeath(playerDeathHandler)' would stop the contents of whatever is in '<...>' from
 * executing because the event callback's handler will have been removed from the list of event callbacks that
 * should be executed when 'OnCharacterDeath' (or any one of its filter equivalents, such as 'OnCharacterDeathTeam', etc.)
 * is triggered.
 *
 * When this is used, generally it's good practice to also dispose of the event handler by setting its variable to nil
 * (e.g., 'playerDeathHandler = nil').
 *
 * @param eventHandler     Event callback handler to deregister. NOTE: This must not be a local variable.
 */
void ReleaseFinishCapture(void* eventHandler);

/**
 * Actor: post
 * Context: holding (table of characters)
 *
 * This Event occurs when a unit finishes capturing a neutral Command Post.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `post, holding`
 * @return                 Unique event callback handler
 */
void* OnFinishCapture(const std::function<void(int post, const std::vector<int>& holding)>& callback);

/**
 * Actor: post
 * Context: holding (table of characters)
 *
 * This Event occurs when a unit finishes capturing a neutral Command Post of the specified name.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `post, holding`
 * @param nameStr          Command Post name
 * @return                 Unique event callback handler
 */
void* OnFinishCaptureName(const std::function<void(int post, const std::vector<int>& holding)>& callback, const std::string& nameStr);

/**
 * Actor: post
 * Context: holding (table of characters)
 *
 * This Event occurs when a unit finishes capturing a neutral Command Post of the specified team.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `post, holding`
 * @param teamIndex        Command Post team
 * @return                 Unique event callback handler
 */
void* OnFinishCaptureTeam(const std::function<void(int post, const std::vector<int>& holding)>& callback, int teamIndex);

// CommandPostKill

/**
 * Deregisters the specified event callback handler.
 *
 * For example, if you assign an event callback to a variable via 'playerDeathHandler = OnCharacterDeath(<...>)',
 * calling 'ReleaseCharacterDeath(playerDeathHandler)' would stop the contents of whatever is in '<...>' from
 * executing because the event callback's handler will have been removed from the list of event callbacks that
 * should be executed when 'OnCharacterDeath' (or any one of its filter equivalents, such as 'OnCharacterDeathTeam', etc.)
 * is triggered.
 *
 * When this is used, generally it's good practice to also dispose of the event handler by setting its variable to nil
 * (e.g., 'playerDeathHandler = nil').
 *
 * @param eventHandler     Event callback handler to deregister. NOTE: This must not be a local variable.
 */
void ReleaseCommandPostKill(void* eventHandler);

/**
 * Actor: post
 * Context: killer (character)
 *
 * This Event occurs when a Command Post dies.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `post, killer`
 * @return                 Unique event callback handler
 */
void* OnCommandPostKill(const std::function<void(int post, int killer)>& callback);

/**
 * Actor: post
 * Context: killer (character)
 *
 * This Event occurs when a Command Post of the specified name dies.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `post, killer`
 * @param nameStr          Command Post name
 * @return                 Unique event callback handler
 */
void* OnCommandPostKillName(const std::function<void(int post, int killer)>& callback, const std::string& nameStr);

/**
 * Actor: post
 * Context: killer (character)
 *
 * This Event occurs when a Command Post of the specified team dies.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `post, killer`
 * @param teamIndex        Command Post team
 * @return                 Unique event callback handler
 */
void* OnCommandPostKillTeam(const std::function<void(int post, int killer)>& callback, int teamIndex);

// CommandPostRespawn

/**
 * Deregisters the specified event callback handler.
 *
 * For example, if you assign an event callback to a variable via 'playerDeathHandler = OnCharacterDeath(<...>)',
 * calling 'ReleaseCharacterDeath(playerDeathHandler)' would stop the contents of whatever is in '<...>' from
 * executing because the event callback's handler will have been removed from the list of event callbacks that
 * should be executed when 'OnCharacterDeath' (or any one of its filter equivalents, such as 'OnCharacterDeathTeam', etc.)
 * is triggered.
 *
 * When this is used, generally it's good practice to also dispose of the event handler by setting its variable to nil
 * (e.g., 'playerDeathHandler = nil').
 *
 * @param eventHandler     Event callback handler to deregister. NOTE: This must not be a local variable.
 */
void ReleaseCommandPostRespawn(void* eventHandler);

/**
 * Actor: post
 * Context: none
 *
 * This Event occurs when a Command Post spawns or respawns.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `post`
 * @return                 Unique event callback handler
 */
void* OnCommandPostRespawn(const std::function<void(int post)>& callback);

/**
 * Actor: post
 * Context: none
 *
 * This Event occurs when a Command Post of the specified name spawns or respawns.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `post`
 * @param nameStr          Command Post name
 * @return                 Unique event callback handler
 */
void* OnCommandPostRespawnName(const std::function<void(int post)>& callback, const std::string& nameStr);

/**
 * Actor: post
 * Context: none
 *
 * This Event occurs when a Command Post of the specified team spawns or respawns.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `post`
 * @param teamIndex        Command Post team
 * @return                 Unique event callback handler
 */
void* OnCommandPostRespawnTeam(const std::function<void(int post)>& callback, int teamIndex);

// EVENT CALLBACKS :: Flag

// FlagPickUp

/**
 * Deregisters the specified event callback handler.
 *
 * For example, if you assign an event callback to a variable via 'playerDeathHandler = OnCharacterDeath(<...>)',
 * calling 'ReleaseCharacterDeath(playerDeathHandler)' would stop the contents of whatever is in '<...>' from
 * executing because the event callback's handler will have been removed from the list of event callbacks that
 * should be executed when 'OnCharacterDeath' (or any one of its filter equivalents, such as 'OnCharacterDeathTeam', etc.)
 * is triggered.
 *
 * When this is used, generally it's good practice to also dispose of the event handler by setting its variable to nil
 * (e.g., 'playerDeathHandler = nil').
 *
 * @param eventHandler     Event callback handler to deregister. NOTE: This must not be a local variable.
 */
void ReleaseFlagPickUp(void* eventHandler);

/**
 * Actor: flag
 * Context: character
 *
 * This Event occurs when a character picks up a Flag.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `flag, character`
 * @return                 Unique event callback handler
 */
void* OnFlagPickUp(const std::function<void(int flag, int character)>& callback);

/**
 * Actor: flag
 * Context: character
 *
 * This Event occurs when a character of the specified name picks up a Flag.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `flag, character`
 * @param nameStr          Character name
 * @return                 Unique event callback handler
 */
void* OnFlagPickUpName(const std::function<void(int flag, int character)>& callback, const std::string& nameStr);

/**
 * Actor: flag
 * Context: character
 *
 * This Event occurs when a character of the specified team picks up a Flag.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `flag, character`
 * @param teamIndex        Character team
 * @return                 Unique event callback handler
 */
void* OnFlagPickUpTeam(const std::function<void(int flag, int character)>& callback, int teamIndex);

/**
 * Actor: flag
 * Context: character
 *
 * This Event occurs when a character of the specified class picks up a Flag.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `flag, character`
 * @param configStr        Character config
 * @return                 Unique event callback handler
 */
void* OnFlagPickUpConfig(const std::function<void(int flag, int character)>& callback, const std::string& configStr);

// FlagDrop

/**
 * Deregisters the specified event callback handler.
 *
 * For example, if you assign an event callback to a variable via 'playerDeathHandler = OnCharacterDeath(<...>)',
 * calling 'ReleaseCharacterDeath(playerDeathHandler)' would stop the contents of whatever is in '<...>' from
 * executing because the event callback's handler will have been removed from the list of event callbacks that
 * should be executed when 'OnCharacterDeath' (or any one of its filter equivalents, such as 'OnCharacterDeathTeam', etc.)
 * is triggered.
 *
 * When this is used, generally it's good practice to also dispose of the event handler by setting its variable to nil
 * (e.g., 'playerDeathHandler = nil').
 *
 * @param eventHandler     Event callback handler to deregister. NOTE: This must not be a local variable.
 */
void ReleaseFlagDrop(void* eventHandler);

/**
 * Actor: flag
 * Context: character
 *
 * This Event occurs when a character drops a Flag.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `flag, character`
 * @return                 Unique event callback handler
 */
void* OnFlagDrop(const std::function<void(int flag, int character)>& callback);

/**
 * Actor: flag
 * Context: character
 *
 * This Event occurs when a character of the specified name drops a Flag.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `flag, character`
 * @param nameStr          Character name
 * @return                 Unique event callback handler
 */
void* OnFlagDropName(const std::function<void(int flag, int character)>& callback, const std::string& nameStr);

/**
 * Actor: flag
 * Context: character
 *
 * This Event occurs when a character of the specified team drops a Flag.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `flag, character`
 * @param teamIndex        Character team
 * @return                 Unique event callback handler
 */
void* OnFlagDropTeam(const std::function<void(int flag, int character)>& callback, int teamIndex);

/**
 * Actor: flag
 * Context: character
 *
 * This Event occurs when a character of the specified class drops a Flag.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `flag, character`
 * @param configStr        Character config
 * @return                 Unique event callback handler
 */
void* OnFlagDropConfig(const std::function<void(int flag, int character)>& callback, const std::string& configStr);

// FlagReturn

/**
 * Deregisters the specified event callback handler.
 *
 * For example, if you assign an event callback to a variable via 'playerDeathHandler = OnCharacterDeath(<...>)',
 * calling 'ReleaseCharacterDeath(playerDeathHandler)' would stop the contents of whatever is in '<...>' from
 * executing because the event callback's handler will have been removed from the list of event callbacks that
 * should be executed when 'OnCharacterDeath' (or any one of its filter equivalents, such as 'OnCharacterDeathTeam', etc.)
 * is triggered.
 *
 * When this is used, generally it's good practice to also dispose of the event handler by setting its variable to nil
 * (e.g., 'playerDeathHandler = nil').
 *
 * @param eventHandler     Event callback handler to deregister. NOTE: This must not be a local variable.
 */
void ReleaseFlagReturn(void* eventHandler);

/**
 * Actor: flag
 * Context: character
 *
 * This Event occurs when a character returns an allied Flag.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `flag, character`
 * @return                 Unique event callback handler
 */
void* OnFlagReturn(const std::function<void(int flag, int character)>& callback);

/**
 * Actor: flag
 * Context: character
 *
 * This Event occurs when a character of the specified name returns an allied Flag.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `flag, character`
 * @param nameStr          Character name
 * @return                 Unique event callback handler
 */
void* OnFlagReturnName(const std::function<void(int flag, int character)>& callback, const std::string& nameStr);

/**
 * Actor: flag
 * Context: character
 *
 * This Event occurs when a character of the specified team returns an allied Flag.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `flag, character`
 * @param teamIndex        Character team
 * @return                 Unique event callback handler
 */
void* OnFlagReturnTeam(const std::function<void(int flag, int character)>& callback, int teamIndex);

/**
 * Actor: flag
 * Context: character
 *
 * This Event occurs when a character of the specified class returns an allied Flag.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `flag, character`
 * @param configStr        Character config
 * @return                 Unique event callback handler
 */
void* OnFlagReturnConfig(const std::function<void(int flag, int character)>& callback, const std::string& configStr);

// FlagCapture

/**
 * Deregisters the specified event callback handler.
 *
 * For example, if you assign an event callback to a variable via 'playerDeathHandler = OnCharacterDeath(<...>)',
 * calling 'ReleaseCharacterDeath(playerDeathHandler)' would stop the contents of whatever is in '<...>' from
 * executing because the event callback's handler will have been removed from the list of event callbacks that
 * should be executed when 'OnCharacterDeath' (or any one of its filter equivalents, such as 'OnCharacterDeathTeam', etc.)
 * is triggered.
 *
 * When this is used, generally it's good practice to also dispose of the event handler by setting its variable to nil
 * (e.g., 'playerDeathHandler = nil').
 *
 * @param eventHandler     Event callback handler to deregister. NOTE: This must not be a local variable.
 */
void ReleaseFlagCapture(void* eventHandler);

/**
 * Actor: flag
 * Context: character
 *
 * This Event occurs when a character captures a neutral or enemy Flag.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `flag, character`
 * @return                 Unique event callback handler
 */
void* OnFlagCapture(const std::function<void(int flag, int character)>& callback);

/**
 * Actor: flag
 * Context: character
 *
 * This Event occurs when a character of the specified name captures a neutral or enemy Flag.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `flag, character`
 * @param nameStr          Character name
 * @return                 Unique event callback handler
 */
void* OnFlagCaptureName(const std::function<void(int flag, int character)>& callback, const std::string& nameStr);

/**
 * Actor: flag
 * Context: character
 *
 * This Event occurs when a character of the specified team captures a neutral or enemy Flag.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `flag, character`
 * @param teamIndex        Character team
 * @return                 Unique event callback handler
 */
void* OnFlagCaptureTeam(const std::function<void(int flag, int character)>& callback, int teamIndex);

/**
 * Actor: flag
 * Context: character
 *
 * This Event occurs when a character of the specified class captures a neutral or enemy Flag.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `flag, character`
 * @param configStr        Character config
 * @return                 Unique event callback handler
 */
void* OnFlagCaptureConfig(const std::function<void(int flag, int character)>& callback, const std::string& configStr);

// EVENT CALLBACKS :: Object

// ObjectCreate

/**
 * Deregisters the specified event callback handler.
 *
 * For example, if you assign an event callback to a variable via 'playerDeathHandler = OnCharacterDeath(<...>)',
 * calling 'ReleaseCharacterDeath(playerDeathHandler)' would stop the contents of whatever is in '<...>' from
 * executing because the event callback's handler will have been removed from the list of event callbacks that
 * should be executed when 'OnCharacterDeath' (or any one of its filter equivalents, such as 'OnCharacterDeathTeam', etc.)
 * is triggered.
 *
 * When this is used, generally it's good practice to also dispose of the event handler by setting its variable to nil
 * (e.g., 'playerDeathHandler = nil').
 *
 * @param eventHandler     Event callback handler to deregister. NOTE: This must not be a local variable.
 */
void ReleaseObjectCreate(void* eventHandler);

/**
 * Actor: object
 * Context: none
 *
 * This Event occurs on the creation of an Object, before setting its properties.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `object`
 * @return                 Unique event callback handler
 */
void* OnObjectCreate(const std::function<void(int object)>& callback);

/**
 * Actor: object
 * Context: none
 *
 * This Event occurs on the creation of an Object of the specified name, before setting its properties.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `object`
 * @param nameStr          Object name
 * @return                 Unique event callback handler
 */
void* OnObjectCreateName(const std::function<void(int object)>& callback, const std::string& nameStr);

/**
 * Actor: object
 * Context: none
 *
 * This Event occurs on the creation of an Object of the specified team, before setting its properties.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `object`
 * @param teamIndex        Object team
 * @return                 Unique event callback handler
 */
void* OnObjectCreateTeam(const std::function<void(int object)>& callback, int teamIndex);

/**
 * Actor: object
 * Context: none
 *
 * This Event occurs on the creation of an Object of the specified class, before setting its properties.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `object`
 * @param configStr        Object config
 * @return                 Unique event callback handler
 */
void* OnObjectCreateConfig(const std::function<void(int object)>& callback, const std::string& configStr);

// ObjectInit

/**
 * Deregisters the specified event callback handler.
 *
 * For example, if you assign an event callback to a variable via 'playerDeathHandler = OnCharacterDeath(<...>)',
 * calling 'ReleaseCharacterDeath(playerDeathHandler)' would stop the contents of whatever is in '<...>' from
 * executing because the event callback's handler will have been removed from the list of event callbacks that
 * should be executed when 'OnCharacterDeath' (or any one of its filter equivalents, such as 'OnCharacterDeathTeam', etc.)
 * is triggered.
 *
 * When this is used, generally it's good practice to also dispose of the event handler by setting its variable to nil
 * (e.g., 'playerDeathHandler = nil').
 *
 * @param eventHandler     Event callback handler to deregister. NOTE: This must not be a local variable.
 */
void ReleaseObjectInit(void* eventHandler);

/**
 * Actor: object
 * Context: none
 *
 * This Event occurs on the initialization of an Object, after settings its properties.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `object`
 * @return                 Unique event callback handler
 */
void* OnObjectInit(const std::function<void(int object)>& callback);

/**
 * Actor: object
 * Context: none
 *
 * This Event occurs on the initialization of an Object of the specified name, after settings its properties.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `object`
 * @param nameStr          Object name
 * @return                 Unique event callback handler
 */
void* OnObjectInitName(const std::function<void(int object)>& callback, const std::string& nameStr);

/**
 * Actor: object
 * Context: none
 *
 * This Event occurs on the initialization of an Object of the specified team, after settings its properties.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `object`
 * @param teamIndex        Object team
 * @return                 Unique event callback handler
 */
void* OnObjectInitTeam(const std::function<void(int object)>& callback, int teamIndex);

/**
 * Actor: object
 * Context: none
 *
 * This Event occurs on the initialization of an Object of the specified class, after settings its properties.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `object`
 * @param configStr        Object config
 * @return                 Unique event callback handler
 */
void* OnObjectInitConfig(const std::function<void(int object)>& callback, const std::string& configStr);

// ObjectDamage

/**
 * Deregisters the specified event callback handler.
 *
 * For example, if you assign an event callback to a variable via 'playerDeathHandler = OnCharacterDeath(<...>)',
 * calling 'ReleaseCharacterDeath(playerDeathHandler)' would stop the contents of whatever is in '<...>' from
 * executing because the event callback's handler will have been removed from the list of event callbacks that
 * should be executed when 'OnCharacterDeath' (or any one of its filter equivalents, such as 'OnCharacterDeathTeam', etc.)
 * is triggered.
 *
 * When this is used, generally it's good practice to also dispose of the event handler by setting its variable to nil
 * (e.g., 'playerDeathHandler = nil').
 *
 * @param eventHandler     Event callback handler to deregister. NOTE: This must not be a local variable.
 */
void ReleaseObjectDamage(void* eventHandler);

/**
 * Actor: object
 * Context: damager (character)
 *
 * This Event occurs whenever an Object takes damage.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `object, damager`
 * @return                 Unique event callback handler
 */
void* OnObjectDamage(const std::function<void(int object, int damager)>& callback);

/**
 * Actor: object
 * Context: damager (character)
 *
 * This Event occurs whenever an Object of the specified name takes damage.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `object, damager`
 * @param nameStr          Object name
 * @return                 Unique event callback handler
 */
void* OnObjectDamageName(const std::function<void(int object, int damager)>& callback, const std::string& nameStr

);

/**
 * Actor: object
 * Context: damager (character)
 *
 * This Event occurs whenever an Object of the specified team takes damage.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `object, damager`
 * @param teamIndex        Object team
 * @return                 Unique event callback handler
 */
void* OnObjectDamageTeam(const std::function<void(int object, int damager)>& callback, int teamIndex);

/**
 * Actor: object
 * Context: damager (character)
 *
 * This Event occurs whenever an Object of the specified class takes damage.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `object, damager`
 * @param configStr        Object config
 * @return                 Unique event callback handler
 */
void* OnObjectDamageConfig(const std::function<void(int object, int damager)>& callback, const std::string& configStr);

// ObjectRepair

/**
 * Deregisters the specified event callback handler.
 *
 * For example, if you assign an event callback to a variable via 'playerDeathHandler = OnCharacterDeath(<...>)',
 * calling 'ReleaseCharacterDeath(playerDeathHandler)' would stop the contents of whatever is in '<...>' from
 * executing because the event callback's handler will have been removed from the list of event callbacks that
 * should be executed when 'OnCharacterDeath' (or any one of its filter equivalents, such as 'OnCharacterDeathTeam', etc.)
 * is triggered.
 *
 * When this is used, generally it's good practice to also dispose of the event handler by setting its variable to nil
 * (e.g., 'playerDeathHandler = nil').
 *
 * @param eventHandler     Event callback handler to deregister. NOTE: This must not be a local variable.
 */
void ReleaseObjectRepair(void* eventHandler);

/**
 * Actor: object
 * Context: repairer (character)
 *
 * This event occurs when a character finishes repairing an Object. Also conveniently works for checking when a player has built a repair/ammo droid from one of those build pads.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `object, repairer`
 * @return                 Unique event callback handler
 */
void* OnObjectRepair(const std::function<void(int object, int repairer)>& callback);

/**
 * Actor: object
 * Context: repairer (character)
 *
 * This event occurs when a character finishes repairing an Object of the specified name. Also conveniently works for checking when a player has built a repair/ammo droid from one of those build pads.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `object, repairer`
 * @param nameStr          Object name
 * @return                 Unique event callback handler
 */
void* OnObjectRepairName(const std::function<void(int object, int repairer)>& callback, const std::string& nameStr);

/**
 * Actor: object
 * Context: repairer (character)
 *
 * This event occurs when a character finishes repairing an Object of the specified team. Also conveniently works for checking when a player has built a repair/ammo droid from one of those build pads.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `object, repairer`
 * @param teamIndex        Object team
 * @return                 Unique event callback handler
 */
void* OnObjectRepairTeam(const std::function<void(int object, int repairer)>& callback, int teamIndex);

/**
 * Actor: object
 * Context: repairer (character)
 *
 * This event occurs when a character finishes repairing an Object of the specified class. Also conveniently works for checking when a player has built a repair/ammo droid from one of those build pads.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `object, repairer`
 * @param configStr        Object config
 * @return                 Unique event callback handler
 */
void* OnObjectRepairConfig(const std::function<void(int object, int repairer)>& callback, const std::string& configStr);

// ObjectHack

/**
 * Deregisters the specified event callback handler.
 *
 * For example, if you assign an event callback to a variable via 'playerDeathHandler = OnCharacterDeath(<...>)',
 * calling 'ReleaseCharacterDeath(playerDeathHandler)' would stop the contents of whatever is in '<...>' from
 * executing because the event callback's handler will have been removed from the list of event callbacks that
 * should be executed when 'OnCharacterDeath' (or any one of its filter equivalents, such as 'OnCharacterDeathTeam', etc.)
 * is triggered.
 *
 * When this is used, generally it's good practice to also dispose of the event handler by setting its variable to nil
 * (e.g., 'playerDeathHandler = nil').
 *
 * @param eventHandler     Event callback handler to deregister. NOTE: This must not be a local variable.
 */
void ReleaseObjectHack(void* eventHandler);

/**
 * Actor: object
 * Context: hacker (character)
 *
 * This Event occurs whenever a character hacks an Object (which is our nomenclature for kicking dudes out of a vehicle with the fusion cutter... makes sense to me).
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `object, hacker`
 * @return                 Unique event callback handler
 */
void* OnObjectHack(const std::function<void(int object, int hacker)>& callback);

/**
 * Actor: object
 * Context: hacker (character)
 *
 * This Event occurs whenever a character hacks an Object of the specified name (which is our nomenclature for kicking dudes out of a vehicle with the fusion cutter... makes sense to me).
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `object, hacker`
 * @param nameStr          Object name
 * @return                 Unique event callback handler
 */
void* OnObjectHackName(const std::function<void(int object, int hacker)>& callback, const std::string& nameStr);

/**
 * Actor: object
 * Context: hacker (character)
 *
 * This Event occurs whenever a character hacks an Object of the specified team (which is our nomenclature for kicking dudes out of a vehicle with the fusion cutter... makes sense to me).
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `object, hacker`
 * @param teamIndex        Object team
 * @return                 Unique event callback handler
 */
void* OnObjectHackTeam(const std::function<void(int object, int hacker)>& callback, int teamIndex);

/**
 * Actor: object
 * Context: hacker (character)
 *
 * This Event occurs whenever a character hacks an Object of the specified class (which is our nomenclature for kicking dudes out of a vehicle with the fusion cutter... makes sense to me).
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `object, hacker`
 * @param configStr        Object config
 * @return                 Unique event callback handler
 */
void* OnObjectHackConfig(const std::function<void(int object, int hacker)>& callback, const std::string& configStr);

// ObjectKill

/**
 * Deregisters the specified event callback handler.
 *
 * For example, if you assign an event callback to a variable via 'playerDeathHandler = OnCharacterDeath(<...>)',
 * calling 'ReleaseCharacterDeath(playerDeathHandler)' would stop the contents of whatever is in '<...>' from
 * executing because the event callback's handler will have been removed from the list of event callbacks that
 * should be executed when 'OnCharacterDeath' (or any one of its filter equivalents, such as 'OnCharacterDeathTeam', etc.)
 * is triggered.
 *
 * When this is used, generally it's good practice to also dispose of the event handler by setting its variable to nil
 * (e.g., 'playerDeathHandler = nil').
 *
 * @param eventHandler     Event callback handler to deregister. NOTE: This must not be a local variable.
 */
void ReleaseObjectKill(void* eventHandler);

/**
 * Actor: object
 * Context: killer (character)
 *
 * This Event occurs when an Object dies.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `object, killer`
 * @return                 Unique event callback handler
 */
void* OnObjectKill(const std::function<void(int object, int killer)>& callback);

/**
 * Actor: object
 * Context: killer (character)
 *
 * This Event occurs when an Object of the specified name dies.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `object, killer`
 * @param nameStr          Object name
 * @return                 Unique event callback handler
 */
void* OnObjectKillName(const std::function<void(int object, int killer)>& callback, const std::string& nameStr);

/**
 * Actor: object
 * Context: killer (character)
 *
 * This Event occurs when an Object of the specified team dies.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `object, killer`
 * @param teamIndex        Object team
 * @return                 Unique event callback handler
 */
void* OnObjectKillTeam(const std::function<void(int object, int killer)>& callback, int teamIndex);

/**
 * Actor: object
 * Context: killer (character)
 *
 * This Event occurs when an Object of the specified class dies.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `object, killer`
 * @param configStr        Object config
 * @return                 Unique event callback handler
 */
void* OnObjectKillConfig(const std::function<void(int object, int

 killer)>& callback, const std::string& configStr);

// ObjectHeadshot

/**
 * Deregisters the specified event callback handler.
 *
 * For example, if you assign an event callback to a variable via 'playerDeathHandler = OnCharacterDeath(<...>)',
 * calling 'ReleaseCharacterDeath(playerDeathHandler)' would stop the contents of whatever is in '<...>' from
 * executing because the event callback's handler will have been removed from the list of event callbacks that
 * should be executed when 'OnCharacterDeath' (or any one of its filter equivalents, such as 'OnCharacterDeathTeam', etc.)
 * is triggered.
 *
 * When this is used, generally it's good practice to also dispose of the event handler by setting its variable to nil
 * (e.g., 'playerDeathHandler = nil').
 *
 * @param eventHandler     Event callback handler to deregister. NOTE: This must not be a local variable.
 */
void ReleaseObjectHeadshot(void* eventHandler);

/**
 * Actor: object (entity soldier)
 * Context: killer (character)
 *
 * This Event occurs when an Object gets shot in the head.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `object, killer`
 * @return                 Unique event callback handler
 */
void* OnObjectHeadshot(const std::function<void(int object, int killer)>& callback);

/**
 * Actor: object (entity soldier)
 * Context: killer (character)
 *
 * This Event occurs when an Object of the specified name gets shot in the head.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `object, killer`
 * @param nameStr          Object name
 * @return                 Unique event callback handler
 */
void* OnObjectHeadshotName(const std::function<void(int object, int killer)>& callback, const std::string& nameStr);

/**
 * Actor: object (entity soldier)
 * Context: killer (character)
 *
 * This Event occurs when an Object of the specified team gets shot in the head.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `object, killer`
 * @param teamIndex        Object team
 * @return                 Unique event callback handler
 */
void* OnObjectHeadshotTeam(const std::function<void(int object, int killer)>& callback, int teamIndex);

/**
 * Actor: object (entity soldier)
 * Context: killer (character)
 *
 * This Event occurs when an Object of the specified class gets shot in the head.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `object, killer`
 * @param configStr        Object config
 * @return                 Unique event callback handler
 */
void* OnObjectHeadshotConfig(const std::function<void(int object, int killer)>& callback, const std::string& configStr);

// ObjectRespawn

/**
 * Deregisters the specified event callback handler.
 *
 * For example, if you assign an event callback to a variable via 'playerDeathHandler = OnCharacterDeath(<...>)',
 * calling 'ReleaseCharacterDeath(playerDeathHandler)' would stop the contents of whatever is in '<...>' from
 * executing because the event callback's handler will have been removed from the list of event callbacks that
 * should be executed when 'OnCharacterDeath' (or any one of its filter equivalents, such as 'OnCharacterDeathTeam', etc.)
 * is triggered.
 *
 * When this is used, generally it's good practice to also dispose of the event handler by setting its variable to nil
 * (e.g., 'playerDeathHandler = nil').
 *
 * @param eventHandler     Event callback handler to deregister. NOTE: This must not be a local variable.
 */
void ReleaseObjectRespawn(void* eventHandler);

/**
 * Actor: object
 * Context: none
 *
 * This Event occurs when an Object respawns.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `object`
 * @return                 Unique event callback handler
 */
void* OnObjectRespawn(const std::function<void(int object)>& callback);

/**
 * Actor: object
 * Context: none
 *
 * This Event occurs when an Object of the specified name respawns.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `object`
 * @param nameStr          Object name
 * @return                 Unique event callback handler
 */
void* OnObjectRespawnName(const std::function<void(int object)>& callback, const std::string& nameStr);

/**
 * Actor: object
 * Context: none
 *
 * This Event occurs when an Object of the specified team respawns.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `object`
 * @param teamIndex        Object team
 * @return                 Unique event callback handler
 */
void* OnObjectRespawnTeam(const std::function<void(int object)>& callback, int teamIndex);

/**
 * Actor: object
 * Context: none
 *
 * This Event occurs when an Object of the specified class respawns.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `object`
 * @param configStr        Object config
 * @return                 Unique event callback handler
 */
void* OnObjectRespawnConfig(const std::function<void(int object)>& callback, const std::string& configStr);

// ObjectDelete

/**
 * Deregisters the specified event callback handler.
 *
 * For example, if you assign an event callback to a variable via 'playerDeathHandler = OnCharacterDeath(<...>)',
 * calling 'ReleaseCharacterDeath(playerDeathHandler)' would stop the contents of whatever is in '<...>' from
 * executing because the event callback's handler will have been removed from the list of event callbacks that
 * should be executed when 'OnCharacterDeath' (or any one of its filter equivalents, such as 'OnCharacterDeathTeam', etc.)
 * is triggered.
 *
 * When this is used, generally it's good practice to also dispose of the event handler by setting its variable to nil
 * (e.g., 'playerDeathHandler = nil').
 *
 * @param eventHandler     Event callback handler to deregister. NOTE: This must not be a local variable.
 */
void ReleaseObjectDelete(void* eventHandler);

/**
 * Actor: object
 * Context: none
 *
 * This Event occurs on the deletion of an Object. Do not use the Object after deletion!
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `object`
 * @return                 Unique event callback handler
 */
void* OnObjectDelete(const std::function<void(int object)>& callback);

/**
 * Actor: object
 * Context: none
 *
 * This Event occurs on the deletion of an Object of the specified name. Do not use the Object after deletion!
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `object`
 * @param nameStr          Object name
 * @return                 Unique event callback handler
 */
void* OnObjectDeleteName(const std::function<void(int object)>& callback, const std::string& nameStr);

/**
 * Actor: object
 * Context: none
 *
 * This Event occurs on the deletion of an Object of the specified team. Do not use the Object after deletion!
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `object`
 * @param teamIndex        Object team
 * @return                 Unique event callback handler
 */
void* OnObjectDeleteTeam(const std::function<void(int object)>& callback, int teamIndex);

/**
 * Actor: object
 * Context: none
 *
 * This Event occurs on the deletion of an Object of the specified class. Do not use the Object after deletion!
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `object`
 * @param configStr        Object config
 * @return                 Unique event callback handler
 */
void* OnObjectDeleteConfig(const std::function<void(int object)>& callback, const std::string& configStr);

// TeamChange

/**
 * Deregisters the specified event callback handler.
 *
 * For example, if you assign an event callback to a variable via 'playerDeathHandler = OnCharacterDeath(<...>)',
 * calling 'ReleaseCharacterDeath(playerDeathHandler)' would stop the contents of whatever is in '<...>' from
 * executing because the event callback's handler will have been removed from the list of event callbacks that
 * should be executed when 'OnCharacterDeath' (or any one of its filter equivalents, such as 'OnCharacterDeathTeam', etc.)
 * is triggered.
 *
 * When this is used, generally it's good practice to also dispose of the event handler by setting its variable to nil
 * (e.g., 'playerDeathHandler = nil').
 *
 * @param eventHandler     Event callback handler to deregister. NOTE: This must not be a local variable.
 */
void ReleaseTeamChange(void* eventHandler);

/**
 * Actor: object
 * Context: team
 *
 * This Event occurs when an Object changes teams.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `object, team`
 * @return                 Unique event callback handler
 */
void* OnTeamChange(const std::function<void(int object, int team)>& callback);

/**
 * Actor: object
 * Context: team
 *
 * This Event occurs when an Object of the specified name changes teams.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `object, team`
 * @param nameStr          Object name
 * @return                 Unique event callback handler
 */
void* OnTeamChangeName(const std::function<void(int object, int team)>& callback, const std::string& nameStr

);

/**
 * Actor: object
 * Context: team
 *
 * This Event occurs when an Object of the specified team changes teams.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `object, team`
 * @param teamIndex        Object team
 * @return                 Unique event callback handler
 */
void* OnTeamChangeTeam(const std::function<void(int object, int team)>& callback, int teamIndex);

/**
 * Actor: object
 * Context: team
 *
 * This Event occurs when an Object of the specified class changes teams.
 *
 * @param callback         Callback to execute, generally a lambda function. Uses parameters: `object, team`
 * @param configStr        Object config
 * @return                 Unique event callback handler
 */
void* OnTeamChangeConfig(const std::function<void(int object, int team)>& callback, const std::string& configStr);

} // namespace Battlefront2API

#endif // BATTLEFRONT2API_H
