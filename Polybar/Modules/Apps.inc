[Variables]
Apps_X =1330

[Metadata]
Name=Pratous\\Apps
Author=reddit.com/u/khanhas
Description=Launch apps


;editor
[DesktopShape]
Meter=Shape
X=(#Bar_OffsetX#+#Apps_X#)
Y=#Bar_OffsetY#
Shape=Rectangle 0,0,([DesktopButton:W]+#Bar_Height#/2),#Bar_Height# | StrokeWidth 0 | Extend FillColor
FillColor=Fill Color 00000001
DynamicVariables=1

[DesktopButton]
Meter=String
Text=
FontFace=Material Icons
FontSize=(#Font_Size#*16/13)
FontColor=#TextColor2#
AntiAlias=1
StringAlign=CenterCenter
X=(#Bar_Height#/4+[DesktopButton:W]/2)+5r
Y=(#Bar_OffsetY#+#Bar_Height#/2)
SolidColor=0,0,0,1
LeftMouseUpAction=["C:\Program Files\Notepad++\notepad++.exe"]
RightMouseUpAction=
ToolTipText=Notepad++
DynamicVariables=1


;settings
[DesktopShape2]
Meter=Shape
X=(#Bar_OffsetX#+#Apps_X#)+28
Y=#Bar_OffsetY#
Shape=Rectangle 0,0,([DesktopButton:W]+#Bar_Height#/2),#Bar_Height# | StrokeWidth 0 | Extend FillColor
FillColor=Fill Color 00000001
DynamicVariables=1

[DesktopButton2]
Meter=String
Text=
FontFace=Material Icons
FontSize=(#Font_Size#*16/13)
FontColor=#TextColor2#
AntiAlias=1
StringAlign=CenterCenter
X=(#Bar_Height#/4+[DesktopButton:W]/2)+5r
Y=(#Bar_OffsetY#+#Bar_Height#/2)
SolidColor=0,0,0,1
LeftMouseUpAction=ms-settings:
RightMouseUpAction=["C:\TaskbarX\TaskbarX Configurator.exe"]
ToolTipText=System settings#CRLF#Dock settings
DynamicVariables=1


;recyclebin
[DesktopShape3]
Meter=Shape
X=(#Bar_OffsetX#+#Apps_X#)+56
Y=#Bar_OffsetY#
Shape=Rectangle 0,0,([DesktopButton:W]+#Bar_Height#/2),#Bar_Height# | StrokeWidth 0 | Extend FillColor
FillColor=Fill Color 00000001
DynamicVariables=1

[DesktopButton3]
Meter=String
Text=
FontFace=Material Icons
FontSize=(#Font_Size#*16/13)
FontColor=#TextColor2#
AntiAlias=1
StringAlign=CenterCenter
X=(#Bar_Height#/4+[DesktopButton:W]/2)+5r
Y=(#Bar_OffsetY#+#Bar_Height#/2)
SolidColor=0,0,0,1
LeftMouseUpAction=shell:RecycleBinFolder	
RightMouseUpAction=
ToolTipText=Recycle Bin
DynamicVariables=1