[Variables]
Uptime_X=955

[Metadata]
Name=Paper\\Uptime
Author=reddit.com/u/falconwingz
Description=Display up time.

[MeasureUptime]
Measure=upTime
Format="%3!i!h, %2!i!m, %1!i!s"

[UptimeIcon]
Meter=String
Text=
FontFace=Material Icons
FontSize=(#Font_Size#*16/13)
FontColor=#PowerColor#
AntiAlias=1
StringAlign=LeftCenter
X=(#Bar_OffsetX#+#Uptime_X#)
Y=(#Bar_OffsetY#+#Bar_Height#/2)
DynamicVariables=1
Hidden=1

[Uptime]
Meter=String
MeasureName=MeasureUptime
FontFace=#Font_Face#
FontSize=#Font_Size#
FontWeight=#Font_Weight#
FontColor=#TextColor1##Font_Opacity#
AntiAlias=1
StringAlign=CenterCenter
X=10R
Y=r
LeftMouseUpAction=taskmgr
ToolTipText=Task Manager

