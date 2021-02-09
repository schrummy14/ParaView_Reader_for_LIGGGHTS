This is copied from the forum post on CFDEM.com
URL: https://www.cfdem.com/forums/update-richti83-visualisation-script-super-quadric-particles
Author: Jan Evangelista Purkyně University in Ústí nad Labem, Faculty of Science, Pasteurova 3632/15, 400 96 Ústí nad Labem, Czech Republic https://prf.ujep.cz/en/
Team leader: Jaromir Havlica (havlica@icpf.cas.cz)

Below is the forum post and modification will be denoted in a different file.

******************************************
Changes:
v2.0
* Multiple types and sizes of superquadric particles in single file
* Automatically included variables
* Toroid representation switch - fixed height and surface area
* Optional data skipping
* Removed precision switch - decided by input data
v1.1
* GUI interface
* Two versions - custom/vtk source, custom lpp/vtk source
* Fixed height toroid representation
v1.0
* Initial release based on richti's code
******************************************
Requirements:
* Requires Paraview v4.0.1 and newer
******************************************
Notes:
* Liggghts vtk and lpp converted vtk files have different structure - use appropriate xml version
* Some parameters can have different names in older LIGGGHTS versions (TENSOR=M, etc. - check advanced settings in script to edit property names)
* You may need to change initial rotation of superquadric particle - in newer Paraview versions main axis is set to Y (default) instead of Z
* Tested on Paraview 5.5.0, 5.6.0 x64
******************************************
Sources:

* custom/vtk dump with defined values
dump dmp all custom/vtk 100 post/dump*.superq.vtk id type mass x y z vx vy vz fx fy fz omegax omegay omegaz radius shapex shapey shapez quat1 quat2 quat3 quat4 blockiness1 blockiness2 tqx tqy tqz angmomx angmomy angmomz

Minimal requirements: x y z blockiness1 blockiness2 shapex shapey shapez quat1 quat2 quat3 quat4

* custom dump with defined values
dump dmp all custom 100 post/dump*.superq id type mass x y z vx vy vz fx fy fz omegax omegay omegaz radius shapex shapey shapez quat1 quat2 quat3 quat4 blockiness1 blockiness2 tqx tqy tqz angmomx angmomy angmomz

Minimal requirements: x y z blockiness1 blockiness2 shapex shapey shapez quat1 quat2 quat3 quat4

Convert via lpp tool into vtk afterwards
cd post
lpp dump*.superq
******************************************
Usage:

* Paraview with VTK superquadric support and xml plugins support

-1) Load plugins - can be auto-loaded next time

Tools - Manage Plugins - Load New - LiggghtsSuperquadricVTK.xml
Tools - Manage Plugins - Load New - LiggghtsSuperquadricDUMP.xml

0) Open dump*.superq.vtk or superq*.vtk

1) Select dump

2) Filters -> Alphabetical -> LIGGGHTS - Superquadric visualiser (VTK) or LIGGGHTS - Superquadric visualiser (DUMP)

3) Done

* Paraview with VTK superquadric support

In case of incompatible version of Paraview for xml filter

0) Open dump*.superq.vtk or superq*.vtk

1) Select dump

2) Filters -> Alphabetical -> Programmable Filter

Select output as vtkUnstructuredGrid
Input python data from specified .py file

3) Done
******************************************

