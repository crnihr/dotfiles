[Variables]
date_x=1705

[Metadata]
Name=Pratous\\Date
Author=reddit.com/u/falconwingz
Description=Display date. Click to activate Calendar View with Google Calendar and Microsoft Outlook support.

[MeasureDate]
Measure=Time
Format=%a, %b %#d, %Y

[DateIcon]
Meter=String
;Text=
Text=
FontFace=Material Icons
FontSize=(#Font_Size#*16/13)
FontColor=#TextColor2#
AntiAlias=1
StringAlign=LeftCenter
X=(#Bar_OffsetX#+#Date_X#)
Y=(#Bar_OffsetY#+#Bar_Height#/2)
DynamicVariables=1

[Date]
Meter=String
MeasureName=MeasureDate
FontFace=#Font_Face#
FontSize=#Font_Size#
FontWeight=#Font_Weight#
FontColor=#TextColor2##Font_Opacity#
AntiAlias=1
StringAlign=LeftCenter
X=8R
Y=r
DynamicVariables=1
LeftMouseUpAction=

