[Variables]
Power_X=885

[Metadata]
Name=Paper\\Power
Author=reddit.com/u/khanhas
Description=Click to activate Power menu to Turn Off, Restart, Sleep or Log off.

[PowerShape]
Meter=Shape
X=(#Bar_OffsetX#+#Power_X#)
Y=#Bar_OffsetY#
Shape=Rectangle 0,0,([PowerButton:W]+#Bar_Height#),#Bar_Height# | StrokeWidth 0 | Extend FillColor
FillColor=Fill Color 00000001
DynamicVariables=1

[PowerReplaceCharCalc]
Measure=Calc
IfCondition=SubSkinDirectionCalc = 1
IfTrueAction=[!SetVariable PowerReplaceChar ]
IfFalseAction=[!SetVariable PowerReplaceChar ]

[PowerButton]
Meter=String
Text=
FontFace=Material Icons
FontSize=(#Font_Size#*16/13)
FontColor=#PowerColor#
AntiAlias=1
StringAlign=CenterCenter
X=([PowerButton:W]/2+#Bar_Height#/2)r
Y=(#Bar_OffsetY#+#Bar_Height#/2)
LeftMouseUpAction=[!SetOption #CURRENTSECTION# Text #PowerReplaceChar#][!UpdateMeter PowerButton][!Redraw][!WriteKeyValue Variables Curr_X (#Bar_OffsetX#+#Power_X#+#CURRENTCONFIGX#) "#ROOTCONFIGPATH#\Scripts\PowerMenu.ini"][!WriteKeyValue Variables Curr_Y [SubSkinYPositionCalc] "#ROOTCONFIGPATH#\Scripts\PowerMenu.ini"][!WriteKeyValue Variables Dir [SubSkinDirectionCalc] "#ROOTCONFIGPATH#\Scripts\PowerMenu.ini"][!ToggleConfig "#ROOTCONFIG#\Scripts" "PowerMenu.ini"]
DynamicVariables=1
