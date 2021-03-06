# FFRK Ability Orb Calculator
![alt-tag](https://cloud.githubusercontent.com/assets/2381953/10517775/70fe4e16-732c-11e5-9ccb-1c4cd12fba3f.png)

![alt-tag](https://cloud.githubusercontent.com/assets/2381953/10517780/7485b93e-732c-11e5-9569-6ddca55d88d8.png)

This is a light-weight application that allows the calculation of orbs needed for the abilities in FFRK. The data is stored within flat files and parsed at application runtime.

To use the application, download the <a href="https://github.com/Tibonium/ffrk_abilities/raw/master/builds/windows_release.zip">Windows Full</a> or <a href="https://github.com/Tibonium/ffrk_abilities/raw/master/builds/linux_release.tar.gz">Linux Full</a> version (Linux version as of 6 Apr 2016 has not been updated like windows). After doing so, unpack the files to any folder. Before running the application, you'll need to make sure the filepath for the application is correct. To do this, open the ffrk_ability_config file and change the line to "spells/", save and then close. Then you should be able to open the application.

If you just need the most recent exectuable, you can select from the below:

* <a href="https://github.com/Tibonium/ffrk_abilities/raw/master/builds/ffrk_abilities_windows.exe">Windows</a>
* <a href="https://github.com/Tibonium/ffrk_abilities/raw/master/builds/ffrk_abilities_linux">Linux</a> (Older version, yet to be updated)

A few notes about usage. Without going into major depth right now (I plan to have a better ReadMe) in the future, the application runs off of flat files provided in the spells directory. There is a "set of files", the "_magic" files, and then the orb_statistics file.

The "_magic" files contain the abilities from FFRK. The format should be pretty evident when viewing a single file, and hence you can add any missed ones. Please let me know if I missed any though, as I want to add it to the download files so future people won't have to worry about it. The parser is case sensative and the format is set in stone, so be careful when editing the files. If you do break the parser, you'll receive a notification in the stdout with where and what the file error is, so you can easily find and correct it. Lastly, you'll need to have the definition of the Lvl Schemas, which are provided below:
````
Schema  Cumulative Count        Base per Rank
1       {1, 3, 6,10, 15}        {1, 2, 3, 4, 5}
2       {2, 5, 11, 23, 41}      {2, 3, 6, 12, 18}
2A      {2, 7, 17, 37, 67}      {2, 5, 10, 20, 30}
3       {3, 9, 21, 39, 69}      {3, 6, 12, 18, 30}
3A      {3, 11, 26, 46, 91}     {3, 8, 15, 30, 45}
3B      {3, 8, 18, 38, 68}      {3, 5, 10, 20, 30}
3C      {3, 8, 18, 33, 58}      {3, 5, 10, 15, 25}
3D      {3, 9, 18, 30, 45}      {3, 6, 9, 12, 15}
5       {5, 15, 35, 65, 115}    {5, 10, 20, 30, 50}
6       {6, 18, 36, 66, 126}    {6, 12, 18, 30, 60}
6A      {6, 18, 42, 78, 138}    {6, 12, 24, 36, 60}
6B      {6, 16, 36, 76, 136}    {6, 10, 20, 40, 60}
8       {8, 23, 53, 98, 173}    {8, 15, 30, 45, 75}
10      {10, 30, 70, 130, 230}  {10, 20, 40, 60, 100}
10A     {10, 30, 60, 110, 210}  {10, 20, 30, 50, 100}
15      {15, 45, 90, 165, 315}  {15, 30, 45, 75, 150}
````
Finally, the orb_statistics file provides a fun way to attempt to figure out how much stamina is going to be required to get all the juicy orbs that you're looking for. Simply change the Stamina/orb values to the currently accepted values, then change the probability of orb drop for each orb type to the required value. If you do this while the application is running, you can save the file then click ont he "Reload Probablities" button to update the application with the new information.

* If you're unable to run the application because of an error "Missing MSVCR120.DLL" you can download and install this file [here](https://www.microsoft.com/en-US/download/details.aspx?id=40784). You'll need to install the ".._x86" version for the application to work properly.

NOTICE: I do have abilities in the application flat files that have NOT been released globally yet, so be aware of this when planning.

DISCLAIMER: The estimated stamina in the application is the most LIKELY amount of stamina required to obtain the amount of orbs with the statistics provided. This means you could have anything from WAY MORE or LESS stamina required to achieve your goal.

UPDATE: Added Darkness and enabled Blue, Engineer (Machinist). When spell maps are created, if the file does not exist the user will be instructed that it was not loaded and the reason, but will continue to load all available files. Contributions to names and spells by /u/OberonGX
