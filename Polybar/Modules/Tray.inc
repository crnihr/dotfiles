[Variables]
Tray_X=1005

[Metadata]
Name=Paper\\Tray
Author=reddit.com/u/khanhas
Description=Click to show tray

[TrayShape]
Meter=Shape
X=(#Bar_OffsetX#+#Tray_X#)
Y=#Bar_OffsetY#
Shape=Rectangle 0,0,([TrayButton:W]+#Bar_Height#/2),#Bar_Height# | StrokeWidth 0 | Extend FillColor
FillColor=Fill Color 00000001
DynamicVariables=1

[TrayXPos]
Measure=Calc
Formula=#CURRENTCONFIGX#+[TrayButton:X]+[TrayButton:W]/2
DynamicVariables=1

[TrayYPos]
Measure=Calc
Formula=#CURRENTCONFIGY# >= #SCREENAREAHEIGHT#/2 ? (#CURRENTCONFIGY#+#Bar_OffsetY#) : (#CURRENTCONFIGY#+#Bar_OffsetY#+#Bar_Height#)
DynamicVariables=1

[TrayIconDirection]
Measure=String
IfCondition=SubSkinDirectionCalc = 1
IfTrueAction=[!SetOption TrayIconDirection String ""]
IfFalseAction=[!SetOption TrayIconDirection String ""]
DynamicVariables=1 

[TrayButton]
Meter=String
Text=
FontFace=Material Icons
FontSize=(#Font_Size#*16/13)
FontColor=#TextColor1#
AntiAlias=1
StringAlign=CenterCenter
X=(#Bar_Height#/4+[TrayButton:W]/2)r
Y=(#Bar_OffsetY#+#Bar_Height#/2)+2
SolidColor=0,0,0,1
LeftMouseDownAction=["#@#ActivateTray.exe" "[TrayXPos]" "[TrayYPos]" "[SubSkinDirectionCalc]"]
DynamicVariables=1
