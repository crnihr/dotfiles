[Variables]
Time_X=1855

[Metadata]
Name=Pratous\\Clock
Author=reddit.com/u/khanhas
Description=Clock with material icon. Click to activate Windows 10 Alarm & Clock app.

[MeasureTime]
Measure=Time
Format=%R

[TimeIcon]
Meter=String
Text=
FontFace=FontAwesome
FontSize=(#Font_Size#*16/13)
FontColor=#TextColor1#
AntiAlias=1
StringAlign=LeftCenter
X=(#Bar_OffsetX#+#Time_X#)
Y=(#Bar_OffsetY#+#Bar_Height#/2)
DynamicVariables=1

[Time]
Meter=String
MeasureName=MeasureTime
FontFace=#Font_Face#
FontSize=#Font_Size#
FontWeight=#Font_Weight#
FontColor=#TextColor1##Font_Opacity#
AntiAlias=1
StringAlign=LeftCenter
X=8R
Y=r
DynamicVariables=1
RightMouseUpAction=[explorer.exe shell:appsFolder\Microsoft.WindowsAlarms_8wekyb3d8bbwe!App]
LeftMouseUpAction=["#@#nircmd.exe" sendkeypress lwin+a]
